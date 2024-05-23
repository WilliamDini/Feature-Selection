#include <iostream>
#include "../header/node.h"

using std::cout;

Node::Node(float f, string s) {
    prcnt = f;
    feature = s;
}


void Node::addChild(Node *child, Node *par) {
    children.push_back(child);
    child->parent.push_back(par);
}

vector<Node*> Node::getChildren() {
    return children;
}

bool Node::checkUsedNums(int i) {
    if (checkNums.count(i)) return true;
    return false;
}

vector<int> Node::getNums() {
    return numsUsed;
}

string Node::getFeat() {
    return feature;
}

void Node::setNums(vector<int> vec) {
    numsUsed = vec;
    for (int i = 0; i < numsUsed.size(); i++) checkNums.insert(numsUsed[i]);
}

float Node::getPrcnt() {
    return prcnt;
}

Node* Node::findMax(int x) {
    string f = "", tempMax = "";
    float max = 0;
    Node *temp = nullptr;
    string dispFt;
    vector<Node*> tempVec = (x == 1)? children : parent; 
    if (tempVec.size() == 0 or tempVec[0] == nullptr) return nullptr;
    for (int i = 0; i < tempVec.size(); i++) {
        dispFt = "";
        cout << "            Using feature(s) {";
        f = tempVec[i]->getFeat();
        for (int j = 0; j < f.length(); j++) {
            dispFt += f[j];
            if (j < f.length()-1) dispFt += ",";
        }
        cout << dispFt << "} accuracy is " << tempVec[i]->getPrcnt() << "%\n";
        if (tempVec[i]->getPrcnt() > max) {
            max = tempVec[i]->getPrcnt(); 
            temp = tempVec[i];
            tempMax = dispFt;
        }
    }
    cout << "\nFeature set {" << tempMax << "} was best, accuracy is " << temp->getPrcnt() << "%\n\n";
    return temp;
}