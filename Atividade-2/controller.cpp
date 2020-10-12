#include <iostream>
#include "controller.hpp"
#include <memory>

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

