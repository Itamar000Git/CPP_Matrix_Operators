//itamarbabai98@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "squareMath.hpp"
#include <iostream>

using namespace matrix_math;

TEST_CASE("Testing matrix constructor"){
    std::cout<<"||||||||||||||||||||Testing the matrix constructor|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3);
  

    CHECK_THROWS_AS(SquareMatrix(-1), std::invalid_argument); //check if its possible to create a matrix with negative size
    CHECK_THROWS_AS(SquareMatrix(0), std::invalid_argument);   //check if its possible to create a matrix with 0 size
    CHECK_THROWS_AS(SquareMatrix(101), std::invalid_argument); //check if its possible to create a matrix with size bigger than 100
}
TEST_CASE("Testing matrix copy constructor"){
    std::cout<<"||||||||||||||||||||Testing the matrix copy constructor|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3);
    SquareMatrix matrix2(matrix1);
    CHECK(matrix1.getSize() == matrix2.getSize()); //check if the size of the two matrices is the same
    CHECK(matrix1[0][0] == matrix2[0][0]); //check if the first element of the two matrices is the same
    CHECK(matrix1[1][1] == matrix2[1][1]); //check if the second element of the two matrices is the same
    matrix1[0][0] = 1;
    CHECK(matrix1[0][0] != matrix2[0][0]); //check if the first element of the two matrices is not the same
}
TEST_CASE("Testing matrix assignment operator"){
    std::cout<<"||||||||||||||||||||Testing the matrix assignment operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3);
    SquareMatrix matrix2(3);
    matrix1[0][0] = 1;
    matrix2 = matrix1;
    CHECK(matrix1.getSize() == matrix2.getSize()); //check if the size of the two matrices is the same
    CHECK(matrix1[0][0] == matrix2[0][0]); //check if the first element of the two matrices is the same
    CHECK(matrix1[1][1] == matrix2[1][1]); //check if the second element of the two matrices is the same

    SquareMatrix matrix3(4);
    matrix3=matrix1;
    CHECK(matrix3.getSize() == matrix1.getSize()); //check if the old matrix 3 is deleted
    CHECK(matrix3[0][0] == matrix1[0][0]); 

}

TEST_CASE("Testing matrix1+matrix2 operator"){
    std::cout<<"||||||||||||||||||||Testing the matrix1+matrix2 operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3), matrix3(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;

    matrix2[0][0]=3.0;
    matrix2[1][1]=2.0;
    matrix2[2][2]=1.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix3 = matrix1 + matrix2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix3"<<std::endl;
    std::cout<<matrix3;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1+matrix2;
    CHECK(matrix3[0][0] == matrix1[0][0] + matrix2[0][0]); 
    CHECK(matrix3[1][1] == matrix1[1][1] + matrix2[1][1]); 
    std::cout<<"Matrix3=matrix1 + matrix2"<<std::endl;
    std::cout<<matrix3;
    std::cout << "-------------------------" << std::endl;

    SquareMatrix matrix4(3),matrix5(4);
    matrix4[0][0]=1.0;
    matrix4[0][1]=1.0;
    matrix4[0][2]=1.0;
    CHECK_THROWS_AS(matrix4+matrix5, std::invalid_argument); //check if its possible to add two matrices with different size
}

TEST_CASE("Testing matrix1-matrix2 operator"){
    std::cout<<"||||||||||||||||||||Testing the matrix1-matrix2 operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3), matrix3(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;

    matrix2[0][0]=3.0;
    matrix2[1][1]=2.0;
    matrix2[2][2]=1.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix3 = matrix1 - matrix2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix3"<<std::endl;
    std::cout<<matrix3;
    std::cout << "-------------------------" << std::endl;

    matrix3=matrix1-matrix2;

    CHECK(matrix3[0][0] == matrix1[0][0] - matrix2[0][0]); 
    CHECK(matrix3[1][1] == matrix1[1][1] - matrix2[1][1]); 
    CHECK(matrix3[2][2] == matrix1[2][2] - matrix2[2][2]); 
    std::cout<<"Matrix3=matrix1 - matrix2"<<std::endl;
    std::cout<<matrix3;

    SquareMatrix matrix4(3),matrix5(4);
    matrix4[0][0]=1.0;
    matrix4[0][1]=1.0;
    matrix4[0][2]=1.0;
    CHECK_THROWS_AS(matrix4-matrix5, std::invalid_argument); //check if its possible to add two matrices with different size

}
TEST_CASE("Testing -matrix1 operator"){
    std::cout<<"||||||||||||||||||||Testing the -matrix1 operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = -matrix1---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    matrix2=-matrix1;
    std::cout<<matrix2;
    CHECK(matrix2[0][0] == -matrix1[0][0]); 
    CHECK(matrix2[1][1] == -matrix1[1][1]);
}

