#ifndef TASK1_FILM_H
#define TASK1_FILM_H

#include <string>
#include <fstream>
using namespace std;

struct film {
    enum key {FEATURE, CARTOON, DOCUMENTARY};
    key k;              // тип фильма
    std::string title;  // название фильма
    int year;           // год выхода
};

struct feature : film {
    std::string director; // имя режиссёра
};

struct cartoon : film {
    enum type {HAND_DRAWN, PUPPET, PLASTICINE}; // тип анимации
    type t;
};

struct documentary : film {
    int duration;   // длина фильма
};

film *InputFilm(ifstream &ifst);

film *InputRndFilm();

double Func(const film &f);

void OutFilm(film *&s, ofstream &ofst);

#endif
