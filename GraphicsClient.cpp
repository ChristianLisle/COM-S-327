#include "GraphicsClient.h"
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include <iostream>

using namespace std;

GraphicsClient::GraphicsClient(string connectionUrl, int connectionPort) {
  url = connectionUrl;
  port = connectionPort;
  socketId = socket(AF_INET, SOCK_STREAM, 0);

  if (socketId < 0) {
    fprintf(stderr, "Error occured creating socket\n");
    // TODO: exit constructor or something
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  // serv_addr.sin_port = htons(port);
  serv_addr.sin_port = htons(7777);

  // TODO: does this need to be the given connectionUrl/url or is it hardcoded like so?
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
    fprintf(stderr, "Invalid connection address provided.\n");
    // TODO: exit constructor or something
  }
  cout << socketId << endl; // TODO: delete this
  // cout << sizeof(serv_addr) << endl;
  if (connect(socketId, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Connection failed.\n");
    // TODO: exit constructor or something
  }
}

GraphicsClient::GraphicsClient(GraphicsClient &other) {
  GraphicsClient(other.url, other.port);
}

GraphicsClient::~GraphicsClient() {
  // TODO: close connection and such
  close(socketId);
};

void GraphicsClient::operator=(const GraphicsClient rhs) {
  // close existing connection
  close(socketId);
  
  // create new connection with parameters from rhs
  GraphicsClient(rhs.url, rhs.port);
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

void GraphicsClient::drawString(int, int, string) {
  // TODO
};

void GraphicsClient::repaint() {
  // TODO
};