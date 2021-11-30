#include "GraphicsClient.h"
#include "CellularAutomaton.h"
#include "Simulator.h"
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>

using namespace std;

Simulator::Simulator(string url, int port) {
  client = new GraphicsClient(url, port);
  isPlaying = 0;
  size = 600;
  rerender();
}

Simulator::Simulator(Simulator &other) {
  ca = other.ca;
  client = other.client;
  isPlaying = 0;
  size = 600;
}

Simulator::~Simulator() {
  delete client;
}

void Simulator::operator=(const Simulator rhs) {
  ca = rhs.ca;
  client = rhs.client;
  isPlaying = 0;
  size = 600;
}

void Simulator::rerender() {
  client -> clear();
  client -> setDrawingColor(127, 127, 127);
  client -> fillRectangle(600, 0, 200, 600);

  client -> setDrawingColor(255, 255, 255);
  client -> fillRectangle(670, 50, 60, 30);
  client -> fillRectangle(670, 95, 60, 30);
  client -> fillRectangle(670, 140, 60, 30);
  client -> fillRectangle(670, 185, 60, 30);
  client -> fillRectangle(670, 230, 60, 30);
  client -> fillRectangle(670, 275, 60, 30);
  client -> fillRectangle(670, 320, 60, 30);
  client -> drawString(666, 510, "SELECT SIZE");
  client -> fillRectangle(640, 525, 30, 30);
  client -> fillRectangle(685, 525, 30, 30);
  client -> fillRectangle(730, 525, 30, 30);

  client -> setDrawingColor(0, 0, 0);

  if (isPlaying) {
    client -> drawString(682, 70, "PAUSE");
  }
  else {
    client -> drawString(688, 70, "RUN");
  }
  client -> drawString(684, 115, "RESET");
  client -> drawString(686, 160, "STEP");
  client -> drawString(674, 205, "RANDOM");
  client -> drawString(684, 250, "LOAD");
  client -> drawString(682, 295, "CLEAR");
  client -> drawString(686, 340, "QUIT");
  client -> drawString(652, 545, "1");
  client -> drawString(697, 545, "2");
  client -> drawString(742, 545, "3");

  if (ca) ca -> displayCA(*client);

  client -> repaint();
}

Click Simulator::listen() {
  Click received;
  received.success = 0;

  int sockfd = client -> getSockfd();
  int count = 0;

  ioctl(sockfd, FIONREAD, &count);
  
  if (count) {
    // TODO: might have to change to if count == 15, because it might interfere with files (probably not, though)
    // printf("%d\n", count); // TODO: delete
    unsigned char buff[count];
    read(sockfd, &buff, count);

    received.type = buff[5];
    received.button = buff[6];

    // determine coordinates from their four bytes
    int firstByte = buff[7] << 12;
    int secondByte = buff[8] << 8;
    int thirdByte = buff[9] << 4;
    int fourthByte = buff[10];
    received.x = firstByte | secondByte | thirdByte | fourthByte;

    firstByte = buff[11] << 12;
    secondByte = buff[12] << 8;
    thirdByte = buff[13] << 4;
    fourthByte = buff[14];
    received.y = firstByte | secondByte | thirdByte | fourthByte;

    received.success = 1;
  }

  return received;
}

void Simulator::step(unsigned char (*rule)(CellularAutomaton*, int, int)) {
  // TODO
}

void Simulator::togglePlayback() {
  isPlaying ^= 1;
  rerender();
  // TODO
}

void Simulator::load() {
  struct timespec remaining, request = {(1 / 10), 100}; // TODO: check that this is correct
  int sockfd = client -> getSockfd();
  client -> requestFile();

  int count = 0;
  while (count == 0) {
    ioctl(sockfd, FIONREAD, &count); 
    nanosleep(&request, &remaining);
  }

  unsigned char buff[count];
  read(sockfd, &buff, count);

  string filename = "";
  for (int i = 6; i < count; i++) {
    unsigned char firstByte = buff[i] << 4;
    unsigned char secondByte = buff[++i];

    filename += firstByte | secondByte;
  }

  if (ca) {
    delete ca;
  }
  ca = new CellularAutomaton(filename, 0);

  rerender();
}

void Simulator::clear() {
  // TODO
}

void Simulator::randomize() {
  // TODO
}

void Simulator::handleClick(int x, int y) {
  // TODO
  if (670 <= x && x <= 720) {
    if (50 <= y && y <= 80) {
      togglePlayback();
    }
    else if (95 <= y && y <= 125) {
      cout << "RESET" << endl;
    }
    else if (140 <= y && y <= 170) {
      cout << "STEP" << endl;
    }
    else if (185 <= y && y <= 215) {
      cout << "RANDOM" << endl;
    }
    else if (230 <= y && y <= 260) {
      cout << "LOAD" << endl;
      load();
    }
    else if (275 <= y && y <= 305) {
      cout << "CLEAR" << endl;
    }
    else if (320 <= y && y <= 350) {
      quit();
    }
  }

  if (525 <= y && y <= 555) {
    if (640 <= x && x <= 670) {
      cout << "1" << endl;
      size = 40;
    }
    else if (685 <= x && x <= 715) {
      cout << "2" << endl;
      size = 150;
    }
    else if (730 <= x && x <= 760) {
      cout << "3" << endl;
      size = 600;
    }
  }
}