TEST_CASE("Testing matrix1*matrix2 operator"){
    SquareMatrix matrix1(3),matrix2(3), matrix3(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;

    matrix2[0][0]=3.0;
    matrix2[1][1]=2.0;
    matrix2[2][2]=1.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1*matrix2;
    std::cout<<"Matrix3 = matrix1 * matrix2 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;

    CHECK(matrix3[0][0] == 3);
    CHECK(matrix3[1][1] == 4);
    CHECK(matrix3[0][0] == 3);

    SquareMatrix matrix4(3),matrix5(4);
    matrix4[0][0]=1.0;
    matrix4[0][1]=1.0;
    CHECK_THROWS_AS(matrix4*matrix5, std::invalid_argument);
}

TEST_CASE("Testing matrix1*scalar operator (both sidse)"){
    std::cout<<"||||||||||||||||||||Testing the matrix1*scalar operator (both sidse)|||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3), matrix3(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = matrix1 * 2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=matrix1*2;
    std::cout<<"Matrix2 = matrix1 * 2 "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 2);
    CHECK(matrix2[1][1] == 4);
    CHECK(matrix2[0][0] == 2);
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix3 = 2 * matrix1---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=2*matrix1;
    std::cout<<"Matrix3 = 2 * matrix1 "<<std::endl<<matrix3<<std::endl;
    CHECK(matrix3[0][0] == 2);
    CHECK(matrix3[1][1] == 4);
    CHECK(matrix3[0][0] == 2);
    std::cout << "-------------------------" << std::endl;
}
TEST_CASE("Testing matrix1%matrix2 (element by element) operator"){
    std::cout<<"||||||||||||||||||||Testing the matrix1%matrix2 (element by element) operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3), matrix3(3);
    matrix1[0][0]=1.0;
    matrix1[0][1]=2.0;
    matrix1[0][2]=3.0;

    matrix2[0][0]=3.0;
    matrix2[0][1]=2.0;
    matrix2[0][2]=1.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix3 = matrix1 % matrix2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1%matrix2;
    std::cout<<"Matrix3 = matrix1 % matrix2 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix3[0][0] == 3);
    CHECK(matrix3[0][1] == 4);
    CHECK(matrix3[0][2] == 3);

    SquareMatrix matrix4(3),matrix5(4);
    matrix4[0][0]=1.0;
    matrix4[0][1]=1.0;
    CHECK_THROWS_AS(matrix4%matrix5, std::invalid_argument);
}
TEST_CASE("Testing matrix1 % scalar (mod each element) operator"){
    std::cout<<"||||||||||||||||||||Testing the matrix1 % scalar (mod each element) operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[0][1]=2.5;
    matrix1[0][2]=3.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = matrix1 % 2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=matrix1%2;
    std::cout<<"Matrix2 = matrix1 % 2 "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 1);
    CHECK(matrix2[0][1] == 0.5);
    CHECK(matrix2[0][2] == 1);
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = matrix1 % 0.5---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=matrix1%0.5;
    std::cout<<"Matrix2 = matrix1 % 0.5 "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 0.0);
    CHECK(matrix2[0][1] == 0.0);
    CHECK(matrix2[0][2] == 0.0);
    std::cout << "-------------------------" << std::endl;
}

TEST_CASE("Testing matrix1 / scalar (div each element) operator"){
    std::cout<<"||||||||||||||||||||Testing the matrix1 / scalar (div each element) operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[0][1]=2.5;
    matrix1[0][2]=3.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = matrix1 / 2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=matrix1/2;
    std::cout<<"Matrix2 = matrix1 / 2 "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 0.5);
    CHECK(matrix2[0][1] == 1.25);
    CHECK(matrix2[0][2] == 1.5);
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = matrix1 / 0---------------"<<std::endl;
    CHECK_THROWS_AS(matrix2 = matrix1/0, std::invalid_argument);
}

