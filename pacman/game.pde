class game {
  player pacman;
  blinky red;
  pinky pink;
  inky blue;
  clyde orange;
  int num_lives;
  int score;
  level field;
  game() {
    field = new level();
    field.load_level("data/with_player.txt");
    field.render_level();
    pacman = new player(field.player_start, field.o_size, field.scale);
    //pacman = new player(new PVector(10, 10), field.scale);
  }
  void update() {
  }
  void display() {
    field.draw_level();
    field.save_level("data/with_player.txt");
    pacman.display(field.origin);
  }

  void click() {
    if (mouseButton == LEFT) {
      field.add_wall();
    }
    if (mouseButton == RIGHT) {
      field.remove_wall();
    }
  }

  void key() {
    if (key == 'j') {
      field.set_jail();
    }
    if (key == 'p') {
      println("@@@");
      field.set_player_start();
      pacman.pos = field.player_start;
    }
  }
}