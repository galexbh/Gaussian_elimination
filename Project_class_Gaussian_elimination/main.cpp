/** Gaussian elimination programming class I C ++   **/

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

/* Funciones*/

void DiagonalEnUno(int, float X[][100], float);
void Ingreso_de_datos (float X[][100], float temp[][100], int);

/*-------------------------*/

int main(){

    //Variables
    int NxN=4;
    srand(time(NULL));      //Función para generar números al azar.
    //int NxN= rand()%10+2;
    int a=1;
    int C=0;
    int b=0;
    int Finalizar_Ciclo=1;
    float aux=0;
    float eliminar=0;
    float elemento1=0, elemento2=0;
    float diagonal=1;
    int estatico=0;
    int columnas_fijas=0;
    int filas_fijas=0;
    float elemento_Permanente1, elemento_Permanente2;
    float Renglon_Evaluar=0;
    float multiplo, variado, division;
    int fijo, recorrido;
    /*-------------------------*/

    //Matrices
    float X[100][100];
    float temp[100][100];
    int Argumentos[100];

    /*-------------------------*/

    /** Entrada de datos **/

    /*cout << "Ingrese el tamaño de la matriz" <<endl;
    cin >> NxN;*/

    Ingreso_de_datos(X,temp,NxN);

    cout<<"Imprimiendo la  matriz original"<<endl;

    for(int i=0; i < NxN; i++){
        for(int j=0; j< NxN; j++ ){

            cout << setw(6);
            cout <<" "<< X[i][j];
            temp[i][j] = X[i][j];
            if (j==NxN-1){
                cout<<endl;
            }
        }
    }


    cout<<"---------------"<<endl;
    //Hacer toda la diagonal 1. Crear una funcion para este ciclo


//Haciedo uno (1) al primer elemento
    if (X[0][0]!=1)
    {
        float F= X[0][0];
        for(int k=0; k < NxN; k++)
        {
            X[0][k] = (X[0][k])/(F);
            //  cout<<"<--------------->"<<endl;
        }
    }

    //Hacer ceros debajo de la primera columna
    for(int Ceros=0; Ceros<NxN; Ceros++)
    {
        for(int Fila=a; Fila<NxN; Fila++)
        {
            elemento_Permanente2 = (-1)*(X[Fila][Ceros]);
            for(int Columnas=C; Columnas<NxN; Columnas++)
            {
                elemento_Permanente1 = X[Ceros][Columnas];
                Renglon_Evaluar = elemento_Permanente2;
                eliminar = elemento_Permanente1*Renglon_Evaluar;
                X[Fila][Columnas]= X[Fila][Columnas] + eliminar;
                //cout<<"--------------------> "<<Columnas<<endl;
            }
            DiagonalEnUno(NxN, X, diagonal);
        }

        a+=1;
        C+=1;
    }

    /** Mostrar proceso de matriz con diagonal en (1)**/
/*    cout<<"Imprimiendo la  matriz Con la diagonal en (1)"<<endl;
    for(int i=0; i < NxN; i++){
        for(int j=0; j< NxN; j++ ){

            cout << setw(3);
            cout <<" "<< X[i][j];

            if (j==NxN-1){

                cout<<endl;
            }
        }
    }
*/

    /** Final del proceso**/
    cout<<"Imprimiendo la nueva matriz"<<endl;
    for(int i=0; i < NxN; i++){
        for(int j=0; j< NxN; j++ ){

            cout << setw(3);
            cout <<"|"<<setprecision(6)<< X[i][j];

            if (j==NxN-1){

                cout<<endl;
            }
        }
    }

    return 0;
}
void DiagonalEnUno(int NxN, float X[][100], float diagonal){

    for (int D=1; D<NxN; D++){

        diagonal = X[D][D];

        for (int M=1; M<NxN; M++){

            X[D][M] = (X[D][M])/(diagonal);
        }
    }
}
void Ingreso_de_datos(float X[][100], float temp[][100], int NxN){

        cout<<"\nDigite los elementos de la matriz en la posicion: "<<endl;

    for(int i=0; i<NxN; i++){
        for(int j=0; j<NxN; j++){

//            X[i][j] = rand()%4+1;       /* Números al azar por pruebas*/
            cout << "[" << i << "," << j <<"] = ";
            cin >> X[i][j];               /* Ingreso de datos*/
            temp[i][j] = X[i][j];         /* Pasar datos a Matriz Auxiliar*/
        }
    }
}
