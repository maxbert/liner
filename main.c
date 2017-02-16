#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);

  int x = 0;
  int y = 0;
  for (x; x< 500; x += 25){
    for(y; y< 500; y += 25){
      draw_line(100,100,x,y,s,c);
    }
  }
  x = 500;
  y = 500;
  for (x; x > 0; x -= 25){
    for(y; y > 0; y -= 25){
      draw_line(100,100,x,y,s,c);
    }
  }
  draw_line(100,100,100,200,s,c);
  draw_line(100,100,0,100,s,c);
  display(s);
  save_extension(s, "lines.png");
}  
