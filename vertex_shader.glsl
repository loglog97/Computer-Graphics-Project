#version 430 core

in layout (location = 0) vec3 vPosition;
in layout (location = 1) vec3 vColor;

uniform mat4 modelTransMatLoc;
uniform mat4 projMatLoc;
uniform mat4 scaleMatrix;
uniform mat4 rotMatLoc;
out vec3 theColor;

void main()
{
  vec4 v = vec4(vPosition, 1.0f);
  vec4 loc = scaleMatrix * rotMatLoc * v;
  gl_Position = loc;
  theColor = vColor;
}
