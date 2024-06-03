#include "../header/classify.h"
#include <cmath>
#include <numeric>

void Classifier::setClass(float x) { this->classNum = x; }

void Classifier::insertFeatures(float x) { this->features.push_back(x); }

float Classifier::getClassNum() { return this->classNum; }

float Classifier::getfeatNum(int x) { return this->features.at(x); }

int Classifier::featSize() { return this->features.size(); }

void Classifier::normalize(vector<vector<float>> &data){
    float numFeatures = data[0].size();
    float numInstances = data.size();

    vector<float> mean(numFeatures, 0.0);
    vector<float> stdDev(numFeatures, 0.0);

    for (int i = 0; i < numFeatures; i++){ //this calculates mean
        float sum = 0.0;
        for(const auto&instance : data){
            sum += instance[i];
        }
        mean[i]= sum / numInstances;
    }
    for(int i = 0; i < numFeatures; ++i){ //this calculates the std
        float sumOfSquares = 0.0;
        for(const auto& instance : data){
            sumOfSquares += pow(instance[i] - mean[i],2);
        }
        float variance = sumOfSquares / numInstances;
        stdDev[i] = sqrt(variance);
    }
    for(auto &instance : data){ //normalizing the data
        for (int i = 0; i < numFeatures; ++i){
            instance[i] = (instance[i] - mean[i]) / stdDev[i];
        }
    }
}