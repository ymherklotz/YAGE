# Matrix Guide {#matrix_guide}

The matrix class is a templated class which implements a mathematical %Matrix.


## Usage Guide

The class can be instantiated


## Example Code

Creating a %Matrix and performing operations on it.

```
#include <YAGE/Math/matrix.hpp>

int main(int, char **)
{
    yage::Matrix<2, 2, int> mat1 {{1, 2, 3, 4}};
    yage::Matrix<2, 2, int> mat2 {{5, 6, 7, 8}};

    int dot = yage::math::dot(mat1, mat2);
    return 0;
}
```
