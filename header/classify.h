#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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
        float findMax(vector<float>);
        float findMin(vector<float>);
        float normalizeCalc(float, float, float);
        //void normalize(vector<vector<float>> &);
        float testing(const vector<float> &);
};

#endif