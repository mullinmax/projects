class player{
  PImage [] frames;
  int tile_size = 27;
  int tile_buff = 3;
  PVector pos;
 player(){
   PImage temp = loadImage("graphics_test.png");
   frames = new PImage[3];
   frames[0] = temp.get(3*(tile_size + tile_buff), 0*(tile_size + tile_buff), tile_size, tile_size);
   frames[1] = temp.get(3*(tile_size + tile_buff), 1*(tile_size + tile_buff), tile_size, tile_size);
   frames[2] = temp.get(3*(tile_size + tile_buff), 2*(tile_size + tile_buff), tile_size, tile_size);
 }
 void update(){
   
 }
 void display(){
   
 }
}