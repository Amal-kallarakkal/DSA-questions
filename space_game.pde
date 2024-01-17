
Ship ship = new Ship();

ArrayList<Asteroid> arr = new ArrayList<Asteroid>();

  int total = 10;
  
  
ArrayList<Laser> las_arr = new ArrayList<Laser>();
  
void setup() {
  size(800,800);
  for(int i = 0 ; i < 10; i++) arr.add(new Asteroid()); 
  
  
}


void draw() {
  background(0);
  
  
  ship.render();
  ship.turn();
  ship.update();
  ship.edges();
  
  //ast.render();
  
  for(Laser x: las_arr) {
    x.render();
    x.update();    
  }
  
  
  for(int i = arr.size() - 1 ; i >= 0; i--) {
    arr.get(i).render();
    arr.get(i).update();
    arr.get(i).edges();  
    
    for(int j = las_arr.size() - 1 ; j >= 0; j--) {       
        if(las_arr.get(j).hits(arr.get(i))) {
          
          if(arr.get(i).r > 10) {
            var newAsteroids = arr.get(i).breakup();
            var newAsteroids2 = arr.get(i).breakup();
            arr.set(i, newAsteroids); 
            arr.add(i+1, newAsteroids2);
          } else {       
          arr.remove(i);
          //las_arr.remove(i);
          }
          break; 
        }
    }
    
  }
  
}
//PVector pos;

void keyReleased() {
  
  ship.setRotation(0);
}

void keyPressed() {
  if(key == ' ') {
     las_arr.add(new Laser(ship.pos, ship.heading)); 
  }else if(keyCode == RIGHT) {
     ship.setRotation(0.1); 
  } else if(keyCode == LEFT) {
      ship.setRotation(-0.1);
  } else if(keyCode == UP) {
    ship.boost();
  }
  
}
