#include "node_group.h"
#include "node.h"

#include <iostream>
#include <assert.h> 

#ifndef NODEGROUP_H
#define NODEGROUP_H

NodeGroup::NodeGroup() {
  this->children = new set<Node*>();
}

NodeGroup::~NodeGroup() {
  delete this->children;
}

set<Node*>* NodeGroup::getChildren() {
  return this->children;
}

void NodeGroup::add(Node* child) {
  children->insert(child);
  child->setParent(this);
}

// void NodeGroup::add(Node* child, int index) {
//   children->insert(children->begin() + index, child);
// }

// void NodeGroup::remove(Node* child, int index) {
//   // children->erase(children->begin() + index, child);
// }

void NodeGroup::remove(Node* node) {
  std::set<Node*>::iterator child = children->find(node);
  // child->deleteParent();
  children->erase(child);
}

void NodeGroup::printChildren() {
  std::cout << "Child set: " << std::endl;
  for (std::set<Node*>::iterator it = children->begin(); it != children->end(); ++it) {
    std::cout << " " << &*it << " " << *it << std::endl;
  }
  std::cout << std::endl;
}

#endif