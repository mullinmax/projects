game pacman;


void setup() {
  //fullScreen();
  size(900, 900);
  pacman = new game();
}

void draw() {
  pacman.update();
  pacman.display();
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