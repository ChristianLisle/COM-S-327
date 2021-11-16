#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifndef GRAPHICS_CLIENT_
#define GRAPHICS_CLIENT_

class GraphicsClient {
  private:
    std::string url;
    int port;
    int socketId;
    struct sockaddr_in serv_addr;
  public:
    GraphicsClient(std::string, int);
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
    void drawString(int, int, std::string);
    void repaint();
};

#endif