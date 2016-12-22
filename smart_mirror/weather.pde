import controlP5.*;
ControlP5 cp5;
XML xml;
int previous_update;
String server = "http://query.yahooapis.com/v1/public/yql?format=xml&q=select+*+from+weather.forecast+where+woeid=";
String location = "2356937+and+u='F'"; // newcastle upon type in F
String city;
String region;
String sunrise;
String sunset;
String temp_now;
String high_later;
String low_later;

void get_weather() {
  if (previous_update + 5000 < millis()) {
    xml = loadXML(server + location);
    previous_update = millis();
    XML location = xml.getChild("results/channel/yweather:location");
    if (location != null) {
      city = location.getString("city");
    }
    XML weather_now = xml.getChild("results/channel/item/yweather:condition");
    if (weather_now != null) {
      temp_now = weather_now.getString("temp");
    }
    XML weather_later = xml.getChild("results/channel/item/yweather:forecast");
    if (weather_later != null) {
      high_later = weather_later.getString("high");
      low_later = weather_later.getString("low");
    }
    XML weather_tomorrow = xml.getChild("results/channel/item");
    if (weather_tomorrow != null) {
      //print(weather_tomorrow.getContent());
    }
    /*println();
    println();
    print("city: " + city);
    println();
    print("current temp: " + temp_now);
    println();
    print("high today: " + high_later);
    println();
    print("low today: " + low_later);*/
    println(weather_tomorrow.listChildren());
  }
}