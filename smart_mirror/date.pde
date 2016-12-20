void date(float x, float y, float size){
  textSize(size);
  String date = month() + "/" + day() + "/" + year(); 
  text(date, x, y);
}