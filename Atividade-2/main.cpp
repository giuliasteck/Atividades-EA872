#include <iostream>
#include <memory>
#include "controller.hpp"

int main(){
	std::shared_ptr<View>v (new View);
	std::shared_ptr<Dados>d (new Dados);
	std::shared_ptr<Equacoes>e (new Equacoes(d,v));
	
	for(int n = 0; n<100; n++){
		e->ForcaMola();
		e->ForcaAmortecedor();
		e->ForcaTotal();
		e->Aceleracao();
		e->Velocidade();
		e->Posicao();
		e->Rasterizacao();
		d->imprimir();
		v->imprimirCoordenadas();
	}
}

