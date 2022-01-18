#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
  private:
    float data[4][4];
  public:
    Matrix();
    Matrix translationMatrix(char type, int size);
    Matrix scaleMatrix(float size);
    Matrix rotationMatrix(char type, int degrees);
    Matrix perspectiveMatrix(float far, float near);
    Matrix operator *(Matrix&);
    float* operator [](int i);
    void print();
};
#endif
