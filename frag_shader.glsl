#version 430 core

in vec3 theColor;

out layout (location = 0) vec4 fColor;

void main()
{
  fColor = vec4(theColor, 1.0);
}
