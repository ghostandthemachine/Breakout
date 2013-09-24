/* scene.h
 *
 * Maintains Scene information
 *
 */

#ifndef SCENE_H
#define SCENE_H

#include "Angel.h"

class Scene {
  

  public:

    Scene();
    ~Scene();

    void init(GLuint program);

    GLuint v_position;
    GLuint v_color;

};

#endif
