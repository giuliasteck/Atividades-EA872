class View{
        private:
                const int altura = 400;
                const int largura = 200;
                int X, Y;
		SDL_Window *window = nullptr;
		SDL_Renderer *renderer = nullptr;
        public:
                View(){
                        X = 0;
                        Y = 0;
                }

                void setX(int x);
                int getX();
                void setY(int y);
                int getY();

                const int getAltura();
                const int getLargura();

		void CriarJanela(SDL_Window *window);
		void Renderizar(SDL_Window *window, SDL_Renderer *renderer);

                void imprimirCoordenadas();
};

