String weather;

int text_size = 20;
void setup() {
  fullScreen();
  noCursor();
  textAlign(CENTER);
  get_weather();
  frameRate(60);
}

void draw() {
  background (0);
  date(width/2, text_size + height/10, text_size);
  clock(width/2, height/10, text_size);
  get_weather();
}