TEST_CASE("Testing matrix1 ^ scalar  operator"){
    std::cout<<"||||||||||||||||||||Testing matrix1 ^ scalar  operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;
    std::cout<<"-----------Matrix2 = matrix1^3---------------"<<std::endl;  
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=matrix1^3;
    std::cout<<"Matrix2 = matrix1 ^ 3 "<<std::endl<<matrix2<<std::endl;
    std::cout << "-------------------------" << std::endl;

    CHECK(matrix2[0][0] == 1);
    CHECK(matrix2[1][1] == 16);
    CHECK(matrix2[2][2] == 81);

    CHECK_THROWS_AS(matrix2 = matrix1^(-1), std::invalid_argument);

    matrix2=matrix1^0;
    std::cout<<"Matrix2 = matrix1 ^ 0 "<<std::endl<<matrix2<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix2 == matrix1);
    CHECK(matrix2[0][0] == 1);
    CHECK(matrix2[1][1] == 2);
    CHECK(matrix2[2][2] == 3);
}

TEST_CASE("Testing matrix1++ (postfix)  operator"){
    std::cout<<"||||||||||||||||||||Testing matrix1++ (postfix)  operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = matrix1++---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=matrix1++;
    std::cout<<"Matrix2 = matrix1++ "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 1);
    CHECK(matrix2[1][1] == 2);
    CHECK(matrix2[2][2] == 3);

    CHECK(matrix1[0][0] == 2);
    CHECK(matrix1[1][1] == 3);
    CHECK(matrix1[2][2] == 4);
}
TEST_CASE("Testing matrix1-- (postfix)  operator"){
    std::cout<<"||||||||||||||||||||Testing matrix1-- (postfix)  operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = matrix1-----------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=matrix1--;
    std::cout<<"Matrix2 = matrix1-- "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 1);
    CHECK(matrix2[1][1] == 2);
    CHECK(matrix2[2][2] == 3);

    CHECK(matrix1[0][0] == 0);
    CHECK(matrix1[1][1] == 1);
    CHECK(matrix1[2][2] == 2);
}
TEST_CASE("Testing ++matrix1 (prefix)  operator"){
    std::cout<<"||||||||||||||||||||Testing ++matrix1 (prefix)  operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = ++matrix1---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=++matrix1;
    std::cout<<"Matrix2 = ++matrix1 "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 2);
    CHECK(matrix2[1][1] == 3);
    CHECK(matrix2[2][2] == 4);

    CHECK(matrix1[0][0] == 2);
    CHECK(matrix1[1][1] == 3);
    CHECK(matrix1[2][2] == 4);
}   
TEST_CASE("Testing --matrix1 (prefix)  operator"){
    std::cout<<"||||||||||||||||||||Testing --matrix1 (prefix)  operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = --matrix1---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix2=--matrix1;
    std::cout<<"Matrix2 = --matrix1 "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 0);
    CHECK(matrix2[1][1] == 1);
    CHECK(matrix2[2][2] == 2);

    CHECK(matrix1[0][0] == 0);
    CHECK(matrix1[1][1] == 1);
    CHECK(matrix1[2][2] == 2);
}
TEST_CASE("Testing ~matrix1 (transpose)  operator"){
    std::cout<<"||||||||||||||||||||Testing ~matrix1 (transpose)  operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix  matrix4(3);
    matrix4[0][0]=1.0;
    matrix4[0][1]=1.0;
    matrix4[0][2]=1.0;
    matrix4[1][0]=3.0;
    matrix4[1][1]=3.0;
    matrix4[1][2]=3.0;
    matrix4[2][0]=2.0;
    matrix4[2][1]=2.0;
    matrix4[2][2]=2.0;

    std::cout<<"-----------Matrix4 traspose---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix4"<<std::endl;
    std::cout<<matrix4;
    std::cout << "-------------------------" << std::endl;
    ~matrix4;
    std::cout<<"Matrix4 = ~matrix4 "<<std::endl<<matrix4<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix4[0][0] == 1);
    CHECK(matrix4[1][0] == 1);
    CHECK(matrix4[2][0] == 1);
    CHECK(matrix4[0][1] == 3);
    CHECK(matrix4[1][1] == 3);
    CHECK(matrix4[2][1] == 3);
    CHECK(matrix4[0][2] == 2);
    CHECK(matrix4[1][2] == 2);
    CHECK(matrix4[2][2] == 2);  
    ~matrix4;
    std::cout<<"Matrix4 = ~matrix4 "<<std::endl<<matrix4<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix4[0][0] == 1);
    CHECK(matrix4[0][1] == 1);
    CHECK(matrix4[0][2] == 1);
    CHECK(matrix4[1][0] == 3);
    CHECK(matrix4[1][1] == 3);  
    CHECK(matrix4[1][2] == 3);
    CHECK(matrix4[2][0] == 2);
    CHECK(matrix4[2][1] == 2);
    CHECK(matrix4[2][2] == 2);
          
}
TEST_CASE("Testing matrix1[] (index) operator"){
    std::cout<<"||||||||||||||||||||Testing matrix1[] (index) operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3);
    matrix1[0][0]=1.0;
    matrix1[0][1]=2.0;
    matrix1[0][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix1[0][0] == 1);
    CHECK(matrix1[0][1] == 2);
    CHECK(matrix1[0][2] == 3);


    //double* row = matrix1[0];
    rows row = matrix1[0];

    CHECK(row[0] == 1);
    CHECK(row[1] == 2);
    CHECK(row[2] == 3);
    CHECK_THROWS_AS(matrix1[3], std::out_of_range); //check if its possible to access a row that is out of range
    CHECK_THROWS_AS(matrix1[-1], std::out_of_range); //check if its possible to access a row that is out of range

    CHECK_THROWS_AS(matrix1[3][0], std::out_of_range); //check if its possible to access a column that is out of range
    CHECK_THROWS_AS(matrix1[-1][0], std::out_of_range); //check if its possible to access a column that is out of range
    CHECK_THROWS_AS(matrix1[2][15], std::out_of_range); //check if its possible to access a column that is out of range
}
TEST_CASE("Testing matrix1==matrix1 and matrix1!=matrix2 operator"){//by their sum
    std::cout<<"||||||||||||||||||||Testing matrix1==matrix2 and matrix1!=matrix2 operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3) ,matrix3(4);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;
    matrix1[0][2]=3.0;


    matrix2[0][0]=3.0;
    matrix2[1][1]=2.0;
    matrix2[2][2]=1.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;

    CHECK(matrix1==matrix1);
    CHECK(matrix1.sum()==9);
    CHECK(matrix2.sum()==6);
    CHECK_FALSE(matrix1==matrix2);

    CHECK(matrix1!=matrix2);
    CHECK_FALSE(matrix1!=matrix1);


}

