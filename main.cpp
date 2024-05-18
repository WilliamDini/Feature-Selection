#include <iostream>

using namespace std;

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

  cout << "Using no features and \"random\" evaluation, I get the accuracy of " << accuracyPerc << "%" << endl << endl;

  cout << "Beginning Search." << endl << endl;



  return 0;
}
