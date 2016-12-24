
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

void get_weather() {

  fill(255);
  text(city + ", " + region, width / 2, height / 2);
  text("sunrise: " + sunrise + " sunset: " + sunset, width / 2, 20+ height / 2);
  text("current tempurature: " + current_temp + "°", width / 2, 40+ height / 2);
  text("high for today: " + high_today + "° low for today: " + low_today + "°", width / 2, 60+ height / 2);
  text("high for tomorrow: " + high_tomorrow + "° low for tomorrow: " + low_tomorrow + "°", width / 2, 80+ height / 2);

  if (previous_update + 5000 < millis()) {
    xml = loadXML(server + location);
    previous_update = millis();
    if (xml != null) {
      XML location = xml.getChild("results/channel/yweather:location");
      if (location != null) {
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