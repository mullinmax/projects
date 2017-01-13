level field = new level();



void setup() {
  size(900, 900);
  smooth(0);
  field.load_level("test_level.txt");
  //field.print_level();
  field.save_level("test_save.txt");
  field.load_level("test_save.txt");
  //field.print_level();
  field.render_level();
}

void draw() {
  field.draw_level();
}

void mouseClicked() 
{
  if (mouseButton == LEFT) {
    field.add_wall(mouseX, mouseY);
    println("!!!!!");
  }
  if (mouseButton == RIGHT) {
    //field.remove_wall(mouseX, mouseY);
  }
}