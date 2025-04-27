//itamarbabai98@gmail.com
#include <stdexcept>
#ifndef rows_hpp
#define rows_hpp
namespace matrix_math
{  
class rows{ //class for the rows of the matrix that will chack the index of the columns
    private:
        int size;
        double *row;
    public:
        rows(double *row, int size):
            size(size), row(row){} //constructor
        ~rows(){} //distructor

        double& operator[](int index){ //index operator
            if(index<0 || index>=size){
                throw std::out_of_range("Index out of range");
            }
            return row[index];
        }

};
}


#endif