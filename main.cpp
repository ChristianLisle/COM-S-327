#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <cstring>

#include <iostream>
#include "GraphicsClient.h"
#include "CellularAutomaton.h"

using namespace std;


int main(int argc, char *argv[]) {
	string filename = argv[1];
	CellularAutomaton* ca = new CellularAutomaton(filename, 0);

}

// int main(void) {
//     GraphicsClient* x = new GraphicsClient("127.0.0.1", 7777);
    
//     x -> repaint();
//     x -> drawString(120, 120, "DEFAULT");


//     cin.get();
//     x -> clear();
//     x -> repaint();


//     x -> setBackgroundColor(150, 150, 150);
//     x -> clear();
//     x -> drawString(120, 120, "SETTING BACKGROUND COLOR");
//     x -> repaint();


//     cin.get();
//     x -> clear();
//     x -> repaint();


//     x -> setDrawingColor(0, 0, 0);
//     x -> clear();
//     x -> repaint();
//     x -> drawString(120, 120, "SETTING DRAWING COLOR (set to black)");
//     x -> repaint();


//     cin.get();
//     x -> clear();
//     x -> repaint();


//     x -> drawString(120, 120, "DRAWING LINE");
//     x -> drawLine(120, 122, 210, 122);
//     x -> repaint();


//     cin.get();
//     x -> clear();
//     x -> repaint();
    

//     x -> setPixel(140, 140, 0, 0, 0);
//     x -> setPixel(141, 141, 0, 0, 0);
//     x -> setPixel(142, 142, 0, 0, 0);
//     x -> setPixel(143, 143, 0, 0, 0);
//     x -> setPixel(144, 144, 0, 0, 0);
//     x -> drawString(120, 120, "SETTING PIXELS");
//     x -> repaint();


//     cin.get();
//     x -> clear();
//     x -> repaint();


//     x -> drawRectangle(225, 225, 100, 100);
//     x -> fillRectangle(500, 225, 100, 100);
//     x -> drawString(120, 120, "DRAWING & FILLING RECTANGLES");
//     x -> repaint();


//     cin.get();

//     x -> clearRectangle(525, 250, 50, 50);
//     x -> clearRectangle(100, 100, 400, 40);
//     x -> clearRectangle(225, 225, 100, 100);
//     x -> drawString(120, 120, "CLEARING RECTANGLES");
//     x -> repaint();

//     cin.get();
//     x -> clear();
//     x -> repaint();    

//     x -> drawOval(225, 225, 100, 100);
//     x -> fillOval(500, 225, 100, 100);
//     x -> repaint();
//     x -> drawString(120, 120, "DRAWING & FILLING OVALS");
//     x -> repaint();

   

//     cin.get();
//     x -> clear();

//     // GraphicsClient* y = new GraphicsClient("127.0.0.1", 7777);
//     // y -> setBackgroundColor(160, 58, 79);
//     // y -> clear();
//     // x -> repaint();
// }