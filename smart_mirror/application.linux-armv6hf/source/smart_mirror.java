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


int text_size = 20;
public void setup() {
  //size(500, 500);
  
  noCursor();
  textAlign(CENTER);
  get_weather();
  frameRate(60);
  large_font = createFont("Prototype.ttf", 45);
  small_font = createFont("Prototype.ttf", 45);
}

public void draw() {
  textFont(small_font);
  //background (0);
  fill(0, 0, 0, 10);
  rect(0, 0, width, height);
  date(width/2, 40+ height/10);
  clock(width/2, height/10);
  get_weather();
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
String high_today;
String low_today;
String low_tomorrow;
String high_tomorrow;
boolean good_call = false;
int delay = 5000;

public void get_weather() {
  if (good_call) {
    fill(255);
  text(city + ", " + region, width / 2, height / 2);
  text("Sunrise: " + sunrise + "   Sunset: " + sunset, width / 2, 40+ height / 2);
  text("Surrent tempurature: " + current_temp + "\u00b0", width / 2, 80+ height / 2);
  text("High for today: " + high_today + "\u00b0   Low for today: " + low_today + "\u00b0", width / 2, 120+ height / 2);
  text("High for tomorrow: " + high_tomorrow + "\u00b0   Low for tomorrow: " + low_tomorrow + "\u00b0", width / 2, 160+ height / 2);
    delay = 5000;
  } else {
    text("LOADING", width / 2, height/2);
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
