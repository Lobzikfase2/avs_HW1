#include <iostream>
#include <string>
#include "generator.h"
#include "film.h"

using namespace std;

film *InputFilm(ifstream &ifst) {
    film *sp;
    int k;
    string title = "";
    int year;
    ifst >> k;
    ifst >> title;
    ifst >> year;
    switch (k) {
        case 1:
            sp = new feature;
            sp->k = film::FEATURE;
            sp->title = title;
            sp->year = year;
            ifst >> reinterpret_cast<feature*>(sp)->director;
            return sp;
        case 2:
            sp = new cartoon;
            sp->k = film::CARTOON;
            sp->title = title;
            sp->year = year;
            int t;
            ifst >> t;
            reinterpret_cast<cartoon*>(sp)->t = static_cast<cartoon::type>(t-1);
            return sp;
        case 3:
            sp = new documentary;
            sp->k = film::DOCUMENTARY;
            sp->title = title;
            sp->year = year;
            ifst >> reinterpret_cast<documentary*>(sp)->duration;
            return sp;
        default:
            return 0;
    }
}

film *InputRndFilm() {
    film *sp;
    int k = rand() % 3 + 1;
    string title = GenStr();
    int year = rand() % 135 + 1895;
    switch (k) {
        case 1:
            sp = new feature;
            sp->title = title;
            sp->year = year;
            sp->k = film::FEATURE;
            reinterpret_cast<feature*>(sp)->director = GenStr() + " " + GenStr();
            return sp;
        case 2:
            sp = new cartoon;
            sp->title = title;
            sp->year = year;
            sp->k = film::CARTOON;
            reinterpret_cast<cartoon*>(sp)->t = (cartoon::type) (rand() % 3 + 1);
            return sp;
        case 3:
            sp = new documentary;
            sp->title = title;
            sp->year = year;
            sp->k = film::DOCUMENTARY;
            reinterpret_cast<documentary*>(sp)->duration = rand() % 150 + 30;
            return sp;
        default:
            return 0;
    }
}

double Func(const film &f){
    return f.year / f.title.length();
}

void OutFilm(film *&s, ofstream &ofst) {
    switch ((*s).k) {
        case film::FEATURE:
            ofst << "feature film:" << endl;
            ofst << "\ttitle: " << s->title << endl;
            ofst << "\tyear: " << s->year << endl;
            ofst << "\tdirector: " << reinterpret_cast<feature*>(s)->director << endl;
            ofst << endl;
            break;
        case film::CARTOON:
            ofst << "cartoon film:" << endl;
            ofst << "\ttitle: " << s->title << endl;
            ofst << "\tyear: " << s->year << endl;
            switch (reinterpret_cast<cartoon*>(s)->t) {
                case cartoon::type::HAND_DRAWN:
                    ofst << "\ttype: " << "hand drawn" << endl;
                    break;
                case cartoon::type::PUPPET:
                    ofst << "\ttype: " << "puppet" << endl;
                    break;
                case cartoon::type::PLASTICINE:
                    ofst << "\ttype: " << "plasticine" << endl;
                    break;
            }
            ofst << endl;
            break;
        case film::DOCUMENTARY:
            ofst << "documentary film:" << endl;
            ofst << "\ttitle: " << s->title << endl;
            ofst << "\tyear: " << s->year << endl;
            ofst << "\tduration: " << reinterpret_cast<documentary*>(s)->duration << endl;
            ofst << endl;
            break;
        default:
            ofst << "Incorrect string!" << endl;
            break;
    }
}
