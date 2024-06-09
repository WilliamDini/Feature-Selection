#include "../header/classify.h"
#include <cmath>

void Classifier::setClass(float x) { this->classNum = x; }

float Classifier::getClassNum() { return this->classNum; }

float Classifier::getfeatNum(int x) { return this->dataSet.at(x).size(); }

int Classifier::featSize() { return this->dataSet[0].size()-1; }

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

//modified to work with Test
float Classifier::euclideanDistance(vector<int> featuresToTest, int toTest, int testData) {
    double sum = 0.0;
    for (int i = 0; i < featuresToTest.size(); i++) {
        sum += (pow(dataSet[testData][featuresToTest[i]-1] - dataSet[toTest][featuresToTest[i]-1], 2));
    }
    return sqrt(sum);
}

//essentially just a getNearestNeighbor function, renamed to try and stay within the recommended bounds of part 2
int Classifier::Test(vector<int>featuresToTest, int leaveOut) {
    //set nearestNeighbor and shortestDist to unattainble values by default
    int nearestNeighbor = -1;
    float shortestDist = 9999999;
    for(int i = 0; i < dataSet.size(); i++) {
        //skip the instance we are testing
        if(i == leaveOut) { continue; }
        float tempDist = euclideanDistance(featuresToTest, i, leaveOut);
        //cout << "Distance between instance" << i << " and instance " << leaveOut << ": " << tempDist << endl;
        if (tempDist < shortestDist) {
            nearestNeighbor = i;
            shortestDist = tempDist;
        }     
    }
    //cout << "I have chosen instance " << nearestNeighbor << "!!\n";
    return nearestNeighbor;
}


void Classifier::Train(vector<float> data) {
    this->dataSet.push_back(data);
}