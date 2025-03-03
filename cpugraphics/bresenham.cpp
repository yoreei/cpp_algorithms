#pragma once
#include <array>
#include <iostream>

const int SIDE = 8;
std::array<bool, SIDE * SIDE> plt;

void plot(int x, int y, bool val = true) {
    plt[y * SIDE + x] = val;
}

void plotLine(int x0, int y0, int x1, int y1)
{
   int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
   int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1; 
   int err = dx+dy, e2; /* error value e_xy */
 
   for(;;){  /* loop */
      plot(x0,y0);
      if (x0==x1 && y0==y1) break;
      e2 = 2*err;
      if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
      if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
   }
}

void plotLineWidth(int x0, int y0, int x1, int y1, float wd = 3)
{ 
   int dx = abs(x1-x0), sx = x0 < x1 ? 1 : -1; 
   int dy = abs(y1-y0), sy = y0 < y1 ? 1 : -1; 
   int err = dx-dy, e2, x2, y2;                          /* error value e_xy */
   //float ed = dx+dy == 0 ? 1 : sqrt((float)dx*dx+(float)dy*dy);
   
   for (wd = (wd+1)/2; ; ) {                                   /* pixel loop */
      plot(x0,y0);
      e2 = err; x2 = x0;
      if (2*e2 >= -dx) {                                           /* x step */
         //for (e2 += dy, y2 = y0; e2 < ed*wd && (y1 != y2 || dx > dy); e2 += dx)
         for (e2 += dy, y2 = y0; e2 < wd*wd && (y1 != y2 || dx > dy); e2 += dx)
            plot(x0, y2 += sy);
         if (x0 == x1) break;
         e2 = err; err -= dy; x0 += sx; 
      } 
      if (2*e2 <= dy) {                                            /* y step */
         //for (e2 = dx-e2; e2 < ed*wd && (x1 != x2 || dx < dy); e2 += dy)
         for (e2 = dx-e2; e2 < wd*wd && (x1 != x2 || dx < dy); e2 += dy)
            plot(x2 += sx, y0);
         if (y0 == y1) break;
         err += dx; y0 += sy; 
      }
   }
   plot(x0, y0 + 1, false);
   plot(x1, y1 - 1, false);
}

void drawPlt() {
    for (int i = 0; i < plt.size(); ++i) {
        if (i % SIDE == 0) { std::cout << "|\n|"; }
        std::cout << (plt[i] ? "#" : "_");
    }
}
int main() {
    //for (int i = 0; i < SIDE; i += 4) {
    //    plotLine(SIDE / 2, SIDE / 2, i, 0);
    //    plotLine(SIDE / 2, SIDE / 2, i, SIDE - 1);
    //}

    //for (int i = 0; i < SIDE; i += 4) {
    //    plotLine(SIDE / 2, SIDE / 2, 0, i);
    //    plotLine(SIDE / 2, SIDE / 2, SIDE - 1, i);
    //}

    plotLineWidth(1,1, 6,6);
    drawPlt();

}
