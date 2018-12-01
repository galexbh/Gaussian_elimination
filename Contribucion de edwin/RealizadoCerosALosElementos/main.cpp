#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
    void DiagonalEnUno(int, float X[][100], float);
int main()
{
    int N= 4;
    srand(time(NULL));
    //int N= rand()%10+2;


    int a = 1;
    int C = 0;
    int b= 0;
    int Finalizar_Ciclo=1;
    float aux=0;
    float eliminar = 0;
    float elemento1=0;
    float elemento2=0;
    float diagonal=1;
    int estatico=0;
    int columnas_fijas = 0;
    int filas_fijas = 0;
    float elemento_Permanente1;
    float elemento_Permanente2;
    float Renglon_Evaluar=0;


    float multiplo, variado, division;
    int fijo, recorrido;

    //Matriz
    float X[100][100];
    float temp[100][100];
    int B[100];

    for(int i=0; i < N; i++)
    {
        for(int j=0; j< N; j++ )
        {
           // cout<<"**************************--------------------> "<<endl;
            X[i][j] = rand()%10+1;


        }

    }

    cout<<"Imprimiendo la  matriz original"<<endl;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j< N; j++ )
        {
            cout << setw(3);
            cout <<" "<< X[i][j];
            temp[i][j] = X[i][j];
            if (j==N-1)
            {
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
        for(int k=0; k < N; k++)
        {
            X[0][k] = (X[0][k])/(F);
            //  cout<<"<--------------->"<<endl;
        }
    }
    //Hacer ceros debajo de la primera columna
    for(int Ceros=0;Ceros<N; Ceros++){
    for(int Fila=a; Fila<N; Fila++)
    {
        elemento_Permanente2 = (-1)*(X[Fila][Ceros]);
        for(int Columnas=C; Columnas<N; Columnas++)
        {
            elemento_Permanente1 = X[Ceros][Columnas];
            Renglon_Evaluar = elemento_Permanente2;
            eliminar = elemento_Permanente1*Renglon_Evaluar;
            X[Fila][Columnas]= X[Fila][Columnas] + eliminar;
            //cout<<"--------------------> "<<Columnas<<endl;
        }
        DiagonalEnUno(N, X, diagonal);

    }

    a+=1;
    C+=1;
    }

    cout<<"Imprimiendo la  matriz Con la diagonal en (1)"<<endl;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j< N; j++ )
        {
            cout << setw(3);
            cout <<" "<< X[i][j];
            if (j==N-1)
            {
                cout<<endl;
            }
        }

    }

    cout<<"Imprimiendo la nueva matriz"<<endl;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j< N; j++ )
        {
            cout << setw(3);

            cout <<"|"<<setprecision(5)<< X[i][j];
            if (j==N-1)
            {
                cout<<endl;
            }
        }

    }

    return 0;
}
 void DiagonalEnUno(int N, float X[][100], float diagonal){
    for (int D=1; D<N; D++)
    {
        diagonal = X[D][D];
        for (int M=1; M<N; M++)
        {
            X[D][M] = (X[D][M])/(diagonal);
        }

    }
    }
