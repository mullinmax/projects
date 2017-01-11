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
      graphics = loadImage("graphics.png");
    }
    scale = width / tiles_wide;
    PImage wall_img = graphics.get(196, 77, 12, 12);
    PImage empty_img = graphics.get(6, 6, 12, 12);
    wall_img.resize(scale, scale);
    empty_img.resize(scale, scale);
    background = createImage(width, height, RGB);
    background.loadPixels();
    for (int x = 0; x < tiles_wide; x++) {
      for (int y = 0; y < tiles_tall; y++) {
        if (is_wall[(y * tiles_wide)+x]) {
          background.set(x*scale, y*scale, wall_img);
        } else {
          background.set(x*scale, y*scale, empty_img);
        }
      }
    }
    background.updatePixels();
  }
  void draw_level() {
    image(background, 0, 0, width, height);
  }

  void print_level() {
    println(tiles_wide);
    println(tiles_tall);
    println(tiles);
  }
}