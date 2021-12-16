#include "container.h"

void Init(container &c) {
    c.len = 0;
}

void Clear(container &c) {
    c.len = 0;
}

void In(container &c, ifstream &ifst) {
    while(!ifst.eof())
    {
        c.cont[c.len] = InputFilm(ifst);
        if(c.cont[c.len] != 0) {
            c.len++;
        }
    }
}

void InRnd(container &c, int size) {
    while(c.len < size){
        (c.cont[c.len] = InputRndFilm());
        if(c.cont[c.len] != nullptr) {
            c.len++;
        }
    }
}

void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl << endl;
    for(int i = 0; i < c.len; i++){
        OutFilm(*&(c.cont[i]), ofst);
    }
}

void DeleteElements(container &arr, ofstream &ofst) {
    double sum = 0;
    for (int i = 0; i < arr.len; i++) {
        sum += Func(*arr.cont[i]);
    }
    double average = sum / (arr.len);
    ofst << "function average: " << average << endl;
    for (int i = 0; i < arr.len; i++) {
        if (Func(*arr.cont[i]) > average) {
            for(int j = i; j < arr.len; j++) {
                arr.cont[j] = arr.cont[j+1];
            }
            arr.cont[arr.len-1] = NULL;
            arr.len--;
            i--;
        }
    }
}
