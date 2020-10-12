#include <iostream>
#include "view.hpp"

void View::setX(int x) {X = x;}

int View::getX() {return X;}

void View::setY(int y) {Y = y;}

int View::getY() {return Y;}

const int View::getAltura() {return altura;}
const int View::getLargura() {return largura;}

void View::imprimirCoordenadas() {std::cout << '(' << X << ',' << Y << ')' << std::endl;}

