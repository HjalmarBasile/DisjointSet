//
//  Node.hpp
//  DisjointSet
//
//  Created by Hjalmar Basile on 14/02/2017.
//  Copyright © 2017 Hjalmar Basile. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <iostream>

class Node {
    private:
        int data;
        int rank;    
        Node* parent;
    
    public:
        // Constructors
        Node();
        Node(int);
    
        // Getters
        int getData();
        int getRank();
        Node* getParent();
        int getParentData();
    
        // Setters
        void setParent(Node*);
        void increaseRank();
    
        // Output utilities
        void printData();
        void printRank();
        void printParentData();
        void printAll();
};

#endif /* Node_hpp */

