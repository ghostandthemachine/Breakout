/* node.h
 *
 * Base node class for scene graph objects
 * 
 */


#ifndef NODE_H
#define NODE_H


class Node {
    
  private:
    // Parent
    Node* parent;

    // picking id
    int id;

    // Visibility
    bool visible;

  public:
    Node();

    void setParent(Node* parent);
    Node* getParent();

    void deleteParent();

    void setVisible(bool visible);
    bool isVisible();

    int getId();
};

#endif