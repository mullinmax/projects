PFont large_font;
PFont small_font;


int text_size = 20;
void setup() {
  //size(500, 500);
  fullScreen();
  noCursor();
  textAlign(CENTER);
  get_weather();
  frameRate(60);
  large_font = createFont("Prototype.ttf", 45);
  small_font = createFont("Prototype.ttf", 45);
}

void draw() {
  textFont(small_font);
  //background (0);
  fill(0, 0, 0, 10);
  rect(0, 0, width, height);
  date(width/2, 40+ height/10);
  clock(width/2, height/10);
  get_weather();
}