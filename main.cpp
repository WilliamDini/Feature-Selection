#include <iostream>

using namespace std;

const float HUNDO = 100.0;

double evaluationFunc() {
  return static_cast<double>((rand() % 100));
}

int main() {
  int features, algorNumIn;
  float accuracyPerc = 0.0;

  cout << "Welcome to Drizzay's Feature Selection Algorithm" << endl << endl;
  cout << "Please enter the total number of features: ";
  cin >> features;
  cout << endl;

  cout << "Type the number of the algorithm you want to run.\n\n"
       << "\tFoward Selection\n"
       << "\tBackward Elimination\n"
       << "\tBertie's Special Algorithm\n\n" << endl;
  cin >> algorNumIn;
  cout << endl;

  accuracyPerc = evaluationFunc();

  cout << "Using no features and \"random\" evaluation, I get the accuracy of " << accuracyPerc << "%" << endl << endl;
  cout << "Beginning Search." << endl << endl;



  return 0;
}
