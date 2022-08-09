#include "Inventory.h"

Inventory::Inventory(SDL_Window* w, SDL_Surface* s):surface(s),win(w),
rect_hotbar_cell{3,nullptr}{
	img_hotbar = IMG_Load("img/inventory/cell_hotbar.png");
	img_hotbar_active = IMG_Load("img/inventory/cell_hotbar_active.png");
	for (int i = 0; i < 3; i++)
		rect_hotbar_cell[i] = new SDL_Rect{ 920,410 + i * 60,980,470 + i * 60 };
}

void Inventory::Draw() {
	for (int i = 0; i < 3; i++)
		SDL_BlitSurface(img_hotbar, nullptr, surface, rect_hotbar_cell[i]);
	SDL_BlitSurface(img_hotbar_active, nullptr, surface, rect_hotbar_cell[active_hotbar]);
}

void Inventory::Change_hotbar() {
	active_hotbar = (active_hotbar + 1) % 3;
}


Inventory::~Inventory() {
	for (int i = 0; i < 3; i++)
		delete rect_hotbar_cell[i];
	SDL_FreeSurface(img_hotbar);
	SDL_FreeSurface(img_hotbar_active);
}