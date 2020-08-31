#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void Pivoting(int arrA[3][4]){
    int temp[4];
    for(int r = 0;r<2;r++){
        if(arrA[r][r] == 0){
           for(int i = r+1;i<3;i++){
                if(abs(arrA[i][r]) > abs(arrA[r][r])){
                    for(int j = 0;j<4;j++){
                        temp[j] = arrA[r][j];
                        arrA[r][j] = arrA[r+1][j];
                        arrA[r+1][j] = temp[j];
                    }
                }
           }
        }
        else continue;
    }
    /*
    cout<< "The swapped matrix B is:"<< endl;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<6;j++){
            cout<<arrA[i][j]<< " ";
        }
        cout<<endl;
    }
    */
}
void getarray_GD(int arrA[3][4]){
    Pivoting(arrA);
    int pivot;
    for(int r = 0;r<3;r++){
        //deciding a pivot
        pivot = arrA[r][r];
        //moving to columns
        for(int c = r;c<4;c++){
            arrA[r][c] = arrA[r][c]/pivot;
        }
        for(int k = 0;k<3;k++){
            if(k == r || arrA[k][r] == 0){
                continue;
            }
            else{
                int factor = arrA[k][r];
                for(int c = r;c<4;c++){
                   arrA[k][c] = arrA[k][c] - factor*arrA[r][c];
                }
            }
        }
    }
    //make into a new matrix
    int arrX[3][1];
    for(int r = 0;r<3;r++){
        arrX[r][0] = arrA[r][3];
    }
    cout<< "The solution are: " << endl;
    int x = arrX[0][0];
    int y = arrX[1][0];
    int z = arrX[2][0];
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}
int main(){

    int arrB[3][4], arrA[3][3];
    ifstream myfileB;
    myfileB.open("Q1.txt");
    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            myfileB >> arrB[i][j];
            //cout<< arrB[i][j] <<" ";
        }
        //cout<<endl;
    }
    //cout<<"The matrix A is:"<< endl;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            arrA[i][j] = arrB[i][j];
            //cout<< arrA[i][j] <<" ";
        }
        //cout << endl;
    }
    //Pivoting(arrB);
    getarray_GD(arrB);
    /*
    RESULT:
    The solution are:
       x = 3
       y = 1
       z = -2
    */
    return 0;
}
