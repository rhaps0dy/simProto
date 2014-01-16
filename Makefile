default:all
.PHONY:default

all:
	g++ -g -std=c++11 simproto.cpp proto.cpp -o simproto -lSDL -lSDL_gfx -lboost_system
.PHONY:all
