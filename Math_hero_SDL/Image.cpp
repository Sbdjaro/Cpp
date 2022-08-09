#include "Image.h"
#include <iostream>
Image::Image(const char* s) {
	img = IMG_Load(s);
	
	SDL_SetColorKey(img, SDL_TRUE, SDL_MapRGB(img->format, 255, 255, 255));
}

Image::~Image() {
	SDL_FreeSurface(img);
}