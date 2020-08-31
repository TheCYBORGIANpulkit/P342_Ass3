#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void Pivoting(float arrA[3][4]){
    int temp[4];
    for(int r = 0;r<2;r++){
        if(arrA[r][r] == 0){
           for(int i = r+1;i<3;i++){
                if(abs(int(arrA[i][r])) > abs(int(arrA[r][r]))){
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
void getarray_GD(float arrA[3][4]){
    Pivoting(arrA);
    float pivot;
    for(int r = 0;r<3;r++){
        //deciding a pivot
        pivot = arrA[r][r];
        //moving to columns
        for(int c = r;c<4;c++){
            arrA[r][c] = (arrA[r][c])/pivot;
        }
        for(int k = 0;k<3;k++){
            if(k == r || arrA[k][r] == 0){
                continue;
            }
            else{
                float factor = arrA[k][r];
                for(int c = r;c<4;c++){
                   arrA[k][c] = arrA[k][c] - factor*arrA[r][c];
                }
            }
        }
    }
    //make into a new matrix
    float arrX[3][1];
    cout<< "The solution are: " << endl;
    for(int r = 0;r<3;r++){
        arrX[r][0] = arrA[r][3];
        //cout<< arrX[r][0];
        //cout<< endl;
    }

    float x = arrX[0][0];
    float y = arrX[1][0];
    float z = arrX[2][0];
    cout << " x = "<< x << endl;
    cout << " y = "<< y << endl;
    cout <<" z = "<< z << endl;



    /*
    cout << "The inverse matrix is: " << endl;
    int** arrN = new int*[3];
    for(int r = 0;r<3;r++){
        arrN[r] = new int[3];
        for(int j = 0;j<3;j++){
            arrN[r][j] = arrA[r][j+3];
            cout<< arrN[r][j]<< " ";
        }
        cout<< endl;
    }
    return arrN;
    */
}
int main(){

    float arrB[3][4], arrA[3][3];
    ifstream myfileB;
    myfileB.open("Q2.txt");
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

    getarray_GD(arrB);
    /*
    RESULT:
    The solution are:
       x = -1.59459
       y = 0.837838
       z = 1.81081
    */

    return 0;
}
