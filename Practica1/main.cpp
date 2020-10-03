#include <iostream>

using namespace std;

/*
    PRACTICA 1
    EDGAR JULIAN CRUZ BUITRAGO
    C.C.  8127774
*/

int main()
{
    int menu, ejer, prob;
    int A=0, B=0, C=0, D=0, E=0;
    float F=0.0, G=0.0;
    double H=3.1416;
    char I;
    while (true) {
        cout << endl;
        cout << "1. Ejercicios" << endl;
        cout << "2. Problemas" << endl;
        cout << "3. Salir" << endl;
        cout << "Por favor seleccione la opcion deseada: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << endl << "Ingrese el numero del ejercicio que desea ejecutar: ";
            cin >> ejer;
            switch (ejer)
            {
            /** EJERCICIOS **/
            case 1:
                cout << "Ingrese el numero A: ";
                cin >> A;
                cout << "Ingrese el numero B: ";
                cin >> B;
                while (B==0) {
                    cout << "El denominador ingresado no es valido. Por favor ingrese uno valido." << endl;
                    cout << "Ingrese el numero B: ";
                    cin >> B;
                }
                cout << endl << "El residuo de la division " << A << "/" << B << " es: " << A%B << endl;
                break;
            case 2:
                cout << "Ingrese el numero A: ";
                cin >> A;
                if (A%2==0) {
                    cout << "El numero ingresado " << A << ", es PAR." << endl;
                } else {
                    cout << "El numero ingresado " << A << ", es IMPAR." << endl;
                }
                break;
            case 3:
                cout << "Ingrese el numero A: ";
                cin >> A;
                cout << "Ingrese el numero B: ";
                cin >> B;
                if (A > B) {
                    cout << "El numero mayor es " << A << endl;
                } else if(B > A) {
                    cout << "El numero mayor es " << B << endl;
                } else {
                    cout << "Los numeros son iguales." << endl;
                }
                break;
            case 4:
                cout << "Ingrese el numero A: ";
                cin >> A;
                cout << "Ingrese el numero B: ";
                cin >> B;
                if (A < B) {
                    cout << "El numero menor es " << A << endl;
                } else if(B < A) {
                    cout << "El numero menor es " << B << endl;
                } else {
                    cout << "Los numeros son iguales." << endl;
                }
                break;
            case 5:
                cout << "Ingrese el numero A: ";
                cin >> A;
                cout << "Ingrese el numero B: ";
                cin >> B;
                while (B==0) {
                    cout << "El denominador ingresado no es valido. Por favor ingrese uno valido." << endl;
                    cout << "Ingrese el numero B: ";
                    cin >> B;
                }
                cout << A << "/" << B << "=" << A/B;
                break;
            case 6:
                F = 1.0;
                cout << "Ingrese el numero A: ";
                cin >> A;
                cout << "Ingrese el numero B: ";
                cin >> B;
                C=B;
                if (C<0) C=C*-1;
                for (D=1;D<=C;D++){
                    F *= A;
                }
                if (B<0) F=1/F;
                cout << A << "^" << B << "=" << F << endl;
                break;
            case 7:
                B=0;
                cout << "Ingrese el numero A: ";
                cin >> A;
                while (A<0) {
                    cout << "Por favor ingrese un numero positivo" << endl;
                    cout << "Ingrese el numero A: ";
                    cin >> A;
                }
                for (C=0; C<=A; C++) {
                    B += C;
                }
                cout << "La sumatoria desde 0 hasta " << A << " es: " << B << endl;
                break;
            case 8:
                B=1;
                cout << "Ingrese un numero A positivo: ";
                cin >> A;
                while (A<0) {
                    cout << "Por favor ingrese un numero positivo" << endl;
                    cout << "Ingrese el numero A: ";
                    cin >> A;
                }
                for (C=1; C<=A; C++) {
                    B *= C;
                }
                cout << A << "!= " << B << endl;
                break;
            case 9:                                
                cout << "Ingrese el radio: ";
                cin >> A;
                cout << "Perimetro: " << 2*H*A << endl;
                cout << "Area: " << H * (A*A) << endl;
                break;
            case 10:
                cout << "Ingrese A: ";
                cin >> A;
                cout << "Multiplos de " << A << "menores de 100:" << endl;
                for (B=1;B<=100;B++) {
                    if (A*B < 100) {
                        cout << A*B << endl;
                    }
                }
                break;
            case 11:
                cout << "Ingrese A: ";
                cin >> A;
                for (B=1; B<=10; B++) {
                    cout << B << "x" << A << "=" << B*A << endl;
                }
                break;
            case 12:
                D=1;
                cout << "Ingrese A: ";
                cin >> A;
                for (B=1;B<=5;B++) {
                    for (C=1; C<=B; C++) {
                        D*=A;
                    }
                    cout << A << "^" << B << "=" << D << endl;
                    D=1;
                }
                break;
            case 13:
                cout << "Ingrese A: ";
                cin >> A;
                cout << "Los divisores de " << A <<" son: " << endl;
                for (B=1;B<=A;B++) {
                    if (A%B == 0) {
                        cout << B << endl;
                    }
                }
                break;
            case 14:
                A=51;
                for (B=1;B<=50;B++) {
                    cout << B << '\t' << A-B << endl;
                }
                break;
            case 15:                
                B=0;
                do {
                    cout << "Ingrese un numero: ";
                    cin >> A;
                    B += A;
                } while (A!=0);
                cout << "El resultado de la sumatoria es: " << B << endl;
                break;
            case 16:
                B=0;
                C=0;
                do {
                    cout << "Ingrese un numero: ";
                    cin >> A;
                    B += A;
                    C++;
                } while (A!=0);
                cout << "El promedio es: " << B/(C-1) << endl;
                break;
            case 17:
                B=0;
                do {
                    cout << "Ingrese un numero: ";
                    cin >> A;
                    if (A > B) {
                        B = A;
                    }
                } while (A!=0);
                cout << "El numero mayor fue: " << B << endl;
                break;
            case 18:                                
                cout << "Ingrese un numero entero: ";
                cin >> A;
                for (B=1; B<=(A/2); B++) {
                    if ((B*B) == A) {
                        cout << A << " es un cuadrado perfecto." << endl;
                        break;
                    }
                }
                if ((B >= (A/2)) && (A > 1)) {
                    cout << A << " NO es un cuadrado perfecto." << endl;
                }
                break;
            case 19:
                B = 0;
                cout << "Ingrese un numero: ";
                cin >> A;
                for(int n=1;n<=A;n++) {
                    if(A % n == 0){
                        B++;
                    }
                }
                if(B == 2){
                    cout << A << " es un numero PRIMO." << endl;
                }else{
                    cout<< A <<" NO es un numero PRIMO." << endl;
                }
                break;
            case 20:
                D=0;
                cout << "Ingrese un numero: ";
                cin >> A;
                C = A;
                do {
                    B = C%10;
                    C /= 10;
                    D*=10;
                    D+=B;
                } while (C != 0);
                if (D==A) {
                    cout << A << " es un numero palindromo.";
                } else {
                    cout << A << " NO es un numero palindromo.";
                }
                break;
            case 21:                
                char r;
                cout << "Ingrese un caracter: ";
                cin >> r;
                A=r;
                if (A>=65 && A<=90) {
                    A+=32;
                    r = char(A);
                    cout << r << endl;
                } else if (A>=97 && A<=122) {
                    A-=32;
                    r = char(A);
                    cout << r << endl;
                } else {
                    cout << "El caracter ingresado no es una letra.";
                }
                break;
            case 22:                
                cout << "Ingrese el valor en segundos: ";
                cin >> A;
                B=A/3600;
                C=A%3600;
                D=C%60;
                C=C/60;
                cout << B << ":" << C << ":" << D << endl;
                break;
            case 23:                
                cout << "Ingrese el numero A: ";
                cin >> A;
                cout << "Ingrese el numero B: ";
                cin >> B;
                E = A*B;
                int minimo;
                if (A<B) minimo = A;
                else if (B<A) minimo = B;
                else minimo = B;
                for (int n=A*B;n>=minimo;n--) {
                    C=n%A;
                    D=n%B;
                    if (C==0 && D==0) {
                        E = n;
                    }
                }
                cout<<"El MCM de "<<A<<" y "<<B<<" es: "<<E<<endl;
                break;
            case 24:
                cout << "Ingrese el numero A: ";
                cin >> A;
                for (B=1;B<=A;B++) {
                    for (C=1;C<=A;C++) {
                        if (B==1 || B==A) {
                            cout << "+";
                        } else if (C==1 || C==A) {
                            cout << "+";
                        } else {
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
                break;
            case 25:
                B=0;
                cout << "Ingrese un numero: ";
                cin >> A;
                C = A;
                do {
                    C /= 10;
                    B++;
                } while (C != 0);
                cout << A << " tiene " << B << " digitos." << endl;
                break;
            case 26:
                cout << "Ingrese valor de lado A: ";
                cin >> A;
                cout << "Ingrese valor de lado B: ";
                cin >> B;
                cout << "Ingrese valor de lado C: ";
                cin >> C;
                if (A==B && A==C && B==C) {
                    cout << "Se forma un triangulo equilatero." << endl;
                } else {
                        D=max(A,B);
                        if (A>B) D=A;
                        else D=B;
                        if (C>D) D=C;
                        if (((A==D) && (B+C<=A)) || ((B==D) && (A+C<=B)) || ((C==D) && (A+B<=C))) {
                            cout << "Las longitudes ingresadas no forman un triangulo." << endl;
                        } else if (A==B || A==C || B==C) {
                            cout << "Se forma un triangulo isosceles." << endl;
                        } else {
                            cout << "Se forma un triangulo escaleno." << endl;
                        }
                }
                break;
            case 27:
                cout << "Ingrese numero A: ";
                cin >> A;
                cout << "Ingrese un operando (+,-,*,/): ";
                cin >> I;
                cout << "Ingrese numero B: ";
                cin >> B;
                C = I;
                if (C==43) {
                    cout << A << "+" << B << "=" << A+B << endl;
                } else if (C==45) {
                    cout << A << "-" << B << "=" << A-B << endl;
                } else if (C==42) {
                    cout << A << "*" << B << "=" << A*B << endl;
                } else if (C==47) {
                    cout << A << "/" << B << "=" << A/B << endl;
                } else {
                    cout << "El operando ingresado no es valido." << endl;
                }
                break;
            case 28:                
                F = 4.0;
                G = 0.0;
                B = 1;
                cout << "Ingrese el numero de elementos: ";
                cin >> A;
                for (float n=3;n<A*2;n+=2) {
                   B*=-1;
                   G=(4/n)*B;
                   F+=G;
                }
                cout << "pi es aproximadamente: " << F << endl;
                break;
            case 29:
                B=0;
                C=101;
                char I;
                srand(time_t(NULL));
                do {
                    E = C - B;
                    A = rand() % E + B;
                    cout << "El numero que pensaste es: " << A << " ? (<,>,=)" << endl;
                    cin >> I;
                    D = I;
                    if (D==62) {
                        B = A+1;
                    } else if (D == 60) {
                        C = A;
                    }
                    if (C-B==1) {
                        cout << "Tu numero es " << B << endl;
                        break;
                    }
                } while (D!=61);
                break;
            case 30:
                C=0;
                srand(time_t(NULL));
                A = rand() % 101;
                do {
                    cout << "Adivina el numero que tengo en memoria: ";
                    cin >> B;
                    C++;
                    if (B>A) {
                        cout << "El numero que ingresaste es mayor al que tengo en memoria." << endl;
                    } else if (B<A) {
                        cout << "El numero que ingresaste es menor al que tengo en memoria." << endl;
                    }
                } while (A!=B);
                cout << "Adivinaste!! en " << C << " intentos." << endl;
                break;
            default:
                cout << endl << "El ejercicio seleccionado no existe";
                break;
            }
            break;
        case 2:
            cout << endl << "Ingrese el numero del problema que desea ejecutar: ";
            cin >> prob;
            switch (prob)
            {
            case 1:
                /* code */
                break;

            default:
                cout << endl << "El problema seleccionado no existe";
                break;
            }
            break;
        case 3:
            exit(0);
        default:
            cout << endl << "La opcion seleccionada no existe";
            break;
        }
    }
}
