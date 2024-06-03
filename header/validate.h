#ifndef VALIDATE
#define VALIDATE
#include <iostream>
#include "../header/classify.h"

using namespace std;

class Validate {
    private:
        vector<Classifier> Train;
    public:
        void insertData(Classifier);
        int dataSetSize();
        // void print();
};

#endif

