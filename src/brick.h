#ifndef BRICK_H
#define BRICK_H

#include "geometry.h"
#include <vector>

typedef Angel::vec4 color4;
typedef Angel::vec4 point4;

class Brick : public Geometry {

  public:
    // // Basic quad points    
    static point4 brick_vertices[8];
    // // Basic colors
    static color4 brick_vertex_colors[8];

    static std::vector<point4> brick_points;
    static std::vector<color4> brick_colors;

    static void quad(int a, int b, int c, int d);



};

#endif