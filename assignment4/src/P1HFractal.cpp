/*
 * File: HFractal.cpp
 * ------------------
 * This program draws an H-fractal on the graphics window.int main() {
 */

#include "gwindow.h"
#include "console.h"

/* Function prototypes */

void drawHFractal(GWindow & gw, double x, double y, double size, int order);

/* Main program */

int P1HFractal() {
   GWindow gw;
   double xc = gw.getWidth() / 2;
   double yc = gw.getHeight() / 2;
   drawHFractal(gw, xc, yc, 100, 3);
   return 0;
}


/*
 * Function: drawHFractal
 * Usage: drawHFractal(gw, x, y, size, order);
 * -------------------------------------------
 * Draws a fractal diagram consisting of an H in which each additional
 * fractal layer draws half-size fractals at the four endpoints of each H.
 */

void drawHFractal(GWindow & gw, double x, double y, double size, int order) {
   gw.setColor("Black");
   gw.setExitOnClose(true);
   int x_right = x + size / 2;
   int x_left  = x - size / 2;
   int y_up    = y + size / 2;
   int y_down  = y - size / 2;

   gw.drawLine(x_left, y, x_right, y);
   gw.drawLine(x_left, y_down, x_left, y_up);
   gw.drawLine(x_right, y_down, x_right, y_up);

   if (order!=0){
       drawHFractal(gw, x_left, y_down, size/2, order - 1);
       drawHFractal(gw, x_left, y_up, size/2, order - 1);
       drawHFractal(gw, x_right, y_down, size/2, order - 1);
       drawHFractal(gw, x_right, y_up, size/2, order - 1);
   }

   }
   //TODO
