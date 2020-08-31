#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void Pivoting(int arrA[3][6]){
    int temp[6];
    for(int r = 0;r<2;r++){
        if(arrA[r][r] == 0){
           for(int i = r+1;i<3;i++){
                if(abs(int(arrA[i][r])) > abs(int(arrA[r][r]))){
                    for(int j = 0;j<6;j++){
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

void Product(int arrM[3][3], int arrN[3][3],int n){
    int arrP[n][n], x;
    //int arrQ[3][3];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            arrP[i][j] = 0;
            //arrQ[i][j] = 0;
        }
    }
    for(int a = 0;a<n;a++){
        for(int b = 0;b<n;b++){
            for(int i = 0;i<n;i++){
                x = int(arrM[a][i])*int(arrN[i][b]);
                //cout<<x<<endl;
                arrP[a][b] = arrP[a][b] + x;
                //cout<< arrP[a][b];
            }
            //cout<< arrP[a][b]<< " ";
            //cout<< endl;
        }
    }
    cout<<"The product A*A^(-1) matrix is:"<< endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<arrP[i][j]<< " ";
        }
        cout<<endl;
    }
}
void getarray_GD(int arrA[3][6], int arrA_1[3][3]){
    Pivoting(arrA);
    float pivot;
    for(int r = 0;r<3;r++){
        //deciding a pivot
        pivot = arrA[r][r];
        //moving to columns
        for(int c = r;c<6;c++){
            arrA[r][c] = arrA[r][c]/pivot;
        }
        for(int k = 0;k<3;k++){
            if(k == r || arrA[k][r] == 0){
                continue;
            }
            else{
                int factor = arrA[k][r];
                for(int c = r;c<6;c++){
                   arrA[k][c] = arrA[k][c] - factor*arrA[r][c];
                }
            }
        }
    }

    //make into a new matrix


    cout << "The inverse matrix is: " << endl;
    for(int r = 0;r<3;r++){
        for(int j = 0;j<3;j++){
            arrA_1[r][j] = arrA[r][j+3];
            cout<< arrA_1[r][j]<< " ";
        }
        cout<< endl;
    }
    //return arrA_1;
}



int main(){

    int arrB[3][6], arrA[3][3];
    ifstream myfileB;
    myfileB.open("Q3.txt");
    for(int i = 0;i<3;i++){
        for(int j = 0;j<6;j++){
            myfileB >> arrB[i][j];
            //cout<< arrB[i][j] <<" ";
        }
        //cout<<endl;
    }
    cout<<"The matrix A is:"<< endl;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            arrA[i][j] = arrB[i][j];
            cout<< arrA[i][j] <<" ";
        }
        cout << endl;
    }

    //Pivoting(arrB);
    int arrA_1[3][3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            arrA_1[i][j] = 0;
        }
    }
    getarray_GD(arrB, arrA_1);
    cout<< "Let's check by multiplying it with the original matrix." << endl;
    Product(arrA_1, arrA,3);    //getarray_GD(arrB);
    //Product()
    return 0;
}
