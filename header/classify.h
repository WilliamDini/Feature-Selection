#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include <iostream>
#include <vector>

using namespace std;

class Classifier {
    private:    
        float classNum;
        vector<float> features;
    public:
        void setClass(float);
        void insertFeatures(float);
        float getClassNum();
        float getfeatNum(int);
        int featSize();
        void normalize(vector<vector<float>> &data);
};

#endif