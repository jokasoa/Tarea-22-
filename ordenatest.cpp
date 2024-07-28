/*
Fecha: 25/7/2024
Autor:Jeremy novoa
Medir el tipo de ejecucion de un algoritmo
*/
#include<iostream>
#include <time.h>
#include <cstdlib>
 #include <windows.h>
using namespace std;
 
//Imprime los elementos del vector
void ImprimeVector(int x[], int total)
{
  for(int k=0; k <total; k++)
  {
    cout<<endl<<x[k];
  }
}
 
//llena el vector con números aleatorios
void VectorNumAleatorios(int vector1[],int vector2[], int vector3[],int total)
{
  int lim_inf = 1;
  int lim_sup = 10000;
  for(int k=0; k < total; k++)
  {
    int numero = lim_inf + rand() % ((lim_sup + 1) - lim_inf);
    vector1[k]=numero;
    vector2[k]=numero;
  }
  //Intercambio de valores
 
}
 void intercambiar(int& num1, int& num2){
  {
    int aux = num1;
    num1=num2;
    num2=aux;
  }
 }
/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
 void burbujaMejorado(int arreglo[], int tamano){

    int comparaciones = tamano;

    bool termino = false;

    for (int i = 0; i<(tamano-1) ; i++){

        if (termino)

            break;

        termino = true;

        for (int j = 0; j<comparaciones-1 ; j++)

            if(arreglo[j] > arreglo[j+1]){

                intercambiar(arreglo[j],arreglo[j+1]);

                termino = false;

            }

        comparaciones--;

    }

}
void ordenShell(int a[], int n){

    int ints,i,aux;
    bool band;
    ints=n;
    while(ints>1){
        ints=ints/2;
        band=true;
        while(band==true){
            band=false;
            i=0;
            while((i+ints)<n){
                if(a[i]>a[i + ints]){
                    aux=a[i];
                    a[i]=a[i + ints];
                    a[i + ints]=aux;
                    band=true;
                }
                i++;
            }

        }

    }

}

void ordenShell2(int a[], int n){//optimizado

    int i,j,inc;

    int temp;

    for(inc=1;inc<n;inc=inc*3+1);

    while(inc>0){

        for(i=inc;i<n;i++){

            j=i;

            temp=a[i];

            while((j>=inc)&&(a[j-inc]>temp)){

                a[j]=a[j-inc];

                j=j-inc;

            }

            a[j]=temp;

        }

        inc=inc/2;

    }

}


int main()
{
  srand(time(NULL));
  const int MAX=10000;

  int vectorBurbuja[MAX];
  int vectorshell[MAX];
  int vectorShellOpt[MAX];
  LARGE_INTEGER t_ini, t_fin;
  double secs,secsshell,segshellOpt;

 VectorNumAleatorios(vectorBurbuja,vectorshell,vectorShellOpt,MAX);
 //Burbuja
 QueryPerformanceCounter(&t_ini);
 burbujaMejorado(vectorBurbuja,MAX);
QueryPerformanceCounter(&t_fin); 
secs = performancecounter_diff(&t_fin, &t_ini);

 //SHELL
 QueryPerformanceCounter(&t_ini);
 ordenShell(vectorshell,MAX);
QueryPerformanceCounter(&t_fin); 
secsshell = performancecounter_diff(&t_fin, &t_ini);
 //SHELL OPT
 QueryPerformanceCounter(&t_ini);
 ordenShell2(vectorShellOpt,MAX);
QueryPerformanceCounter(&t_fin); 
segshellOpt = performancecounter_diff(&t_fin, &t_ini);
cout<<endl<<"Prueba con"<<MAX<<"Elementos";
 cout<<endl<<"Tiempo de ejecucion Burbuja Mejorado: "<<secs *1000.0;
cout<<endl<<"Tiempo de ejecucion SHELL: "<<secsshell *1000.0;
cout<<endl<<"Tiempo de ejecucion de SHELL OPTIMIZADO: "<<segshellOpt * 1000.0;

//SHELL OPTIMIZADO
QueryPerformanceCounter(&t_ini);
QueryPerformanceCounter(&t_fin);


  return 0;
}