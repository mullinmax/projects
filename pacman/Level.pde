class level {

  int tiles_wide;
  int tiles_tall;
  boolean [] is_wall;
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
    is_wall = new boolean[tiles_wide * tiles_tall];
    for (int x = 0; x < tiles_wide; x++) {
      for (int y = 0; y < tiles_tall; y++) {
        int col = x;
        int row = y * tiles_wide;
        if (tiles.charAt(col+row) == 'W') {
          is_wall[row+col] = true;
        } else if (tiles.charAt(col+row) == 'E') {
          is_wall[row+col] = false;
        }
      }
    }
    if (graphics == null) {
      graphics = loadImage("graphics_test.png");
    }
    scale = 40;//width / tiles_wide;
    PImage wall_img = graphics.get(0, 0, 9, 9);
    PImage empty_img = graphics.get(10, 10, 9, 9);
    background = createImage(tiles_wide * 9, tiles_tall * 9, RGB);
    background.loadPixels();
    for (int x = 0; x < tiles_wide; x++) {
      for (int y = 0; y < tiles_tall; y++) {
        if (is_wall[(y * tiles_wide)+x]) {
          background.set(x*9, y*9, wall_img);
        } else {
          background.set(x*9, y*9, empty_img);
        }
      }
    }
    background.updatePixels();
  }
  void draw_level() {
    background(100+100*sin(millis()/100.0));
    image(background, 0, 0, width, height);
  }

  void print_level() {
    println(tiles_wide);
    println(tiles_tall);
    println(tiles);
  }
}