//itamarbabai98@gmail.com
#include<iostream>
#include"squareMath.hpp"

using namespace matrix_math;

int main(){
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
    std::cout<<"Matrix3 = matrix1 + matrix2 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;


    std::cout<<"-----------Matrix3 = matrix1 - matrix2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;

    matrix3=matrix1-matrix2;
    std::cout<<"Matrix3 = matrix1 - matrix2 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;

   std::cout<<"-----------Matrix3 = -matrix1 (minus onari)---------------"<<std::endl;
   std::cout << "-------------------------" << std::endl;

    matrix3=-matrix3;
    std::cout<<"Matrix3 = -matrix3 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;


    std::cout<<"-----------Matrix3 = matrix1 * matrix2---------------"<<std::endl;
    matrix1[1][0]=1.0;
    matrix2[2][0]=1.0;
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

    std::cout<<"-----------Matrix3 = matrix1 * 2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1*2;
    std::cout<<"Matrix3 = matrix1 * 2 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------Matrix3 = 0.5* matrix1---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=0.5*matrix1;
    std::cout<<"Matrix3 = 0.5 * matrix1"<<std::endl<<matrix3<<std::endl;
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

    std::cout<<"-----------Matrix3 = matrix1 % 2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1%2;
    std::cout<<"Matrix3 = matrix1 % 2 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------Matrix3 = matrix1/3---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1/3;
    std::cout<<"Matrix3 = matrix1 / 3 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------Matrix3 = matrix1^3---------------"<<std::endl;  
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1^3;
    std::cout<<"Matrix3 = matrix1 ^ 3 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------Matrix3 = matrix1++ (postfix)---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1 - before"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1++;
    std::cout<<"Matrix3 = matrix1++ "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1 - after"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;


    std::cout<<"-----------Matrix3 = matrix1-- (postfix)---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1 - before"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=matrix1--;
    std::cout<<"Matrix3 = matrix1-- "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1 - after"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;


    std::cout<<"-----------Matrix3 = ++matrix1 (prefix)---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1 - before"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=++matrix1;
    std::cout<<"Matrix3 = ++matrix1 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1 - after"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------Matrix3 = --matrix1 (prefix)---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1 - before"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;
    matrix3=--matrix1;
    std::cout<<"Matrix3 = --matrix1 "<<std::endl<<matrix3<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix1 - after"<<std::endl;
    std::cout<<matrix1;
    std::cout << "-------------------------" << std::endl;

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

    SquareMatrix matrix5(3);
    std::cout<<"-----------Example of using [] operator---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix5"<<std::endl;
    std::cout<<matrix5;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix5[0][0] = 1.0"<<std::endl;
    std::cout<<"Matrix5[0][1] = 1.0"<<std::endl;
    std::cout<<"Matrix5[0][2] = 1.0"<<std::endl;
    matrix5[0][0]=1.0;
    matrix5[0][1]=1.0;
    matrix5[0][2]=1.0;
    std::cout<<"Matrix5 after insert"<<std::endl;
    std::cout<<matrix5;
    std::cout << "-------------------------" << std::endl;
    std::cout<<" get matrix5[0][0] = "<<matrix5[0][0]<<std::endl;
    std::cout << "-------------------------" << std::endl;

    SquareMatrix  matrix6(3) ,matrix7(3);
    matrix7[0][0]=1;
    matrix7[0][1]=1;
    matrix7[0][2]=1;
    matrix7[1][0]=1;
    matrix7[1][2]=1;

    matrix6[0][0]=1;
    matrix6[0][1]=1;
    matrix6[0][2]=1;
    matrix6[1][0]=1;
    matrix6[1][2]=1;
    std::cout<<"-----------Matrix6 == Matrix7 ---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix6"<<std::endl;
    std::cout<<matrix6;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix7"<<std::endl;
    std::cout<<matrix7;
    std::cout << "-------------------------" << std::endl;
    if (matrix6==matrix7)
    {
        std::cout<<"The matrix sum is equal with sum of: "<<matrix6.sum()<<std::endl;
        
    }
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------Matrix6 != Matrix7 ---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    matrix7[0][0]=2;
    std::cout<<"Matrix6"<<std::endl;
    std::cout<<matrix6;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix7"<<std::endl;
    std::cout<<matrix7;
    std::cout << "-------------------------" << std::endl;
    if (matrix6!=matrix7)
    {
        std::cout<<"The matrix sum is not equal"<<std::endl;
        std::cout<<"Matrix6 sum is: "<<matrix6.sum()<<std::endl;
        std::cout<<"Matrix7 sum is: "<<matrix7.sum()<<std::endl;
    }
    std::cout << "-------------------------" << std::endl;  

    std::cout<<"-----------Matrix7 > Matrix6 ---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix6"<<std::endl;
    std::cout<<matrix6;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix7"<<std::endl;
    std::cout<<matrix7;
    std::cout << "-------------------------" << std::endl;
    if (matrix7>matrix6)
    {
        std::cout<<"The matrix7 sum is bigger than matrix 6"<<std::endl;
        std::cout<<"Matrix7 sum is: "<<matrix7.sum()<<std::endl;
        std::cout<<"Matrix6 sum is: "<<matrix6.sum()<<std::endl;
        if (matrix7>=matrix6)
        {
            std::cout<<"The matrix7 sum is also big equal to matrix 6"<<std::endl;
        }
    }
    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix7 < Matrix6 ---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    matrix6[0][2]=5;
    std::cout<<"Matrix6"<<std::endl;
    std::cout<<matrix6;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix7"<<std::endl;
    std::cout<<matrix7;
    std::cout << "-------------------------" << std::endl;
    if (matrix7<matrix6)
    {
        std::cout<<"The matrix7 sum is smaller than matrix 6"<<std::endl;
        std::cout<<"Matrix7 sum is: "<<matrix7.sum()<<std::endl;
        std::cout<<"Matrix6 sum is: "<<matrix6.sum()<<std::endl;
        if (matrix7<=matrix6)
        {
            std::cout<<"The matrix7 sum is also small equal to matrix 6"<<std::endl;
        }
    }

    std::cout << "-------------------------" << std::endl;
    std::cout<<"-----------Matrix7 >= Matrix6 and  Matrix6 >= Matrix7---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    matrix7[1][1]=3;
    std::cout<<"Matrix6"<<std::endl;
    std::cout<<matrix6;
    std::cout<<"matrix6 sum is: "<<matrix6.sum()<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix7"<<std::endl;
    std::cout<<matrix7;
    std::cout<<"matrix7 sum is: "<<matrix7.sum()<<std::endl;
    std::cout << "-------------------------" << std::endl;
    if (matrix6<=matrix7){
        std::cout<<"The matrix6 sum is small equal to matrix7"<<std::endl;
    }
    if (matrix6>=matrix7){
        std::cout<<"The matrix6 sum is big equal to matrix7"<<std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------Determinant of matrix8---------------"<<std::endl;

    SquareMatrix  matrix8(3),matrix9(3);
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            matrix8[i][j]=i;
        }
    }
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix8"<<std::endl;
    std::cout<<matrix8;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"The det of matrix8 is: "<<!matrix8<<std::endl;
    std::cout << "-------------------------" << std::endl;

    matrix9[0][0]=1;
    matrix9[1][1]=2;
    matrix9[2][2]=3;
    std::cout<<"Matrix9"<<std::endl;
    std::cout<<matrix9;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"The det of matrix9 is: "<<!matrix9<<std::endl;
    std::cout << "-------------------------" << std::endl;
    
    SquareMatrix matrix10(3), matrix11(3);


    std::cout<<"-----------matrix10+=matrix10---------------"<<std::endl;
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            matrix10[i][j]=1;
            matrix11[i][j]=1;
        }
    }
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix10"<<std::endl;
    std::cout<<matrix10;
    std::cout << "-------------------------" << std::endl;

    matrix10+=matrix10;
    std::cout<<"Matrix10 += matrix10 "<<std::endl<<matrix10<<std::endl;
    std::cout << "-------------------------" << std::endl;


    std::cout<<"-----------matrix10/=matrix10---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    matrix10/=matrix10;
    std::cout<<"Matrix10 /= matrix10 "<<std::endl<<matrix10<<std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------matrix11-=matrix10---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix10"<<std::endl;
    std::cout<<matrix10;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix11"<<std::endl;
    std::cout<<matrix11;
    std::cout << "-------------------------" << std::endl;
    matrix11-=matrix10;
    std::cout<<"Matrix11 -= matrix10 "<<std::endl<<matrix11<<std::endl;
    std::cout << "-------------------------" << std::endl;


    SquareMatrix matrix12(3), matrix13(3);
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            matrix12[i][j]=2;
            matrix13[i][j]=2;
        }
    }
    std::cout<<"-----------matrix12%=matrix13---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix12"<<std::endl;
    std::cout<<matrix12;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix13"<<std::endl;
    std::cout<<matrix13;
    std::cout << "-------------------------" << std::endl;
    matrix12%=matrix13;
    std::cout<<"Matrix12 %= matrix13 "<<std::endl<<matrix12<<std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------matrix12%=3---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix12"<<std::endl;
    std::cout<<matrix12;
    std::cout << "-------------------------" << std::endl;
    matrix12%=3;
    std::cout<<"Matrix12 %= 3 "<<std::endl<<matrix12<<std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------matrix13*=2---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix13"<<std::endl;
    std::cout<<matrix13;
    std::cout << "-------------------------" << std::endl;
    matrix13*=2;
    std::cout<<"Matrix13 *= 2 "<<std::endl<<matrix13<<std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout<<"-----------2*=matrix13---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<<"Matrix13"<<std::endl;
    std::cout<<matrix13;
    std::cout << "-------------------------" << std::endl;
    2*=matrix13;
    std::cout<<"2*=Matrix13"<<std::endl<<matrix13<<std::endl;
    std::cout << "-------------------------" << std::endl;

    SquareMatrix matrix14(3);

    std::cout<<"-----------matrix14*=matrix14---------------"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    matrix14[0][0]=1;
    matrix14[1][1]=2;
    matrix14[2][2]=3;
    std::cout<<"matrix14"<<std::endl;
    std::cout<<matrix14;
    std::cout<<"matrix14*=matrix14 is: "<<std::endl<<(matrix14*=matrix14)<<std::endl;
    std::cout << "-------------------------" << std::endl;
    return 0;

}