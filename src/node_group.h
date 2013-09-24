
// #include "node.cpp"

#include <set>

using std::set;

class NodeGroup: public Node {
  
  public:
    NodeGroup();
    ~NodeGroup();

    set<Node*>* getChildren();

    void add(Node* child);
    void add(Node* child, int index);
    
    void remove(Node* child, int index);
    void remove(Node* child);

    void printChildren();

  private:
    set<Node*>* children;
  
};