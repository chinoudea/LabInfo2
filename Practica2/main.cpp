#include "lab.h"
#include "stdio.h"
void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void ejercicio();
int main()
{    
    //int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //fun_b(array, 10);
    ejercicio();
    return 0;    
}

void fun_a(int *px, int *py) {
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

void fun_b(int a[], int tam) {
    int f, l;
    int *b = a;
    for (f=0, l=tam; f<1; f++, l--) {
        fun_a(&b[f], &b[l]);
    }
}

void ejercicio() {
    int lon;
    char *cadena;
    cout << "Ingrese la longitud de la cadena: ";
    cin >> lon;
    cadena = new char[lon+1];
    cadena[lon]='\0';
    fflush(stdin);
    fgets(cadena,lon,stdin);
    fgets(cadena,lon,stdin);
    eliminar_repetidos(cadena,lon);
    delete [] cadena;

}
