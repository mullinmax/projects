import controlP5.*;
ControlP5 cp5;
XML xml;
int previous_update;
String server = "http://query.yahooapis.com/v1/public/yql?format=xml&q=select+*+from+weather.forecast+where+woeid=";
String location = "2356937+and+u='F'"; // newcastle upon type in F
String city;
String region;
String sunrise_time;
String sunset_time;
String current_temp;
String high_today;
String low_today;
String low_tomorrow;
String high_tomorrow;

void get_weather() {
  if (previous_update + 5000 < millis()) {
    xml = loadXML(server + location);
    previous_update = millis();
    if (xml != null) {
      XML location = xml.getChild("results/channel/yweather:location");
      if (location != null) {
        city = location.getString("city");
      }
      XML weather_now = xml.getChild("results/channel/item/yweather:condition");
      if (weather_now != null) {
        current_temp = weather_now.getString("temp");
      }
      XML forecasts[] = xml.getChildren("results/channel/item/yweather:forecast");
      high_today = forecasts[0].getString("high");
      low_today = forecasts[0].getString("low");
      high_tomorrow = forecasts[1].getString("high");
      low_tomorrow = forecasts[1].getString("low");
    }
    /*println();
     println();
     print("city: " + city);
     println();
     print("current temp: " + temp_now);
     println();
     print("high today: " + high_later);
     println();
     print("low today: " + low_later);
     println(weather_tomorrow.listChildren());
     */
  }
}