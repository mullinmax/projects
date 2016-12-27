void clock(float x, float y) {
  fill(255);
  int h = hour() % 12;
  int m = minute();
  int s = second();
  String time = h + ":";
  if (m < 10) {
    time += "0";
  }
  time += m;
  //seconds
  /*time += ":";
   if(s < 10){
   time += "0"; 
   }
   time += s;
   */
  text(time, x, y);
}