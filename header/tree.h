#ifndef TREE_H
#define TREE_H

#include <unordered_map>
#include "node.h"
#include <iostream>

using std::unordered_map;
using std::string;

class Tree {
    private:
        Validate validator;
        unordered_map<string,Node*> umap;   // hashmap probably here where string = feature combo and Node* = address of that node if it already exists
        vector<int> feats; // vec to hold actual features        
        Node *curNode;
        int numFeatures;    // Total number of features.
        int numInstances;
        int searchType;
        
    public:
        Tree(int, vector<vector<float>>);
        ~Tree();
        float genVal(); // Randomly generate node percent.
        void fillTree(string);    // Create tree.
        void printTree();   // Print tree.
        void search();   // Perform search.
        float getStrtPrcnt();   // Return start node percent.
};


#endif