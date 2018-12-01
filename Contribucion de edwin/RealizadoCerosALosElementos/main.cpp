#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    int N= 3;
//int N= rand()%5+2;
    float BuscarMultiplo(int b,float X[][4],int M, int N);
    int a = 1;
    int b= 0;
    float aux=0;
    float eliminar = 0;
    int diagonal=1;
    int estatico=0;
    srand(time(NULL));


    float multiplo, variado, division;
    int fijo, recorrido;

    //Matriz
    float X[4][4];
    float temp[4][4];
    // int B[100];

    for(int i=0; i < N; i++)
    {
        for(int j=0; j< N; j++ )
        {
            do
            {
                cout<<"**************************--------------------> ";
                X[i][j] = rand()%4+1;
                temp[i][j] = X[i][j];
            }
            while(X[j][j]==0);
        }

    }

    cout<<"Imprimiendo la  matriz original"<<endl;
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



    cout<<"---------------"<<endl;
    //Hacer toda la diagonal 1. Crear una funcion para este ciclo
    for (int D=1; D<N; D++)
    {
        diagonal = X[D][D];
        for (int M=0; M<N; M++)
        {
            X[D][M] = (X[D][M])/(diagonal);
        }

    }
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

    //Verificando si hay Ceros (abajo del 1)

    do
    {
        for (int M=a; M<N; M++)
        {
            cout<<"< Haciedo Cero a los elementos. Iteraccion #>"<<M<<endl;
            estatico += b;

            if(X[M][b]!=0)
            {
                //buscando el multiplo
                //aux = BuscarMultiplo(b,X,M,N);

                for(int L=b; L<N; L++)
                {
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

        cout<<b<<endl;
    }
    while(a<N);



    cout<<"Imprimiendo la nueva matriz"<<endl;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j< N; j++ )
        {
            cout << setw(3);

            cout <<" "<<setprecision(1)<< X[i][j];
            if (j==N-1)
            {
                cout<<endl;
            }
        }

    }

    return 0;
}

