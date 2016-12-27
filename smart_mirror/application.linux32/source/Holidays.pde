void holidays(String hol[]) {
  for (int i = 1; i < hol.length; i++) {
    String minute = hol[i].substring(0, 2);
    String hour = hol[i].substring(3, 5);
    String day = hol[i].substring(6, 8);
    String month = hol[i].substring(9, 11);
    if (minute.equals("**")|| minute() == int(minute)) {
      if (hour.equals("**")|| hour() == int(hour)) {
        if (day.equals("**")|| day() == int(day)) {
          if (month.equals("**")|| month() == int(month)) {
            println(hol[i]);
          }
        }
      }
    }
  }
}