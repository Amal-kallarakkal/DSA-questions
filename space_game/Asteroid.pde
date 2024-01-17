class Asteroid {

  PVector pos;
  Float r;
  
  PVector vel; 
  Float[] offset = new Float[10];   
   
  Asteroid(PVector pos, float r) {
    this.pos = pos.copy();
    this.r = r*0.5;
    vel = PVector.random2D();
    
    int j = 0;
    while (j<10) {
      offset[j] = random(-this.r, this.r);
      j++;
    }
    
  }
  
     
  Asteroid() {
    
    
    pos = new PVector(random(width), random(height));
    r = random(20, 50);
    vel = PVector.random2D();
    
    int j = 0;
    while (j<10) {
      offset[j] = random(-this.r, this.r);
      j++;
    }
    
  }
  
 
  
     
  void update() {
    this.pos.add(this.vel);
  }
  
  void edges() {
    if(this.pos.x > width + this.r) this.pos.x = -this.r;    
    else if(this.pos.x < -this.r) this.pos.x = width + this.r;
    
    if(this.pos.y > height + this.r) this.pos.y = -this.r;    
    else if(this.pos.y < -this.r) this.pos.y = height + this.r;
      
  }
  
  
  Asteroid breakup() {
    
    var arr2 = new Asteroid(this.pos, this.r);
    //arr2.add(new Asteroid(this.pos, this.r));
    //arr2.add(new Asteroid(this.pos, this.r));
    return arr2;
    
  }
  
  void render() {   
    
    
    push();
    translate(this.pos.x, this.pos.y);
    noFill();
    stroke(255);
    
    beginShape();
    //Float offset = random(-r, r);
    for (int i = 0; i < total; i++) {
      float angle = map(i, 0, total, 0, TWO_PI);

      float x = (this.r + offset[i])*cos(angle);
      float y = (this.r + offset[i])*sin(angle);

      vertex(x, y);
    }
    endShape(CLOSE);
    pop();
  }
};
