app: main.cpp GraphicsClient.cpp GraphicsClient.h
	g++ main.cpp GraphicsClient.cpp

GraphicsClient.cpp: GraphicsClient.h
	g++ -c GraphicsClient.cpp