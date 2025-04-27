//itamarbabai98@gmail.com

#ifndef squareMath_hpp
#define squareMath_hpp
#include "rows.hpp"

namespace matrix_math
{  
    class SquareMatrix
    {
        private:
            int columns;
            double **matrix;
            void set(int i, int j, double value);
            double get(int i, int j) const;
        public:
            SquareMatrix(int n); //constructor
            ~SquareMatrix();    //distructor
            int getSize() const;
            SquareMatrix(const SquareMatrix &other); //copy constructor
            SquareMatrix& operator=(const SquareMatrix &other);//copy assignment operator
            SquareMatrix operator+(const SquareMatrix &other);//add operator
            SquareMatrix operator-(const SquareMatrix &other);//sub operator
            SquareMatrix operator-();//unary minus
            SquareMatrix operator*(const SquareMatrix &other);//matrix multiply
            SquareMatrix operator*(double scalar);//matrix from left, multiply by scalar
            friend SquareMatrix operator*(double scalar,const SquareMatrix &other);//matrix from right , multiply by scalar
            SquareMatrix operator%(const SquareMatrix &other); //multiply element by element
            SquareMatrix operator%(double scalar); //mod by scalar
            SquareMatrix operator/(double scalar); //divide by scalar
            SquareMatrix operator^(double scalar); //power of matrix

            SquareMatrix operator++(int); //postfixe
            SquareMatrix operator--(int);

            SquareMatrix operator++(); //prefix
            SquareMatrix operator--();

            SquareMatrix operator~(); //transpose

            rows operator[](int index); //index operator
            double sum()const; //sum of all elements in the matrix

            bool operator==(const SquareMatrix &other); //equal operator

            bool operator!=(const SquareMatrix &other);//not equal operator

            bool operator>(const SquareMatrix &other);//greater operator
            bool operator<(const SquareMatrix &other);//less operator
            bool operator>=(const SquareMatrix &other);//greater or equal operator
            bool operator<=(const SquareMatrix &other);//less or equal operator

            double operator!()const; //determinant operator
            SquareMatrix minor(int row,int col) const; //minor matrix

            SquareMatrix operator+=(const SquareMatrix &other);//add and assign
            SquareMatrix operator-=(const SquareMatrix &other);//sub and assign
            SquareMatrix operator/=(const SquareMatrix &other);//divide and assign

            SquareMatrix operator%=(const SquareMatrix &other);//multiply element by element and assign
            SquareMatrix operator%=(double scalar);//mod by scalar and assign

            SquareMatrix operator*=(double scalar);//matrix from left, multiply by scalar and assign
            friend SquareMatrix operator*=(double scalar, SquareMatrix &other);//matrix from right , multiply by scalar and assign
           
            SquareMatrix operator*=(SquareMatrix &other);//matrix multiply and assign

            
            friend std::ostream& operator<< (std::ostream& output, const SquareMatrix& other); //output operator
            

    };
}

#endif