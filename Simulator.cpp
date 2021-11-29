#include "GraphicsClient.h"
#include "CellularAutomaton.h"
#include "Simulator.h"

using namespace std;

Simulator::Simulator(CellularAutomaton* cellularAutomaton, string url, int port) {
  ca = cellularAutomaton;
  client = new GraphicsClient(url, port);
}

Simulator::Simulator(Simulator &other) {
  ca = other.ca;
  client = other.client;
}

Simulator::~Simulator() {
  delete client;
}

void Simulator::operator=(const Simulator rhs) {
  ca = rhs.ca;
  client = rhs.client;
}

void Simulator::open() {
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
  client -> drawString(686, 70, "PLAY");
  client -> drawString(684, 115, "RESET");
  client -> drawString(686, 160, "STEP");
  client -> drawString(688, 205, "RUN");
  client -> drawString(674, 250, "RANDOM");
  client -> drawString(686, 295, "LOAD");
  client -> drawString(686, 340, "QUIT");
  client -> drawString(652, 545, "1");
  client -> drawString(697, 545, "2");
  client -> drawString(742, 545, "3");

  client -> repaint();
}

void Simulator::step(unsigned char (*rule)(CellularAutomaton*, int, int)) {
  // TODO
}

void Simulator::run() {
  // TODO
}

void Simulator::pause() {
  // TODO
}

void Simulator::quit() {
  // TODO
}

void Simulator::load() {
  // TODO
}

void Simulator::clear() {
  // TODO
}

void Simulator::randomize() {
  // TODO
}