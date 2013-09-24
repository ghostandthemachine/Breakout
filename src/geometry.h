/* Geometry.h
 *
 * Base class for geometric objects.
 */

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Angel.h"

typedef Angel::vec3 point3;

class Geometry {
  private:

  public:
    Geometry();
    virtual ~Geometry();

    virtual void display() = 0;
    virtual void init() = 0;

    point3 translation;
};

#endif


