#include "Window.h"

Window::Window() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to initialize SDL, ";
		std::cout << SDL_GetError();
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		std::cout << "GG";
	std::cout << IMG_GetError();
	window = SDL_CreateWindow("Snake",
		SDL_WINDOWPOS_CENTERED_MASK,
		SDL_WINDOWPOS_CENTERED_MASK,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	//pause = SDL_LoadBMP("img/Pause.bmp");
	me = this;
	stats = new Stats();
	pole = new Pole(surface,window);
	game_over = new Game_over(window, surface);
}

void Window::Game() {
	SDL_Event e;
	bool quit = false;
	int x = 0, y = 0;
	while (1) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_TAB) {
					pole->inventory->Change_hotbar();
				}
				switch (e.key.keysym.sym) {

				case SDLK_UP:
				case SDLK_w:
					y = max(y - 1, -1); break;
				case SDLK_DOWN:
				case SDLK_s:
					y = min(y + 1, 1); break;
				case SDLK_LEFT:
				case SDLK_a:
					x = max(x - 1, -1); break;
				case SDLK_RIGHT:
				case SDLK_d:
					x = min(x + 1, 1); break;
				case SDLK_0:
				case SDLK_KP_0:
					pole->panel->Add(0); break;
				case SDLK_1:
				case SDLK_KP_1:
					pole->panel->Add(1); break;
				case SDLK_2:
				case SDLK_KP_2:
					pole->panel->Add(2); break;
				case SDLK_3:
				case SDLK_KP_3:
					pole->panel->Add(3); break;
				case SDLK_4:
				case SDLK_KP_4:
					pole->panel->Add(4); break;
				case SDLK_5:
				case SDLK_KP_5:
					pole->panel->Add(5); break;
				case SDLK_6:
				case SDLK_KP_6:
					pole->panel->Add(6); break;
				case SDLK_7:
				case SDLK_KP_7:
					pole->panel->Add(7); break;
				case SDLK_8:
				case SDLK_KP_8:
					pole->panel->Add(8); break;
				case SDLK_9:
				case SDLK_KP_9:
					pole->panel->Add(9); break;
				case SDLK_SPACE:
					pole->panel->Check(); break;
				case SDLK_MINUS:
				case SDLK_KP_MINUS:
					pole->panel->Minus(); break;
				}
			}
			else if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
				case SDLK_UP:
				case SDLK_w:
					y = min(y + 1, 1); break;
				case SDLK_DOWN:
				case SDLK_s:
					y = max(y - 1, -1); break;
				case SDLK_LEFT:
				case SDLK_a:
					x = min(x + 1, 1); break;
				case SDLK_RIGHT:
				case SDLK_d:
					x = max(x - 1, -1); break;
				}
			}
		}
		//cout << x <<" " << y << "\n";
		pole->Draw(x, y);
		stats->Check();
		SDL_Delay(6);
	}
}

void Window::End_game() {
	game_over->Set(pole->panel->score->score, stats->time);

	while (1)
		game_over->Draw();
}

Window::~Window() {
	delete pole;
	delete stats;
	delete game_over;
	SDL_FreeSurface(pause);
	SDL_DestroyWindow(window);
	SDL_Quit();
}