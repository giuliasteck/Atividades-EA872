#include <iostream>
#include <memory>

class Dados{
	private:
		const float m = 10;
		const float K = 1;
		const float B = 2;
		const float x0 = 0;
		const float y0 = 1;
		const float v0 = 2;
		const float T = 0.5;
		
		float  X, Y, V, Fm, Fa, Ft, A;
	public:
		Dados(){
			X = x0;
			Y = y0;
			V = v0;
			Fm = 0;
			Fa = 0;
			Ft = 0;
			A = 0;
		}

		void setX(float x) {X = x;}

		float getX() {return X;}

		void setY(float y) {Y=y;}

		float getY() {return Y;}	

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

	//	void imprimir() {std::cout << A << ' ' << V << ' ' << X << std::endl;}
};

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

		void setX(int x) {X = x;}	
		int getX() {return X;}
		void setY(int y) {Y = y;}
		int getY() {return Y;}

		const int getAltura() {return altura;}
		const int getLargura() {return largura;}

		void imprimirCoordenadas() {std::cout << '(' << X << ',' << Y << ')' << std::endl;}	
};


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

void Equacoes::ForcaMola(){
	float Fm_novo;
	Fm_novo = -(d->getK()*d->getY());
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
	float Y_novo;
	Y_novo = (d->getY()+d->getV()*d->getT());
	d->setY(Y_novo);
	
}

void Equacoes::Rasterizacao(){
	int YPixel = d->getY() + v->getAltura()/2;
	int XPixel = d->getX() + v->getLargura()/2;
	v->setX(XPixel);
	v->setY(YPixel);
}

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
		v->imprimirCoordenadas();
	}
}

