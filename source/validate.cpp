#include "../header/validate.h"
#include "../header/classify.h"

void Validate::insertData(Classifier x) { this->Train.push_back(x); }

int Validate::dataSetSize() { return this->Train.size(); }

vector<vector<float>> Validate::seperateData(int y, int z) {
    vector<vector<float>> norman;
    for(int i = 0; i < y; ++i) {
        vector<float> naval;
        for(int j = 0; j < z; ++j) {
            naval.push_back(this->Train.at(j).getfeatNum(i));
        }
        norman.push_back(naval);
    }
    return norman;
}

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

void Validate::normalize(vector<vector<float>> &data){
    float numFeatures = data[0].size();
    float numInstances = data.size();

    vector<float> mean(numFeatures, 0.0);
    vector<float> stdDev(numFeatures, 0.0);

    for (int i = 0; i < numFeatures; i++){ //this calculates mean
        float sum = 0.0;
        for(const auto&instance : data){
            sum += instance[i];
            cout << fixed << setprecision(10) << instance[i]<< endl;
        }
        mean[i]= sum / numInstances;
        
        cout << "sum: " << sum << endl;
        cout << "numInstances: " << numInstances << endl;
        cout <<  i << " mean: " << mean[i] << endl;
    }
    for(int i = 0; i < numFeatures; ++i){ //this calculates the std
        float sumOfSquares = 0.0;
        for(const auto& instance : data){
            sumOfSquares += pow(instance[i] - mean[i],2);
        }
        float variance = sumOfSquares / numInstances;
        stdDev[i] = sqrt(variance);
        //cout << "std: " << stdDev[i] << endl;
    }
    for(auto &instance : data){ //normalizing the data
        for (int i = 0; i < numFeatures; ++i){
            instance[i] = (instance[i] - mean[i]) / stdDev[i];
            //cout << "instance: " << instance[i] << endl;
        }

    }   
    cout << "normalizing function" << endl;
}