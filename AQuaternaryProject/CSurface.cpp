#include "CSurface.h"
#include <stdio.h>

CSurface::CSurface() {
}

SDL_Surface* CSurface::OnLoad(char* file, SDL_Window* optform) {
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* Surf_Return = NULL;

	if ((Surf_Temp = SDL_LoadBMP(file)) == NULL) {
		printf("Error loading file %s. Error: %s\n", file, SDL_GetError());
		return NULL;
	}

	if ((Surf_Return = SDL_ConvertSurfaceFormat(Surf_Temp, SDL_GetWindowPixelFormat(optform), 0)) == NULL) {
		printf("Error loading file %s. Error: %s\n", file, SDL_GetError());
		return NULL;
	}

	SDL_FreeSurface(Surf_Temp);

	return Surf_Return;
}

bool CSurface::OnDraw(SDL_Surface* windowsurf, SDL_Surface* src, int x, int y) {
	if (windowsurf == NULL || src == NULL) {
		printf("No window or source surface provided.");
		return false;
	}

	SDL_Rect DestR;
	DestR.x = x;
	DestR.y = y;

	SDL_BlitSurface(src, NULL, windowsurf, &DestR);


	delete &DestR;
	return true;
}