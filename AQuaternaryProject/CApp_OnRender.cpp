#include "CApp.h"

void CApp::OnRender() {
	CSurface::OnDraw(windowsurf, Surf_Test, 0, 0);
	SDL_RenderClear(renderer);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, windowsurf);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
}