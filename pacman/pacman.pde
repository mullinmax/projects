//level field = new level();
game pacman;


void setup() {
  //fullScreen();
  size(900, 900);
  pacman = new game();
}

void draw() {
  pacman.update();
  pacman.display();
  //field.draw_level();
  //field.save_level("data/test_level.txt");
}

void mousePressed() {
  pacman.click();
}

void mouseDragged() {
  pacman.click();
}

void keyPressed() {
  pacman.key();
}