GCC_OPTIONS=-Wall -pedantic -I ../include
GL_OPTIONS=-framework OpenGL -framework GLUT 

COMMON=../common/initShader.cpp \
			 ../include/Angel.h

OPTIONS=$(GCC_OPTIONS) $(GL_OPTIONS) $(COMMON)

breakout: breakout.o geometry.o game.o brick.o
	g++ $(OPTIONS) -g -o breakout breakout.o geometry.o game.o brick.o

breakout.o: breakout.cpp game.h
	g++ $(GCC_OPTIONS) -g -c breakout.cpp

game.o: game.h game.cpp
	g++ $(GCC_OPTIONS) -g -c game.cpp

paddle.o: paddle.h paddle.cpp
	g++ $(GCC_OPTIONS) -g -c paddle.cpp

geometry.o: geometry.h geometry.cpp
	g++ $(GCC_OPTIONS) -g -c geometry.cpp

brick.o: brick.h brick.cpp
	g++ $(GCC_OPTIONS) -g -c brick.cpp



clean:
	rm -f breakout breakout.o ball.o brick.o game.o geometry.o paddle.o scene.o brick.o



.cpp: 
	g++ $@.cpp ../common/initShader.cpp $(OPTIONS) -o $@