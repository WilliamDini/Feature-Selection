#include "../header/validate.h"
#include "../header/classify.h"

void Validate::insertData(Classifier x) { this->Train.push_back(x); }

int Validate::dataSetSize() { return this->Train.size(); }

// void Validate::print() {
//     for(int i = 0; i < this->Train.size(); i++) {
//         int cnt = 0;
//         cout << "[" << i + 1 << "]Class ID: " << Train.at(i).getClassNum() << endl;
//         for(int j = 0; j < Train.at(i).featSize(); ++j) {
//             cnt++;
//             cout << "[" << j + 1 << "] " << Train.at(i).getfeatNum(j) << " ";
//             if(cnt > 4) {
//                 cnt = 0;
//                 cout << "\n";
//             }
//         }
//         cout << endl;
//     }
// }
