class level {
  int tiles_wide;
  int tiles_tall;
  boolean [][] is_wall;
  char [][] tiles;
  PImage background;
  PImage graphics;
  int scale;
  PImage wall_left_down;
  PImage wall_right_down;
  PImage wall_right_up;
  PImage wall_left_up;
  PImage wall_up_down;
  PImage wall_left_right;
  PImage wall_end_up;
  PImage wall_end_left;
  PImage wall_end_down;
  PImage wall_end_right;
  PImage wall_T_up;
  PImage wall_T_left;
  PImage wall_T_down;
  PImage wall_T_right;
  PImage wall_all;
  PImage wall_none;
  PImage empty;
  PImage erase;
  void load_level(String file) {
    String [] level_data = loadStrings(file);
    level_data = split(level_data[0], ' ');
    tiles_wide = int(level_data[0]);
    tiles_tall = int(level_data[1]);
    println(tiles_wide + ", " + tiles_tall);
    tiles = new char[tiles_wide][tiles_tall];
    String tile_string = level_data[2];
    is_wall = new boolean[tiles_wide][tiles_tall];
    for (int y = 0; y < tiles_tall; y++) {
      for (int x = 0; x < tiles_wide; x++) {
        int col = x;
        int row = y * tiles_wide;
        //try{
        tiles[x][y] = tile_string.charAt(col+row);
        //}catch(ArrayIndexOutOfBoundsException e){
        //}
        if (tile_string.charAt(col+row) == 'W') {
          is_wall[x][y] = true;
        } else if (tile_string.charAt(col+row) == 'E') {
          is_wall[x][y] = false;
        }
      }
    }
    graphics = loadImage("graphics_test.png");
    scale = min(width / tiles_wide, height / tiles_tall);
    wall_left_down = graphics.get(0, 20, 9, 9);
    wall_right_down = rotateImage_CC(wall_left_down);
    wall_right_up = rotateImage_CC(wall_right_down);
    wall_left_up = rotateImage_CC(wall_right_up);

    wall_up_down = graphics.get(10, 30, 9, 9);
    wall_left_right = rotateImage_CC(wall_up_down);

    wall_end_up = graphics.get(10, 20, 9, 9);
    wall_end_left = rotateImage_CC(wall_end_up);
    wall_end_down = rotateImage_CC(wall_end_left);
    wall_end_right = rotateImage_CC(wall_end_down);

    wall_T_up = graphics.get(20, 20, 9, 9);
    wall_T_left = rotateImage_CC(wall_T_up);
    wall_T_down = rotateImage_CC(wall_T_left);
    wall_T_right = rotateImage_CC(wall_T_down);

    wall_all = graphics.get(20, 30, 9, 9);

    wall_none = graphics.get(0, 30, 9, 9);

    empty = graphics.get(0, 40, 9, 9);

    erase = graphics.get(20, 40, 9, 9);
  }
  void save_level(String file) {
    String [] level_data = new String[1];
    level_data[0] = tiles_wide + " ";
    level_data[0] += tiles_tall + " ";
    for (int y = 0; y < tiles_tall; y++) {
      for (int x = 0; x < tiles_wide; x++) {
        if (tiles[x][y] == 'W') {
          if (!is_wall[x][y]) {
            tiles[x][y] = 'E';
          }
        } else if (is_wall[x][y]) {
          tiles[x][y] = 'W';
        }
        level_data[0] += tiles[x][y];
      }
    }
    //add in otherthings like start pos and jail to string
    saveStrings(file, level_data);
  }
  void render_level() {
    background = createImage(tiles_wide * 9, tiles_tall * 9, RGB);
    background.loadPixels();
    for (int x = 0; x < tiles_wide; x++) {
      for (int y = 0; y < tiles_tall; y++) {
        if (is_wall[x][y]) {
          if (y > 0 && is_wall[x][y-1]) {
            if (y < tiles_tall - 1 && is_wall[x][y+1]) {
              if (x < tiles_wide - 1 && is_wall[x+1][y]) {
                if (x > 0 && is_wall[x-1][y]) {
                  //up down right left 
                  background.set(x*9, y*9, wall_all);
                } else {//up down right not left
                  background.set(x*9, y*9, wall_T_right);
                }
              } else {
                if (x > 0 && is_wall[x-1][y]) {
                  //up down not right left
                  background.set(x*9, y*9, wall_T_left);
                } else {
                  //up down not right not left
                  background.set(x*9, y*9, wall_up_down);
                }
              }
            } else {
              if (x < tiles_wide - 1 && is_wall[x+1][y]) {
                if (x > 0 && is_wall[x-1][y]) {
                  //up not down right left
                  background.set(x*9, y*9, wall_T_up);
                } else {
                  //up not down right not left
                  background.set(x*9, y*9, wall_right_up);
                }
              } else {
                if (x > 0 && is_wall[x-1][y]) {
                  //up not down not right left
                  background.set(x*9, y*9, wall_left_up);
                } else {
                  //up not down not right not left
                  background.set(x*9, y*9, wall_end_up);
                }
              }
            }
          } else {
            if (y < tiles_tall - 1 && is_wall[x][y+1]) {
              if (x < tiles_wide - 1 && is_wall[x+1][y]) {
                if (x > 0 && is_wall[x-1][y]) {
                  //not up down right left
                  background.set(x*9, y*9, wall_T_down);
                } else {
                  //not up down right not left
                  background.set(x*9, y*9, wall_right_down);
                }
              } else {
                if (x > 0 && is_wall[x-1][y]) {
                  //not up down not right left
                  background.set(x*9, y*9, wall_left_down);
                } else {
                  //not up down not right not left
                  background.set(x*9, y*9, wall_end_down);
                }
              }
            } else {
              if (x < tiles_wide -1 && is_wall[x+1][y]) {
                if (x > 0 && is_wall[x-1][y]) {
                  //not up not down right left
                  background.set(x*9, y*9, wall_left_right);
                } else {
                  //not up not down right not left
                  background.set(x*9, y*9, wall_end_right);
                }
              } else {
                if (x > 0 && is_wall[x-1][y]) {
                  //not up not down not right left
                  background.set(x*9, y*9, wall_end_left);
                } else {
                  //not up not down not right not left
                  background.set(x*9, y*9, wall_none);
                }
              }
            }
          }
        } else {
          background.set(x*9, y*9, empty);
        }
      }
    }
    for (int x = 0; x < tiles_wide - 1; x++) {
      for (int y = 0; y < tiles_tall - 1; y++) {
        if (is_wall[x][y] && is_wall[x+1][y] && is_wall[x][y+1] && is_wall[x+1][y+1]) {
          background.set(x*9+5, y*9+5, erase);
        }
      }
    }
    background.updatePixels();
  }
  void draw_level() {
    background(0);
    imageMode(CENTER);
    image(background, width / 2, height / 2, background.width * scale / 9, background.height * scale / 9);
    imageMode(CORNER);
  }
  void add_wall(int x_p, int y_p) {
    float x_beg = (width/2.0)-(background.width * scale / 18.0);
    float y_beg = (height/2.0)-(background.height * scale / 18.0);
    float x_end = width - x_beg;
    float y_end = height - y_beg;
    if (x_p < x_beg || x_p > x_end || y_p < y_beg || y_p > y_end) {
      return;
    }
    x_p = int(map(x_p, x_beg, x_end, 0, tiles_wide));
    y_p = int(map(y_p, y_beg, y_end, 0, tiles_tall));
    int x = x_p;
    int y = y_p;
    if (x >= tiles_wide || y >= tiles_tall ||x < 0||y < 0) {
      return;
    }
    is_wall[x][y] = true;
    render_level();
  }
  void remove_wall(int x_p, int y_p) {
    float x_beg = (width/2.0)-(background.width * scale / 18.0);
    float y_beg = (height/2.0)-(background.height * scale / 18.0);
    float x_end = width - x_beg;
    float y_end = height - y_beg;
    if (x_p < x_beg || x_p > x_end || y_p < y_beg || y_p > y_end) {
      return;
    }
    x_p = int(map(x_p, x_beg, x_end, 0, tiles_wide));
    y_p = int(map(y_p, y_beg, y_end, 0, tiles_tall));
    int x = x_p;
    int y = y_p;
    if (x >= tiles_wide || y >= tiles_tall ||x < 0||y < 0) {
      return;
    }
    is_wall[x][y] = false;
    render_level();
  }
  void print_level() {
    println(tiles_wide);
    println(tiles_tall);
    for (int x = 0; x < tiles_wide; x++) {
      for (int y = 0; y < tiles_tall; y++) {
        print(tiles[x][y]);
      }
    }
    print("/n");
  }
}