void clock(float x, float y, float size){
  textSize(size);
  
  
  //needs to write zeros in when time is less than 10  
  
  String time = hour() + ":" + minute() + ":" + second();
  text(time, x, y);
}