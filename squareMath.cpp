//itamarbabai98@gmail.com
#include<iostream>
#include <cmath>
#include"squareMath.hpp"

namespace matrix_math
{  
    SquareMatrix::SquareMatrix(int n){//constructor
        if(n<=0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(n>100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }

        columns = n;
        matrix = new double*[n];
        for(int i = 0; i < n; i++){
            matrix[i] = new double[n];
            for(int j = 0; j < n; j++){
                matrix[i][j] = 0;
            }
        }
    }
    SquareMatrix::~SquareMatrix(){ //distructor
        for(int i = 0; i < columns; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    
    void SquareMatrix::set(int i, int j, double value){ //can be maneged with operator[] directly
        if(i < 0 || i >= columns || j < 0 || j >= columns){
            throw std::out_of_range("Index out of range");
        }
        matrix[i][j] = value;
     }
    double SquareMatrix::get(int i, int j) const{//can be maneged with operator[] directly
        if(i < 0 || i >= columns || j < 0 || j >= columns){
            throw std::out_of_range("Index out of range");
        }
        return matrix[i][j];
    }
    int SquareMatrix::getSize() const{
        return columns;
    }
    
    SquareMatrix::SquareMatrix(const SquareMatrix &other){ //copy constructor
        if(other.columns<=0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(other.columns>100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(this == &other){
            return;
        }


        columns = other.columns;
        matrix = new double*[columns];
        for(int i = 0; i < columns; i++){
            matrix[i] = new double[columns];
            for(int j = 0; j < columns; j++){
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    SquareMatrix& SquareMatrix::operator=(const SquareMatrix &other){//copy assignment operator
        if(other.columns<=0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(other.columns>100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }


        if(this != &other){
            for(int i = 0; i < columns; i++){
                delete[] matrix[i];
            }
            delete[] matrix;

            columns = other.columns;
            matrix = new double*[columns];
            for(int i = 0; i < columns; i++){
                matrix[i] = new double[columns];
                for(int j = 0; j < columns; j++){
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }

    SquareMatrix SquareMatrix::operator+(const SquareMatrix &other){//add operator
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
       
        SquareMatrix result(columns);
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                result.matrix[i][j] = matrix[i][j]+ other.matrix[i][j];//for each element in the matrix adding the other element.
            }
        }
        return result;
    }
    SquareMatrix SquareMatrix::operator-(const SquareMatrix &other){//sub operator
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        SquareMatrix result(columns);
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                result.matrix[i][j] = matrix[i][j]- other.matrix[i][j];//for each element in the matrix subtracting the other element.
            }
        }
        return result;
    }

    SquareMatrix SquareMatrix::operator-(){//unary minus, plipping the sign
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        SquareMatrix result(columns);

        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                if(matrix[i][j] != 0){
                result.matrix[i][j] = -matrix[i][j];
                }
            }
        }
        return result;
    }

    SquareMatrix SquareMatrix::operator*(const SquareMatrix &other){//matrix multiply
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        SquareMatrix result(columns);
        for(int i = 0; i < columns; i++){ //index of the row
            for(int j = 0; j < columns; j++){// index of the column
                result.matrix[i][j] = 0;
                for(int k = 0; k < columns; k++){// index of the column of the first matrix and row of the second matrix
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];//summing the product of the elements
                }
            }
        }
        return result;
    }

    SquareMatrix SquareMatrix::operator*(double scalar){//matrix from left, multiply by scalar
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        SquareMatrix result(columns);

        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                if(matrix[i][j] != 0){
                result.matrix[i][j] = matrix[i][j] * scalar;//for each element in the matrix multiplying by the scalar.
                }
            }
        }
        return result;
    }
    SquareMatrix operator*(double scalar,const SquareMatrix &other){//matrix from right , multiply by scalar
        if(other.columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(other.columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        SquareMatrix result =SquareMatrix(other);
        for(int i = 0; i < result.columns; i++){
            for(int j = 0; j < result.columns; j++){
                if(result.matrix[i][j] != 0){
                result.matrix[i][j] = result.matrix[i][j] * scalar;//for each element in the matrix multiplying by the scalar.
                }
            }
        }
        return result;
    }

    SquareMatrix SquareMatrix::operator%(const SquareMatrix &other){//multiply element by element
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        SquareMatrix result(columns);

        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                result.matrix[i][j] = matrix[i][j]* other.matrix[i][j];//for each element in the matrix multiplying by the other element.
            }
        }
        return result;
    }

    SquareMatrix SquareMatrix::operator%(double scalar){//mod by scalar
        SquareMatrix result(columns);

        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                result.matrix[i][j] =fmod(matrix[i][j],scalar); //enable mod with double, for each element in the matrix mod by the scalar.
            }
        }
        return result;
    }

    SquareMatrix SquareMatrix::operator/(double scalar){//divide by scalar
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(scalar == 0){
            throw std::invalid_argument("Division by zero");
        }

       return this->operator*(1/scalar);//divide by scalar is the same as multiplying by 1/scalar
    }
    SquareMatrix SquareMatrix::operator^(double scalar){//power of matrix
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(scalar < 0){
            throw std::invalid_argument("Power must be positive");
        }
        SquareMatrix result(columns);
        result=*this;
        for(int i=0; i<scalar;i++){//power matrix is the same as multiplying the matrix by itself
            result=result*(*this);
        }
        return result;
    }


    SquareMatrix SquareMatrix::operator++(int){ //plus 1 postfix
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        SquareMatrix result(*this); //make a copy of the current matrix
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                matrix[i][j] = matrix[i][j]+1;//for each element in the matrix adding 1.
            }
        }
        return result;//return the copy of the matrix
    }
    SquareMatrix SquareMatrix::operator--(int){ //minus 1 postfix
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        SquareMatrix result(*this);//make a copy of the current matrix
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                matrix[i][j] = matrix[i][j]-1;//for each element in the matrix subtracting 1.
            }
        }
        return result;//return the copy of the matrix
    }

    SquareMatrix SquareMatrix::operator++(){//plus prefix
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                matrix[i][j] = matrix[i][j]+1;//for each element in the matrix adding 1.
            }
        }
        return *this;//return the current matrix after adding 1
    }

    SquareMatrix SquareMatrix::operator--(){//minus prefix
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                matrix[i][j] = matrix[i][j]-1;//for each element in the matrix subtracting 1.
            }
        }
        return *this;//return the current matrix after subtracting 1
    }

    SquareMatrix SquareMatrix::operator~(){//transpose
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        double temp;
        for(int i = 0; i < columns; i++){
            for(int j = i; j < columns; j++){//run only half of the matrix
                //swap the elements
                temp=matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        return *this;
    }

    double* SquareMatrix::operator[](int index){//index operator
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(index>=columns || index<0){
            throw std::out_of_range("Out of range index");
        }
        return matrix[index];//return the row of the matrix
    }

    double SquareMatrix::sum() const{//sum of all elements in the matrix
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns == 1){
            return matrix[0][0];
        }
        double sum=0;
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                sum+=matrix[i][j];
            }
        }

        return sum;
    }

    bool SquareMatrix::operator==(const SquareMatrix &other){//equal operator
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }

        return this->sum() == other.sum();//compare the sum of the elements in the matrix
    }
    bool SquareMatrix::operator!=(const  SquareMatrix &other){//not equal operator
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        return !(*this == other);//using the equal operator that compares the sum of the elements in the matrix.
    }

    bool SquareMatrix::operator>(const SquareMatrix &other){//greater operator
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns == 1){
            return matrix[0][0] > other.matrix[0][0];
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        return this->sum()>other.sum();
    }
    bool SquareMatrix::operator<(const SquareMatrix &other){//less operator
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns == 1){
            return matrix[0][0] < other.matrix[0][0];
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        return this->sum()<other.sum();
    }
    bool SquareMatrix::operator>=(const SquareMatrix &other){//greater or equal operator
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns == 1){
            return matrix[0][0] >= other.matrix[0][0];
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        return this->sum()>=other.sum();
    }
    bool SquareMatrix::operator<=(const SquareMatrix &other){//less or equal operator
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns == 1){
            return matrix[0][0] <= other.matrix[0][0];
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        return this->sum()<=other.sum();
    }

    double SquareMatrix::operator!()const{//determinant operator imlemented with recursion
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns==1){ //determinant of 1x1 matrix
            return matrix[0][0];
        }
        if(columns==2){//determinant of 2x2 matrix
            return matrix[0][0]*matrix[1][1] - (matrix[1][0]*matrix[0][1]);
        }
        int det_sum=0;
        int mul=0;
        for (int i = 0; i < columns; i++)
        {
            if(i%2==0){ //even index
                mul=1;
            }
            else{
                mul=-1;
            }
            SquareMatrix after_minor = minor(0,i); //Culculating the minor matrix
            mul=mul*matrix[0][i];
            det_sum+=mul*!after_minor; //recursive call for the determinant of the minor matrix
        }
        return det_sum;
    }
    SquareMatrix SquareMatrix::minor(int row,int col)const{//minor matrix
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(row<0 || row>=columns || col<0 || col>=columns){
            throw std::out_of_range("Index out of range");
        }

        SquareMatrix minor_mat(columns-1);
        int min_col=0, min_row=0;
        for(int i=0; i<columns;i++){
            min_col=0;
            if(i==row){
                continue;
            }
            for(int j=0; j<columns;j++){
                if(j==col){
                    continue;
                }
                minor_mat[min_row][min_col]=matrix[i][j];//building the minor matrix
                min_col++; 
            }
            min_row++;
        }

        return minor_mat;
    }

    SquareMatrix SquareMatrix::operator+=(const SquareMatrix &other){//add and assign
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        *this= *this+other; //using the add operator
        return *this; //return the current matrix
    }

    SquareMatrix SquareMatrix::operator-=(const SquareMatrix &other){//sub and assign
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        *this= *this-other;//using the sub operator
        return *this;//return the current matrix
    }
    SquareMatrix SquareMatrix::operator/=(const SquareMatrix &other){//divide and assign
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        for(int i = 0; i < columns; i++){
            for(int j = 0; j < columns; j++){
                if(other.matrix[i][j] == 0){
                    throw std::invalid_argument("Division by zero");
                }
                matrix[i][j] = matrix[i][j]/ other.matrix[i][j];//for each element in the matrix dividing by the other element.
            }
        }
        return *this;//return the current matrix
    }

    SquareMatrix SquareMatrix::operator%=(const SquareMatrix &other){//multiply element by element and assign
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        *this= *this%other;//using the multiply element by element operator
        return *this;//return the current matrix
    }
    SquareMatrix SquareMatrix::operator%=(double scalar){//mod by scalar and assign
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(scalar<=0){
            throw std::invalid_argument("Scalar must be positive");
        }
        *this= *this%scalar;//using the mod by scalar operator
        return *this;//return the current matrix
    }

    SquareMatrix SquareMatrix::operator*=(double scalar){//matrix from left, multiply by scalar and assign
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        *this= *this*scalar;//using the multiply by scalar operator
        return *this;//return the current matrix
    }
    SquareMatrix operator*=(double scalar, SquareMatrix &other){//matrix from right, multiply by scalar and assign
        if(other.columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(other.columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        other= scalar * other;//using the multiply by scalar operator
        return other;//return the current matrix
    }

    SquareMatrix SquareMatrix::operator*=(SquareMatrix &other){//matrix multiply and assign
        if(columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        if(columns != other.columns){
            throw std::invalid_argument("Matrices must be of the same size");
        }
        *this= *this*other;//using the multiply operator
        return *this;//return the current matrix
    }

    std::ostream& operator<< (std::ostream& output, const SquareMatrix& other){// output operator
        if(other.columns <= 0){
            throw std::invalid_argument("Matrix size must be positive");
        }
        if(other.columns > 100){
            throw std::invalid_argument("Matrix size must be less than 100");
        }
        for(int i = 0; i < other.getSize(); i++){
            for(int j = 0; j < other.getSize(); j++){
                output << other.get(i, j) << " ";
            }
            output<< std::endl;
        }
        return output;
    }
    
}