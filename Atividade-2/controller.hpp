#include <memory>
#include "view.hpp"
#include "dados.hpp"

class Equacoes{
        private:
                std::shared_ptr<Dados>d;
                std::shared_ptr<View>v;
        public:
                Equacoes(std::shared_ptr<Dados>d, std::shared_ptr<View>v){
                        this->d = d;
                        this->v = v;
                }
                void ForcaMola();
                void ForcaAmortecedor();
                void ForcaTotal();
                void Aceleracao();
                void Posicao();
                void Velocidade();
                void Rasterizacao();
};

