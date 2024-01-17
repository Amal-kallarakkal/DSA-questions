class Ship {
  PVector pos = new PVector(width/2, height/2);
  PVector vel = new PVector(0,0);
  int r = 30;
  float heading = 0.0 ;
  float rotation = 0; 
  boolean isBoosting = false;
  
  void boosting(boolean b) {
    isBoosting = b;
  }
  
  void update() {
   if(isBoosting) {
     boost();
   }
   this.pos.add(this.vel);
   this.vel.mult(0.99);
  }
  
  void boost() {
    PVector force = PVector.fromAngle(heading);
    force.mult(0.1);
    this.vel.add(force);
  }
  
  void render() { 
    
    push();
    translate(this.pos.x, this.pos.y);
    rotate(this.heading + PI/2);
    noFill();
    stroke(255);
    triangle(-this.r, this.r, this.r, this.r, 0, 0);
    pop();
  } 
  
  
  void edges() {
    if(this.pos.x > width + this.r) this.pos.x = -this.r;    
    else if(this.pos.x < -this.r) this.pos.x = width + this.r;
    
    if(this.pos.y > height + this.r) this.pos.y = -this.r;    
    else if(this.pos.y < -this.r) this.pos.y = height + this.r;
      
  }
  
  void setRotation(float a) {
    this.rotation = a;
  }
  
  void turn() {    
    this.heading += rotation;
  }
};
