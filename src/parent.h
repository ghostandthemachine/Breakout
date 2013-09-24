class Parent : public Node {
  private:
    set<Node*>* children;
  public:
    set<Node*>* getChildren();
    void Parent::remove(Node* node);
};