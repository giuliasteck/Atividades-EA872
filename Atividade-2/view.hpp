class View{
        private:
                const int altura = 400;
                const int largura = 200;
                int X, Y;
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

                void imprimirCoordenadas();
};

