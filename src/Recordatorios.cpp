#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif
    void incrementar_dia();
    bool operator<(Fecha f);

  private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) {
    if(mes <= 12 && mes >= 1){
        mes_ = mes;
    }
    if(dia >= 1){
        dia_ = dia;
    }
}

int Fecha::mes() {
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia() && this->mes() == o.mes();
    return igual_dia;
}

void Fecha::incrementar_dia() {
    if (this->dia() == dias_en_mes(this->mes())){
        mes_ = this->mes() +1;
        dia_ = 1;
    }else {
        mes_ = this->mes();
        dia_ = this->dia() + 1;
    }
}
bool Fecha::operator<(Fecha f) {
    return this->mes() < f.mes() || (f.mes() == this->mes() && this->dia() < f.dia());
}
#endif

// Ejercicio 11, 12

// Clase Horario
class Horario {
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario o);
    bool operator<(Horario h);

private:
    int hora_;
    int min_;
};
Horario::Horario(uint hora, uint min) {
    if(hora <= 23 && hora >= 0){
        hora_ = hora;
    }
    if(min >= 0 && min <= 59){
        min_ = min;
    }
}

uint Horario::hora() {
    return hora_;
}

uint Horario::min() {
    return min_;
}

bool Horario::operator==(Horario o) {
    bool igual = this->hora() == o.hora() && this->min() == o.min();
    return igual;
}

bool Horario::operator<(Horario h) {
    return this->hora() < h.hora() || (h.hora() == this->hora() && this->min() < h.min());
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}
// Ejercicio 13

// Clase Recordatorio
class Recordatorio {
public:
    Recordatorio(Fecha f, Horario h, string msg);
    string msg();
    Fecha f();
    Horario h();
    bool operator<(Recordatorio r);

private:
    string msg_;
    Fecha f_;
    Horario h_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string msg) : msg_(msg), f_(f), h_(h) {}

string Recordatorio::msg() {
    return msg_;
}

Fecha Recordatorio::f() {
    return f_;
}

Horario Recordatorio::h() {
    return h_;
}
ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.msg() << " @ " << r.f() << " " << r.h();
    return os;
}

// Ejercicio 14
// Clase Agenda
class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    Fecha hoy_;
    list<Recordatorio> r;
};

Agenda::Agenda(Fecha fecha_inicial) : hoy_(fecha_inicial) {}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    r.push_back(rec);
}

void Agenda::incrementar_dia() {
    hoy_.incrementar_dia();
}

list <Recordatorio> Agenda::recordatorios_de_hoy() {
    list <Recordatorio> hoys;
    for(Recordatorio rec : r){
        if (hoy_ == rec.f()){
            hoys.push_back(rec);
        }
    }
    return hoys;
}

Fecha Agenda::hoy() {
    return hoy_;
}
ostream& operator<< (ostream& os, Agenda a) {
    os << a.hoy() << endl << "=====" << endl;
    list<Recordatorio> orden = a.recordatorios_de_hoy();
    orden.sort();
    for(Recordatorio recordatorio : orden){
        os << recordatorio << endl;
    }
    return os;
}
bool Recordatorio::operator<(Recordatorio r) {
    return this->h() < r.h();
}
