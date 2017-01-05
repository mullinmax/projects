PFont large_font;
PFont small_font;
int small_size = 35;
int large_size = 100;

String hol[];

int text_size = 20;
void setup() {
  size(1024, 600);
  //fullScreen();
  noCursor();
  textAlign(CENTER);
  get_weather();
  frameRate(60);
  large_font = createFont("Prototype.ttf", int(1.2 *large_size));
  small_font = createFont("Prototype.ttf", int(1.2 * small_size));
  hol = loadStrings("hol.txt");
}

void draw() {
  //background (0);
  fill(0, 0, 0);//, 10);
  rect(0, 0, width, height);
  holidays(hol);
  textFont(large_font);
  date(width/2, 2 * large_size);
  clock(width/2, large_size);
  textFont(small_font);
  get_weather();
}