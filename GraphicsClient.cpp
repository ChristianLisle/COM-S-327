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

void convertInt2Byte(int v, char* buff, int index) {
  buff[index] = (v >> 4) & 0x0F;
  buff[index + 1] = v & 0x0F;
}

void convertInt4Byte(int v, char* buff, int index) {
  buff[index] = (v >> 12) & 0x0F;
  buff[index + 1] = (v >> 8) & 0x0F;
  buff[index + 2] = (v >> 4) & 0x0F;
  buff[index + 3] = v & 0x0F;
}

void preformatMessage(char* message, int payloadSize, int type) {
  message[0] = SYNC;
  convertInt4Byte(payloadSize, message, 1);
  message[5] = type;
}

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
}

void GraphicsClient::operator=(const GraphicsClient rhs) {
  // close existing connection
  close(socketId);
  
  // create new connection with parameters from rhs
  GraphicsClient(rhs.url, rhs.port);
}

void GraphicsClient::setBackgroundColor(int r, int g, int b) {
  char message[12];
  preformatMessage(message, 7, SET_BACKGROUND_COLOR);
  convertInt2Byte(r, message, 6);
  convertInt2Byte(g, message, 8);
  convertInt2Byte(b, message, 10);

  send(socketId, message, 12, 0);
}

void GraphicsClient::setDrawingColor(int r, int g, int b) {
  char message[12];
  preformatMessage(message, 7, SET_DRAWING_COLOR);
  convertInt2Byte(r, message, 6);
  convertInt2Byte(g, message, 8);
  convertInt2Byte(b, message, 10);

  send(socketId, message, 12, 0);
}

void GraphicsClient::clear() {
  char message[6];
  preformatMessage(message, 1, CLEAR);

  send(socketId, message, 6, 0);
}

void GraphicsClient::setPixel(int x, int y, int r, int g, int b) {
  char message[20];
  preformatMessage(message, 15, SET_PIXEL);
  convertInt4Byte(x, message, 6);
  convertInt4Byte(y, message, 10);
  convertInt2Byte(r, message, 14);
  convertInt2Byte(g, message, 16);
  convertInt2Byte(b, message, 18);

  send(socketId, message, 20, 0);
}

void GraphicsClient::drawRectangle(int x, int y, int width, int height) {
  char message[22];
  preformatMessage(message, 17, DRAW_RECTANGLE);
  convertInt4Byte(x, message, 6);
  convertInt4Byte(y, message, 10);
  convertInt4Byte(width, message, 14);
  convertInt4Byte(height, message, 18);

  send(socketId, message, 22, 0);
}

void GraphicsClient::fillRectangle(int x, int y, int width, int height) {
  char message[22];
  preformatMessage(message, 17, FILL_RECTANGLE);
  convertInt4Byte(x, message, 6);
  convertInt4Byte(y, message, 10);
  convertInt4Byte(width, message, 14);
  convertInt4Byte(height, message, 18);

  send(socketId, message, 22, 0);
}

void GraphicsClient::clearRectangle(int x, int y, int width, int height) {
  char message[22];
  preformatMessage(message, 17, CLEAR_RECTANGLE);
  convertInt4Byte(x, message, 6);
  convertInt4Byte(y, message, 10);
  convertInt4Byte(width, message, 14);
  convertInt4Byte(height, message, 18);

  send(socketId, message, 22, 0);
}

void GraphicsClient::drawOval(int x, int y, int width, int height) {
  char message[22];
  preformatMessage(message, 17, DRAW_OVAL);
  convertInt4Byte(x, message, 6);
  convertInt4Byte(y, message, 10);
  convertInt4Byte(width, message, 14);
  convertInt4Byte(height, message, 18);

  send(socketId, message, 22, 0);
}

void GraphicsClient::fillOval(int x, int y, int width, int height) {
  char message[22];
  preformatMessage(message, 17, FILL_OVAL);
  convertInt4Byte(x, message, 6);
  convertInt4Byte(y, message, 10);
  convertInt4Byte(width, message, 14);
  convertInt4Byte(height, message, 18);

  send(socketId, message, 22, 0);
}

void GraphicsClient::drawLine(int x1, int y1, int x2, int y2) {
  char message[22];
  preformatMessage(message, 17, DRAW_LINE);
  convertInt4Byte(x1, message, 6);
  convertInt4Byte(y1, message, 10);
  convertInt4Byte(x2, message, 14);
  convertInt4Byte(y2, message, 18);

  send(socketId, message, 22, 0);
}

void GraphicsClient::drawString(int x, int y, string characters) {
  int payloadSize = 9 + (characters.length() * 2);
  int messageSize = 6 + payloadSize;
  
  char message[messageSize];
  preformatMessage(message, payloadSize, DRAW_STRING);
  convertInt4Byte(x, message, 6);
  convertInt4Byte(y, message, 10);

  for (int i = 0; i < characters.length(); i++) {
    convertInt2Byte(characters[i], message, 14 + (i * 2));
  }

  send(socketId, message, messageSize, 0);
}

void GraphicsClient::repaint() {
  char message[6];
  preformatMessage(message, 1, REPAINT);
  send(socketId, message, 6, 0);
}