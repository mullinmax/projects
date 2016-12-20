import controlP5.*;
ControlP5 cp5;
XML xml;
int previous_update;
String server = "http://query.yahooapis.com/v1/public/yql?format=xml&q=select+*+from+weather.forecast+where+woeid=";
String location = "2356937+and+u='F'"; // newcastle upon type in F

void get_weather() {
  if (xml == null || previous_update + 5000 < millis()) {
    xml = loadXML(server + location);
    previous_update = millis();
    print(xml);
    println();
    print("...");
    println();
  }
  print(".");
  //XML myval = xml.getChild("results/channel/yweather:location");
}