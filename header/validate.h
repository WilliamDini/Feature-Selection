#ifndef VALIDATE
#define VALIDATE
#include "../header/classify.h"

using namespace std;

class Validate {
    private:
        Classifier classifier;
        vector<int> instances;
        int numInstances;
        int numFeatures;
    public:
        Validate();
        void initialize(vector<vector<float> >);
        void insertData(Classifier);
        int dataSetSize();
        void print();
        vector<vector<float> > seperateData(int, int);
        void normalize(vector<vector<float> > &);
        int getNumFeatures();
        float leaveOneOut(string);
};

#endif

