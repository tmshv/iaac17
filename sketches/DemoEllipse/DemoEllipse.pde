float x = 0;
float y = 0;

void setup(){
  size(500, 500);
  frameRate(100);
}

void draw(){
  background(200);
  
  float m = 0.025;
  float deltaX = (mouseX - x) * m;
  float deltaY = (mouseY - y) * m;
  
  x += deltaX;
  y += deltaY;
  
  int r = (int) map(x, 0, width, 0, 255);
  int g = (int) map(y, 0, height, 0, 255);
  fill(r, g, 255);
  ellipse(x, y, 10, 10);
}