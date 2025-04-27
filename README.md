//itamarbabai98@gmail.com
# SquareMatrix Library - C++

## General Explanation
This project implements a `SquareMatrix` class in C++ to handle operations on square matrixs. The library supports various matrix operations, including addition, subtraction, multiplication, scalar operations, transposition, and determinant calculation. It also includes errors handling for edge cases.

---

## Features
- **Matrix Operations**:
  - Addition (`+`), Subtraction (`-`), Multiplication (`*`).
  - Scalar multiplication and division.
  - Element by element multiplication (`%`).
  - Transposition (`~`).
  - Determinant calculation (`!`).
- **Comparison Operators**:
  - Equality (`==`) and inequality (`!=`).
- **Increment and Decrement**:
  - Prefix (`++matrix`, `--matrix`) and postfix (`matrix++`, `matrix--`).
- **Error Handling**:
  - Handles invalid matrix sizes, division by zero, and out-of-bound index access.

---

## Compiler and Build Instructions
- **Compiler**: `g++`
- **Build and Run Example**:
  ```bash
  make Main
  ```
- **Run Tests**:
  ```bash
  make test
  ```
  - **Clean**:
  ```bash
  make clean
  ```
  - **Run valgrined**:
  ```bash
  make valgrined
  ```
  - **Run tests with valgrined**:
  ```bash
  make test valgrined
  or
  make valgrined_test
  ```

## Project Structure
```bash
CPP_OPERATORS/
├── main.cpp
├── SquareMath.cpp
├── Test_prog.cpp
├── doctest.cpp
├── doctest.h
├── SquareMath.hpp
├── rows.hpp
├── Makefile
└── README.md
```
## SquareMatrix Class
### Constructor:
- The constructor initializes a square matrix of size `n x n` with all elements set to zero.
- It throws an `invalid_argument` exception if `n` is less than 1 or greater than 100.
### Destructor:
- The destructor deallocates the memory used for the matrix.
### Copy Constructor:
- The copy constructor creates a deep copy of the matrix, ensuring that changes to the copied matrix do not affect the original.
### Assignment Operator:
- The assignment operator allows for assignment between two `SquareMatrix` objects, ensuring proper memory management and deep copying.
### Operators:
- **Addition (`+`)**: Adds two matrices element-wise.
- **Subtraction (`-`)**: Subtracts one matrix from another element-wise.
- **Multiplication (`*`)**: Multiplies two matrices using the standard matrix multiplication algorithm.
- **Scalar Multiplication (`*`)**: Multiplies each element of the matrix by a scalar value.
- **Scalar Division (`/`)**: Divides each element of the matrix by a scalar value.
- **Element-wise Multiplication (`%`)**: Multiplies two matrices element-wise.
- **Element-wise Modulus (`%`)**: Computes the modulus of each element of the matrix with a scalar value.
- **Transposition (`~`)**: Transposes the matrix.   
- **Determinant (`!`)**: Calculates the determinant of the matrix.
- **Comparison Operators (`==`, `!=`)**: Compares two matrices for equality of sums.
- **Increment (`++`)**: Increments each element of the matrix by 1.
- **Decrement (`--`)**: Decrements each element of the matrix by 1.
### Error Handling:
- The library includes error handling for invalid matrix sizes, division by zero, and out-of-bound index access.


### test: 
In this part of the code we try to test the extream cases that can hapand and may become a problem.
1. Test SquareMatrix constructor:
    * Trying to create matrix with -1 rows and cols - invalid_argument exception.
    * Trying to create matrix with 0 rows and cols - invalid_argument exception.
    * Trying to create matrix with 101 rows and cols - invalid_argument exception.

2. Test SquareMatrix copy constructor:
    - After creating a matrix with 3 rows and cols, we create a copy of it and check if the sizes are the same.
    - Check if the data is the same.
    - Check if the data is not the same after changing one (deep copy).

3. Test SquareMatrix assignment operator:
    - After creating a matrix with 3 rows and cols, we create a copy of it and check if the sizes are the same.
    - Check if the data is the same.
    - Create a new matrix with 4 rows and cols and assign it to the first matrix.
    - Check if the sizes are the same (means that the old matrix deleted).

4. Test the matrix1+matrix2 operator:
    - Create two matrices with 3 rows and cols and add them together, check if after adding the result are as expected.
    -Try to add two matrices with different sizes - invalid_argument exception.

