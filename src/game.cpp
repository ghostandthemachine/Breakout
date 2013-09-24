/* game.cpp
 *
 * Implementation of Game class.
 *
 */

#include "game.h"


#include "Angel.h"


typedef Angel::vec4 color4;
typedef Angel::vec4 point4;

const int NUM_VERTICES = 36; //(6 faces)(2 triangles/face)(3 vertices/triangle)

GLuint program;

point4 points[NUM_VERTICES];
color4 colors[NUM_VERTICES];

vec2 offset = vec2(0.0, 0.0);

// Vertices of a unit cube centered at origin, sides aligned with axes
point4 vertices[8] = {
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
color4 vertex_colors[8] = {
  color4(0.0, 0.0, 0.0, 1.0),  // black
  color4(1.0, 0.0, 0.0, 1.0),  // red
  color4(1.0, 1.0, 0.0, 1.0),  // yellow
  color4(0.0, 1.0, 0.0, 1.0),  // green
  color4(0.0, 0.0, 1.0, 1.0),  // blue
  color4(1.0, 0.0, 1.0, 1.0),  // magenta
  color4(1.0, 1.0, 1.0, 1.0),  // white
  color4(0.0, 1.0, 1.0, 1.0)   // cyan
};

// Array of rotation angles (in degrees) for each coordinate axis
enum {
  X_AXIS = 0,
  Y_AXIS = 1,
  Z_AXIS = 2,
  NUM_AXES = 3
};

int Axis = X_AXIS;

GLfloat Theta[NUM_AXES] = { 0.0, 0.0, 0.0 };

// GLuint theta;  // The location of the "theta" shader uniform variable

// quad generates two triangles for each face and assigns colors
//    to the vertices
int Index = 0;
void quad(int a, int b, int c, int d) {
  colors[Index] = vertex_colors[a];
  points[Index] = vertices[a];
  Index++;
  
  colors[Index] = vertex_colors[b];
  points[Index] = vertices[b];
  Index++;
  
  colors[Index] = vertex_colors[c];
  points[Index] = vertices[c];
  Index++;
  
  colors[Index] = vertex_colors[a];
  points[Index] = vertices[a];
  Index++;
  
  colors[Index] = vertex_colors[c];
  points[Index] = vertices[c];
  Index++;
  
  colors[Index] = vertex_colors[d];
  points[Index] = vertices[d];
  Index++;
}

//----------------------------------------------------------------------------

// generate 12 triangles: 36 vertices and 36 colors
void colorcube() {
  quad(1, 0, 3, 2);
  quad(2, 3, 7, 6);
  quad(3, 0, 4, 7);
  quad(6, 5, 1, 2);
  quad(4, 5, 6, 7);
  quad(5, 4, 0, 1);
}


// static initializer
Game* Game::callbackInstance(NULL);

Game::Game() {
}

Game::Game(int* argcp, char** argv) {
  init(argcp, argv);

}

Game::~Game() {
  // do any cleanup
}

void Game::init(int* argcp, char** argvp) {
  // GLUT init code here...
  glutInit(argcp, argvp);
  glutInitWindowSize(512, 512);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("Assignment 1");
}

void Game::initGame() {
  if (callbackInstance == NULL)     {
    callbackInstance = this;
  }
  colorcube();

  print_version_info();
  // Create a vertex array object
  GLuint vao;
  glGenVertexArraysAPPLE(1, &vao);
  glBindVertexArrayAPPLE(vao);

  // Create and initialize a buffer object
  GLuint buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), NULL, GL_STATIC_DRAW);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
  glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);

  // Load shaders and use the resulting shader program
  program = InitShader("vshader31.glsl", "fshader31.glsl");
  glUseProgram(program);

  // set up vertex arrays
  GLuint v_position = glGetAttribLocation(program, "v_position");
  glEnableVertexAttribArray(v_position);
  glVertexAttribPointer(v_position, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

  GLuint v_color = glGetAttribLocation(program, "v_color"); 
  glEnableVertexAttribArray(v_color);
  glVertexAttribPointer(v_color, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points)));

  // theta = glGetUniformLocation(program, "theta");

  // glUniform2fv(glGetUniformLocation(program, "offset"), 1, offset);

  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0, 1.0, 1.0, 1.0); 


  ///////////////////////////////////////////////////////////////////////////  
  // Bricks /////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////  
  // int point_size = Brick::brick_points.size();
  // int color_size = Brick::brick_colors.size();

  // GLuint brick_vbo;
  // glGenBuffers(1, &brick_vbo);
  
  // glBindBuffer(GL_ARRAY_BUFFER, brick_vbo);
  // glBufferData(GL_ARRAY_BUFFER,
  //              point_size + color_size,
  //              NULL,
  //              GL_STATIC_DRAW);

  // glBufferSubData(GL_ARRAY_BUFFER, 0, point_size, Brick::brick_points);
  // glBufferSubData(GL_ARRAY_BUFFER, point_size, color_size, Brick::brick_colors);

  // // Load shaders and use the resulting shader program
  // brick_program = InitShader("vbrick.glsl", "fbrick.glsl");
  // glUseProgram(brick_program);

///////////////////////////////////////////////////////////////////////////  


}


void idle() {
  Theta[Axis] += 0.5;
  glutPostRedisplay();
}

void Game::registerCallbacks() {
  glutDisplayFunc(displayWrapper);
  glutReshapeFunc(reshapeWrapper);
  glutKeyboardFunc(keyboardWrapper);
  glutIdleFunc(idle);
}


void Game::run() {
  initGame();
  registerCallbacks();
  glutMainLoop();
}

void Game::display() {
  GLuint theta = glGetUniformLocation(program, "theta");
  glUniform3fv(theta, 1, Theta);

  // send offset changes to shader
  GLuint location = glGetUniformLocation(program, "offset");
  glUniform2fv(location, 1, offset);
  // display code here...
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glDrawArrays(GL_TRIANGLES, 0, NUM_VERTICES);

  for(int i = 0; i < bricks.length; i++) {
    bricks[i].display();
  }

  glutSwapBuffers();
}

void Game::displayWrapper() {
  callbackInstance->display();
}

void Game::reshape(int width, int height) {
  // reshape code here...
}

void Game::reshapeWrapper(int width, int height) {
  callbackInstance->reshape(width, height);
}

void Game::keyboard(unsigned char key, int x, int y) {
  // keyboard code here...
  switch(key) {
    case 033:
        exit(EXIT_SUCCESS);
        break;
    case 'r':
       offset = vec2(0.0, 0.0);
       break;
    case 'i':
       offset += vec2(0.0, 0.2);
       break;
    case 'j':
       offset += vec2(-0.2, 0.0);
       break;
    case 'k':
       offset += vec2(0.2, 0.0);
       break;
    case 'm':
       offset += vec2(0.0, -0.2);
       break;
    }
    glutPostRedisplay();
}

void Game::keyboardWrapper(unsigned char keycode, int x, int y) {
  callbackInstance->keyboard(keycode, x, y);
}

// game specific functions here...


void Game::print_err(const char* s) {
  GLenum error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("tried to \'%s\'\n", s);
    printf("GL Error: %s\n\n", gluErrorString(error));
  } else {
    printf("tried to \'%s\'\n", s);
    printf("No GL Error\n\n");
  }
}

void Game::print_version_info() {
  printf("\n");
  printf("Version Information:\n");
  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
  printf("GLSL Language supported by this platform (%s): \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
  printf("\n");
}


