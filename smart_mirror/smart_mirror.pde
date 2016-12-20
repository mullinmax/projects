

String weather;

int text_size = 20;
void setup() {
  size(500, 500, P2D);
  textAlign(CENTER);
  get_weather();
  frameRate(60);
}

void draw() {
  background (0);
  date(width/2, text_size + height/10, text_size);
  clock(width/2, height/10, text_size);
  //print(weather);
  get_weather();
}