#include <iostream>
#include <memory>

class Dados{
	private:
		const float m = 10;
		const float K = 1;
		const float B = 2;
		const float x0 = 1;
		const float v0 = 2;
		const float T = 0.5;
		
		float X, V, Fm, Fa, Ft, A;
	public:
		Dados(){
			X = x0;
			V = v0;
			Fm = 0;
			Fa = 0;
			Ft = 0;
			A = 0;
		}

		void setX(float x) {X = x;}

		float getX() {return X;}	

		void setV(float v) {V = v;}

		float getV() {return V;}

		void setFm(float fm) {Fm = fm;}

		float getFm() {return Fm;}

		void setFa(float fa) {Fa = fa;}

		float getFa() {return Fa;}

		void setFt(float ft) {Ft = ft;}

		float getFt() {return Ft;}

		void setA(float a) {A = a;}

		float getA() {return A;}

		float getK() {return K;}

		float getB() {return B;}

		float getM() {return m;}

		float getT() {return T;}

//		void imprimir(){
//			std::cout << A << ' ' << V << ' ' << X << std::endl;
//		}
};

class View{
	private:
		const int altura = 400;
		const int largura = 200;
		int x,y;
	public:
		View(){
			x = 200;
			y = 100;
		}

		const int getAltura(){return altura;}
		const int getLargura(){return largura;}
		float
	
}


class Equacoes{
	private:
		std::shared_ptr<Dados>d;
		std::shared_ptr<View>v;
	public:
		Equacoes(std::shared_ptr<Dados>d, std::shared_ptr<View>v){
			this->d = d;
		}
		void ForcaMola();
		void ForcaAmortecedor();
		void ForcaTotal();
		void Aceleracao();
		void Posicao();
		void Velocidade();
};

void Equacoes::ForcaMola(){
	float Fm_novo;
	Fm_novo = -(d->getK()*d->getX());
	d->setFm(Fm_novo);
}

void Equacoes::ForcaAmortecedor(){
	float Fa_novo;
	Fa_novo = -(d->getB()*d->getV());
	d->setFa(Fa_novo);
}

void Equacoes::ForcaTotal(){
	float Ft_novo;
	Ft_novo = (d->getFa()+d->getFm());
	d->setFt(Ft_novo);
}

void Equacoes::Aceleracao(){
	float A_novo;
	A_novo = (d->getFt()/d->getM());
	d->setA(A_novo);
}

void Equacoes::Velocidade(){
	float V_novo;
	V_novo = (d->getV()+d->getA()*d->getT());
	d->setV(V_novo);
}

void Equacoes::Posicao(){
	float X_novo;
	X_novo = (d->getX()+d->getV()*d->getT());
	d->setX(X_novo);
	
}

void Renderizacao(){

}

int main(){
	std::shared_ptr<View>v (new Dados);
	std::shared_ptr<Dados>d (new Dados);
	std::shared_ptr<Equacoes>e (new Equacoes(d,v));
	
	for(int n = 0; n<100; n++){
		e->ForcaMola();
		e->ForcaAmortecedor();
		e->ForcaTotal();
		e->Aceleracao();
		e->Velocidade();
		e->Posicao();
		d->imprimir();
	}
}

