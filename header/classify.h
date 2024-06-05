#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include <iostream>
#include <vector>

using namespace std;

class Classifier {
    private:    
        float classNum;
        vector<vector<float> > dataSet;
    public:
        void setClass(float);
        void insertDataPoint(vector<float>);
        float getClassNum();
        float getfeatNum(int);
        int featSize();
        float findMax(vector<float>);
        float findMin(vector<float>);
        float normalizeCalc(float, float, float);
        void Train(vector<float>);
        float euclideanDistance(vector<int>, int, int);
        int Test(vector<int>, int);
};

#endif