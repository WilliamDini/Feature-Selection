#ifndef NODE_H
#define NODE_H

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;

class Node {
    private:
        float prcnt;    // Value assigned to feature.
        string feature; // The actual feature.
        vector<Node*> children;   // Vec to hold children nodes of current node.
        vector<Node*> parent;   // Vec to hold parent nodes of current node.
        unordered_set<int> checkNums;    // hashset to determine which features are in this combo.
        vector<int> numsUsed;   // Vector store used numbers for sorting.
    public:
        Node();
        Node(float,string);
        string getFeat();   // Return the string feature label of current node.
        float getPrcnt();   // Return current nodes percent.
        void addChild(Node*,Node*);     // Set node as child to current node.
        vector<Node*> getChildren();    // Return children vec.
        vector<int> getNums();  // Return numsUsed vec.
        bool checkUsedNums(int);    // Check if an int is present in current node's checkNums.
        void setNums(vector<int>);  // Insert values into checkNums and numsUsed.
        Node* findMax(int);     // Find child node with highest percent of current node. 



        // maybe hashmap (instead of vec) with key being the feature like "123" and then val being the address of that node
        // this way we have access to all nodes for repeating nodes when needed
        // have vec of all features, 1-4 in pdf ex, and then iterate through for each node checking if ith feature is apart
        // of curr node (feature). i.e if curr feature is '123' and we are on feature 3 in vec, we check if 3 is apart of this feature
        // it is since '123' and we keep '1' '2' '3' in numUsed to check. Then sort and convert to string and make insert that

};

#endif