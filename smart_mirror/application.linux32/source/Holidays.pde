PFont temp_font;
int previous_line = -1;

void holidays(String hol[]) {
  for (int i = 1; i < hol.length; i++) {
    String minute = hol[i].substring(0, 2);
    String hour = hol[i].substring(3, 5);
    String day = hol[i].substring(6, 8);
    String week_day = hol[i].substring(9, 11);
    String month = hol[i].substring(12, 14);
    String year = hol[i].substring(15, 19);
    if (minute.equals("**") || minute() == int(minute)) {
      if (hour.equals("**") || hour() == int(hour)) {
        if (week_day.equals("**") || day_of_week() == int(week_day)) { 
          if (day.equals("**") || day() == int(day)) {
            if (month.equals("**") || month() == int(month)) {
              if (year.equals("****") ||year() == int(year)) {
                String red = hol[i].substring(20, 23);
                String green = hol[i].substring(24, 27);
                String blue = hol[i].substring(28, 31);
                String font_name = hol[i].substring(32, 40);
                String display_text = hol[i].substring(41);
                //println("-"+red+"-"+green+"-"+blue+"-"+font_name+"-"+display_text+"-");
                if (previous_line != i) {
                  temp_font = createFont(font_name, 120);
                  previous_line = i;
                }
                textFont(temp_font);
                fill(float(red), float(green), float(blue));
                text(display_text, width/2, 360);
                return;
              }
            }
          }
        }
      }
    }
  }
  previous_line = -1;
}


int day_of_week() {
  int d = day();
  int m = month();
  int y = year();
  if (m < 3) {
    m += 12;
    y--;
  }
  return((d + int((m+1)*2.6) +  y + int(y/4) + 6*int(y/100) + int(y/400) + 6) % 7);
}