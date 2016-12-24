void date(float x, float y, float size){
  textSize(size);
  fill(255);
  String date = month() + "/" + day() + "/" + year(); 
  text(date, x, y);
}