5. Test the matrix1-matrix2 operator:
    - Create two matrices with 3 rows and cols and subtract them together, cheack if after subtracting the result are as expected.
    -Try to subtract two matrices with different sizes - invalid_argument exception.

6. Test the -matrix1 operator:
    - Create a matrix with 3 rows and cols and activate the minus operator it, check if after activating the result are as expected.

7. Test the matrix1*matrix2 operator:
    - Create two matrices with 3 rows and cols and multiply them together, check if after multiplying the result are as expected.
    -Try to multiply two matrices with different sizes - invalid_argument exception.

8. Test the matrix1*scalar operator:
    - Create a matrix with 3 rows and cols and multiply it by a scalar, check if after multiplying the result are as expected.

9. Test the matrix1%matrix2 (element by element) operator:
    - Create two matrices with 3 rows and cols and multiply them together, check if after multiplying the result are as expected.
    -Try to multiply two matrices with different sizes - invalid_argument exception.

10. Test the matrix1 % scalar (mod each element) operator:
    - Create a matrix with 3 rows and cols and multiply it by a scalar, check if after multiplying the result are as expected.
    - Also check if a double number is working.

11. Test the matrix1/scalar (div each element) operator:
    - Create a matrix with 3 rows and cols and divide it by a scalar, check if after dividing the result are as expected.
    - Try to divide by 0 - invalid_argument exception.

12. Test the matrix1^scalar operator:
    - Create a matrix with 3 rows and cols and power it by a scalar, check if after powerin the result are as expected.
    - Try to powee by (-1) - invalid_argument exception.
    - Try to power by 0 - sepose to stay the same.
  
12. Test the matrix1++ , matrix1-- operator (postfix):
    - Create a matrix with 3 rows and cols and increment it by 1, check if after incrementing the result are as expected.
    - Create a matrix with 3 rows and cols and decrement it by 1, check if after decrementing the result are as expected.
    - Check if the postfix returns the old value and after that the new value.

13. Test the ++matrix1 , --matrix1 operator (prefix):
    - Create a matrix with 3 rows and cols and increment it by 1, check if after incrementing the result are as expected.
    - Create a matrix with 3 rows and cols and decrement it by 1, check if after decrementing the result are as expected.
    - Check if the prefix returns the new value immidiatly.

14. Test the ~matrix1 operator:
    - Create a matrix with 3 rows and cols and transpose it, check if after transposing the result are as expected.
    - Check if the transpose of the transpose is the same as the original matrix.

15. Test the matrix1[] operator:
    - Create a matrix with 3 rows and cols and try to access the elements using the [] operator, check if after accessing the result are as expected.
    - Try to access an out of bound index - out_of_range exception.

16. Test the == and != operators:
    - Create a matrix with 3 rows and cols and check if it equal to itself.
    - Create a different matrix with 3 rows and cols and check if it is not equal to the first matrix.
    - Check if the sum function is working.
    - Try to compare two matrices with different sizes - invalid_argument exception.

17. Test the > , < , >= , <= operators:
    - Create a equal matrix with 3 rows and cols and check if it is greater or equal than each other.
    - Make one marix bigger and check if it is greater than the other.
    - Try to compare two matrices with different sizes - invalid_argument exception.
    - Create 2 matrix with 1 row and 1 col and check if one of them is greater than the other.

18. Test the !matrix1 operator:
    - Create a matrix with 3 rows and cols and calculate the determinant, check if after calculating the result are as expected.
    - Create a matrix with 1 row and col and calculate the determinant, check if after calculating the result are as expected.
    - Create a matrix with 2 rows and cols and calculate the determinant, check if after calculating the result are as expected.

19. Test the += , -= , /= , %= , *=  operators:
    - Create a matrix with 3 rows and cols and add a scalar to it, check if after adding the result are as expected.
    -Cheack if after subtracting the result are as expected.
    - Cheack if after multiplying the result are as expected.
    - Ccheck if after dividing the result are as expected.
    - Cheack if after duplicate element-wise the result are as expected.
    - Try to divide by 0 - invalid_argument exception.
    - Try to operate with a different size matrix - invalid_argument exception.

20. Test the %= (mod with scalar) , *= (mul with scalar both sides) operators:
    - Create a matrix with 3 rows and cols and mod it by a scalar, check if after modding the result are as expected.
    - Cheack if after multiplying the result are as expected.
    - Try to mod by -2 - invalid_argument exception.

21. Test << operator:
    - Create a matrix with 3 rows and cols and print it, check if after printing the result are as expected.
    - Check if there is any trowing exception.


