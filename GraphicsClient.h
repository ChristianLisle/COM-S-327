#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifndef GRAPHICS_CLIENT_
#define GRAPHICS_CLIENT_

#define SYNC 0xFF
#define CLEAR 0x01
#define SET_BACKGROUND_COLOR 0x02
#define SET_PIXEL 0x03
#define DRAW_STRING 0x05
#define SET_DRAWING_COLOR 0x06
#define DRAW_RECTANGLE 0x07
#define FILL_RECTANGLE 0x08
#define CLEAR_RECTANGLE 0x09
#define DRAW_OVAL 0x0A
#define FILL_OVAL 0x0B
#define REPAINT 0x0C
#define DRAW_LINE 0x0D

using namespace std;

class GraphicsClient {
  private:
    string url;
    int port;
    int socketId;
    struct sockaddr_in serv_addr;
  public:
    GraphicsClient(string, int);
    GraphicsClient(GraphicsClient&);
    ~GraphicsClient();
    void operator=(const GraphicsClient);
    void setBackgroundColor(int, int, int);
    void setDrawingColor(int, int, int);
    void clear();
    void setPixel(int, int, int, int, int);
    void drawRectangle(int, int, int, int);
    void fillRectangle(int, int, int, int);
    void clearRectangle(int, int, int, int);
    void drawOval(int, int, int, int);
    void fillOval(int, int, int, int);
    void drawLine(int, int, int, int);
    void drawString(int, int, string);
    void repaint();
};

#endif