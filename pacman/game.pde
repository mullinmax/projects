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
    field.load_level("data/test_level.txt");
    field.render_level();
  }
  void update() {
  }
  void display() {
    field.draw_level();
  }

  void click() {
    if (mouseButton == LEFT) {
      field.add_wall(mouseX, mouseY);
    }
    if (mouseButton == RIGHT) {
      field.remove_wall(mouseX, mouseY);
    }
  }

  void key() {
    if (keyCode == 'J') {
    }
    if (keyCode == 'P') {
    }
  }
}