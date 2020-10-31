#include "lab.h"
#include "stdio.h"

/*
    PRACTICA 2
    EDGAR JULIAN CRUZ BUITRAGO
    C.C.  8127774
*/

// PROTOTIPOS DE FUNCIONES DECLARADAS EN EL MAIN



int main()
{
    //Variables Globales
    int menu, ejer, prob;
    //Variables Ejercicio 1
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //Variables Ejercicio 2
    double array2[10] = {1, 12, 23, 34, 45, 55, 66, 77, 88, 99};
    double varPromedio = 0;
    double varSuma = 0;
    //Variables Ejercicio 3
    unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};
    //Variables Problema 1
    int valores[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int cantidad;
    int num;
    //Variables Problema 2
    char charList[200];
    int countletras[26];
    //Variables Problema 3
    char cadena1[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char cadena2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'h', 'h', 'i', 'j'};
    //Variables Problema 4
    char userInput[80];
    //Variables Problema 5
    int intInput;
    char salida[80];
    //Variables Problema 6
    int cont = 0;
    char letra;
    //Variables Problema 7
    char validate[80];
    int cont2 = 0;
    //Variables Problema 8
    char charArray[80];
    char numArray[80];
    int cont0=0, cont1=0;
    //Variables Problema 9
    int n, digito;
    int tam=0, sum=0, lim=0;
    // Variables Problema 11
    char asientos[15][20];
    int option = 0, silla;
    char fila;
    bool flag=true;
    // Variables Problema 12
    const int dimension=3;
    int sumf=0, sumc=0, backf=0, backc=0;
    int matriz[dimension][dimension];
    //Variables Problema 13
    int matriz13[6][8] = {{0,3,4,0,0,0,6,8},
                        {5,13,6,0,0,0,2,3},
                        {2,6,2,7,3,0,10,0},
                        {0,0,4,15,4,1,6,0},
                        {0,0,7,12,6,9,10,4},
                        {5,0,6,10,6,4,8,0}};
    //Variables Problema 14
    int matriz14[5][5];
    //Variables Problema 15
    int rect1[]={0,0,8,4};
    int rect2[]={5,2,6,7};
    int rect3[4];
    //Variables Problema 16
    int dimM=0;
    int caminos=0;
    //Ciclo principal
    while (true) {
        cout << endl << endl;
        cout << "1. Ejercicios" << endl;
        cout << "2. Problemas" << endl;
        cout << "3. Salir" << endl;
        cout << "Por favor seleccione la opcion deseada: ";
        cin >> menu;
        switch (menu) {
        case 1:
            cout << endl << "Ingrese el numero del ejercicio que desea ejecutar: ";
            cin >> ejer;
            switch (ejer)
            {
            /** EJERCICIOS **/

            case 1:
                cout << endl;
                cout << "La direcccion de memoria de array es : " << &array << endl;
                cout << "Como es un arreglo de tipo int cada posicion de memoria es de " << sizeof (array[0]) << " bytes." << endl;
                cout << "La direccion de memoria del elemento array[3] es " << &array[3] << endl;
                cout << "El contenido en memoria del elemento array[3] es " << array[3] << endl;
                fun_b(array, 10);
                cout << "El efecto de fun_b sobre el arreglo array es que lo recorre de inicio a fin y fin a inicio, intercambiando los valores de posicion." << endl;
                break;
            case 2:
                cout << endl;
                fun_c(array2,10,&varPromedio,&varSuma);
                cout << "El Promedio calculado fue= " << varPromedio << endl;
                cout << "La Suma calculada fue= " << varSuma << endl;
                break;
            case 3:
                cout << endl;
                cout << "DETALLE DE LAS POSICIONES DEL ARREGLO B" << endl << endl;
                cout << "B = " << &b << endl;
                cout << "B[0] = " << &b[0] << endl;
                cout << "\t" << "B[0][0] = " << &b[0][0] << endl;
                cout << "\t" << "B[0][1] = " << &b[0][1] << endl;
                cout << "B[1] = " << &b[1] << endl;
                cout << "\t" << "B[1][0] = " << &b[1][0] << endl;
                cout << "\t" << "B[1][1] = " << &b[1][1] << endl;
                cout << "B[2] = " << &b[2] << endl;
                cout << "\t" << "B[2][0] = " << &b[2][0] << endl;
                cout << "\t" << "B[2][1] = " << &b[2][1] << endl;
                cout << "B[3] = " << &b[3] << endl;
                cout << "\t" << "B[3][0] = " << &b[3][0] << endl;
                cout << "\t" << "B[3][1] = " << &b[3][1] << endl << endl;
                cout << "DETALLE DE EVALUACION DE EXPRESIONES CON ARREGLO B" << endl << endl;
                cout << "b: " << b << endl;
                cout << "b+2: " << b+2 << endl;
                cout << "*(b+2): " << *(b+2) << endl;
                cout << "*(b+2)+1: " << *(b+2)+1 << endl;
                cout << "*(*(b+2)+1): " << *(*(b+2)+1) << endl;
                cout << "b[3][1]: " << b[3][1] << endl;
                cout << "*b++: Este comando arroja error: cannot increment value of type unsigned short [4][2]" << endl;
                break;
            case 4:
                cout << endl;
                cout << "El desarrollo del ejercicio se encuentra en el siguiente enlace: " << endl;
                cout << "\t" << "https://www.tinkercad.com/things/2hSftflFZ5H" << endl;
                break;
            case 5:
                cout << endl;
                cout << "El desarrollo del ejercicio se encuentra en el siguiente enlace: " << endl;
                cout << "\t" << "https://www.tinkercad.com/things/4GOngWMuuN2" << endl;
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
                cout << endl;
                cout << "Ingrese un valor: ";
                cin >> cantidad;
                cout << endl;
                for (int i=0; i<10; i++) {
                    num = cantidad/valores[i];
                    cout << valores[i] << " = " << num << endl;
                    cantidad = cantidad - (valores[i]*num);
                }
                if (cantidad > 0) {
                    cout << "Faltante: " << cantidad << endl;
                }
                break;
            case 2:
                cout << endl;
                for(int i=0;i<200;i++) {
                    charList[i]=rand() % 26 + 65;
                }
                cout << "El arreglo de caracteres es: " << endl << endl;
                cout << charList << endl;
                for(int i=0; i<26;i++) {
                    countletras[i]=0;
                    for (int j=0; j<200; j++) {
                        if (charList[j]==(i+65)) {
                            countletras[i] = countletras[i] + 1;
                        }
                    }
                    if (countletras[i]>0) {
                        cout << char(i+65) << " : " << countletras[i] << endl;
                    }
                }
                break;
            case 3:
                cout << endl ;
                if (fun_prob3(cadena1, 10, cadena2, 10)) cout << "Son iguales" << endl;
                else  cout << "Son diferentes" << endl;
                break;
            case 4:
                cout << endl;
                cout << "Ingrese un valor numerico: ";
                cin >> userInput;
                cout << endl << "El valor convertido >> " << fun_prob4(userInput) << endl;
                break;
            case 5:
                cout << endl;
                cout << "Ingrese un valor numerico: ";
                cin >> intInput;
                fun_prob5(intInput, salida);
                cout << endl << "El valor convertido >> " << salida << endl;
                break;
            case 6:
                cout << "Ingrese un texto: ";
                cin >> userInput;
                letra = userInput[cont];
                while(userInput[cont]!='\0') {
                    if(userInput[cont]>=97 && userInput[cont]<=122) {
                        userInput[cont] = userInput[cont] - 32;
                    }
                    cont++;
                }
                cout << endl << "El resultado es: " << userInput << endl;
                break;
            case 7:
                cout << "Ingrese un texto: ";
                cin >> userInput;
                while(userInput[cont]!='\0') {
                    if(cont==0) {
                        validate[cont2]=userInput[cont];
                        cont2++;
                        cont++;
                        continue;
                    }
                    bool flag = true;
                    for(int i=0;i<cont;i++) {
                        if(validate[i]==userInput[cont]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        validate[cont2]=userInput[cont];
                        cont2++;
                    }
                    cont++;
                }
                validate[cont2]='\0';
                cout << endl << "El resultado: " << validate << endl;
                break;
            case 8:
                cout << "Ingrese un texto: ";
                cin >> userInput;
                while(userInput[cont0]!='\0') {
                    if (userInput[cont0]>=48 && userInput[cont0]<=57){
                        numArray[cont1]=userInput[cont0];
                        cont1++;
                    } else {
                        charArray[cont2]=userInput[cont0];
                        cont2++;
                    }
                    cont0++;
                }
                numArray[cont1]='\0';
                charArray[cont2]='\0';
                cout << endl << "Original: " << userInput << endl;
                cout << "Texto: " << charArray << endl;
                cout << "Numero: " << numArray << endl;
                break;
            case 9:
                cout << "Ingrese un numero de caracteres: " ;
                cin >> n;
                cout << "Ingrese un texto: ";
                cin >> userInput;
                while (userInput[tam]!='\0') {
                    tam++;
                }
                lim = n-1;
                for(int i=tam-1;i>=0;i--) {
                    digito = userInput[i] - 48;
                    for(int i=0; i<cont; i++) {
                        digito *= 10;
                    }
                    sum += digito;
                    cont++;
                    if (cont > lim) {
                        cont=0;
                    }
                }
                cout << endl << "Original: " << userInput << endl;
                cout << "Suma: " << sum << endl;
                break;
            case 10:
                cont=0, sum=0;
                cout << "Ingrese un numero romano: ";
                cin >> userInput;
                while (userInput[cont]!='\0') {
                    int act = fun_prob10(userInput[cont]);
                    int next = fun_prob10(userInput[cont+1]);
                    if(act>=next) {
                        sum+=act;
                    } else {
                        sum-=act;
                    }
                    cont++;
                }
                cout << "Corresponde a: " << sum << endl;
                break;
            case 11:
                // se inicializan los asientos
                for(int i=0; i<15; i++) {
                    for(int j=0; j<20; j++) {
                        asientos[i][j]='+';
                    }
                }
                // Se realiza ciclo para interactuar con el usuario.
                while(flag){
                    system("CLS");
                    // Se muestran en pantalla los asientos
                    for(int i=0; i<15; i++) {
                        cout << endl << "\t";
                        for(int j=0; j<20; j++) {
                            cout << asientos[i][j] << " ";
                        }
                    }

                    cout << endl << endl << "1. Reservar un asiento." << endl;
                    cout << "2. Cancelar una reserva." << endl;
                    cout << "0. Salir" << endl;
                    cout << "Seleccione la opcion deseada: " ;
                    cin >> option;
                    switch (option) {
                        case 0:
                            flag = false;
                            break;
                        case 1:
                            cout << endl << "Seleccione la fila (A-O): ";
                            cin >> fila;
                            cout << endl << "Seleccion la silla (1-20): ";
                            cin >> silla;
                            fila-=65;
                            silla-=1;
                            if (!fun_prob11(fila,silla, asientos,'-')) {
                                cout << endl << "La silla seleccionada ya esta reservada" << endl;
                                system("PAUSE");
                            }
                            break;
                        case 2:
                            cout << endl << "Seleccione la fila (A-O): ";
                            cin >> fila;
                            cout << endl << "Seleccion la silla (1-20): ";
                            cin >> silla;
                            fila-=65;
                            silla-=1;
                            if (!fun_prob11(fila,silla, asientos,'+')) {
                                cout << endl << "La silla seleccionada no esta reservada" << endl;
                                system("PAUSE");
                            }
                            break;
                    }
                }
                break;
            case 12:
                flag=true;
                for(int i=0; i<dimension;i++){
                    for(int j=0; j<dimension;j++){
                        cout << "Por favor ingrese el valor del elemento ("<<i<<","<<j<<"): ";
                        cin >> matriz[i][j];
                        cout << endl;
                    }
                }
                cout << "Se procedera a validar la matriz" << endl;
                //Validacion por filas y columnas
                for(int i=0;i<dimension;i++) {
                    backf = sumf;
                    backc = sumc;
                    sumf = 0;
                    sumc = 0;
                    for(int j=0; j<dimension;j++){
                        sumf+=matriz[i][j];
                        sumc+=matriz[j][i];
                    }
                    if(i!=0) {
                        if ((sumf!=backf) || (sumc!=backc)) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(sumc!=sumf) {
                    flag=false;
                } else {
                    backc=sumc;
                }
                if (flag) {
                    //Validacion por diagonales
                    sumc=0;
                    sumf=0;
                    for(int i=0,j=dimension-1;i<dimension;i++,j--) {
                        sumc+=matriz[i][i];
                        sumf+=matriz[j][j];
                    }
                    if((sumc==sumf)&&(backc==sumc)) {
                        cout << endl << "La matriz es un cuadro magico" << endl;
                    } else {
                        cout << endl << "La matriz no es un cuadro magico" << endl;
                    }
                } else {
                    cout << endl << "La matriz no es un cuadro magico" << endl;
                }
                break;
            case 13:
                cout << "El numero de estrellas identificadas es: " << fun_prob13(matriz13, 6, 8) << endl;
                break;
            case 14:

                option=0;
                cont=1;

                flag=true;
                //Se llena la matriz
                for(int i=0; i<5;i++){
                    for(int j=0; j<5;j++){
                        matriz14[i][j]=cont;
                        cont++;
                    }
                }
                //Ciclo infinito para interactuar con el usuario
                while(flag) {
                    system("CLS");
                    //Se muestra la matriz
                    for(int i=0; i<5;i++){
                        cout << endl;
                        for(int j=0; j<5;j++){
                            cout << matriz14[i][j] << ((matriz14[i][j]<10)?"  ":" ");
                        }
                    }
                    //Se muestran opciones al usuario
                    cout << endl << endl;
                    cout << "1. Girar 90 grados." << endl;
                    cout << "2. Girar 180 grados." << endl;
                    cout << "3. Girar 270 grados." << endl;
                    cout << "0. Para salir" << endl;
                    cout << "Seleccione la opcion deseada: " ;
                    cin >> option;
                    switch (option) {
                        case 0:
                            flag = false;
                            break;
                        case 1:
                            cout << endl;
                            //Se muestra la matriz girada 90
                            for(int i=0; i<5;i++){
                                cout << endl;
                                for(int j=4; j>=0;j--){
                                    cout << matriz14[j][i] << ((matriz14[j][i]<10)?"  ":" ");
                                }
                            }
                            break;
                        case 2:
                            cout << endl;
                            //Se muestra la matriz girada 180
                            for(int i=4; i>=0;i--){
                                cout << endl;
                                for(int j=4; j>=0;j--){
                                    cout << matriz14[i][j] << ((matriz14[i][j]<10)?"  ":" ");
                                }
                            }
                            break;
                        case 3:
                            cout << endl;
                            //Se muestra la matriz girada 180
                            for(int i=4; i>=0;i--){
                                cout << endl;
                                for(int j=0; j<5;j++){
                                    cout << matriz14[j][i] << " ";
                                }
                            }
                            break;
                    }
                    cout << endl;
                    system("PAUSE");
                }
                break;
            case 15:
                fun_prob15(rect1,rect2,rect3);
                cout << "El arreglo C es: " << endl;
                for(int i=0; i<4;i++) {
                    cout << rect3[i] << " ";
                }
                cout << endl;
                break;
            case 16:
                cout << endl << "Ingrese la dimension: ";
                cin >> dimM;
                caminos = fun_prob16(2*dimM)/(fun_prob16(dimM)*fun_prob16(dimM));
                cout << "Para una malla de " << dimM << "x" << dimM << " puntos hay " << caminos << " caminos." << endl;

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


    return 0;
}

