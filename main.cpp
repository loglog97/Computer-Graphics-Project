#include <iostream>
#include "Matrix.h"
using namespace std;

/**
* Creates a 3D image of a wartortle
* By: Logan Cole
**/
#include <GL/glew.h>
#include "draw.h"
#include <GL/glut.h>
#include <GL/freeglut.h>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))
void checkForShaderError(GLuint shader);
void checkForProgramError(GLuint programID);

GLuint vPosition = 0;
GLuint vColor = 1;
GLuint buffer;
GLuint programID;

/**
* Reads the code in the vertex and fragment shader
**/
char* readShaderCode(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        cout <<  "File failed to load..." << filename;
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* data = (char*)calloc(res+1, sizeof(char));
    fread(data, sizeof(char),res, fp);
    cout << data << endl;
    fclose(fp);
    return data;
}

/**
* Inits the buffers and shaders for the program
*/ 
void init(void)
{
    cout << glGetString(GL_VERSION) << endl;

    GLfloat* verticesArray = (GLfloat*) malloc(200000*sizeof(GLfloat));
    //Draws the squares (is sent into draw.cpp)
    for(int x = 0; x < 22; x++)
    {
        for(int y = 0; y < 25; y++)
        {
          addSquare(x,y, verticesArray);
	}
    }

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 200000 * sizeof(GLfloat), verticesArray, GL_STATIC_DRAW);
    // describe vertex data
    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);

    // describe color data
    glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), BUFFER_OFFSET(3*sizeof(float)));
    glEnableVertexAttribArray(vColor);

    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    const char* adapter[1];
    adapter[0] = readShaderCode("vertex_shader.glsl");
    glShaderSource(vertexShaderID, 1, adapter, 0);
    adapter[0] = readShaderCode("frag_shader.glsl");
    glShaderSource(fragmentShaderID, 1, adapter, 0);

    glCompileShader(vertexShaderID);
    glCompileShader(fragmentShaderID);

    programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    glUseProgram(programID);

}

/**
* Clears buffers and draws the arrays
*/
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Creating the matrix for the operations in the shader
    Matrix transMatrix, scaleMatrix, perspectiveMatrix, rotateMatrix;
    transMatrix = transMatrix.translationMatrix('z', 10);  //translates on z by 10
    scaleMatrix = scaleMatrix.scaleMatrix(.7f); //scales the image down by 0.7f
    perspectiveMatrix = perspectiveMatrix.perspectiveMatrix(20, -10);
    rotateMatrix = rotateMatrix.rotationMatrix('y', 60);
    
    //setting up the names for the matrices in the vertex shader
    GLint modelTransMatLoc = glGetUniformLocation(programID, "modelTransMatLoc");
    GLint projMatLoc = glGetUniformLocation(programID, "projMatLoc");
    GLint modelScaleMatLoc = glGetUniformLocation(programID, "scaleMatrix");
    GLint rotMatLoc = glGetUniformLocation(programID, "rotMatLoc");
    GLint rotMatLoc2 = glGetUniformLocation(programID, "rotMatLoc2");
    
    //giving the data to the variables in the vertex shader
    glUniformMatrix4fv(modelScaleMatLoc, 1, GL_TRUE, &scaleMatrix[0][0]);
    glUniformMatrix4fv(projMatLoc, 1, GL_TRUE, &perspectiveMatrix[0][0]);
    glUniformMatrix4fv(modelTransMatLoc, 1, GL_TRUE, &transMatrix[0][0]);
    glUniformMatrix4fv(rotMatLoc, 1, GL_TRUE, &rotateMatrix[0][0]);

    glDrawArrays(GL_TRIANGLES, 0, 20000);
    glFlush();
}

/**
* Checks for errors in the shader code
**/
void checkForShaderError(GLuint shader)
{
    GLint compileStatus;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != GL_TRUE)
    {
        cout << compileStatus << endl;
        GLint maxLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
        cout << maxLength << endl;
        GLchar* errorLog = new GLchar[maxLength];
        GLsizei bufferSize;
        glGetShaderInfoLog(shader, maxLength, &bufferSize, errorLog);
        cout << errorLog << endl;
        delete [] errorLog;
    }
}

/**
* Checks for errors in the program itself
**/
void checkForProgramError(GLuint programID)
{
    GLint linkStatus;
    glGetProgramiv(programID, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE)
    {
        GLint maxLength;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);
        GLchar* errorLog = new GLchar[maxLength];
        GLsizei bufferSize;
        glGetProgramInfoLog(programID, maxLength, &bufferSize, errorLog);
        cout << errorLog << endl;
        delete [] errorLog;
    }
}

/**
* Main method
**/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(512, 512);
    glutCreateWindow("wartortle");

    if (glewInit())
    {
	    cerr << "Unable to initialize GLEW ... exiting" << endl;
	    exit(EXIT_FAILURE);
    }
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    init();

    glutDisplayFunc(display);

    glutMainLoop();
}
