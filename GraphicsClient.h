#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifndef GRAPHICS_CLIENT_
#define GRAPHICS_CLIENT_

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