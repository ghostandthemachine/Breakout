attribute vec4 v_position;
attribute vec4 v_color;

varying vec4 color;

uniform vec3 theta;
uniform vec2 offset;

void main() {
  // Compute the sines and cosines of theta for each of the three axes in one computation.
  vec3 angles = radians(theta);
  vec3 c = cos(angles);
  vec3 s = sin(angles);

  // Remeber: these matrices are column-major
  mat4 rx = mat4(1.0,  0.0,  0.0, 0.0,
                 0.0,  c.x,  s.x, 0.0,
                 0.0, -s.x,  c.x, 0.0,
                 0.0,  0.0,  0.0, 1.0);

  mat4 ry = mat4(c.y, 0.0, -s.y, 0.0,
                 0.0, 1.0,  0.0, 0.0,
                 s.y, 0.0,  c.y, 0.0,
                 0.0, 0.0,  0.0, 1.0);

  mat4 rz = mat4(c.z, -s.z, 0.0, 0.0,
                 s.z,  c.z, 0.0, 0.0,
                 0.0,  0.0, 1.0, 0.0,
                 0.0,  0.0, 0.0, 1.0);

  color = v_color;
  gl_Position = rz * ry * rx * v_position + vec4(offset.xy, 0.0, 0.0);
} 