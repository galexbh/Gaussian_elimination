/**Gaussian elimination programming class I C ++**/

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>

/*Declaración de funciones*/

//float BuscarMultiplo(int b,float X[][4],int M, int N);

/* ----------------------------------------- */

using namespace std;
int main()
{

    /**Declaración de las variables**/

    int N = 3;            /* Tamaño de la matriz*/
//    int N= rand()%5+2; /* Números al azar pruebas de funcionamiento*/
    int a = 1, b = 0, diagonal=1, estatico=0;
    int fijo, recorrido;
    float aux = 0, eliminar = 0;
    float multiplo, variado, division;

    srand(time(NULL));  /*Función para generar números al azar con tiempo de la BIOS*/

    //Matriz
    float X[100][100];
    float temp[100][100];
//    int B[100];

    /** Entrada de datos **/

    /*cout << "Ingrese el tamaño de la matriz" <<endl;
    cin >> N;*/

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

//            X[i][j] = rand()%4+1;       /* Números al azar por pruebas*/
            cout << "[" << i << "," << j <<"] = ";
            cin >> X[i][j];
            temp[i][j] = X[i][j];
        }
    }

    /* ----------------------------------------- */

    /** Imprimir matriz **/

    cout << "Imprimiendo la  matriz original" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++ ){

            cout << setw(3);
            cout <<" "<< X[i][j];
            if (j==N-1){

                cout << endl;
            }
        }
    }
    /* ----------------------------------------- */

    /** Función **/

    cout << "---------------" << endl;
    //Hacer toda la diagonal 1. Crear una funcion para este ciclo
    for (int D=1; D<N; D++){

        diagonal = X[D][D];

        for (int M=0; M<N; M++){

            X[D][M] = (X[D][M])/(diagonal);
        }
    }
//Haciedo uno (1) al primer elemento

    if (X[0][0]!=1){

        float F = X[0][0];
        for(int k=0; k < N; k++){

            X[0][k] = (X[0][k])/(F);
            //  cout<<"<--------------->"<<endl;
        }
    }

    cout << "Imprimiendo la  matriz con la diagonal en (1)" << endl;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            cout << setw(3);
            cout <<" "<< X[i][j];
            if (j==N-1){

                cout << endl;

            }
        }
    }

    //Verificando si hay Ceros (abajo del 1)

    do{
        for (int M=a; M<N; M++){

            cout << "< Haciedo Cero a los elementos. Interaccion #>" << M << endl;
            estatico += b;

            if(X[M][b]!=0){

                //buscando el multiplo
                //aux = BuscarMultiplo(b,X,M,N);

                for(int L=b; L<N; L++){

                    cout<<"El valor de M es:"<<M<<endl;
                    cout<<"El valor de estatico es: "<<estatico<<endl;
                    cout<<"El valor de L es: "<<L<<endl;
                    cout<<"El valor de X[estatico][L] es: "<<X[estatico][L]<<endl;
                    cout<<"El valor de -1*X[M][b] es: "<<(-1)*(X[M][b])<<endl;
                    cout<<"El valor de B es: "<<b<<endl;
                    eliminar = (X[estatico][L])*(-1*X[M][b]);// 3 * (-1*5)= -15

                    cout<<"El valor de ELIMIAR es: "<<eliminar<<endl;
                    //eliminar = -1*X[M][b];
                    X[M][L] = X[M][L] + eliminar; //X = 5+(-5) = 0

                }
            }
            b+=1;
        }
        a+=1;

        cout << b << endl;
    }
    while(a<N);



    cout << "Imprimiendo la nueva matriz" << endl;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            cout << setw(3);
            cout <<" "<<setprecision(1)<< X[i][j];

            if (j==N-1){

                cout << endl;
            }
        }
    }

    return 0;
}

