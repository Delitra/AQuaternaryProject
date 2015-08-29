#include "CApp.h"
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void CApp::OnCleanup() {
	SDL_DestroyWindow(window);
	SDL_FreeSurface(Surf_Test);
	Surf_Test = NULL;
	window = NULL;
	SDL_Quit();
	_CrtDumpMemoryLeaks();
}