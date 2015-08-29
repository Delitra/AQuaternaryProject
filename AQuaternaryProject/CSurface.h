#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <sdl.h>

class CSurface {
public:
	CSurface();
	static SDL_Surface* OnLoad(char* File, SDL_Window* optform);
	static bool OnDraw(SDL_Surface* windowsurf, SDL_Surface* src, int x, int y);
};

#endif