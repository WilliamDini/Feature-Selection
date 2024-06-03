#include "../header/classify.h"
#include <cmath>
#include <numeric>

void Classifier::setClass(float x) { this->classNum = x; }

void Classifier::insertFeatures(float x) { this->features.push_back(x); }

float Classifier::getClassNum() { return this->classNum; }

float Classifier::getfeatNum(int x) { return this->features.at(x); }

int Classifier::featSize() { return this->features.size(); }

float Classifier::normalizeCalc(float value, float min, float max) {
    return ((value - min) / (max - min));
}

float Classifier::findMax(vector<float> x) {
    int min = x.at(0);
    for(int i = 0; i < x.size(); i++) {
        if(x.at(i) < min) {
            min = x.at(i);
        }
    }
    return min;
}

float Classifier::findMin(vector<float> x) {
    int max = x.at(0);
    for(int i = 0; i < x.size(); i++) {
        if(x.at(i) > max) {
            max = x.at(i);
        }
    }
    return max;
}