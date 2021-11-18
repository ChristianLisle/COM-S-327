app: main.cpp GraphicsClient.cpp CellularAutomaton.cpp
	g++ main.cpp GraphicsClient.cpp CellularAutomaton.cpp

GraphicsClient.cpp: GraphicsClient.h
	g++ -c GraphicsClient.cpp

CellularAutomaton.cpp: CellularAutomaton.h
	g++ -c CellularAutomaton.cpp