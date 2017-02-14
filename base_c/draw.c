#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_lineHelper(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = x0 - x1;
  int d = 2 * a + b;
  while(x0 < x1){
    plot(s,c,x0,y0);
    if(d > 0){
      d += 2 * b;
      y0++;
    }
    x0++;
    d += 2 * a;
  }
}

void draw_lineHelper_down(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = x0 - x1;
  int d = 2 * a + b;
  while(x0 > x1){
    plot(s,c,x0,y0);
    if(d < 0){
      d -= 2 * b;
      y0--;
    }
    x0--;
    d -= 2 * a;
  }
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int dx = x1 - x0;
  int dy = y1 - y0;
  int a = y1 - y0;
  int b = x0 - x1;
  int d = 2 * a + b;
  if(dx > 0){// 1st half
    if(dy > 0){//1st quartile
      if(dx > dy){//1st octant
	draw_lineHelper(x0,y0,x1,y1,s,c);
      }else{//2nd octant
	draw_lineHelper(y0,x0,y1,x1,s,c);
      }
    }else{//4th quadrant
      if(dx > -1 * dy){//8th octatn
	draw_lineHelper(x0,-1 * y0,x1,-1 * y1,s,c);
      }else{//7th octant
	draw_lineHelper(y0*-1,x0,y1*-1,x1,s,c);
      }
    }
  }else{//2nd half
    draw_lineHelper(x0,y0,x1,y1,s,c);
  }	
}

