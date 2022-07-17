all: Game

Game : Array.o Cell.o Err_Window.o Main.o Next_button.o Pole.o Saves.o Special_buttons.o Window.o
	g++ Array.o Cell.o Err_Window.o Main.o Next_button.o Pole.o Saves.o Special_buttons.o Window.o -o Game -lfltk

Array.o : Array.cpp
	g++ -c Array.cpp

Cell.o : Cell.cpp
	g++ -c Cell.cpp

Err_Window.o : Err_Window.cpp
	g++ -c Err_Window.cpp

Main.o : Main.cpp
	g++ -c Main.cpp

Next_button.o : Next_button.cpp
	g++ -c Next_button.cpp

Pole.o : Pole.cpp
	g++ -c Pole.cpp

Saves.o : Saves.cpp
	g++ -c Saves.cpp

Special_buttons.o : Special_buttons.cpp
	g++ -c Special_buttons.cpp

Window.o : Window.cpp
	g++ -c Window.cpp



clean :
	rm -rf *.o Game
