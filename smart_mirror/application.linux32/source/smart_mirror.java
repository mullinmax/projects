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
String hol[];

int text_size = 20;
public void setup() {
  //size(500, 500);
  
  noCursor();
  textAlign(CENTER);
  get_weather();
  frameRate(60);
  large_font = createFont("Prototype.ttf", 120);
  small_font = createFont("Prototype.ttf", 45);
  hol = loadStrings("hol.txt");
}

public void draw() {
  //background (0);
  fill(0, 0, 0, 10);
  rect(0, 0, width, height);
  textFont(large_font);
  holidays(hol);
  date(width/2, 240);
  clock(width/2, 120);
  textFont(small_font);
  get_weather();
}
public void holidays(String hol[]) {
  for (int i = 1; i < hol.length; i++) {
    String minute = hol[i].substring(0, 2);
    String hour = hol[i].substring(3, 5);
    String day = hol[i].substring(6, 8);
    String month = hol[i].substring(9, 11);
    if (minute.equals("**")|| minute() == PApplet.parseInt(minute)) {
      if (hour.equals("**")|| hour() == PApplet.parseInt(hour)) {
        if (day.equals("**")|| day() == PApplet.parseInt(day)) {
          if (month.equals("**")|| month() == PApplet.parseInt(month)) {
            println(hol[i]);
          }
        }
      }
    }
  }
}
public void clock(float x, float y) {
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
  text("It is " + condition_now + " in " + city + ", " + region, width / 2, height - 160);
  text("Current tempurature: " + current_temp + "\u00b0", width / 2, height - 120);
  text("Sunrise: " + sunrise + " Sunset: " + sunset, width / 2, height - 80);
  text("Today day: " + low_today + "\u00b0 - " + high_today + "\u00b0", width / 2, height - 40);
  text("Tomorrow: " + low_tomorrow + "\u00b0 - " + high_tomorrow + "\u00b0", width / 2, height);
    delay = 5000;
  } else {
    text("LOADING...", width / 2, 40 + height/2);
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
