/**Gaussian elimination programming class I C ++**/
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
char jump= '\n'; // Salto de linea
using namespace std;
void coeficintes (float X[][500], int); // Se ingresan los elementos de a la MatrizA
int main()
{
    int n,N=4;
    cout << "ingrese los sistemas lineales que quiere resolver" << jump;
    cin >> n;
    float MatrizA[n][500];
    coeficintes(MatrizA,n);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++ ){
                cout << setw(3);
        cout << MatrizA[i][j];
    if (j==N-1){
        cout<<jump;
    }
        }
    }

    cout<<"---------------"<<jump;
         if (MatrizA[0][0]!=1){
                float F = MatrizA[0][0];
            for(int k=0; k<N; k++){
                    MatrizA[0][k] = (MatrizA[0][k])/(F);
                    cout<<"<--------------->"<<jump;
            }
                }

     for(int i=0; i < N; i++){
        for(int j=0; j< N; j++ ){
                cout << setw(3);

        cout <<" "<< MatrizA[i][j];
    if (j==N-1){
        cout<<jump;
    }
        }
    }
    return 0;
}
void coeficintes (float X[][500], int N){
    srand(time(NULL)); /*prueba con números al azar*/
    cout << "Ingrese los coeficientes de cada variable" <<jump;
        for(int i=0; i<N; i++){
            for(int j=0; j< N; j++){
                X[i][j] = rand()%9+1; /* Ingreso de números del 1 al 9 */
                //cin>> X[i][j];
        }
    }
}
