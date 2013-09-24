#include "transformation.cpp"

#ifndef GLEW_H
#include <GL/glew.h>
#endif

class Rotate : public Transformation {
  private:
    Vec3f rotate;
  
  public:
    float getX();
    float getY();
    float getZ();
    
    float setX(float x);
    float setY(float y);
    float setZ(float z);

    void translate(float x, float y);
    void translate(float x, float y, float z);

    virtual void render();
};


float Rotate::getRotateX() {
  return this->rotate.x;
}

float Rotate::getRotateY() {
  return this->rotate.y;
}

float Rotate::getRotateZ() {
  return this->rotate.z;
}

float Rotate::setRotateX(float x) {
  this->rotate.x = x;
  return this->rotate.x;
}

float Rotate::setRotateY(float y) {
  this->rotate.y = y;
  return this->rotate.y;
}

float Rotate::setRotateZ(float z) {
  this->rotate.z = z;
  return this->rotate.z;
}

void Rotate::setRotate(float x, float y) {
  this->rotate.x = x;
  this->rotate.y = y;
}

void Rotate::setRotate(float x, float y, float z) {
  this->rotate.x = x;
  this->rotate.y = y;
  this->rotate.z = z;
}

void Rotate::render() {
  glRotatef(this->rotate.x,
           this->rotate.y,
           this->rotate.z)
}

void Rotate::render() {
  glRotatef(this->rotate.x,
            this->rotate.y,
            this->rotate.z)
}