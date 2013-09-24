#ifndef TRANSFORMATION
#include "transformation.cpp"
#endif

#ifndef TRANSFORMATION_CPP
#include "transformation.cpp"
#endif

#ifndef GLEW_H
#include <GL/glew.h>
#endif

class Scale : public Transformation {
  private:
    Vec3f scale;
  
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


float Scale::getScaleX() {
  return this->scale.x;
}

float Scale::getScaleY() {
  return this->scale.y;
}

float Scale::getScaleZ() {
  return this->scale.z;
}

float Scale::setScaleX(float x) {
  this->scale.x = x;
  return this->scale.x;
}

float Scale::setScaleY(float y) {
  this->scale.y = y;
  return this->scale.y;
}

float Scale::setScaleZ(float z) {
  this->scale.z = z;
  return this->scale.z;
}

void Scale::setScale(float x, float y) {
  this->scale.x = x;
  this->scale.y = y;
}

void Scale::setScale(float x, float y, float z) {
  this->scale.x = x;
  this->scale.y = y;
  this->scale.z = z;
}

void Scale::render() {
  glScalef(this->scale.x,
           this->scale.y,
           this->scale.z)
}