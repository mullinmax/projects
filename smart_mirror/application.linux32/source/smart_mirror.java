import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class smart_mirror extends PApplet {

PFont large_font;
PFont small_font;
int small_size = 35;
int large_size = 100;

String hol[];

int text_size = 20;
public void setup() {
  //size(1024, 600);
  
  noCursor();
  textAlign(CENTER);
  get_weather();
  frameRate(60);
  large_font = createFont("Prototype.ttf", PApplet.parseInt(1.2f *large_size));
  small_font = createFont("Prototype.ttf", PApplet.parseInt(1.2f * small_size));
  hol = loadStrings("hol.txt");
}

public void draw() {
  //background (0);
  fill(255, 0, 0);//, 10);
  rect(0, 0, width, height);
  holidays(hol);
  textFont(large_font);
  date(width/2, 2 * large_size);
  clock(width/2, large_size);
  textFont(small_font);
  get_weather();
}
PFont temp_font;
int previous_line = -1;

public void holidays(String hol[]) {
  for (int i = 1; i < hol.length; i++) {
    if(hol[i] == null || hol[i].length() < 41){
      return;
    }
    String minute = hol[i].substring(0, 2);
    String hour = hol[i].substring(3, 5);
    String day = hol[i].substring(6, 8);
    String week_day = hol[i].substring(9, 11);
    String month = hol[i].substring(12, 14);
    String year = hol[i].substring(15, 19);
    if (minute.equals("**") || minute() == PApplet.parseInt(minute)) {
      if (hour.equals("**") || hour() == PApplet.parseInt(hour)) {
        if (week_day.equals("**") || day_of_week() == PApplet.parseInt(week_day)) { 
          if (day.equals("**") || day() == PApplet.parseInt(day)) {
            if (month.equals("**") || month() == PApplet.parseInt(month)) {
              if (year.equals("****") ||year() == PApplet.parseInt(year)) {
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
                fill(PApplet.parseFloat(red), PApplet.parseFloat(green), PApplet.parseFloat(blue));
                text(display_text, width/2, 3*large_size);
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


public int day_of_week() {
  int d = day();
  int m = month();
  int y = year();
  if (m < 3) {
    m += 12;
    y--;
  }
  return((d + PApplet.parseInt((m+1)*2.6f) +  y + PApplet.parseInt(y/4) + 6*PApplet.parseInt(y/100) + PApplet.parseInt(y/400) + 6) % 7);
}
public void clock(float x, float y) {
  fill(255);
  int h = hour() % 12;
  if(h == 0){
    h = 12;
  }
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
public void date(float x, float y) {
  fill(255);
  String date = month() + "/" + day() + "/" + year(); 
  text(date, x, y);
}


XML xml;
int previous_update;
String server = "http://query.yahooapis.com/v1/public/yql?format=xml&q=select+*+from+weather.forecast+where+woeid=";
String location = "2356937+and+u='F'"; // newcastle upon type in F
String city;
String region;
String sunrise;
String sunset;
String current_temp;
String condition_now;
String high_today;
String low_today;
String low_tomorrow;
String high_tomorrow;
boolean good_call = false;
int delay = 5000;

public void get_weather() {
  if (good_call) {
    fill(255);
  text("It is " + condition_now + " in " + city + ", " + region, width / 2, height - small_size * 4);
  text("Current tempurature: " + current_temp + "\u00b0", width / 2, height - small_size * 3);
  text("Sunrise: " + sunrise + " Sunset: " + sunset, width / 2, height - small_size * 2);
  text("Today: " + low_today + "\u00b0 - " + high_today + "\u00b0", width / 2, height - small_size);
  text("Tomorrow: " + low_tomorrow + "\u00b0 - " + high_tomorrow + "\u00b0", width / 2, height);
    delay = 60000;
  } else {
 //   text("LOADING...", width / 2, 40 + height/2);
    delay = 5000;
  }
  if (previous_update + delay < millis()) {
    xml = loadXML(server + location);
    previous_update = millis();
    if (xml != null) {
      XML location = xml.getChild("results/channel/yweather:location");
      if (location != null) {
        good_call = true;
        city = location.getString("city");
        region = location.getString("region");
      }
      XML weather_now = xml.getChild("results/channel/item/yweather:condition");
      if (weather_now != null) {
        current_temp = weather_now.getString("temp");
        condition_now = weather_now.getString("text");
      }
      XML sun = xml.getChild("results/channel/yweather:astronomy");
      if (sun != null) {
        sunrise = sun.getString("sunrise");
        sunset = sun.getString("sunset");
        if (sunrise.charAt(sunrise.indexOf(":") + 2) == ' ') {
          sunrise = sunrise.substring(0, sunrise.indexOf(":")+1) + "0" + sunrise.substring(sunrise.indexOf(":")+1);
        }
        if (sunset.charAt(sunset.indexOf(":") + 2) == ' ') {
          sunset = sunset.substring(0, sunset.indexOf(":")+1) + "0" + sunset.substring(sunset.indexOf(":")+1);
        }
      }
      XML forecasts[] = xml.getChildren("results/channel/item/yweather:forecast");
      if (forecasts != null && forecasts.length > 0) {
        high_today = forecasts[0].getString("high");
        low_today = forecasts[0].getString("low");
        high_tomorrow = forecasts[1].getString("high");
        low_tomorrow = forecasts[1].getString("low");
      }
    }
  }
}
  public void settings() {  fullScreen(); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--present", "--window-color=#666666", "--hide-stop", "smart_mirror" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
