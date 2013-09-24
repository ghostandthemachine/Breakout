#include "brick.h"

point4 Brick::brick_vertices[8] = {
  point4(-0.5, -0.5,  0.5, 1.0),
  point4(-0.5,  0.5,  0.5, 1.0),
  point4(0.5,  0.5,  0.5, 1.0),
  point4(0.5, -0.5,  0.5, 1.0),
  point4(-0.5, -0.5, -0.5, 1.0),
  point4(-0.5,  0.5, -0.5, 1.0),
  point4(0.5,  0.5, -0.5, 1.0),
  point4(0.5, -0.5, -0.5, 1.0)
};

// RGBA olors
color4 Brick::brick_vertex_colors[8] = {
  color4(0.0, 0.0, 0.0, 1.0),  // black
  color4(1.0, 0.0, 0.0, 1.0),  // red
  color4(1.0, 1.0, 0.0, 1.0),  // yellow
  color4(0.0, 1.0, 0.0, 1.0),  // green
  color4(0.0, 0.0, 1.0, 1.0),  // blue
  color4(1.0, 0.0, 1.0, 1.0),  // magenta
  color4(1.0, 1.0, 1.0, 1.0),  // white
  color4(0.0, 1.0, 1.0, 1.0)   // cyan
};

void Brick::quad(int a, int b, int c, int d) {
  Brick::brick_colors.push_back(Brick::brick_vertex_colors[a]);
  Brick::brick_points.push_back(Brick::brick_vertices[a]);
  
  Brick::brick_colors.push_back(Brick::brick_vertex_colors[b]);
  Brick::brick_points.push_back(Brick::brick_vertices[b]);
  
  Brick::brick_colors.push_back(Brick::brick_vertex_colors[c]);
  Brick::brick_points.push_back(Brick::brick_vertices[c]);
  
  Brick::brick_colors.push_back(Brick::brick_vertex_colors[a]);
  Brick::brick_points.push_back(Brick::brick_vertices[a]);
  
  Brick::brick_colors.push_back(Brick::brick_vertex_colors[c]);
  Brick::brick_points.push_back(Brick::brick_vertices[c]);
  
  Brick::brick_colors.push_back(Brick::brick_vertex_colors[d]);
  Brick::brick_points.push_back(Brick::brick_vertices[d]);
}


Brick::Brick() {
  translation = vec3(0.0, 0.0, 0.0);
}

Brick::Brick(float x, float y, float z) {
  translation = vec3(x, y, z);
}

Brick::~Brick() {

}

void Brick::display() {
  // Pass the translation to the vertex buffer
  // The handle is referring to the VAO for this class of object
  // position is some vec2 representing the x,y of this object
  // glUniform2fv(some_uniform_handle, &this->position); // or use
  // glUniform2f(some_uniform_handle, this->x, this->y); 
  // if you just want to store an x and y
  glDrawArrays(GL_TRIANGLES, 0, 6);
}