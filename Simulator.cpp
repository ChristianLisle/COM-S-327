#include "GraphicsClient.h"
#include "CellularAutomaton.h"
#include "Simulator.h"
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>

using namespace std;

Simulator::Simulator(string url, int port, unsigned char (*caRule)(CellularAutomaton*, int, int)) {
  client = new GraphicsClient(url, port);
  rule = caRule;
  status = 0;
  size = 600;
  renderControlPanel();
}

Simulator::Simulator(Simulator &other) {
  ca = other.ca;
  client = other.client;
  rule = other.rule;
  file = other.file;
  status = 0;
  size = 600;
  renderAll();
}

Simulator::~Simulator() {
  delete client;
  delete ca;
}

void Simulator::operator=(const Simulator rhs) {
  ca = rhs.ca;
  client = rhs.client;
  rule = rhs.rule;
  file = rhs.file;
  status = 0;
  size = 600;
  renderAll();
}

void Simulator::renderCA() {
  client -> setDrawingColor(0, 0, 0);
  client -> fillRectangle(0, 0, 600, 600);

  if (ca) ca -> displayCA(*client, size);

  client -> repaint();
}

void Simulator::renderControlPanel() {
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

  if (status != 1) client -> drawString(688, 70, "RUN");
  else client -> drawString(682, 70, "PAUSE");

  client -> drawString(684, 115, "RESET");
  client -> drawString(686, 160, "STEP");
  client -> drawString(674, 205, "RANDOM");
  client -> drawString(684, 250, "LOAD");
  client -> drawString(682, 295, "CLEAR");

  if (status != -1) client -> drawString(686, 340, "QUIT");
  else client -> drawString(672, 340, "QUITTING");

  client -> drawString(652, 545, "1");
  client -> drawString(697, 545, "2");
  client -> drawString(742, 545, "3");

  client -> repaint();
}

void Simulator::renderAll() {
  client -> clear();

  renderCA();
  renderControlPanel();
}

Click Simulator::listen() {
  Click received;
  received.success = 0;

  int sockfd = client -> getSockfd();
  int count = 0;

  ioctl(sockfd, FIONREAD, &count);
  
  if (count) {
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

void Simulator::step() {
  ca -> step(rule);
  renderCA();
}

void Simulator::reset() {
  if (ca) delete ca;

  ca = new CellularAutomaton(file, 0);
  renderCA();
}

void Simulator::load() {
  status = 0; // stop stepping CA

  struct timespec request = {0, 100000000};
  int sockfd = client -> getSockfd();
  client -> requestFile();

  int count = 0;
  while (count == 0) {
    ioctl(sockfd, FIONREAD, &count); 
    nanosleep(&request, NULL);
  }

  unsigned char buff[count];
  read(sockfd, &buff, count);

  // Ignore payloads that aren't file paths
  if (buff[5] != 0x0A) return;

  file = "";
  for (int i = 6; i < count; i++) {
    unsigned char firstByte = buff[i] << 4;
    unsigned char secondByte = buff[++i];

    file += firstByte | secondByte;
  }

  if (ca) delete ca;
  ca = new CellularAutomaton(file, 0);

  renderCA();
}

void Simulator::clear() {
  int height = ca -> getHeight();
  int width = ca -> getWidth();

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      ca -> setCell(x, y, 0);
    }
  }
  renderCA();
}

void Simulator::randomize() {
  if (!ca) {
    ca = new CellularAutomaton(100, 100, 0);
  }

  int height = ca -> getHeight();
  int width = ca -> getWidth();
  srand(time(NULL)); // Initialize randomization

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      ca -> setCell(x, y, rand() % 2);
    }
  }
  renderCA();
}

void Simulator::handleClick(int x, int y) {
  if (0 <= x <= 600) {
    // TODO: implement clicking on cells
  }
  else if (670 <= x && x <= 720) {
    if (50 <= y && y <= 80) {
      if (ca) togglePlayback();
    }
    else if (95 <= y && y <= 125) {
      if (!file.empty()) reset();
    }
    else if (140 <= y && y <= 170) {
      if (ca) step();
    }
    else if (185 <= y && y <= 215) {
      randomize();
    }
    else if (230 <= y && y <= 260) {
      load();
    }
    else if (275 <= y && y <= 305) {
      if (ca) clear();
    }
    else if (320 <= y && y <= 350) {
      quit();
    }
    renderControlPanel();
  }

  if (525 <= y && y <= 555) {
    if (640 <= x && x <= 670) {
      if (ca -> getHeight() <= 40 && ca -> getWidth() <= 40)
        size = 40;
    }
    else if (685 <= x && x <= 715) {
      if (ca -> getHeight() <= 150 && ca -> getWidth() <= 150)
        size = 150;
    }
    else if (730 <= x && x <= 760) {
      size = 600;
    }
    renderCA();
  }
}
