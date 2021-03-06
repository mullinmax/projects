class player {
  PImage [] frames;
  int tile_size = 27;
  int field_tile_size;
  int tile_buff = 3;
  PVector pos;
  float size;
  player(PVector player_start,int o_size, int scale) {
    field_tile_size = o_size * scale;
    println(o_size);
    println(scale);
    pos = new PVector(player_start.x, player_start.y);
    size = scale;
    PImage temp = loadImage("graphics_test.png");
    frames = new PImage[3];
    frames[0] = temp.get(3*(tile_size + tile_buff), 0*(tile_size + tile_buff), 2*tile_size, 2*tile_size);
    frames[1] = temp.get(3*(tile_size + tile_buff), 1*(tile_size + tile_buff), 2*tile_size, 2*tile_size);
    frames[2] = temp.get(3*(tile_size + tile_buff), 2*(tile_size + tile_buff), 2*tile_size, 2*tile_size);
  }
  void update() {
  }
  void display(PVector org) {
    image(frames[0], tile_size+org.x, tile_size+org.y, size, size);
  }
}