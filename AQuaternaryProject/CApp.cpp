#include "CAPP.h"
#include <stdio.h>
#undef main

CApp::CApp(int w, int h) {
	window = NULL;
	Surf_Test = NULL;
	renderer = NULL;
	SCR_W = w;
	SCR_H = h;
	running = true;
}

int CApp::OnExecute() {
	if (OnInit() == false) {
		printf("Error occured whilst initialising SDL. Error: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Event Event;

	while (running) {
		while (SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

int main(int argc, char* argv[]) {
	CApp App(800, 600);
	return App.OnExecute();
}