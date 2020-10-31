#include "lab.h"

void eliminar_repetidos(char *cad, int a){
    char *no_rep = new char[a+1];
    int k=0;
    no_rep[0]='\0';
    for(int i=0;cad[i]!='\0';i++){
        for(k=0; cad[i]!=no_rep[k] && no_rep[k]!='\0';k++);
        if(no_rep[k]=='\0'){
            no_rep[k]=cad[i];
            no_rep[k+1]='\0';
            cout << cad[i];
        }
    }
    cout << endl;
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

void fun_c(double *a, int n, double *promedio, double *suma){
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++)
        *suma += *(a + i);
    *promedio = *suma / n;
}

bool fun_prob3(char a[], int tam1, char b[], int tam2) {
    if ( tam1 != tam2) {
        return false;
    }
    for (int i=0; i<tam1; i++) {
        if (a[i]!=b[i]) {
            return false;
        }
    }
    return true;
}

int fun_prob4(char a[]) {
    int longitud=0;
    int digito, convertido=0;
    for (int i=0;i<80;i++) {
        if (a[i]!='\0') {
            longitud++;
        } else {
            break;
        }
    }
    for (int i=longitud-1, j=0;i>=0;i--, j++) {
        digito = a[i] - 48;
        for (int k=0;k<j;k++) {
            digito*=10;
        }
        convertido+=digito;
    }
    return convertido;
}

void fun_prob5(int a, char b[]){
    int control=a;
    int numAux=0, cont=0;
    int mod;
    while(control>0) {
        numAux*=10;
        mod=control%10;
        control/=10;
        numAux+=mod;
    }
    while(numAux>0) {
        mod=numAux%10;
        numAux/=10;
        b[cont]=mod+48;
        cont++;
    }
    b[cont]='\0';
}

int fun_prob10(char a) {
    switch (a) {
    case 'M':
        return 1000;
        break;
    case 'D':
        return 500;
        break;
    case 'C':
        return 100;
        break;
    case 'L':
        return 50;
        break;
    case 'X':
        return 10;
        break;
    case 'V':
        return 5;
        break;
    case 'I':
        return 1;
        break;
    case '\0':
        return 0;
        break;
    }
}

bool fun_prob11(int fila, int silla, char a[15][20], char status) {
    if (a[fila][silla]=='+') {
        if (status=='+') {
            return false;
        } else {
            a[fila][silla]='-';
            return true;
        }
    } else {
        if (status=='-') {
            return false;
        } else {
            a[fila][silla]='+';
            return true;
        }
    }
}

int fun_prob13(int foto[6][8], int fila, int column) {

    int cont = 0;
    double calculo = 0.0;
    for(int i=0; i<fila;i++){
        for(int j=0; j<column;j++){
            if ((i==0)||(j==0)||(i==fila-1)||(j==column-1)) {
                continue;
            } else {
                calculo = foto[i][j]+foto[i][j-1]+foto[i][j+1]+foto[i-1][j]+foto[i+1][j];
                calculo/=5;
                if (calculo>6) {
                    cont++;
                }
            }
        }
    }
    return cont;
}
void fun_prob15(int a[], int b[], int c[]){
    int x1a = a[0];
    int y1a = a[1];
    int x2a = x1a + a[2];
    int y2a = y1a + a[3];
    int x1b = b[0];
    int y1b = b[1];
    int x2b = x1b + b[2];
    int y2b = y1b + b[3];
    if ((x2a>x1b)&&(y2a>y1b)) {
        c[0]=x1b;
        c[1]=y1b;
        c[2]=x2a-x1b;
        c[3]=y2a-y1b;
    }
    if ((x2b>x1a)&&(y2b>y1a)) {
        c[0]=x1a;
        c[1]=y1a;
        c[2]=x2b-x1a;
        c[3]=y2b-y1a;
    }
}


int fun_prob16(int numero) {
    int B=1;
    // Calculamos el comun multiplo de multiplicar todos los numeros.
    for (int i=1; i<=numero; i++) {
        B = B * i;
    }
    return B;
}


