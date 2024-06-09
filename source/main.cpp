#include "../header/classify.h"
#include "../header/node.h"
#include "../header/tree.h"
#include "../header/validate.h"
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include <cstdlib>
using namespace std;

const float HUNDO = 100.0;

void print(vector<vector<float> > x) {
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


  int instances = 0;
  int feat;
  vector<vector<float> > dataSet;
  while(getline(inFS, line)) {
    instances++;
    istringstream stream(line);
    vector<float> temp;
    stream >> classNum;
    temp.push_back(classNum);
    feat = 0;
    while(stream >> featNum) {
      feat++;
      temp.push_back(featNum);
    }
    features = feat;
    // dataSet.push_back(dataPoint);
    dataSet.push_back(temp);
    temp.clear();
  }

  // cout << dataSet.dataSetSize() << endl;
  // dataSet.print();
  // cout << endl;
  inFS.close();

  // cout << "Enter 1 for default features, or 2 to enter your own.\n";
  // cin >> features;

  //cout << "This dataset has " << feat << " features (not including the class attribute), with " << instances << " instances." << endl << endl;

  
  //for testing purposes, should not go here for final product
  // Validate validator;
  // validator.initialize(dataSet);
  // cout << "\n\n\naccuracy: " << validator.leaveOneOut("1 15 27") << "\n\n\n"; 


  bool done = false;
  while(!done) {
    cout << "Type the number of the alorithm you want to run." << endl << endl;

    cout << "Forward Selection\n"
        << "Backward Eliminatio\n"
        << "Drizzay's Special Algorithm (Nearest Neighbor)" << endl << endl << endl;
    cin >> algorNumIn;
    switch(algorNumIn) {
    case 1:
      done = true;
      solve = new Tree(1, dataSet);
      break;
    case 2:
      done = true;
      solve = new Tree(2, dataSet);
      break;
    case 3:
      cout << "Drizzay's Special Algorithm is not done :( please select a different algorithm.\n\n)";
      break;
    default:
      cout << "Please enter 1-3.\n\n";
  }
  }
  

  return 0;
}