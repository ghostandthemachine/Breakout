#include "node.h"

// Constructors

Node::Node() {
}

Node* Node::getParent() {
  return this->parent;
}

void Node::setParent(Node* parent) {
  this->parent = parent;
}

void Node::deleteParent() {
  // this->parent = NULL;
}

void Node::setVisible(bool visible) {
  this->visible = visible;
}

bool Node::isVisible() {
  return this->visible;
}

int Node::getId() {
  return this->id;
}