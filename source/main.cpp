#include <cstdlib> 
#include <iostream> 
#include <time.h> 
#include "../header/node.h"
#include "../header/tree.h"


using namespace std;

const float HUNDO = 100.0;

double evaluationFunc() {
  return static_cast<double>((rand() % 100));
}

int main() {
  srand(time(0)); 
  int features, algorNumIn;
  //float accuracyPerc = 0.0;
  Tree *solve;

  cout << "Welcome to Drizzay's Feature Selection Algorithm" << endl << endl;
  cout << "Enter 1 for default features, or 2 to enter your own.\n";
  cin >> features;
  if (features == 1) {
    solve = new Tree();
  }
  else if (features == 2) {
    int numF = 0;
    cout << "Features will be represented by integers, i.e '1','2','3'...\n"
         << "Please enter total number of features:\n";
    cin  >> numF;
    solve = new Tree(numF);
  }
  solve->fillTree();
  cout << "Enter 1 for forward selection, 2 for backward elimination\n";
  int srch;
  cin >> srch;
  cout << "Using no features and \"random\" evaluation, I get the accuracy of " << solve->getStrtPrcnt() << "%\n\n"
       << "Beginning search\n\n";
  solve->search(srch);
  delete solve;



  return 0;
}
