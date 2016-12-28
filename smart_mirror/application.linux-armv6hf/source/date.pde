void date(float x, float y) {
  fill(255);
  String date = month() + "/" + day() + "/" + year(); 
  text(date, x, y);
}