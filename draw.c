#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_lineHelper(int x0, int y0, int x1, int y1, screen s, color c) {
  //  printf("1");
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
void draw_lineHelper2(int x0, int y0, int x1, int y1, screen s, color c) {
  // printf("2");
  int a = y1 - y0;
  int b = x0 - x1;
  int d = 2 * b + a;
  while(y0 < y1){
    plot(s,c,x0,y0);
    if(d < 0){
      d += 2 * a;
      x0++;
    }
    y0++;
    d += 2 * b;
  }
}

void draw_lineHelper7(int x0, int y0, int x1, int y1, screen s, color c) {
  //printf("7");
  int a = y1 - y0;
  int b = x0 - x1;
  int d =  a - (2 * b);
  //printf("y0 = %d y1 = %d", y0, y1);
  while(y0 > y1){
    //printf("x %d y %d\n", x0,y0);
    plot(s,c,x0,y0);
    if(d > 0){
      d += 2 * a;
      x0++;
    }
    y0--;
    d -= 2 * b;
  }
}
void draw_lineHelper8(int x0, int y0, int x1, int y1, screen s, color c) {
  //printf("8");
  int a = y1 - y0;
  int b = x0 - x1;
  int d = 2 * a - b;
  while(x0 < x1){
    plot(s,c,x0,y0);
    if(d < 0){
      d -= 2 * b;
      y0--;
    }
    x0++;
    d += 2 * a;
  }
}
void draw_lineHelperV(int x0, int y0, int x1, int y1, screen s, color c) {
  while(y0 < y1){
    plot(s,c,x0,y0);
    y0++;
  }
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int dx = x1 - x0;
  int dy = y1 - y0;
  int a = y1 - y0;
  int b = x0 - x1;
  int d = 2 * a + b;
  if(!dx){
    if(dy > 0){
      draw_lineHelperV(x0,y0,x1,y1,s,c);
    }else{
      draw_lineHelperV(x1,y1,x0,y0,s,c);
    }
  }else{
    
    if(dx > 0){// 1st half
      if(dy > 0){//1st quartile
	if(dx > dy){//1st octant
	  draw_lineHelper(x0,y0,x1,y1,s,c);
	}else{//2nd octant
	  draw_lineHelper2(x0,y0,x1,y1,s,c);
	}
      }else{//4th quadrant
	if(dx > (-1 * dy)){//8th octatn
	  draw_lineHelper8(x0,y0,x1,y1,s,c);
	}else{//7th octant
	  draw_lineHelper7(x0,y0,x1,y1,s,c);
	}
      }
    }else{//2nd halg
      draw_line(x1,y1,x0,y0,s,c);
    }
  }
}

