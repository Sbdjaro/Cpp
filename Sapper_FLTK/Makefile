all: Game

Game : Main.o Window.o Pole.o Start.o Menu.o Flag.o Cell.o
	sudo apt-get install libfltk1.3-dev
	sudo apt-get install libx11-dev
	g++ Main.o Window.o Pole.o Start.o Menu.o Flag.o Cell.o -o Game -lfltk

Main.o : Main.cpp
	g++ -c main.cpp

Window.o : Window.cpp
	g++ -c Window.cpp

Pole.o : Pole.cpp
	g++ -c Pole.cpp

Start.o : Start.cpp
	g++ -c Start.cpp

Menu.o : Menu.cpp
	g++ -c Menu.cpp

Flag.o : Flag.cpp
	g++ -c Flag.cpp

Cell.o : Cell.cpp
	g++ -c Cell.cpp

clean:
	 rm -rf *.o Game 
	