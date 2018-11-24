/**Gaussian elimination programming class I C ++**/
#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
char jump= '\n';

int main()
{
    srand(time(NULL));

    int N=4;

    float X[N][N];
    int Y[10];

    for(int i=0; i < N; i++){
        for(int j=0; j< N; j++ ){
        X[i][j] = rand()%9+1;
        }

    }

    for(int i=0; i < N; i++){
        for(int j=0; j< N; j++ ){
                cout << setw(3);
        cout <<" "<< X[i][j];
    if (j==N-1){
        cout<<jump;
    }
        }

    }

    cout<<"---------------"<<jump;
         if (X[0][0]!=1){
                float F= X[0][0];
            for(int k=0; k < N; k++){
                    X[0][k] = (X[0][k])/(F);
                    cout<<"<--------------->"<<jump;
            }
                }

     for(int i=0; i < N; i++){
        for(int j=0; j< N; j++ ){
                cout << setw(3);

        cout <<" "<< X[i][j];
    if (j==N-1){
        cout<<jump;
    }
        }

    }
