level field = new level();



void setup() {
  size(900, 900);
  smooth(0);
  field.load_level("data/test_level.txt");
  //field.print_level();
  field.save_level("data/test_level.txt");
  field.render_level();
}

void draw() {
  field.draw_level();
  field.save_level("data/test_level.txt");
}

void mousePressed() 
{
  if (mouseButton == LEFT) {
    field.add_wall(mouseX, mouseY);
  }
  if (mouseButton == RIGHT) {
    field.remove_wall(mouseX, mouseY);
  }
}

void mouseDragged() 
{
  if (mouseButton == LEFT) {
    field.add_wall(mouseX, mouseY);
  }
  if (mouseButton == RIGHT) {
    field.remove_wall(mouseX, mouseY);
  }
}