#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "container.h"

using namespace std;

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f inputfile outputfile01 outputfile02\n"
            "  Or:\n"
            "     command -g number outputfile01 outputfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f inputfile outputfile01 outputfile02\n"
            "  Or:\n"
            "     command -g number outputfile01 outputfile02\n";
}

int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    clock_t start_time = clock();
    cout << "Start"<< endl;
    container c;
    Init(c);

    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        In(c, ifst);
    }
    else if(!strcmp(argv[1], "-g")) {
        auto size = (atoi(argv[2]));
        if((size < 1) || (size > 10001)) {
            cout << "incorrect number of strings = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    ofstream ofst1(argv[3]);
    ofstream ofst2(argv[4]);

    Out(c, ofst1);
    DeleteElements(c, ofst2);
    Out(c, ofst2);
    ofst1.close();
    ofst2.close();

    Clear(c);
    clock_t end_time = clock();
    double seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << seconds<<"s \n";
    cout << "Stop"<< endl;
}
