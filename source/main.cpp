#include <cstdlib> 
#include <iostream> 
#include <time.h> 
#include <fstream>
#include <sstream>
#include "../header/node.h"
#include "../header/tree.h"
#include "../header/classify.h"
#include "../header/validate.h"

using namespace std;

const float HUNDO = 100.0;

void print(vector<vector<float>> x) {
  for(int i = 0; i < x.size(); i++) {
    cout << "[" << i << "] = [";
    for(int j = 0; j < x.at(i).size(); j++) {
      cout << x.at(i).at(j) << ", ";
    }
    cout << "] => Size of " << x.at(i).size() << endl;
  }
}


double evaluationFunc() {
  return static_cast<double>((rand() % 100));
}

int main(int argc, char *argv[]) {

  string fileName;
  int fileType;

  srand(time(0)); 
  int features, algorNumIn;
  //float accuracyPerc = 0.0;
  Tree *solve;

  cout << "Welcome to Drizzay's Feature Selection Algorithm" << endl << endl;

  // cout << "Enter 1 for Small Data Set or 2 for Large Data Set.\n";
  cout << "Type in the name of the file to test :  ";
  cin >> fileName;
  // if(fileType == 1) {
  //   fileName = "small-test-dataset-1.txt";
  // } else {
  //   fileName = "large-test-dataset-1.txt";
  // }
  cout << endl << endl << endl;

  ifstream inFS;
  string line;
  float classNum, featNum;
  inFS.open(fileName);
  if(!inFS.is_open()) {
      cout << "ERROR: Invalid File" << endl;
      exit(1);
  }


  // Validate dataSet;
  int instances = 0;
  int feat;
  // vector<Classifier> dataSet;
  Validate dataSet;
  while(getline(inFS, line)) {
    instances++;
    istringstream stream(line);
    stream >> classNum;
    feat = 0;
    Classifier dataPoint;
    while(stream >> featNum) {
      feat++;
      dataPoint.insertFeatures(featNum);
    }
    dataPoint.setClass(classNum);
    // dataSet.push_back(dataPoint);
    dataSet.insertData(dataPoint);
  }

  vector<vector<float>> Norm = dataSet.seperateData(feat, instances);

  // cout << dataSet.dataSetSize() << endl;
  // dataSet.print();
  // cout << endl;
  // print(Norm);
  inFS.close();

  cout << "Type the number of the alorithm you want to run." << endl << endl;

  cout << "Forward Selection\n"
       << "Backward Eliminatio\n"
       << "Drizzay's Special Algorithm (Nearest Neighbor)" << endl << endl << endl;
  cin >> features;

  // cout << "Enter 1 for default features, or 2 to enter your own.\n";
  // cin >> features;

  cout << "This dataset has " << feat << " features (not including the class attribute), with " << instances << " instances." << endl << endl;
  cout << "Please wait while I normalize the data... ";

  Validate N;
  dataSet.normalize(Norm);
  


  cout << " Done!" << endl << endl;

  // if (features == 1) {
  //   solve = new Tree();
  // }
  // else if (features == 2) {
  //   int numF = 0;
  //   cout << "Features will be represented by integers, i.e '1','2','3'...\n"
  //        << "Please enter total number of features:\n";
  //   cin  >> numF;
  //   solve = new Tree(numF);
  // }
  // solve->fillTree();
  // cout << "Enter 1 for forward selection, 2 for backward elimination\n";
  // int srch;
  // cin >> srch;
  // cout << "Using no features and \"random\" evaluation, I get the accuracy of " << solve->getStrtPrcnt() << "%\n\n"
  //      << "Beginning search\n\n";
  // solve->search(srch);
  // delete solve;

  return 0;
}
