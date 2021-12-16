#ifndef TASK1_CONTAINER_H
#define TASK1_CONTAINER_H

#include <fstream>
#include "film.h"

using namespace std;

struct container {
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    film *cont[max_len];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst);

// Удаление элементов, значение функции у которых больше среднего арифметического
void DeleteElements (container &arr,ofstream &ofst);

#endif
