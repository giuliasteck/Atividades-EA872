#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "view.hpp"

void View::setX(int x) {X = x;}

int View::getX() {return X;}

void View::setY(int y) {Y = y;}

int View::getY() {return Y;}

const int View::getAltura() {return altura;}
const int View::getLargura() {return largura;}

void View::imprimirCoordenadas() {std::cout << '(' << X << ',' << Y << ')' << std::endl;}

void View::CriarJanela(SDL_Window *window){
	window = nullptr;
	window = SDL_CreateWindow ("Demonstração do SDL2",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			largura,
			altura,
			SDL_WINDOW_SHOWN);
	if (window==nullptr) { // Em caso de erro...
    		std::cout << SDL_GetError();
    		SDL_Quit();
   	}
}

void Renderizar(SDL_Window *window, SDL_Renderer *renderer){
      renderer = SDL_CreateRenderer(
      window, -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  	if (renderer==nullptr) { // Em caso de erro...
    		SDL_DestroyWindow(window);
    		std::cout << SDL_GetError();
		SDL_Quit();
  }
}
