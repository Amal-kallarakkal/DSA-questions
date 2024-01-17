class Laser{
  
  
  PVector pos;
  PVector vel;
 
  Laser(PVector spos, float angle) {
    this.pos = new PVector(spos.x,spos.y);
    
    this.vel = PVector.fromAngle(angle);
    vel.mult(10);
  }
 
  boolean hits(Asteroid ast) {
    //translate(this.pos.x, this.pos.y);
    //float x1 = this.pos.x;
    //float y1 = this.pos.y;
    //float x2 = ast.pos.x;
    //float y2 = ast.pos.y;
    float d = dist(this.pos.x,this.pos.y,ast.pos.x,ast.pos.y);
    if(d <= ast.r) return true;
    else return false;
  }
  void update() {
    this.pos.add(this.vel);
  }
  
  void render() {
    stroke(255);
    strokeWeight(4);
    //translate(this.pos.x, this.pos.y);
    point(this.pos.x, this.pos.y);
  }
};
