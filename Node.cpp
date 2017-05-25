//
//  Node.cpp
//  DisjointSet
//
//  Created by Hjalmar Basile on 14/02/2017.
//  Copyright © 2017 Hjalmar Basile. All rights reserved.
//

#include "Node.hpp"


// Constructors

Node::Node() {
    data = -1;
    rank = 0;
    parent = this;
}

Node::Node(int d) {
    data = d;
    rank = 0;
    parent = this;
}



// Getters

int Node::getData() {
    return data;
}

int Node::getRank() {
    return rank;
}

Node* Node::getParent() {
    return parent;
}

int Node::getParentData() {
    return parent->getData();
}



// Setters

void Node::setParent(Node* p) {
    parent = p;
}

void Node::increaseRank() {
    rank++;
}



// Output utilities

void Node::printData() {
    std::cout << "Data: " << data << std::endl;
}

void Node::printRank() {
    std::cout << "Rank: " << rank << std::endl;
}

void Node::printParentData() {
    std::cout << "Parent data: " << parent->getData() << std::endl;
}

void Node::printAll() {
    std::cout << "Node info -->" << std::endl;
    printData();
    printRank();
    printParentData();
    std::cout << std::endl;
}

