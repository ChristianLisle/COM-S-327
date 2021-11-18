app: main.cpp GraphicsClient.cpp GraphicsClient.h CellularAutomaton.cpp CellularAutomaton.h
	g++ main.cpp GraphicsClient.cpp

GraphicsClient.cpp: GraphicsClient.h
	g++ -c GraphicsClient.cpp

CellularAutomaton.cpp: CellularAutomaton.h
	g++ -c CellularAutomaton.cpp