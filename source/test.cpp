#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <ctime> 
using namespace std; 
using std::vector;

vector<int> add();
int main() 
{ 
    srand(time(0)); 
    int *a;
    int x = 3;
    a = &x;
    //cout << a;
    vector<int> ve = add();
    vector<int> yy = ve;
   // for (int i = 0; i < yy.size(); i++) {
     //   cout << yy[i] << " ";
    //
    string nnx = "ab";
    nnx.pop_back();
    cout << nnx;
    
  
    return 0; 
}

vector<int> add() {
    vector<int> b;
    for (int i = 0; i < 5; i++)
        b.push_back(i);
    return b;
}