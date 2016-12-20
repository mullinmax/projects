void clock(float x, float y, float size){
  textSize(size);
  String time = hour() + ":" + minute() + ":" + second();
  text(time, x, y);
}