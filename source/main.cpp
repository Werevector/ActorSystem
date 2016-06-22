#pragma once
#include "sdl.h"
#include <iostream>

int main(int argc, char* argv[])
{
	int win_height = 1080 / 2;
	int win_width = 1920 / 2;
	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_version compiled;
	SDL_version linked;

	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printf("We compiled against SDL version %d.%d.%d ...\n",
		compiled.major, compiled.minor, compiled.patch);
	printf("But we are linking against SDL version %d.%d.%d.\n",
		linked.major, linked.minor, linked.patch);

	

	SDL_Window* window_handle = SDL_CreateWindow("ActorSystem", 100, 100, win_width, win_height, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window_handle, -1, SDL_RENDERER_ACCELERATED);

	SDL_Rect rect; rect.x = (win_width / 2) - 30; rect.y = (win_height / 2) - 30; rect.w = 30; rect.h = 30;

	
	
	SDL_Event* event_handle = new SDL_Event();
	while (!quit) {
		while (SDL_PollEvent(event_handle) != NULL) {
			if (event_handle->type == SDL_QUIT) {
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderDrawRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}

	std::cout << "Quitting program. \n";



	return 0;
}