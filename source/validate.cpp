#include "../header/validate.h"
#include <numeric>
#include <cmath>
#include <sstream>
#include <iostream>
#include <string>

//not sure why this had to be separated into constructor and a method but my compiler yelled at me until i did it like this
Validate::Validate() {}

void Validate::initialize(vector<vector<float> > data) {
    //store numInstances and numFeatures so we can use them in other methods
    numInstances = data.size();
    numFeatures = data[0].size();
    //normalize the data right off the bat, no need for un-normalized data
    normalize(data);
    //send information of the dataset to the classifier
    for(int i = 0; i < numInstances; i++) {
        vector<float> temp;
        for(int j = 1; j < ((data[i].size())); j++) {
            temp.push_back(data[i][j]);
        }
        this->classifier.Train(temp);
        this->instances.push_back(data[i][0]);
        temp.clear();
    }
}

//deprecated(?)
int Validate::getNumFeatures() { return this->classifier.featSize(); }

//deprecated(?)
vector<vector<float> > Validate::seperateData(int y, int z) {
    vector<vector<float> > norman;
    for(int i = 0; i < y; i++) {
        vector<float> naval;
        for(int j = 0; j < z; j++) {
            naval.push_back(this->classifier.getfeatNum(i));
        }
        norman.push_back(naval);
    }
    return norman;
}

// void Validate::print() {
//     for(int i = 0; i < this->classifier.size(); i++) {
//         int cnt = 0;
//         cout << "[" << i + 1 << "]Class ID: " << classifier.at(i).getClassNum() << endl;
//         for(int j = 0; j < classifier.at(i).featSize(); ++j) {
//             cnt++;
//             cout << "[" << j + 1 << "] " << classifier.at(i).getfeatNum(j) << " ";
//             if(cnt > 4) {
//                 cnt = 0;
//                 cout << "\n";
//             }
//         }
//         cout << endl;
//     }
// }

void Validate::normalize(vector<vector<float> >& data){
    cout << "Normalizing data....\t\t";
    vector<double> mean(numFeatures, 0.0);
    vector<double> stdDev(numFeatures, 0.0);

    for (int i = 1; i < numFeatures; i++){ //this calculates mean
        double sum = 0.0;
        for(const auto&instance : data){
            sum += instance[i];
        }
        mean[i]= (sum / numInstances);
       // cout << "sum: " << sum << endl;
       // cout << "numInstances: " << numInstances << endl;
       // cout <<  i << " mean: " << mean[i] << endl;
    }
    for(int i = 1; i < numFeatures; ++i){ //this calculates the std
        double sum = 0.0;
        for(const auto& instance : data){
            sum += instance[i];
        }
        double sumSquared = pow(sum, 2);

        double variance = ((sumSquared) - (sumSquared/numInstances)) / numInstances;
        stdDev[i] = sqrt(variance);
        //cout << "std: " << stdDev[i] << endl;
    }
    for(auto &instance : data){ //normalizing the data
        for (int i = 1; i < numFeatures; ++i){
            instance[i] = (instance[i] - mean[i]) / stdDev[i];
         //   cout << "instance " << i << ": " << instance[i] << endl;
        }

    }   
    cout << "Done!\n\n";
}

float Validate::leaveOneOut(string features) {
    vector<int> featuresToTest;
    string tempString;
    stringstream ss(features);
    vector<string> featureVector;
    //convert string of feature numbers to integers
    while(getline(ss, tempString, ',')) {
        featureVector.push_back(tempString);
    };
    for(int i = 0; i < featureVector.size(); i++) {
        featuresToTest.push_back(stoi(featureVector[i]));
    }
    float numCorrect = 0;
    //find nearest neighbor of each instance
    for (int i = 0; i < numInstances; i++) {
        int nearestNeighbor = classifier.Test(featuresToTest, i);
        //cout << instances[i] << "\t" << instances[nearestNeighbor] << endl;
        //if guess is correct, yippee!
        if(instances[i] == instances[nearestNeighbor]) { numCorrect +=1; }
    }
    //cout << numCorrect << "   " << numInstances << endl;
    float accuracy = (numCorrect / (float)numInstances) * 100;
    return accuracy;
}

