#include <iostream>
#include "Matrix.h"
#include <math.h>
/**
* Matrix Class to be used with 3D image homework
* By: Logan Cole
*/

#define PI 3.14159

using namespace std;

/**
* Inits a fresh matrix
**/
Matrix::Matrix()
{
  for(int x = 0; x < 4; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      data[x][y] = 0;
    }    
  }
}

/**
* Creates a rotation matrix based on what axis its rotating on and by how much depening on degrees
**/
Matrix Matrix::rotationMatrix(char type, int degrees)
{
  Matrix tmp;

  switch(type){
  case 'x':
    tmp[0][0] = 1;
    tmp[1][1] = cos(degrees*(PI/180)); //cos
    tmp[1][2] = -sin(degrees*(PI/180)); //-sin
    tmp[2][1] = sin(degrees*(PI/180)); //sin
    tmp[2][2] = cos(degrees*(PI/180)); //cos
    tmp[3][3] = 1;
    break;
  case 'y':
    tmp[0][0] = cos(degrees*(PI/180)); //cos
    tmp[0][2] = -sin(degrees*(PI/180)); //-sin
    tmp[1][1] = 1;
    tmp[2][0] = sin(degrees*(PI/180)); //sin
    tmp[2][2] = cos(degrees*(PI/180)); //cos
    tmp[3][3] = 1;
    break;
  case 'z':
    tmp[0][0] = cos(degrees*(PI/180));//cos
    tmp[0][1] = -sin(degrees*(PI/180));//-sin
    tmp[1][0] = sin(degrees*(PI/180)); //sin
    tmp[1][1] = cos(degrees*(PI/180));
    tmp[2][2] = 1;
    tmp[3][3] = 1;
    break;
  }

  return tmp;
}

/**
* Creates a perspective matrix
**/
Matrix Matrix::perspectiveMatrix(float far, float near)
{
  Matrix tmp;
  float tan_half_angle = tan((60*PI)/(2*180));
  float ratio = 1.0f;
  
    tmp[0][0] = 1 / (ratio * tan_half_angle);
    tmp[1][1] = 1 / (tan_half_angle);
    tmp[2][2] = (far + near) / (far - near);
    tmp[3][2] = 1;
    tmp[2][3] = -(2 * far * near) / (far - near);
    tmp[3][3] = 0;
    return tmp;
}

/**
* Creates a Translation Matrix based on the axis and the size to translate it by.
* Returns the Matrix to be used to translate the picture
**/
Matrix Matrix::translationMatrix(char type, int size){
  Matrix tmp;

  switch(type){
  case 'x':
    tmp[0][0] = 1;
    tmp[1][1] = 1;
    tmp[2][2] = 1;
    tmp[3][3] = 1;
    tmp[0][3] = size;
    break;
  case 'y':
    tmp[0][0] = 1;
    tmp[1][1] = 1;
    tmp[2][2] = 1;
    tmp[3][3] = 1;
    tmp[1][3] = size;
    break;
  case 'z':
    tmp[0][0] = 1;
    tmp[1][1] = 1;
    tmp[2][2] = 1;
    tmp[3][3] = 1;
    tmp[2][3] = size;
    break;
  }

  return tmp;
}

/**
* Create a scale matrix based on the size the user wants the picture
* to be scaled by. 
* Returns the scale matrix
*/
Matrix Matrix::scaleMatrix(float size){
  Matrix tmp;
  tmp[0][0] = size;
  tmp[1][1] = size;
  tmp[2][2] = size;
  tmp[3][3] = 1;
  return tmp;
}

/** Used to multiply two matrices */
Matrix Matrix :: operator *( Matrix &ob)
{
  Matrix tmp;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
	      tmp[i][j] += (data[i][k] * ob[k][j]);
      }
    }
  }
  return tmp;
}

/**
* returns a value from a place in a matrix
**/
float* Matrix:: operator [](int i)
{
  return data[i];
}

/**
* Prints a matrix
**/
void Matrix::print()
{
  for(int x = 0; x < 4; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      cout << data[x][y] << " ";
    }
    cout << "\n";
  }
}
