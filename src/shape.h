/* shape.h
 *
 * Base class for geometric objects.
 */

#ifndef SHAPE_H
#define SHAPE_H

 #include "node.h"

class Shape : public Node {
  private:

    // common state variables

  public:
    Shape();
    virtual ~Shape();

    /*
       Pure virtual function to display the Shape. Classes
       inheriting from Shape need to provide a definition
       for display().
    */
    virtual void render() = 0;

    // setters, getters, common behaviors
};

#endif
