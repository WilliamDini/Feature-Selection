#ifndef CLASSIFIER
#define CLASSIFIER
#include <iostream>

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
        void normalize(vector<Classifier>&);
        float findMax(vector<float>);
        float findMin(vector<float>);
        float normalizeCalc(float, float, float);
};

#endif