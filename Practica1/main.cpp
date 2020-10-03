#include <iostream>

using namespace std;

/*
    PRACTICA 1
    EDGAR JULIAN CRUZ BUITRAGO
    C.C.  8127774
*/
void problema15();
int main()
{
    int menu, ejer, prob;
    int A=0, B=0, C=0, D=0, E=0;
    float F=0.0, G=0.0;
    double H=3.1416;
    char I;
    //Variables adicionales usadas en problemas
    int valores[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int horaDia, duracion, auxH1=0, auxM1=0, auxH2=0, auxM2=0, resultado;
    int numero, digito, control, count=0;
    double control2, control3=10, sumatoria = 0, potencias=0;
    bool esMCM, encontrado;
    //Ciclo principal
    while (true) {
        cout << endl << endl;
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
                cout << "Ingrese un caracter: ";
                cin >> I;
                A=I;
                if (A==65 || A==69 || A==73 || A==79 || A==85 || A==97 || A==101 || A==105 || A==111 || A==117) {
                    cout << "El caracter ingresado es una vocal." << endl;
                } else if ((A>=65 && A<=90)||(A>=97 && A<=122)) {
                    cout << "El caracter ingresado es una consonante." << endl;
                } else {
                    cout << "El dato ingresado no es vocal ni consonante." << endl;
                }
                break;
            case 2:
                cout << "Ingrese el valor que desea convertir: ";
                cin >> A;
                B = A;
                for (int n=0; n<10; n++) {
                    cout << valores[n] << ": " << B/valores[n] << endl;
                    B%=valores[n];
                }
                if (B>0) cout << "Faltante: "<< B << endl;
                break;
            case 3:
                cout << "Digite un numero de mes: ";
                cin >> A;
                if (A < 1 || A > 12) {
                    cout << A << " es un mes invalido." << endl;
                } else {
                    cout << "Digite un numero de dia para ese mes: ";
                    cin >> B;
                    if (B < 1 || B > 31) {
                        cout << B << " es un dia invalido." << endl;
                    } else if ((A==4 || A==6 || A==9 || A==11)&&(B>30)) {
                        cout << B << "/" << A << " es una fecha invalida." << endl;
                    } else if (A==2 && B>29) {
                        cout << B << "/" << A << " es una fecha invalida." << endl;
                    } else if (A==2 && B==29) {
                        cout << B << "/" << A << " es una fecha valida en bisiesto." << endl;
                    } else {
                        cout << B << "/" << A << " es una fecha valida." << endl;
                    }
                }
                break;
            case 4:
                cout << "Ingrese una hora del dia en formato 24 horas (HHMM): ";
                cin >> horaDia;
                //Tomo las horas y los minutos
                auxH1 = horaDia/100;
                auxM1 = horaDia%100;
                // Validacion de la hora
                if ((horaDia < 0 || horaDia > 2359) || (auxM1 > 59)) {
                    cout << horaDia << "es una hora invalida." << endl;
                } else {
                    cout << "Ingrese una duracion en formato 24 horas (HHMM): ";
                    cin >> duracion;
                    //Tomo las horas y los minutos
                    auxH2 = duracion/100;
                    auxM2 = duracion%100;
                    // Validacion de la duración
                    if ((duracion < 0 || duracion > 2359) || (auxM2 > 59)) {
                        cout << duracion << "es una duracion invalida." << endl;
                    }
                }
                // Tomamos las horas resultantes de sumar los minutos
                resultado = (auxM1+auxM2)/60;
                // Sumamos las horas ingresadas
                resultado += (auxH1+auxH2);
                // Realizamos modulo y multiplicamos por 100 para normalizar la hora y sumamos los minutos restantes.
                resultado = ((resultado%24)*100 + (auxM1+auxM2)%60);
                cout << "La hora es: " << resultado << endl;
                break;
            case 5:
                cout << endl << "Ingrese un numero impar: ";
                cin >> A;
                // Validamos que el numero sea impar e inferior al ancho de caracteres en pantalla.

                if (A%2!=0 && A>0 && A<120) {
                    for (int n=1;n<=A;n+=2) {
                        for (int i=1;i<=((A-n)/2);i++) {
                            cout << " ";
                        }
                        for (int j=1;j<=n;j++) {
                            cout << "*";
                        }
                        cout << endl;
                    }
                    for (int m=A-2;m>=1;m-=2) {
                        for (int i=1;i<=((A-m)/2);i++) {
                            cout << " ";
                        }
                        for (int k=1;k<=m;k++) {
                            cout << "*";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "El numero ingresado no es impar o supera el maximo permitido 119." << endl;
                }
                break;
            case 6:
                F = 1, G=0;
                cout << "Ingrese el numero de elementos: ";
                cin >> A;
                for (int i=0;i<A;i++) {
                    for (int n=1; n<=i; n++) {
                        F *= n;
                    }
                    G += 1/F;
                    F=1;
                }
                cout << "e es aproximadamente: " << G << endl;
                break;
            case 7:
                A = 0, B = 1, C = 0, D = 0;
                cout << "Ingrese el numero N: ";
                cin >> E;
                do {
                    C = A + B;
                    if ((C%2==0) && (C < E)) {
                        D += C;
                    }
                    A=B;
                    B=C;
                }   while (B < E);
                cout << "El resultado de la suma es: " << D << endl;
                break;
            case 8:
                D = 0, E = 0;
                cout << "Ingrese el numero A: ";
                cin >> A;
                cout << "Ingrese el numero B: ";
                cin >> B;
                cout << "Ingrese el numero C: ";
                cin >> C;
                for (int n=1; n<=C; n++) {
                    D = A * n;
                    if (D < C) {
                        if (E>0) {
                            cout << " + ";
                        }
                        cout << D;
                        E += D;
                    } else {
                        break;
                    }
                }
                for (int n=1; n<=C; n++) {
                    D = B * n;
                    if ((D < C) && ((D%A) > 0)) {
                        if (E>0) {
                            cout << " + ";
                        }
                        cout << D;
                        E += D;
                    } else {
                        break;
                    }
                }
                cout << " = " << E << endl;
                break;
            case 9:
                count= 0, control3=1, sumatoria = 0, potencias=0;
                cout << "Escriba un numero entero: ";
                cin >> numero;
                control = numero;
                do {
                    control=control/10;
                    count++;
                    control3 *= 10;
                } while (control > 0);
                control2 = numero;
                for (int i=count-1; i>=0; i--) {
                    control3 /= 10;
                    digito = int (control2 / control3);
                    control2 = control2 - digito*control3;
                    potencias = digito;
                    for (int n=1;n<digito;n++) {
                        potencias *= digito;
                    }
                    sumatoria = sumatoria + potencias;
                }
                cout << "El resultado de la suma es: " << sumatoria << endl;
                break;
            case 10:
                A = 0, B = 0, count = 0;
                cout << "Ingrese un numero: ";
                cin >> C;
                do {
                    A++;
                    // Limpio el control para identificar el numero primo
                    B=0;
                    for(int n=1;n<=A;n++) {
                        if(A % n == 0){
                            B++;
                        }
                    }
                    if(B == 2){
                        count ++;
                    }
                } while (count != C);
                cout << "El primo numero " << C << " es " << A;
                break;
            case 11:
                B=1;
                cout << "Ingrese un numero: ";
                cin >> A;
                // Calculamos el comun multiplo de multiplicar todos los numeros.
                for (int i=1; i<=A; i++) {
                    B = B * i;
                }
                //Empezamos a disminuir para encontrar el minimo comun multiplo
                for (int n=B-1;n>=1;n--) {
                    esMCM = true;
                    //Validamos que el numero ingresado si sea multiplo de todos los digitos
                    for (int i=1; i<=A; i++) {
                        C=n%i;
                        if (C!=0) {
                            esMCM = false;
                            break;
                        }
                    }
                    if (esMCM) {
                        B = n;
                    }
                }
                cout << "El minimo comun multiplo es " << B << endl;
                break;
            case 12:
                resultado=0;
                cout << "Ingrese un numero: ";
                cin >> B;
                for (int i=B; i>=2; i--) {
                    // Validamos que el número sea factor de B
                    if (B%i == 0) {
                        // Limpio el control para identificar el numero primo
                        A=0;
                        for(int n=1;n<=i;n++) {
                            if(i % n == 0){
                                A++;
                            }
                        }
                        if(A == 2){
                            resultado = i;
                            break;
                        }
                    }
                }
                cout << "El mayor factor primo de " << B << " es: " << resultado << endl;
                break;
            case 13:
                A=0, resultado=0;
                cout << "Ingrese un numero: ";
                cin >> B;
                // Realizamos un ciclo con cuenta descendiente para encontrar los primos menores al numero ingresado
                for (int i=B; i>=2; i--) {
                    // Limpio el control para identificar el numero primo
                    A=0;
                    for(int n=1;n<=i;n++) {
                        if(i % n == 0){
                            A++;
                        }
                    }
                    if(A == 2){
                        resultado = resultado + i;
                    }
                }
                cout << "El resultado de la suma es : " << resultado << endl;
                break;
            case 14:
                encontrado = false;
                resultado=0, D=0;
                //Creamos 2 ciclos de todos los numeros de 3 digitos y anidados para todas las posibles combinaciones
                for (int i=999; i>99 ; i--) {
                    for (int j=999; j>99 ; j--) {
                        resultado=i*j;
                        C = resultado;
                        do {
                            B = C%10;
                            C /= 10;
                            D*=10;
                            D+=B;
                        } while (C != 0);
                        if (D==resultado) {
                            cout << i << " * " << j << " = " << resultado << endl;
                            encontrado = true;
                            break;
                        }
                        D=0;
                    }

                    if (encontrado) {
                        break;
                    }
                }
                break;
            case 15:
                problema15();
                break;
            case 16:
                count=0, C = 0, D=0;
                cout << "Ingrese un valor k: ";
                cin >> A;
                for (int i=A-1;i>1;i--) {
                    B=i;
                    count++;
                    do {
                        if (B%2==0) {
                            B = B / 2;
                            count++;
                        } else {
                            B = (3 * B) + 1;
                            count++;
                        }
                    } while(B!=1);
                    if (count > C) {
                        C = count;
                        D = i;
                    }
                    count = 0;
                }
                cout << "La serie mas larga es con la semilla " << D << ", teniendo " << C << " elementos." << endl;
                cout << endl;
                cout << "La serie seria esta:" << endl;
                B = D;
                cout << B << " ";
                do {
                    if (B%2==0) {
                        B = B / 2;
                        count++;
                    } else {
                        B = 3 * B + 1;
                        count++;
                    }
                    cout << B << " ";
                } while(B!=1);
                cout << endl;
                break;
            case 17:
                count=1, B=0, C=0;
                cout << "Ingrese el numero de divisores a validar: ";
                cin >> A;
                //Con este ciclo se recorren todos los numeros triangulares
                do {
                    C=0; // Limpiamos el contador de divisores
                    B = (count*(count+1))/2;
                    // Con este ciclo validamos los divisores de cada numero
                    for (int i=B;i>=1;i--) {
                        if (B%i == 0) {
                            C++;
                        }
                    }
                    count++;
                } while (C <= A);
                cout << "El numero es: " << B << " que tiene " << C << " divisores." << endl;
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

void problema15() {
    //Dimension de la matriz
    int N;
    // Variables para recorrer la matriz
    int i, j;
    // Variables auxiliares para el algoritmo
    int a, b, maxValor, dirRow, dirVert, valor=1;
    bool bandera=false;
    cout << "Ingrese la dimension de la matriz: ";
    cin >> N;
    //Creamos la matriz
    int matriz[N][N];
    // Calculamos maximo valor
    maxValor = N*N;
    // Ubicamos la posicion del primer valor
    if (N%2 == 0) {
        a = N/2 - 1;
    } else {
        a = N/2;
    }
    b = a;
    // Inicializamos los controles de direccion
    dirRow = 1;
    dirVert = 1;
    int dimLlenado = 2;
    //Iniciamos con el llenado de la matriz
    //Se controla el fin del llenado
    do {
            for (int numVeces=0;numVeces<2;numVeces++) {
                for (int c=0;c<dimLlenado;c++) {
                    if (c==0 && bandera) {
                        c++;
                    } else {
                        bandera = true;
                    }
                    matriz[a][b] = valor;
                    if (valor >= maxValor) {
                        valor++;
                        break;
                    }
                    valor++;
                    if ((numVeces==0) && (c != (dimLlenado-1))) {
                        b+=dirRow;
                    } else if ((numVeces==0) && (c == (dimLlenado-1))) {
                        dirRow*=-1;
                        a+=dirVert;
                    } else if ((numVeces==1) && (c != (dimLlenado-1))) {
                        a+=dirVert;
                    } else if ((numVeces==1) && (c == (dimLlenado-1))) {
                        dirVert*=-1;
                        b+=dirRow;
                    }
                }
                if (valor >= maxValor) {
                    break;
                }
            }
            dimLlenado++;
    } while (valor <= maxValor);

    //Se imprime la matriz
    cout << endl;
    if (N>30) {
        cout << "La dimension de la matriz no permitiria una correcta visualizacion." << endl;
    } else {
        for (i=0;i<N;i++) {
            for (j=0;j<N;j++) {
                cout << matriz[i][j];
                if (matriz[i][j]<10 && maxValor<10 && j!=N-1) {
                    cout<< " ";
                } else if (matriz[i][j]<10 && maxValor<100 && j!=N-1) {
                    cout<< "  ";
                } else if (matriz[i][j]<10 && maxValor<1000 && j!=N-1) {
                    cout<< "   ";
                } else if (matriz[i][j]<100 && maxValor<100 && j!=N-1) {
                    cout<< " ";
                } else if (matriz[i][j]<100 && maxValor<1000 && j!=N-1) {
                    cout<< "  ";
                } else {
                    cout<< " ";
                }

            }
            cout << endl;
        }
    }

    cout << endl;
    int sum = 0;
    //Se calcula la sumatoria de la diagonal
    for (i=0;i<N;i++) {
        sum += matriz[i][i];
        if (i!=(N-1-i)) {
            sum += matriz[i][N-1-i];
        }
    }
    cout << "En una matriz " << N << "x" << N << ", la suma es: " << sum << endl;
}
