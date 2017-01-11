level feild = new level();

void setup(){
  size(500, 500);
  smooth(0);
  feild.load_level("test_level.txt");
  feild.print_level();
  feild.save_level("test_save.txt");
  feild.load_level("test_save.txt");
  feild.print_level();
  feild.render_level();
  feild.draw_level();
  
}

void draw(){
  
}