
class Filter : public Parent {
  
  private:
    Node* child;

  public:

    void remove();

    void remove(Node* node);
    void setChild(Node* child);
    Node* getChild();
};