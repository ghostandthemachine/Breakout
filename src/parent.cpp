#include "node_group.h"

Parent::Parent() {
  this->children = new set<Node*>();
}

Parent::~Parent() {
  delete this->children;
}

set<Node*>* Parent::getChildren() {
  return this->children;
}

void Parent::remove(Node* node) {
  std::set<Node*>::iterator child = children->find(node);
  // child->deleteParent();
  children->erase(child);
}