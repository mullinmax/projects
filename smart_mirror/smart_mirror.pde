String weather;

int text_size = 20;
void setup() {
  size(500, 500);
  //fullScreen();
  noCursor();
  textAlign(CENTER);
  get_weather();
  frameRate(60);
}

void draw() {
  //background (0);
  fill(0, 0, 0, 20);
  rect(0, 0, width, height);
  date(width/2, text_size + height/10, text_size);
  clock(width/2, height/10, text_size);
  get_weather();
}