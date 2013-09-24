#include "transformation.cpp"

#ifndef GLEW_H
#include <GL/glew.h>
#endif

class Translate : public Transformation {
  
  private:
    Vec3f translate;
  
  public:
    float getX();
    float getY();
    float getZ();
    
    float setX(float x);
    float setY(float y);
    float setZ(float z);

    void setTranslate(float x, float y);
    void setTranslate(float x, float y, float z);

    virtual void render();
};


float Translate::getX() {
  return this->translate.x;
}

float Translate::getY() {
  return this->translate.y;
}

float Translate::getZ() {
  return this->translate.z;
}

float Translate::setX(float x) {
  this->translate.x = x;
  return this->translate.x;
}

float Translate::setY(float y) {
  this->translate.y = y;
  return this->translate.y;
}

float Translate::setZ(float z) {
  this->translate.z = z;
  return this->translate.z;
}

void Translate::setTranslate(float x, float y) {
  this->translate.x = x;
  this->translate.y = y;
}

void Translate::setTranslate(float x, float y, float z) {
  this->translate.x = x;
  this->translate.y = y;
  this->translate.z = z;
}

void Translate::render() {
  glTranslatef(this->translate.x,
               this->translate.y,
               this->translate.z);
}