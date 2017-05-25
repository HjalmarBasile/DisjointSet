//
//  main.cpp
//  DisjointSet
//
//  Created by Hjalmar Basile on 14/02/2017.
//  Copyright © 2017 Hjalmar Basile. All rights reserved.
//
// Implementation of Disjoint Sets using path compression and union by rank
// (search YouTube lesson by Tushar Roy for a detailed tutorial)
//
// Time complexity: O(m), where m is the number of operations
//


#include <iostream>
#include "DisjointSet.hpp"

int main() {
    DisjointSet* ds = new DisjointSet();
    
    for(int i = 1; i <= 10; i++) {
        ds->makeSet(i);
    }

    
    
    ds->setsUnion(1, 2);
    ds->setsUnion(5, 2);
    ds->setsUnion(4, 2);
    ds->setsUnion(5, 6);
    ds->setsUnion(5, 1);
    
    ds->setsUnion(3, 7);
    
    ds->setsUnion(8, 9);
    
    
    
    for(int i = 1; i <= 10; i++) {
        std::cout << ds->findSet(i) << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}
