all: Game

Game : Main.o Picture.o Shape.o Shape_Cat.o Shape_Cloud.o Shape_Sun.o Shape_Tree.o Simple.o Window.o
	g++ Main.o Picture.o Shape.o Shape_Cat.o Shape_Cloud.o Shape_Sun.o Shape_Tree.o Simple.o Window.o -o Game -lfltk

Main.o : Main.cpp
	g++ -c Main.cpp

Picture.o : Picture.cpp
	g++ -c Picture.cpp

Shape.o : Shape.cpp
	g++ -c Shape.cpp

Shape_Cat.o : Shape_Cat.cpp
	g++ -c Shape_Cat.cpp

Shape_Cloud.o : Shape_Cloud.cpp
	g++ -c Shape_Cloud.cpp

Shape_Sun.o : Shape_Sun.cpp
	g++ -c Shape_Sun.cpp

Shape_Tree.o : Shape_Tree.cpp
	g++ -c Shape_Tree.cpp

Simple.o : Simple.cpp
	g++ -c Simple.cpp

Window.o : Window.cpp
	g++ -c Window.cpp



clean :
	rm -rf *.o Game
