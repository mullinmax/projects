

class level {

  int tiles_wide;
  int tiles_tall;
  boolean [][] is_wall;
  String tiles;
  PImage background;
  PImage graphics;
  int scale;
  void load_level(String file) {
    String [] level_data = loadStrings(file);
    level_data = split(level_data[0], ' ');
    tiles_wide = int(level_data[0]);
    tiles_tall = int(level_data[1]);
    tiles = level_data[2];
  }
  void save_level(String file) {
    String [] level_data = new String[1];
    level_data[0] = tiles_wide + " ";
    level_data[0] += tiles_tall + " ";
    level_data[0] += tiles; 
    saveStrings(file, level_data);
  }
  void render_level() {
    println("rendering");
    is_wall = new boolean[tiles_wide][tiles_tall];
    for (int x = 0; x < tiles_wide; x++) {
      for (int y = 0; y < tiles_tall; y++) {
        int col = x;
        int row = y * tiles_wide;
        if (tiles.charAt(col+row) == 'W') {
          is_wall[x][y] = true;
        } else if (tiles.charAt(col+row) == 'E') {
          is_wall[x][y] = false;
        }
      }
    }

    graphics = loadImage("graphics_test.png");
    scale = 40;//width / tiles_wide;
    PImage wall_left_down = graphics.get(0, 20, 9, 9);
    PImage wall_right_down = rotateImage_CC(wall_left_down);
    PImage wall_right_up = rotateImage_CC(wall_right_down);
    PImage wall_left_up = rotateImage_CC(wall_right_up);

    PImage wall_up_down = graphics.get(10, 30, 9, 9);
    PImage wall_left_right = rotateImage_CC(wall_up_down);

    PImage wall_end_up = graphics.get(10, 20, 9, 9);
    PImage wall_end_left = rotateImage_CC(wall_end_up);
    PImage wall_end_down = rotateImage_CC(wall_end_left);
    PImage wall_end_right = rotateImage_CC(wall_end_down);

    PImage wall_T_up = graphics.get(20, 20, 9, 9);
    PImage wall_T_left = rotateImage_CC(wall_T_up);
    PImage wall_T_down = rotateImage_CC(wall_T_left);
    PImage wall_T_right = rotateImage_CC(wall_T_down);

    PImage wall_all = graphics.get(20, 30, 9, 9);

    PImage wall_none = graphics.get(0, 30, 9, 9);

    PImage empty = graphics.get(0, 40, 9, 9);

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
    background.updatePixels();
  }
  void draw_level() {
    background(0);
    image(background, 0, 0, width, height);
  }
  void add_wall(int x_p, int y_p) {
    int x = x_p/(width / tiles_wide * 1.0);//goes out oof bounds on edges
    int y = y_p/(height / tiles_tall * 1.0);
    is_wall[x][y] = true;
    println("adding wall: " + x + ", " + y);
    render_level();
  }
  void remove_wall() {
  }
  void print_level() {
    println(tiles_wide);
    println(tiles_tall);
    println(tiles);
  }
}