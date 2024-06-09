#include "../header/tree.h"
#include "../header/node.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <cmath>
#include <algorithm>

using std::to_string;
using std::queue;
using std::cout;

Tree::Tree(int searchType, vector<vector<float>> data) {
    validator.initialize(data);
    cout << "\n\n\n Populating tree, please wait...";
    float srtVal = -1;
    curNode = new Node(srtVal,"Z");
    numFeatures = data[0].size();
    numInstances = data.size();
    this->searchType = searchType;
    if(searchType == 1) {
        for (int i = 1; i < data[0].size(); i++) {
            string fet = to_string(i);  // Rest of loop from here is for creating the first n nodes. Here the "label" is made.
            float val = validator.leaveOneOut(fet);   // Rand gen each curNodeing nodes value.
            Node *temp = new Node(val,fet);     // Create the node.
            curNode->addChild(temp,nullptr);  // Adding all created n nodes as options for the curNodeing node.
        }
    }
    else {
        for (int i = 0; i < numFeatures; i++) {
            string fet = "";
            for(int j = 0; j < numFeatures; j++) {
                if (i == j) { continue; }
                fet += to_string(j) + ",";
            }
            fet.pop_back();        
            float val = validator.leaveOneOut(fet);   // generate accuracies for first layer of tree now
            Node *temp = new Node(val,fet);     // Create the node.
            curNode->addChild(temp,nullptr);  // Adding all created n nodes as options for the starting node.
        }   
    }
    cout << "Done. \n\n";
    this->search();
}


Tree::~Tree() {
    delete curNode;
    for (auto x: umap) delete x.second;
}

// Return curNode node percent.
float Tree::getStrtPrcnt() {
    return curNode->getPrcnt();   
}

// Randomly generate percentages for phase 1.
float Tree::genVal() {
    float a = 0;
    for (int i = 0; i < 100; i++)
        a = rand() % 45 + 30;
    return a/100 * 107.0;
}
int counter = 0;
// Perform forward/backward search based on x value.
void Tree::search() {
    Node *temp = curNode;
    Node *maxAcc = curNode;    // Node pointer to record node with highest percent.
    float max = maxAcc->getPrcnt();  // Actual percent of maxAcc node.
    string dispFt = ""; // String to display trace easier.
    bool stopSearch = false;  
    curNode = curNode->findMax(searchType);    // Determines which child/parent of current node to pursue.
    if(curNode->getPrcnt() < maxAcc->getPrcnt()){
        cout << "Warning: accuracy has descreased! Stopping search...\n The best feature subset is {" << maxAcc->getFeat() << "}, which has an accuracy of ";
        cout << maxAcc->getPrcnt() << "%.\n";
    }
    else {
        fillTree(curNode->getFeat());
    }
}

// Creates tree.
void Tree::fillTree(string features) {
    //im really not a fan of how I implemented this (everything down to the if stmt) - couldn't think of a better way to alter the set of
    //features without first turning it into a vector of ints, before immediately switching it back to string. I've been at this for way
    //too long already and if it works it works but if you know of a better / less ugly way of doing this pretty please implement it 🙏 
    cout << "Populating next layer of tree, please wait.....";
    vector<int> feats;
    string tempString;
    stringstream ss(features);
    vector<string> featureVector;
    while(getline(ss, tempString, ',')) {
        featureVector.push_back(tempString);
    };
    for(int i = 0; i < featureVector.size(); i++) {
        feats.push_back(stoi(featureVector[i]));
    };
    vector<int> originalFeats = feats;
    //forward selection case
    if (searchType == 1) {
        for(int i = 1; i < numFeatures; i++) {
            if(find(originalFeats.begin(), originalFeats.end(), i) == originalFeats.end()) {
                feats.push_back(i);
                sort(feats.begin(), feats.end());
                string fet = curNode->getFeat();
                fet = fet + "," + to_string(i);
                float percent = validator.leaveOneOut(fet);
                Node *temp = new Node(percent, fet); 
                curNode->addChild(temp, curNode);
                feats = originalFeats;
            }
        }
    }
    else {
        for(int i = 0; i < originalFeats.size(); i++) {
            vector<int> tempVec;
            for(int j = 0; j < originalFeats.size(); j++) {
                if (i == j) { continue; }
                tempVec.push_back(originalFeats[j]);
            }
                string fet = "";
                for(int j = 0; j < tempVec.size(); j++) {
                    fet += to_string(tempVec[j]) + ",";
                }
                fet.pop_back();  
                float percent = validator.leaveOneOut(fet);
                Node *temp = new Node(percent, fet); 
                curNode->addChild(temp, curNode);
        }
    }
    cout << "Done.\n\n";
    this->search();
}

// Print tree
void Tree::printTree() {
    for (auto x: umap) {
        cout << x.second->getFeat() << "\n"; 
    }
}