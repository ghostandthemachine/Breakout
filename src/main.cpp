// Two-Dimensional Sierpinski Gasket       
// Generated using randomly selected vertices and bisection

#include "Angel.h"

const int NumPoints = 5000;

//----------------------------------------------------------------------------

void print_err(const char* s) {
  GLenum error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("tried to \'%s\'\n", s);
    printf("GL Error: %s\n\n", gluErrorString(error));
  } else {
    printf("tried to \'%s\'\n", s);
    printf("No GL Error\n\n");
  }
}

void print_version_info() {
  printf("\n");
  printf("Version Information:\n");
  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
  printf("GLSL Language supported by this platform (%s): \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
  printf("\n");
}

void init(){
  print_version_info();

  print_err("start init");
  vec2 points[NumPoints];

  // Specifiy the vertices for a triangle
  vec2 vertices[3] = {
      vec2( -1.0, -1.0 ), vec2( 0.0, 1.0 ), vec2( 1.0, -1.0 )
  };

  // Select an arbitrary initial point inside of the triangle
  points[0] = vec2( 0.25, 0.50 );

  // compute and store N-1 new points
  for ( int i = 1; i < NumPoints; ++i ) {
      int j = rand() % 3;   // pick a vertex at random

      // Compute the point halfway between the selected vertex
      //   and the previous point
      points[i] = ( points[i - 1] + vertices[j] ) / 2.0;
  }

  // print_err("finish making points");
  // Create a vertex array object
  GLuint vao[1];
  glGenVertexArraysAPPLE( 1, vao );
  glBindVertexArrayAPPLE( vao[0] );
  // print_err("gen and bind vertex arrays");
  

  // Create and initialize a buffer object
  GLuint buffer;
  glGenBuffers( 1, &buffer );
  glBindBuffer( GL_ARRAY_BUFFER, buffer );
  glBufferData( GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW );
  // print_err("bind buffer and buffer data");

  // Load shaders and use the resulting shader program
  GLuint program = InitShader( "vertex1.glsl", "frag1.glsl" );
  glUseProgram(program);
  print_err("glUseProgram");

  // Initialize the vertex position attribute from the vertex shader
  GLuint loc = glGetAttribLocation( program, "vPosition" );
  glEnableVertexAttribArray( loc );
  glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0,
                         BUFFER_OFFSET(0) );

  glClearColor( 1.0, 1.0, 1.0, 1.0 ); // white background
}

//----------------------------------------------------------------------------

void display() {
    glClear( GL_COLOR_BUFFER_BIT );     // clear the window
    glDrawArrays( GL_POINTS, 0, NumPoints );    // draw the points
    glFlush();
}

//----------------------------------------------------------------------------

void keyboard(unsigned char key, int x, int y) {
    switch ( key ) {
    case 033:
        exit( EXIT_SUCCESS );
        break;
    }
}

//----------------------------------------------------------------------------


int main(int argc, char **argv){

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGBA );
  glutInitWindowSize( 512, 512 );

  // glutInitDisplayMode( GLUT_3_2_CORE_PROFILE | GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

  glutCreateWindow( "Sierpinski Gasket" );
  init();

  glutDisplayFunc( display );
  glutKeyboardFunc( keyboard );

  glutMainLoop();
  return 0;
}
