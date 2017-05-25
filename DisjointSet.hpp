//
//  DisjointSet.hpp
//  DisjointSet
//
//  Created by Hjalmar Basile on 14/02/2017.
//  Copyright © 2017 Hjalmar Basile. All rights reserved.
//

#ifndef DisjointSet_hpp
#define DisjointSet_hpp

#include <unordered_map>
#include "Node.hpp"

class DisjointSet {
    private:
        std::unordered_map<int, Node*>* data_node_hashmap;
    
        // Helper methods
        Node* findSet(Node*);
    
    public:
        // Constructor & Destructor
        DisjointSet();
        ~DisjointSet();
    
        // Core methods
        void makeSet(int);
        int findSet(int);
        bool setsUnion(int, int);
};


#endif /* DisjointSet_hpp */
