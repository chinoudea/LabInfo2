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
    int A=0, B=0, C=0;
    while (true) {
        cout << "1. Ejercicios" << endl;
        cout << "2. Problemas" << endl;
        cout << "Por favor seleccione la opcion deseada." << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << endl << "Ingrese el numero del ejercicio que desea ejecutar: ";
            cin >> ejer;
            switch (ejer)
            {
            case 1:
                /* code */
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
        default:
            cout << endl << "La opcion seleccionada no existe";
            break;
        }
    }
}
