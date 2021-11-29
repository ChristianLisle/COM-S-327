app: casimulator.cpp GraphicsClient.cpp CellularAutomaton.cpp Simulator.cpp
	g++ casimulator.cpp GraphicsClient.cpp CellularAutomaton.cpp Simulator.cpp -o simulator.out

GraphicsClient.cpp: GraphicsClient.h
	g++ -c GraphicsClient.cpp

CellularAutomaton.cpp: CellularAutomaton.h
	g++ -c CellularAutomaton.cpp

Simulator.cpp: Simulator.h
	g++ -c Simulator.cpp