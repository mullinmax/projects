class blinky {
  PVector pos;
  int heading;
  int turning;
  blinky(PVector start_pos) {
    pos = start_pos;
    heading = 4;
    turning = 4;
  }
  void update(boolean[][] walls, PVector player_pos) {
    float minimum;
    
    //prefer up left down right
    if(walls[int(pos.x)][int(pos.y)-1] == false){
      
    }
    if(walls[int(pos.x)][int(pos.y)+1] == false){
      
    }
    if(walls[int(pos.x)-1][int(pos.y)] == false){
      
    }
    if(walls[int(pos.x)+1][int(pos.y)] == false){
      
    }
   
  }
  void display() {
  }
}