#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Image {

public:
	SDL_Surface* img;
	Image(const char*);
	~Image();
};