TEST_CASE("Testing >= , <= , > , < operators"){
    std::cout<<"||||||||||||||||||||Testing >= , <= , > , < operators|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3) ,matrix3(1), matrix4(1);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;

    matrix2[0][0]=3.0;
    matrix2[1][1]=2.0;
    matrix2[2][2]=1.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix1>=matrix2);
    CHECK(matrix1<=matrix2);
    CHECK_FALSE(matrix1>matrix2);
    CHECK_FALSE(matrix1<matrix2);
    matrix1[0][2]=3.0; 
    CHECK(matrix1>matrix2);
    CHECK_FALSE(matrix1<matrix2);

    matrix3[0][0]=1.0;
    matrix4[0][0]=2.0;


    CHECK(matrix4>=matrix3);
    CHECK(matrix3<=matrix4);
    CHECK(matrix4>matrix3);
    CHECK(matrix3<matrix4);

}
TEST_CASE("Testing !matrix1 (det) operator"){ 
    std::cout<<"||||||||||||||||||||Testing !matrix1 (det) operators|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3),matrix3(1), matrix4(2);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;

    matrix2[0][0]=-3.0;
    matrix2[1][1]=2.0;
    matrix2[2][2]=1.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;

    CHECK(!matrix1==6);
    CHECK(!matrix2==-6);

    matrix3[0][0]=1.0;

    matrix4[0][0]=2.0;
    matrix4[0][1]=3.0;
    matrix4[1][0]=4.0;
    matrix4[1][1]=5.0;  
    CHECK(!matrix4==(-2));
    CHECK(!matrix3==1);
}
TEST_CASE("Testing += , -= , /= , %= , *= operators (culc and assign between matrix)"){
    SquareMatrix matrix1(3),matrix2(3), matrix3(2);
    matrix1[0][0]=1.0;
    matrix1[1][1]=2.0;
    matrix1[2][2]=3.0;

    matrix2[0][0]=3.0;
    matrix2[1][1]=2.0;
    matrix2[2][2]=1.0;

    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;
    matrix1+=matrix2;
    std::cout<<"Matrix1+=matrix2 "<<std::endl<<matrix1<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix1[0][0] == 4);
    CHECK(matrix1[1][1] == 4);
    CHECK(matrix1[2][2] == 4);

    matrix1-=matrix2;
    std::cout<<"Matrix1-=matrix2 "<<std::endl<<matrix1<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix1[0][0] == 1);
    CHECK(matrix1[1][1] == 2);
    CHECK(matrix1[2][2] == 3);

    matrix1*=matrix2;
    std::cout<<"Matrix1*=matrix2 "<<std::endl<<matrix1<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix1[0][0] == 3);
    CHECK(matrix1[1][1] == 4);
    CHECK(matrix1[2][2] == 3);


    matrix2[0][1]=1.0;
    matrix2[0][2]=1.0;
    matrix2[1][0]=1.0;
    matrix2[1][2]=1.0;
    matrix2[2][0]=1.0;
    matrix2[2][1]=1.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix2"<<std::endl;
    std::cout<<matrix2;
    std::cout << "-------------------------" << std::endl;

    matrix1/=matrix2;
    std::cout<<"Matrix1/=matrix2 "<<std::endl<<matrix1<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix1[0][0] == 1);
    CHECK(matrix1[1][1] == 2);
    CHECK(matrix1[2][2] == 3);

    matrix1%=matrix2;
    std::cout<<"Matrix1%=matrix2 "<<std::endl<<matrix1<<std::endl;
    std::cout << "-------------------------" << std::endl;
    CHECK(matrix1[0][0] == 3);
    CHECK(matrix1[1][1] == 4);
    CHECK(matrix1[2][2] == 3);

    matrix2[0][0]=0;
    CHECK_THROWS_AS(matrix1/=matrix2, std::invalid_argument); 

    matrix3[0][0]=1.0;
    matrix3[0][1]=1.0;
    matrix3[1][0]=1.0;
    matrix3[1][1]=1.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix3"<<std::endl;
    std::cout<<matrix3;
    std::cout << "-------------------------" << std::endl;
    CHECK_THROWS_AS(matrix1+=matrix3, std::invalid_argument); 
    CHECK_THROWS_AS(matrix1-=matrix3, std::invalid_argument); 
    CHECK_THROWS_AS(matrix1*=matrix3, std::invalid_argument);
    CHECK_THROWS_AS(matrix1%=matrix3, std::invalid_argument); 
    CHECK_THROWS_AS(matrix1/=matrix3, std::invalid_argument); 
}
TEST_CASE("Testing %= (mod with scalar) , *= (mul with scalar both sides) operators"){
    std::cout<<"||||||||||||||||||||Testing %= (mod with scalar) , *= (mul with scalar both sides) operators|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3),matrix2(3);
    matrix1[0][0]=1.0;
    matrix1[0][1]=2.5;
    matrix1[0][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix2 = matrix1 % 2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;


    matrix2=matrix1%2;
    std::cout<<"Matrix2 = matrix1 % 2 "<<std::endl<<matrix2<<std::endl;
    CHECK(matrix2[0][0] == 1);
    CHECK(matrix2[0][1] == 0.5);
    CHECK(matrix2[0][2] == 1);
    std::cout << "-------------------------" << std::endl;


    matrix1%=2;
    std::cout<<"Matrix1%=2 "<<std::endl<<matrix1<<std::endl;
    CHECK(matrix1[0][0] == 1);
    CHECK(matrix1[0][1] == 0.5);
    CHECK(matrix1[0][2] == 1);

    matrix1*=3;
    std::cout<<"Matrix1*=3 "<<std::endl<<matrix1<<std::endl;
    CHECK(matrix1[0][0] == 3);
    CHECK(matrix1[0][1] == 1.5);
    CHECK(matrix1[0][2] == 3);

    matrix1*=0.5;
    std::cout<<"Matrix1*=0.5 "<<std::endl<<matrix1<<std::endl;
    CHECK(matrix1[0][0] == 1.5);
    CHECK(matrix1[0][1] == 0.75);
    CHECK(matrix1[0][2] == 1.5);


    CHECK_THROWS_AS( matrix1%=-2, std::invalid_argument); 
  
}
TEST_CASE("Testing << operator"){
    std::cout<<"||||||||||||||||||||Testing << operator|||||||||||||||||||||||"<<std::endl;
    SquareMatrix matrix1(3);
    matrix1[0][0]=1.0;
    matrix1[0][1]=2.5;
    matrix1[0][2]=3.0;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    CHECK_NOTHROW(std::cout<<matrix1);
    std::cout << "-------------------------" << std::endl;

}