#include <iostream>

using namespace std;
#include "network.h"
//PROTOTIPOS
int showMenu();
void playOption(int option);

//VARIABLES
network MiRed;

int main()
{
    // Inicializa elementos
    int option = -1; // Opción seleccionada
    while (option != 0) {
        system("CLS");
        // Mostrar en pantalla menu de opciones
        option = showMenu();
        // Se ejecuta la accion seleccionada.
        playOption(option);
    }
    return 0;
}

int showMenu() {
    int opt=0;
    cout << "\t" << "*********   MENU PRINCIPAL   *********" << endl << endl;
    cout << "\t1. Mostrar Red" << endl;
    cout << "\t2. Agregar Enrutador" << endl;
    cout << "\t3. Eliminar Enrutador" << endl;
    cout << "\t4. Estimar costo de envio de paquete" << endl;
    cout << "\t5. Mostrar camino eficiente de paquete" << endl;
    cout << "\t6. Cargar configuracion de red" << endl;
    cout << "\t7. Generar red aleatoria" << endl;
    cout << "\t0. Salir" << endl << endl;
    cout << "\tSeleccione una opcion: ";
    cin >> opt;
    return opt;
}

void playOption(int option) {
    // Se valida la opcion ingresada
    switch (option) {
        case 1:
            MiRed.show();
            break;
        case 2:
            MiRed.addRouter();
            break;
        case 3:
            MiRed.removeRouter();
            break;
        case 4:
            MiRed.pathCalculate();
            break;
        case 5:
            MiRed.pathCalculate();
            break;
        case 6:
            MiRed.loadConfig();
            break;
        case 7:
            MiRed.loadRandom();
            break;
        case 0:
            return;
            break;
        default:
            cout << endl << "\tLa opcion seleccionada no es válida." << endl;
        break;
    }
}
