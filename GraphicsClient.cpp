#include "GraphicsClient.h"
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

GraphicsClient::GraphicsClient(std::string connectionUrl, int connectionPort) {
  url = connectionUrl;
  port = connectionPort;
  socketId = socket(AF_INET, SOCK_STREAM, 0);

  if (socketId < 0) {
    fprintf(stderr, "Error occured creating socket\n");
    // TODO: exit program or something here?
  }

  // if (inet_pton(AF_INET, url, ))
}

GraphicsClient::GraphicsClient(GraphicsClient &other) {
  GraphicsClient(other.url, other.port);
}

GraphicsClient::~GraphicsClient() {
  // TODO:
  // close connection and such
};

void GraphicsClient::operator=(const GraphicsClient rhs) {
  // TODO
  // close existing connection
  
  
  // create new connection with parameters from rhs
  url = rhs.url;
  port = rhs.port;

  // CREATE CONNECTION
};

void GraphicsClient::setBackgroundColor(int, int, int) {
  // TODO
};

void GraphicsClient::setDrawingColor(int, int, int) {
  // TODO
};

void GraphicsClient::clear() {
  // TODO
};

void GraphicsClient::setPixel(int, int, int, int, int) {
  // TODO
};

void GraphicsClient::drawRectangle(int, int, int, int) {
  // TODO
};

void GraphicsClient::fillRectangle(int, int, int, int) {
  // TODO
};

void GraphicsClient::clearRectangle(int, int, int, int) {
  // TODO
};

void GraphicsClient::drawOval(int, int, int, int) {
  // TODO
};

void GraphicsClient::fillOval(int, int, int, int) {
  // TODO
};

void GraphicsClient::drawLine(int, int, int, int) {
  // TODO
};

void GraphicsClient::drawString(int, int, std::string) {
  // TODO
};

void GraphicsClient::repaint() {
  // TODO
};