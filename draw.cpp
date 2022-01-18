/**
* Draws and adds color to the display
* By: Logan Cole 
*/
#include <iostream>
#include "draw.h"
#include <GL/glew.h>
#include <GL/glut.h>

#define COL 25
#define ROW 22

GLfloat square_size = 2.0f / 26.0f;

//gray = 0 black = 1 white = 2 dark blue = 3 light blue = 4
//yellow = 5 orange = 6 brown = 7 tan = 8 red = 9
GLushort image [ROW][COL] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,2,4,4,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,2,3,1,1,1,1,0,1,2,2,2,1,0,0,0,0,1,1,1,0,0},
    {0,0,0,1,3,4,4,3,3,3,1,2,4,4,1,0,0,0,0,1,2,2,4,1,0},
    {0,0,1,3,4,4,4,4,3,1,2,4,4,4,1,0,0,0,1,2,4,1,4,1,0},
    {0,0,1,4,4,4,4,4,3,1,2,4,4,1,1,0,0,0,1,2,1,3,3,1,0},
    {0,1,9,4,4,4,4,1,3,3,1,1,1,8,8,1,0,1,2,4,3,1,1,0,0},
    {0,1,4,4,4,4,1,2,3,3,3,3,0,8,8,7,1,1,4,4,3,3,1,0,0},
    {0,1,3,4,4,1,9,2,3,3,3,3,2,8,8,8,1,4,4,3,4,4,1,0,0},
    {0,0,1,3,3,3,9,2,0,0,3,3,1,2,8,8,7,1,3,4,4,3,1,0,0},
    {0,0,0,1,1,2,3,3,3,3,1,1,4,4,2,7,7,1,4,4,3,1,0,0,0},
    {0,0,0,1,3,1,1,1,3,1,2,4,4,3,2,7,7,1,3,1,1,0,0,0,0},
    {0,0,0,0,1,1,5,5,5,1,4,4,3,1,2,7,7,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,5,5,5,1,1,1,1,0,7,7,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,3,1,1,5,5,5,6,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,6,6,1,4,1,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,1,4,4,3,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,4,3,3,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

/**
* Draws the cube
**/ 
void addSquare(int row, int col, GLfloat vertices[])
{
    GLfloat x = 0.5;
    GLfloat y = -0.5;
    GLfloat z = 0.0;
    
    // Color Init
    GLfloat red = 0.0f;
    GLfloat green = 0.0f;
    GLfloat blue = 0.0f;

  //Switch case to find color
  switch(image[row][col]){
    case 0: // gray
      red =  0.752941f;
      blue = 0.752941f;
      green = 0.752941f;
      break;
    case 1: // black
      red = 0.001f;
      blue = 0.001f;
      green = 0.001f;
      break;
    case 2: // white
      red = 1.0f;
      blue = 1.0f;
      green = 1.0f;
      break;
    case 3: // dark blue
      red = 0.0;
      blue = 0.5f;
      green = 0.0f;
      break;
    case 4: // light blue
      red = 0.0f;
      blue = 1.0f;
      green = 0.498039f;
      break;
    case 5: // yellow
      red = 1.0f;
      blue = 0.0f;
      green = 1.0f;
      break;
    case 6: //orange
      red = 1.0f;
      blue = 0.0f;
      green = 0.5f;
      break;
    case 7: // brown
      red = 0.36f;
      blue = 0.20f;
      green = 0.25f;
      break;
    case 8: // tan
      red = 0.59f;
      blue = 0.31f;
      green = 0.41f;
      break;
    case 9: // red
      red = 1.0f;
      blue = 0.0f;
      green = 0.0f;
      break;
  }

  //set square coordinates
  if(col < 13)
    x = (square_size * col)  - 1;

  if(col == 13)
    x = 0;

  if(col > 13)
    x = square_size * (col - 13);

  if(row < 13)
    y = 1 - (square_size * row);

  if(row == 13)
    y = 0;
  if(row > 13)
    y = square_size * (row - 13) * (-1);
  
  vertices[((row * 5400) + (col * 216)) + 0] = x; //front face
  vertices[((row * 5400) + (col * 216)) + 1] = y;
  vertices[((row * 5400) + (col * 216)) + 2] = z;
  vertices[((row * 5400) + (col * 216)) + 3] = red;
  vertices[((row * 5400) + (col * 216)) + 4] = green;
  vertices[((row * 5400) + (col * 216)) + 5] = blue;
  vertices[((row * 5400) + (col * 216)) + 6] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 7] = y;
  vertices[((row * 5400) + (col * 216)) + 8] = z;
  vertices[((row * 5400) + (col * 216)) + 9] = red;
  vertices[((row * 5400) + (col * 216)) + 10] = green;
  vertices[((row * 5400) + (col * 216)) + 11] = blue;
  vertices[((row * 5400) + (col * 216)) + 12] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 13] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 14] = z;
  vertices[((row * 5400) + (col * 216)) + 15] = red;
  vertices[((row * 5400) + (col * 216)) + 16] = green;
  vertices[((row * 5400) + (col * 216)) + 17] = blue;
  vertices[((row * 5400) + (col * 216)) + 18] = x;
  vertices[((row * 5400) + (col * 216)) + 19] = y;
  vertices[((row * 5400) + (col * 216)) + 20] = z;
  vertices[((row * 5400) + (col * 216)) + 21] = red;
  vertices[((row * 5400) + (col * 216)) + 22] = green;
  vertices[((row * 5400) + (col * 216)) + 23] = blue;
  vertices[((row * 5400) + (col * 216)) + 24] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 25] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 26] = z;
  vertices[((row * 5400) + (col * 216)) + 27] = red;
  vertices[((row * 5400) + (col * 216)) + 28] = green;
  vertices[((row * 5400) + (col * 216)) + 29] = blue;
  vertices[((row * 5400) + (col * 216)) + 30] = x;
  vertices[((row * 5400) + (col * 216)) + 31] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 32] = z;
  vertices[((row * 5400) + (col * 216)) + 33] = red;
  vertices[((row * 5400) + (col * 216)) + 34] = green;
  vertices[((row * 5400) + (col * 216)) + 35] = blue;
  
  vertices[((row * 5400) + (col * 216)) + 36] = x; //back face
  vertices[((row * 5400) + (col * 216)) + 37] = y;
  vertices[((row * 5400) + (col * 216)) + 38] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 39] = red;
  vertices[((row * 5400) + (col * 216)) + 40] = green;
  vertices[((row * 5400) + (col * 216)) + 41] = blue;
  vertices[((row * 5400) + (col * 216)) + 42] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 43] = y;
  vertices[((row * 5400) + (col * 216)) + 44] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 45] = red;
  vertices[((row * 5400) + (col * 216)) + 46] = green;
  vertices[((row * 5400) + (col * 216)) + 47] = blue;
  vertices[((row * 5400) + (col * 216)) + 48] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 49] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 50] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 51] = red;
  vertices[((row * 5400) + (col * 216)) + 52] = green;
  vertices[((row * 5400) + (col * 216)) + 53] = blue;
  vertices[((row * 5400) + (col * 216)) + 54] = x;
  vertices[((row * 5400) + (col * 216)) + 55] = y;
  vertices[((row * 5400) + (col * 216)) + 56] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 57] = red;
  vertices[((row * 5400) + (col * 216)) + 58] = green;
  vertices[((row * 5400) + (col * 216)) + 59] = blue;
  vertices[((row * 5400) + (col * 216)) + 60] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 61] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 62] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 63] = red;
  vertices[((row * 5400) + (col * 216)) + 64] = green;
  vertices[((row * 5400) + (col * 216)) + 65] = blue;
  vertices[((row * 5400) + (col * 216)) + 66] = x;
  vertices[((row * 5400) + (col * 216)) + 67] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 68] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 69] = red;
  vertices[((row * 5400) + (col * 216)) + 70] = green;
  vertices[((row * 5400) + (col * 216)) + 71] = blue;
  
  vertices[((row * 5400) + (col * 216)) + 72] = x; //top face
  vertices[((row * 5400) + (col * 216)) + 73] = y;
  vertices[((row * 5400) + (col * 216)) + 74] = z;
  vertices[((row * 5400) + (col * 216)) + 75] = red;
  vertices[((row * 5400) + (col * 216)) + 76] = green;
  vertices[((row * 5400) + (col * 216)) + 77] = blue;
  vertices[((row * 5400) + (col * 216)) + 78] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 79] = y;
  vertices[((row * 5400) + (col * 216)) + 80] = z;
  vertices[((row * 5400) + (col * 216)) + 81] = red;
  vertices[((row * 5400) + (col * 216)) + 82] = green;
  vertices[((row * 5400) + (col * 216)) + 83] = blue;
  vertices[((row * 5400) + (col * 216)) + 84] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 85] = y;
  vertices[((row * 5400) + (col * 216)) + 86] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 87] = red;
  vertices[((row * 5400) + (col * 216)) + 88] = green;
  vertices[((row * 5400) + (col * 216)) + 89] = blue;
  vertices[((row * 5400) + (col * 216)) + 90] = x;
  vertices[((row * 5400) + (col * 216)) + 91] = y;
  vertices[((row * 5400) + (col * 216)) + 92] = z;
  vertices[((row * 5400) + (col * 216)) + 93] = red;
  vertices[((row * 5400) + (col * 216)) + 94] = green;
  vertices[((row * 5400) + (col * 216)) + 95] = blue;
  vertices[((row * 5400) + (col * 216)) + 96] = x;
  vertices[((row * 5400) + (col * 216)) + 97] = y;
  vertices[((row * 5400) + (col * 216)) + 98] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 99] = red;
  vertices[((row * 5400) + (col * 216)) + 100] = green;
  vertices[((row * 5400) + (col * 216)) + 101] = blue;
  vertices[((row * 5400) + (col * 216)) + 102] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 103] = y;
  vertices[((row * 5400) + (col * 216)) + 104] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 105] = red;
  vertices[((row * 5400) + (col * 216)) + 106] = green;
  vertices[((row * 5400) + (col * 216)) + 107] = blue;
  
  
  vertices[((row * 5400) + (col * 216)) + 108] = x; //right side face
  vertices[((row * 5400) + (col * 216)) + 109] = y;
  vertices[((row * 5400) + (col * 216)) + 110] = z;
  vertices[((row * 5400) + (col * 216)) + 111] = red * 0.5;
  vertices[((row * 5400) + (col * 216)) + 112] = green * 0.5;
  vertices[((row * 5400) + (col * 216)) + 113] = blue * 0.5;
  vertices[((row * 5400) + (col * 216)) + 114] = x;
  vertices[((row * 5400) + (col * 216)) + 115] = y;
  vertices[((row * 5400) + (col * 216)) + 116] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 117] = red * 0.5;
  vertices[((row * 5400) + (col * 216)) + 118] = green * 0.5;
  vertices[((row * 5400) + (col * 216)) + 119] = blue * 0.5;
  vertices[((row * 5400) + (col * 216)) + 120] = x;
  vertices[((row * 5400) + (col * 216)) + 121] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 122] = z;
  vertices[((row * 5400) + (col * 216)) + 123] = red * 0.5;
  vertices[((row * 5400) + (col * 216)) + 124] = green * 0.5;
  vertices[((row * 5400) + (col * 216)) + 125] = blue * 0.5;
  vertices[((row * 5400) + (col * 216)) + 126] = x;
  vertices[((row * 5400) + (col * 216)) + 127] = y;
  vertices[((row * 5400) + (col * 216)) + 128] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 129] = red * 0.5;
  vertices[((row * 5400) + (col * 216)) + 130] = green * 0.5;
  vertices[((row * 5400) + (col * 216)) + 131] = blue * 0.5;
  vertices[((row * 5400) + (col * 216)) + 132] = x;
  vertices[((row * 5400) + (col * 216)) + 133] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 134] = z;
  vertices[((row * 5400) + (col * 216)) + 135] = red * 0.5;
  vertices[((row * 5400) + (col * 216)) + 136] = green * 0.5;
  vertices[((row * 5400) + (col * 216)) + 137] = blue * 0.5;
  vertices[((row * 5400) + (col * 216)) + 138] = x;
  vertices[((row * 5400) + (col * 216)) + 139] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 140] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 141] = red * 0.5;
  vertices[((row * 5400) + (col * 216)) + 142] = green * 0.5;
  vertices[((row * 5400) + (col * 216)) + 143] = blue * 0.5;
  
  vertices[((row * 5400) + (col * 216)) + 144] = x + square_size; //left side face
  vertices[((row * 5400) + (col * 216)) + 145] = y;
  vertices[((row * 5400) + (col * 216)) + 146] = z;
  vertices[((row * 5400) + (col * 216)) + 147] = red;
  vertices[((row * 5400) + (col * 216)) + 148] = green;
  vertices[((row * 5400) + (col * 216)) + 149] = blue;
  vertices[((row * 5400) + (col * 216)) + 150] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 151] = y;
  vertices[((row * 5400) + (col * 216)) + 152] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 153] = red;
  vertices[((row * 5400) + (col * 216)) + 154] = green;
  vertices[((row * 5400) + (col * 216)) + 155] = blue;
  vertices[((row * 5400) + (col * 216)) + 156] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 157] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 158] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 159] = red;
  vertices[((row * 5400) + (col * 216)) + 160] = green;
  vertices[((row * 5400) + (col * 216)) + 161] = blue;
  vertices[((row * 5400) + (col * 216)) + 162] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 163] = y;
  vertices[((row * 5400) + (col * 216)) + 164] = z;
  vertices[((row * 5400) + (col * 216)) + 165] = red*.2;
  vertices[((row * 5400) + (col * 216)) + 166] = green*.2;
  vertices[((row * 5400) + (col * 216)) + 167] = blue*.2;
  vertices[((row * 5400) + (col * 216)) + 168] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 169] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 170] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 171] = red*.2;
  vertices[((row * 5400) + (col * 216)) + 172] = green*.2;
  vertices[((row * 5400) + (col * 216)) + 173] = blue*.2;
  vertices[((row * 5400) + (col * 216)) + 174] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 175] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 176] = z;
  vertices[((row * 5400) + (col * 216)) + 177] = red*.2;
  vertices[((row * 5400) + (col * 216)) + 178] = green*.2;
  vertices[((row * 5400) + (col * 216)) + 179] = blue*.2;
  
  vertices[((row * 5400) + (col * 216)) + 180] = x; //bottom face
  vertices[((row * 5400) + (col * 216)) + 181] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 182] = z;
  vertices[((row * 5400) + (col * 216)) + 183] = red;
  vertices[((row * 5400) + (col * 216)) + 184] = green;
  vertices[((row * 5400) + (col * 216)) + 185] = blue;
  vertices[((row * 5400) + (col * 216)) + 186] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 187] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 188] = z;
  vertices[((row * 5400) + (col * 216)) + 189] = red;
  vertices[((row * 5400) + (col * 216)) + 190] = green;
  vertices[((row * 5400) + (col * 216)) + 191] = blue;
  vertices[((row * 5400) + (col * 216)) + 192] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 193] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 194] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 195] = red;
  vertices[((row * 5400) + (col * 216)) + 196] = green;
  vertices[((row * 5400) + (col * 216)) + 197] = blue;
  vertices[((row * 5400) + (col * 216)) + 198] = x;
  vertices[((row * 5400) + (col * 216)) + 199] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 200] = z;
  vertices[((row * 5400) + (col * 216)) + 201] = red;
  vertices[((row * 5400) + (col * 216)) + 202] = green;
  vertices[((row * 5400) + (col * 216)) + 203] = blue;
  vertices[((row * 5400) + (col * 216)) + 204] = x;
  vertices[((row * 5400) + (col * 216)) + 205] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 206] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 207] = red;
  vertices[((row * 5400) + (col * 216)) + 208] = green;
  vertices[((row * 5400) + (col * 216)) + 209] = blue;
  vertices[((row * 5400) + (col * 216)) + 210] = x + square_size;
  vertices[((row * 5400) + (col * 216)) + 211] = y - square_size;
  vertices[((row * 5400) + (col * 216)) + 212] = z + square_size;
  vertices[((row * 5400) + (col * 216)) + 213] = red;
  vertices[((row * 5400) + (col * 216)) + 214] = green;
  vertices[((row * 5400) + (col * 216)) + 215] = blue;
 }
