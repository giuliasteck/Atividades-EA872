class View{
        private:
                const int altura = 400;
                const int largura = 200;
                int X, Y;
        public:
                View(){
                        X = 0;
                        Y = 0;

		    	SDL_Window *window = nullptr;
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
			

			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
     				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        		if (renderer==nullptr) { // Em caso de erro...
                		SDL_DestroyWindow(window);
                		std::cout << SDL_GetError();
                		SDL_Quit();
  			}
		}

                void setX(int x);
                int getX();
                void setY(int y);
                int getY();

                const int getAltura();
                const int getLargura();

                void imprimirCoordenadas();
};

