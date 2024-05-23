#ifndef TREE_H
#define TREE_H

#include <unordered_map>
#include "node.h"
#include <iostream>

using std::unordered_map;
using std::string;

class Tree {
    private:
        unordered_map<string,Node*> umap;   // hashmap probably here where string = feature combo and Node* = address of that node if it already exists
        vector<int> feats; // vec to hold actual features        
        Node *start; // Starting node
        Node *tail; // Pointer to last feature.
        int numFeatures;    // Total number of features.
    public:
        Tree();
        Tree(int);
        ~Tree();
        float genVal(); // Randomly generate node percent.
        void fillTree();    // Create tree.
        void printTree();   // Print tree.
        void search(int);   // Perform search.
        float getStrtPrcnt();   // Return start node percent.
};


#endif