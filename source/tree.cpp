#include "../header/tree.h"
#include "../header/node.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using std::to_string;
using std::queue;
using std::cout;

Tree::Tree() {
    float srtVal = genVal();
    start = new Node(srtVal,"Z");
    for (int i = 1; i < 5; i++) {
        feats.push_back(i);     // Pushing onto vector that will hold features, i.e. 1,2,3...n.
        string fet = to_string(i);  // Rest of loop from here is for creating the first n nodes. Here the "label" is made.
        float val = genVal();   // Rand gen each starting nodes value.
        Node *temp = new Node(val,fet);     // Create the node.
        temp->setNums({i});
        umap[fet] = temp;   // Insert node into map => [string_feature_label] = node_address.
        start->addChild(temp,nullptr);  // Adding all created n nodes as options for the starting node.
    }
}

Tree::Tree(int numFeats) {
    float srtVal = genVal();
    start = new Node(srtVal,"Z");
    for (int i = 1; i < numFeats+1; i++) {
        feats.push_back(i);     // Pushing onto vector that will hold features, i.e. 1,2,3...n.
        string fet = to_string(i);  // Rest of loop from here is for creating the first n nodes. Here the "label" is made.
        float val = genVal();   // Rand gen each starting nodes value.
        Node *temp = new Node(val,fet);     // Create the node.
        temp->setNums({i});
        umap[fet] = temp;   // Insert node into map => [string_feature_label] = node_address.
        start->addChild(temp,nullptr);  // Adding all created n nodes as options for the starting node.
    }
}

Tree::~Tree() {
    delete start;
    for (auto x: umap) delete x.second;
}

// Return start node percent.
float Tree::getStrtPrcnt() {
    return start->getPrcnt();   
}

// Randomly generate percentages for phase 1.
float Tree::genVal() {
    float a = 0;
    for (int i = 0; i < 100; i++)
        a = rand() % 45 + 30;
    return a/100 * 107.0;
}

// Perform forward/backward search based on x value.
void Tree::search(int x) {
    Node *temp = (x == 1)? start : tail;    // Determines what search to perform. 1 = forward, 2 = backward.
    Node *maxAcc = temp;    // Node pointer to record node with highest percent.
    float max = 0;  // Actual percent of maxAcc node.
    string dispFt = ""; // String to display trace easier.
    while (temp != nullptr) {   
        temp = temp->findMax(x);    // Determines which child/parent of current node to pursue.
        if (temp == nullptr) continue;  // End of loop
        if (temp->getPrcnt() > maxAcc->getPrcnt()) maxAcc = temp;   // Record max node.
        if (temp->getPrcnt() < max) cout << "WARNING: Accuracy has decreased!\n";   // Display decrease warning.
        max = temp->getPrcnt(); // Set max value.
    }
    cout << "\nFinished search!! The best feature subset was {";
    for (int j = 0; j < maxAcc->getFeat().length(); j++) {  // Display max node feature combo with commas.
            cout << maxAcc->getFeat()[j];
            if (j < maxAcc->getFeat().length()-1) cout << ",";
    }
    cout << "}, which has an accuracy of " << maxAcc->getPrcnt() << "%";
}

// Creates tree.
void Tree::fillTree() {
    queue<Node*> nodeQ; // Queue to hold all nodes still needing expansion.
    ///////// LOOP HERE
    vector<Node*> nodes = start->getChildren(); // Pointer to start.
    for (int i = 0; i < nodes.size(); i++) nodeQ.push(nodes[i]);    // Push all children of start node onto queue.
    while (!(nodeQ.empty())) {  // Begin creating tree.
        if (nodeQ.size() == 1) tail = nodeQ.front();    //  When final node is made, set tail equal to it for backward search.
        Node *temp = nodeQ.front(); // Get front node from queue.
        nodeQ.pop();
        for (int i = 0; i < feats.size(); i++) {    // Iterates through all individual features stored in feats vec.
            if (temp->checkUsedNums(feats[i])) continue;   // This feature is already present in this nodes label.          
            string unmodFeat = temp->getFeat() + to_string(feats[i]);  // Gets curr nodes label.
            vector<int> featCombo = temp->getNums();
            featCombo.push_back(feats[i]);     // Insert current ith feature into featCombo
            sort(featCombo.begin(), featCombo.end());   // Sort featCombo to get ordered version of label features for future comparison. i.e turn "213" or "132" into "123".
            string modFeat = "";
            for (int j = 0; j < featCombo.size(); j++) {    // Iterate through sorted featCombo to convert ordered features into string.
                modFeat += to_string(featCombo[j]);     // String to hold sorted features in featCombo.
            }
            if (umap.count(modFeat)) {  // Check if this ordered feature has already been seen.
                temp->addChild(umap[modFeat],temp);   // If it has, find the node it belongs to and assign it as child to current node.
            }
            else {  // If it hasnt, create new node with unsorted feature string for actual unique label.  
                float tempVal = genVal();   //  Gen new val for new child node.
                Node *newNode = new Node(tempVal,unmodFeat);    // Make new child node.
                newNode->setNums(featCombo);    // Record individual features used to make this feature combo.
                temp->addChild(newNode,temp);   // Set newly created node as child of current node.
                umap[modFeat] = newNode;    // Insert newly created node into umap.
                nodeQ.push(newNode);    // Push new child node onto queue for later expansion.
            }   
        }
    }
}

// Print tree
void Tree::printTree() {
    for (auto x: umap) {
        cout << x.second->getFeat() << "\n"; 
    }
}