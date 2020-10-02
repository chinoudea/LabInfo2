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
    int A=0, B=0, C=0, D=0;
    float F=0.0;
    double PI=3.1416;
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
                for (int n=1;n<=C;n++){
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
                for (int n=0; n<=A; n++) {
                    B += n;
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
                for (int n=1; n<=A; n++) {
                    B *= n;
                }
                cout << A << "!= " << B << endl;
                break;
            case 9:                                
                cout << "Ingrese el radio: ";
                cin >> A;
                cout << "Perimetro: " << 2*PI*A << endl;
                cout << "Area: " << PI * (A*A) << endl;
                break;
            case 10:
                cout << "Ingrese A: ";
                cin >> A;
                cout << "Multiplos de " << A << "menores de 100:" << endl;
                for (int n=1;n<=100;n++) {
                    if (A*n < 100) {
                        cout << A*n << endl;
                    }
                }
                break;
            case 11:
                cout << "Ingrese A: ";
                cin >> A;
                for (int n=1; n<=10; n++) {
                    cout << n << "x" << A << "=" << n*A << endl;
                }
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                break;
            case 21:
                break;
            case 22:
                break;
            case 23:
                break;
            case 24:
                break;
            case 25:
                break;
            case 26:
                break;
            case 27:
                break;
            case 28:
                break;
            case 29:
                break;
            case 30:
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
