#ifndef VALIDATE
#define VALIDATE
#include <iostream>
#include <iomanip>
#include "../header/classify.h"

using namespace std;

class Validate {
    private:
        vector<Classifier> Train;
    public:
        void insertData(Classifier);
        int dataSetSize();
        void print();
        vector<vector<float>> seperateData(int, int);
        void normalize(vector<vector<float>> &);
};

#endif

