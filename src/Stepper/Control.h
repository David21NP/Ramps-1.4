#ifndef Control_h
#define Control_h

#include <Arduino.h>

typedef struct Matrix
{
    unsigned int rows;
    unsigned int cols;
    float *data;
    Matrix()
    {
    }
    Matrix(int _rows, int _cols, const float *_data) : rows(_rows), cols(_cols)
    {
        data = new float[rows * cols];
        memcpy(data, _data, rows * cols);
    }
    ~Matrix() { delete[] data; }
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
    {
        data = new float[rows * cols];
        memcpy(data, other.data, rows * cols);
    }

    Matrix Add(const Matrix &other) const
    {
        Matrix mo = other;
        if ((other.rows == rows) && (other.cols == cols))
        {
            Matrix res(rows, cols, data);
            for (int i = 0; i < (rows * cols); i++)
            {
                res[i] += other[i];
            }
            return res;
        }
        return Matrix(0, 0, nullptr);
    }

    Matrix Add(const Matrix &other)
    {
        if ((other.rows == rows) && (other.cols == cols))
        {
            Matrix res(rows, cols, data);
            for (int i = 0; i < (rows * cols); i++)
            {
                res[i] += other[i];
            }
            return res;
        }
        return Matrix(0, 0, nullptr);
    }

    Matrix Multiply(const Matrix &other)
    {
        if (other.rows == cols)
        {
            Matrix res(rows, other.cols, data);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < other.cols; j++)
                {
                    float sums = 0;
                    for (int k = 0; k < cols; k++)
                    {
                        sums += data[k + i * cols] * other[j + k * other.cols];
                    }
                    res[i] = sums;
                }
            }
            return res;
        }
        return Matrix(0, 0, nullptr);
    }

    float& operator[](unsigned int p) const
    {
        if (p < (rows * cols))
        {
            return data[p];
        }
    }

    Matrix operator+(const Matrix &other) const
    {
        return Add(other);
    }

    Matrix operator*(const Matrix &other) const
    {
        return Multiply(other);
    }

} Matrix_t;



class Control
{
private:
    float ts;
    float rpm;

public:
    Control();
    Control(float _ts);
    ~Control();
    void set_ts(float);
    float get_ts();
    void set_rpm(float);
    float get_rpm();

    //void _goto
};

#endif