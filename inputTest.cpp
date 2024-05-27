#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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
};

void Classifier::setClass(float x) { this->classNum = x; }

void Classifier::insertFeatures(float x) { this->features.push_back(x); }

float Classifier::getClassNum() { return this->classNum; }

float Classifier::getfeatNum(int x) { return this->features.at(x); }

int Classifier::featSize() { return this->features.size(); }


class Validate {
    private:
        vector<Classifier> Train;
    public:
        void insertData(Classifier);
        int dataSetSize();
        void print();
};

void Validate::insertData(Classifier x) { this->Train.push_back(x); }

int Validate::dataSetSize() { return this->Train.size(); }

void Validate::print() {
    for(int i = 0; i < this->Train.size(); i++) {
        int cnt = 0;
        cout << "[" << i + 1 << "]Class ID: " << Train.at(i).getClassNum() << endl;
        for(int j = 0; j < Train.at(i).featSize(); ++j) {
            cnt++;
            cout << "[" << j + 1 << "] " << Train.at(i).getfeatNum(j) << " ";
            if(cnt > 4) {
                cnt = 0;
                cout << "\n";
            }
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {

    if(argc < 2) {
        cout << "ERROR: Invalid Argument Count" << endl;
        exit(1);
    }
    string fileName = argv[1];
    ifstream inFS;
    string line;
    float classNum, featNum;
    inFS.open(fileName);
    if(!inFS.is_open()) {
        cout << "ERROR: Invalid File" << endl;
        exit(1);
    }
    Validate dataSet;

    while(getline(inFS, line)) {
        istringstream stream(line);
        Classifier dataPoint;
        stream >> classNum;
        while(stream >> featNum) {
            dataPoint.insertFeatures(featNum);
        }
        dataPoint.setClass(classNum);
        dataSet.insertData(dataPoint);
    }
    // cout << dataSet.dataSetSize() << endl;
    dataSet.print();

    inFS.close();







    return 0;
}