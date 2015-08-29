#ifndef _CAPP_H_
#define _CAPP_H_


#include <sdl.h>
#include "CSurface.h"

class CApp {
private:
	bool running;
	SDL_Window* window;
	SDL_Surface* windowsurf;
	SDL_Surface* Surf_Test;
	SDL_Renderer* renderer;
	int SCR_W;
	int SCR_H;
public:
	CApp(int w, int h);
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event* Event);
	void OnLoop();
	void OnRender();
	void OnCleanup();
};

#endif