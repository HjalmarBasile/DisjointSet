//
//  DisjointSet.cpp
//  DisjointSet
//
//  Created by Hjalmar Basile on 14/02/2017.
//  Copyright © 2017 Hjalmar Basile. All rights reserved.
//

#include "DisjointSet.hpp"


// Helper methods

/**
 * Finds the representative recursively
 * and does path compression as well
 */
Node* DisjointSet::findSet(Node* node) {
    Node* p = node->getParent();
    
    if(p == node)
        return p;
    // else
    node->setParent(findSet(p));
    return node->getParent();
}



// Constructor & Destructor

DisjointSet::DisjointSet() {
    data_node_hashmap = new std::unordered_map<int, Node*>();
}

DisjointSet::~DisjointSet() {
    delete data_node_hashmap;
}



// Core methods

/**
 * Creates a set with only one element
 */
void DisjointSet::makeSet(int d) {
    Node* node = new Node(d);
    data_node_hashmap->insert({d, node});
}


/**
 * Finds the representative of the set containing d
 */
int DisjointSet::findSet(int d) {
    Node* node = (*data_node_hashmap)[d];
    return findSet(node)->getData();
}


/**
 * Combines two sets together to one (using union by rank)
 *
 * @returns true iff d1 and d2 are in different sets before the union method call
 */
bool DisjointSet::setsUnion(int d1, int d2) {
    Node* node1 = (*data_node_hashmap)[d1];
    Node* node2 = (*data_node_hashmap)[d2];

    Node* parent1 = findSet(node1);
    Node* parent2 = findSet(node2);
    
    if(parent1 == parent2)
        return false;
    // else
    
    int rank1 = parent1->getRank();
    int rank2 = parent2->getRank();
    if(rank1 < rank2) {
        parent1->setParent(parent2);
    } else if (rank2 < rank1) {
        parent2->setParent(parent1);
    } else {
        if(d1 > d2) {
            parent1->setParent(parent2);
            parent2->increaseRank();
        } else {
            parent2->setParent(parent1);
            parent1->increaseRank();
        }
    }
    return true;
}

