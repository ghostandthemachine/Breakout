#include "filter.h"

Filter::~Filter() {

}

void Filter::remove() {
  
}

void Filter::remove(Node* node) {
  // this->child = NULL;
}

void Filter::setChild(Node* child) {
  this->child = child;
}

Node* Filter::getChild() {
  return this->child;
}

