#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) {
    alto_ = alto;
    ancho_ = ancho;
}
uint Rectangulo::alto() {
    return alto_;
}

uint Rectangulo::ancho() {
    return ancho_;
}

float Rectangulo::area() {
    return ancho_ * alto_;
}

// Ejercicio 2

class Elipse {
public:
    Elipse(uint radioA, uint radioB);
    uint radioA();
    uint radioB();
    float area();

private:
    int radio_a;
    int radio_b;

};
float PI = 3.14;
Elipse::Elipse(uint radioA, uint radioB) {
    radio_a = radioA;
    radio_b = radioB;
}

uint Elipse::radioA() {
    return radio_a;
}

uint Elipse::radioB() {
    return radio_b;
}

float Elipse::area() {
    return radio_a * radio_b * PI;
}


// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return r_.alto();
}

float Cuadrado::area() {
    return r_.area();
}

// Ejercicio 4


class Circulo {
public:
    Circulo(uint radio);
    uint radio();
    float area();

private:
    Elipse e_;

};

Circulo::Circulo(uint radio):e_(Elipse(radio,radio)) {}


uint Circulo::radio() {
    return e_.radioA();
}

float Circulo::area() {
    return e_.area();
}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.radioA() << ", " << e.radioB() << ")";
    return os;
}
// Ejercicio 6
ostream& operator<<(ostream& os, Cuadrado c) {
    os << "Cuad(" << c.lado() << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo c) {
    os << "Circ(" << c.radio() << ")";
    return os;
}


