#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool problemPlay = false;

bool menuPractica();
void ejercicios(int ejercicio);
void encripcionChar(int optEncode, int seed, char *fileInput, char *fileOutput, bool encode);
string encripcionStr(int optEncode, int seed, string fileInput, string fileOutput, bool encode);
void problema();
void encode1Binary(bool txtFileBin[], long long int sizeBit, int seed);
void decode1Binary(bool txtFileBin[], long long int sizeBit, int seed);
void encode2Binary(bool txtFileBin[], long long int sizeBit, int seed);
void decode2Binary(bool txtFileBin[], long long int sizeBit, int seed);
long long int fileSize(char fileInput[]);
void readFile(char *txtFile, char fileInput[]);
void writeBinFile(bool *txtFileBin, long long int sizeBit, char fileOutput[]);
string writeBinFile(bool *txtFileBin, long long int sizeBit, string fileOutput);
void getBinary(bool textBinary[], char *txtFile, long long int size);
void getBinary(bool textBinary[], string *txtFile, long long int size);
string readStrFile(string fileInput);

/* Menu principal para interactuar con el usuario
 *
 * Se encarga de mostrar en pantalla las opciones y procesarlas.
 */
bool menuPractica() {
    int opcion;
    system("CLS");
    cout << endl;
    cout << "1. Metodo 1 (char)" << endl;
    cout << "2. Metodo 1 (string)" << endl;
    cout << "3. Metodo 2 (char)" << endl;
    cout << "4. Metodo 2 (string)" << endl;
    cout << "5. Problema" << endl;
    cout << "0. Salir" << endl;
    cout << endl << "Seleccione la opcion deseada: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        ejercicios(opcion);
        return  true;
        break;
    case 2:
        ejercicios(opcion);
        return true;
        break;
    case 3:
        ejercicios(opcion);
        return  true;
        break;
    case 4:
        ejercicios(opcion);
        return true;
        break;
    case 5:
        problema();
        problemPlay = false;
        return true;
        break;
    case 0:
        return false;
        break;
    default:
        cout << "Se ha seleccionado una opcion invalida." <<endl;
        return true;
        break;
    }
}
/* Metodo para el desarrollo del ejercicio 1
 */
void ejercicios(int ejercicio) {
    // Variables Locales
    int seed, metodo;
    seed = -1;
    char fileInput[80]; //Variable para cargar el nombre del archivo origen
    char fileOutput[80];//Variable para cargar el nombre del archivo destino
    // Code
    while (seed < 3) {
        cout << "Ingrese la semilla: ";
        cin >> seed;
        if (seed < 3) {
            cout<<endl<<"La semilla debe ser un valor superior a 3."<<endl;
        }
    }
    cout << "Ingrese el digito segun lo deseado ENCRIPTAR(1) / DESENCRIPTAR(0): ";
    cin >> metodo;
    cout <<"Ingrese la ruta del archivo de origen: ";
    cin >> fileInput;
    cout << "Ingrese la ruta del archivo de salida: ";
    cin >> fileOutput;
    //Segun el metodo elegido se ejecuta
    if (ejercicio==1)
        encripcionChar(1, seed, fileInput, fileOutput, metodo);
    else if (ejercicio==3)
        encripcionChar(2, seed, fileInput, fileOutput, metodo);
    else if (ejercicio==2)
        encripcionStr(1, seed, fileInput, fileOutput, metodo);
    else if (ejercicio==4)
        encripcionStr(2, seed, fileInput, fileOutput, metodo);
}
/* Metodo en sobrecarga para la parte operativa del ejercicio 1
 */
string encripcionStr(int optEncode, int seed, string fileInput, string fileOutput, bool encode) {
    // Variables Locales
    string response = "";
    string txtFile;
    if (fileInput.compare(0,4,"str.")==0) {
        txtFile = fileInput.substr(4);
    } else {
        txtFile = readStrFile(fileInput);
    }
    long long int size = txtFile.length(); // Variable para manejar el tamaño del archivo procesado.
    bool *txtFileBin = new bool[(size*8)]; // Variable para la representacion en binario del texto en el archivo
    // Code
    // *** AHORA SE CONVIERTE A BINARIO ***
    getBinary(txtFileBin, &txtFile,size);
    // *** SEGUN LA OPCION ELEGIDA SE EJECUTA LA ENCRIPCION ***
    switch (optEncode) {
    case 1:
        if (encode)
            encode1Binary(txtFileBin, (size*8), seed);
        else
            decode1Binary(txtFileBin, (size*8), seed);
        break;
    case 2:
        if (encode)
            encode2Binary(txtFileBin, (size*8), seed);
        else
            decode2Binary(txtFileBin, (size*8), seed);
        break;
    }
    // *** SE ESCRIBE CODIFICACION EN ARCHIVO ***

    response = writeBinFile(txtFileBin, (size*8), fileOutput);
    if ((fileOutput.compare("NA")!=0) && (fileInput.compare(0,4,"str.")!=0)) {
        cout << endl << "Arhivo procesado" << endl;
        system("PAUSE");
    }
    return response;

}
/* Metodo en sobrecarga para la parte operativa del ejercicio 1
 */
void encripcionChar(int optEncode, int seed, char *fileInput, char *fileOutput, bool encode) {
    // Variables Locales
    long long int size=fileSize(fileInput); // Variable para manejar el tamaño del archivo procesado.
    char *txtFile = new char[size]; // Variable para almacenar el texto del archivo
    bool *txtFileBin = new bool[(size*8)]; // Variable para la representacion en binario del texto en el archivo
    // Code
    // ***  LECTURA DE ARCHIVO ***
    readFile(txtFile, fileInput);
    // *** AHORA SE CONVIERTE A BINARIO ***
    getBinary(txtFileBin, txtFile, size);
    // *** SEGUN LA OPCION ELEGIDA SE EJECUTA LA ENCRIPCION ***
    switch (optEncode) {
    case 1:
        if (encode)
            encode1Binary(txtFileBin, (size*8), seed);
        else
            decode1Binary(txtFileBin, (size*8), seed);
        break;
    case 2:
        if (encode)
            encode2Binary(txtFileBin, (size*8), seed);
        else
            decode2Binary(txtFileBin, (size*8), seed);
        break;
    }
    // *** SE ESCRIBE CODIFICACION EN ARCHIVO ***
    writeBinFile(txtFileBin, (size*8), fileOutput);
    cout << endl << "Arhivo procesado" << endl;
    system("PAUSE");
    delete[] txtFile;
}

/* Funcion para ecriptar texto con el primer metodo
 *
 * La funcion recibe los siguientes parametros:
 * txtFileBin: arreglo de bits para codificar
 * sizeBit: Longitud del arreglo de bits
 * seed: Semilla, parametro usado en el metodo de encripción.
 */
void encode1Binary(bool txtFileBin[], long long int sizeBit, int seed) {
    if (!problemPlay) cout << endl << "Texto en binario sin codificar: ";
    for(long long int i=0;i<sizeBit;i++) {
        if (!problemPlay) cout << txtFileBin[i];
    }
    long long int countBits=0;
    int modulo=0; // Variable para el control de codificacion
    bool *seedSample = new bool[seed];  //Arreglo binario del tamaño de la semilla
    while (countBits<sizeBit) {
        int suma=0; //En cada iteracion se realiza la suma del bloque
        for(int i=0;i<seed;i++) {
            if (countBits<seed) { // Si es el primer bloque se codifica de una vez
                suma += txtFileBin[countBits];
                txtFileBin[countBits] = !txtFileBin[countBits];
            } else {
                suma += seedSample[i]; // A partir del segundo bloque usa el arreglo binario de tamaño semilla
            }
            ++countBits;
        }
        // Se valida la suma para realizar la codificacion
        long long int limit = ((countBits+seed)>sizeBit) ? sizeBit : (countBits+seed) ; //Habran tamaños de semilla cuyos multiplos no den igual al tamaño del archivo
        if (((suma == seed/2)&&(seed%2==0))) {  //Cuando sean iguales los 1 y 0
            modulo = 1;
        } else if (suma <= (seed/2)) { //Si hay mas ceros que unos
            modulo = 2;
        } else { // Si hay mas unos que ceros
            modulo = 3;
        }
        // Ahora se realiza la modificacion del bloque siguiente
        for(int i=1;((i<=seed)&&(countBits+i-1)<limit);i++) {
            seedSample[i-1] = txtFileBin[countBits+i-1]; //Antes de modificarlo se toma para la proxima operacion
            txtFileBin[countBits+i-1] = (i%modulo==0)? !txtFileBin[countBits+i-1]:txtFileBin[countBits+i-1];
        }
        if (countBits+seed > sizeBit) {
            break;
        }
    }
    if (!problemPlay) cout << endl << "Texto en binario codificado: ";
    for(long long int i=0;i<sizeBit;i++) {
        if (!problemPlay) cout << txtFileBin[i];
    }
    delete [] seedSample;
}
/* Funcion para decodificar texto con el primer metodo
 *
 * La funcion recibe los siguientes parametros:
 * txtFileBin: arreglo de bits para codificar
 * sizeBit: Longitud del arreglo de bits
 * seed: Semilla, parametro usado en el metodo de encripción.
 */
void decode1Binary(bool txtFileBin[], long long int sizeBit, int seed) {
    if (!problemPlay) cout << endl << "Texto en binario sin codificar: ";
    for(long long int i=0;i<sizeBit;i++) {
        if (!problemPlay) cout << txtFileBin[i];
    }
    long long int countBits=0;
    int modulo=0; // Variable para el control de codificacion
    bool *seedSample = new bool[seed];  //Arreglo binario del tamaño de la semilla
    while (countBits<sizeBit) {
        int suma=0; //En cada iteracion se realiza la suma del bloque
        for(int i=0;i<seed;i++) {
            if (countBits<seed) { // Si es el primer bloque se codifica de una vez
                txtFileBin[countBits] = !txtFileBin[countBits];
                suma += txtFileBin[countBits];
            } else {
                suma += seedSample[i]; // A partir del segundo bloque usa el arreglo binario de tamaño semilla
            }
            ++countBits;
        }
        // Se valida la suma para realizar la codificacion
        long long int limit = ((countBits+seed)>sizeBit) ? sizeBit : (countBits+seed) ; //Habran tamaños de semilla cuyos multiplos no den igual al tamaño del archivo
        if (((suma == seed/2)&&(seed%2==0))) {  //Cuando sean iguales los 1 y 0
            modulo = 1;
        } else if (suma <= (seed/2)) { //Si hay mas ceros que unos
            modulo = 2;
        } else { // Si hay mas unos que ceros
            modulo = 3;
        }
        // Ahora se realiza la modificacion del bloque siguiente
        for(int i=1;((i<=seed)&&(countBits+i-1)<limit);i++) {
            txtFileBin[countBits+i-1] = (i%modulo==0)? !txtFileBin[countBits+i-1]:txtFileBin[countBits+i-1];
            seedSample[i-1] = txtFileBin[countBits+i-1]; //Despues de modificarlo se toma para la proxima operacion
        }
        if (countBits+seed > sizeBit) {
            break;
        }
    }
    if (!problemPlay) cout << endl << "Texto en binario codificado: ";
    for(long long int i=0;i<sizeBit;i++) {
        if (!problemPlay) cout << txtFileBin[i];
    }
    delete [] seedSample;
}
/* Funcion para ecriptar texto con el segundo metodo
 *
 * La funcion recibe los siguientes parametros:
 * txtFileBin: arreglo de bits para codificar
 * sizeBit: Longitud del arreglo de bits
 * seed: Semilla, parametro usado en el metodo de encripción.
 */
void encode2Binary(bool txtFileBin[], long long int sizeBit, int seed) {
    if (!problemPlay) cout << endl << "Texto en binario sin codificar: ";
    for(long long int i=0;i<sizeBit;i++) {
        if (!problemPlay) cout << txtFileBin[i];
    }
    long long int countBits=0;
    bool backup; // Variable para guardar el estado bit final
    while (countBits<sizeBit) {
        // Si no fue una division exacta en la semilla se debe recalcular la ultima iteracion
        long long int limit = (countBits+seed>=sizeBit) ? (sizeBit-countBits) : seed;
        // Para facilitar el manejo de variable de backup se recorre de manera descendente.
        for(long long int i=limit-1;(i>=0);i--) {
            if (i==0) { // En la ultima iteracion se usa el backup
                txtFileBin[countBits+i] = backup;
            } else {
                if (i==(limit-1)) { //Se guarda el bit de la ultima posicion del segmento
                    backup = txtFileBin[countBits+i];
                }
                txtFileBin[countBits+i] = txtFileBin[countBits+i-1];
            }
        }
        countBits+=limit;
    }
    if (!problemPlay) cout << endl << "Texto en binario codificado: ";
    for(long long int i=0;i<sizeBit;i++) {
        if (!problemPlay) cout << txtFileBin[i];
    }
}
/* Funcion para ecriptar texto con el segundo metodo
 *
 * La funcion recibe los siguientes parametros:
 * txtFileBin: arreglo de bits para codificar
 * sizeBit: Longitud del arreglo de bits
 * seed: Semilla, parametro usado en el metodo de encripción.
 */
void decode2Binary(bool txtFileBin[], long long int sizeBit, int seed) {
    if (!problemPlay) cout << endl << "Texto en binario sin codificar: ";
    for(long long int i=0;i<sizeBit;i++) {
        if (!problemPlay) cout << txtFileBin[i];
    }
    long long int countBits=0;
    bool backup; // Variable para guardar el estado bit inicial
    while (countBits<sizeBit) {
        // Si no fue una division exacta en la semilla se debe recalcular la ultima iteracion
        long long int limit = (countBits+seed>=sizeBit) ? (sizeBit-countBits) : seed;
        // Para facilitar el manejo de variable de backup se recorre de manera descendente.
        for(int i=0;i<limit;i++) {
            if (i==(limit-1)) { // En la ultima iteracion se usa el backup
                txtFileBin[countBits+i] = backup;
            } else {
                if (i==0) { //Se guarda el bit de la ultima posicion del segmento
                    backup = txtFileBin[countBits+i];
                }
                txtFileBin[countBits+i] = txtFileBin[countBits+i+1];
            }
        }
        countBits+=limit;
    }
    if (!problemPlay) cout << endl << "Texto en binario codificado: ";
    for(long long int i=0;i<sizeBit;i++) {
        if (!problemPlay) cout << txtFileBin[i];
    }
}
/*Funcion para leer el tamaño del archivo
*/
long long int fileSize(char fileInput[]){
    ifstream fileToRead;
    long long int size = 0;
    fileToRead.open(fileInput, ios::ate);
    if (fileToRead.is_open()) {
        size = fileToRead.tellg();
        fileToRead.close();
    } else {
        cout << endl << "Se ha presentado un error leyendo el archivo." << endl;
    }
    return size;
}
/*Metodo para la lectura de archivo
 *
 * Este metodo por referencia devuelve el contenido y como parametro de salida el tamaño
 */
void readFile(char *txtFile, char fileInput[]) {
    // Se debe leer el archivo y construir el arreglo de caracteres
    long long int size=0;  // Para tener la capacidad de leer archivos grandes.
    ifstream fileToEncode;
    fileToEncode.open(fileInput, ios::in|ios::ate);
    if (fileToEncode.is_open()) {
        size = fileToEncode.tellg(); // Como se abre con el parametro ios:ate la posicion es la posicion final del archivo
        fileToEncode.seekg(0,ios::beg); //Se ubica en el principio del stream
        for (long long int i=0;i<size;i++) fileToEncode.get(txtFile[i]);
        //fileToEncode.read(txtFile,size+1); // Se lee la cantida de caracteres ya conocidos.
        fileToEncode.close(); // Se cierra el archivo
    } else {
        cout << "Se presento un error leyendo el archivo." << endl;
    }
}
/* Metodo para escribir en archivo binario
 *
 * En este metodo se reciben los siguientes parámetros:
 *
 *  txtFileBin: Arreglo de bits.
 *  sizeBit:    Tamaño de arreglo de bits.
 *  fileOutput: nombre del archivo
 */
void writeBinFile(bool *txtFileBin, long long int sizeBit, char fileOutput[]) {
    //Primero convertimos el arreglo de bits a caracteres
    long long int tam = sizeBit/8;
    char *txtFileChar = new char[tam];
    int sum=0;
    int i=0;
    while(i<sizeBit) {
        for (int j=7;j>=0;j--,i++) {
            sum += txtFileBin[i]*int(pow(2,j));
            if (j==0) {
                txtFileChar[((i+1)/8)-1]=sum;
                if (sum==205) tam--;
                sum=0;
            }
        }
    }
    ofstream fileEncoded (fileOutput,ios::out|ios::trunc|ios::ate);
    if (fileEncoded.is_open()) {
        for (int i=0; i<tam; i++)
            fileEncoded << txtFileChar[i];
        fileEncoded.close();
    } else {
        cout << "Se presentaron problemas escribiendo el archivo" << endl;
    }
    delete [] txtFileChar;
}
/* Metodo para convertir arreglo de caracteres a binario
 *
 * En este metodo se reciben los siguientes parámetros:
 *
 *  textBinary: Arreglo de bits por referencia para dar la respuesta.
 *  txtFile:    Arreglo de caracters a convertir
 *  size: tamaño del arreglo de caracteres
 */
void getBinary(bool textBinary[], char *txtFile, long long int size) {
    // Variables Locales
    long long int countBits=0; // Contador para recorrer los bits
    int valChar; // Variable para representar el caracter en numero
    for(int i=0; i<size;i++) { //Se recorre cada caracter convirtiendolo en binario
        valChar = int(txtFile[i]); //Se obtiene el valor numerico del caracter
        if (valChar < 0) {
            valChar+=256;
        }
        countBits = 8*(i+1); //Se configura la posicion en bits del arreglo binario
        while(valChar>0) {
            --countBits;
            (valChar % 2) ? textBinary[countBits]=true : textBinary[countBits]=false; //Se saca modulo del valor remanente del caracter
            valChar/=2; //Se actualiza el valor remanente del caracter.
        }
        //Si el valor no lleno los 8 bits, se llenan el resto con 0 (false)
        for (--countBits;countBits>=(8*i);--countBits) {
            textBinary[countBits]=false;
        }
    }
}
/*Metodo para la lectura de archivo
 *
 * Este metodo por referencia devuelve el contenido y como parametro de salida el tamaño
 */
string readStrFile(string fileInput) {
    // Se debe leer el archivo y construir el arreglo de caracteres
    string line, response="";
    char temp;
    ifstream fileToEncode(fileInput);
    if (fileToEncode.is_open()) {
        while(!fileToEncode.eof()){
            temp=fileToEncode.get();
            if (!fileToEncode.eof()) response.push_back(temp);
        }
        fileToEncode.close(); // Se cierra el archivo
    } else {
        cout << "Se presento un error leyendo el archivo." << endl;
    }
    return response;
}
/* Metodo para escribir en archivo binario
 *
 * En este metodo se reciben los siguientes parámetros:
 *
 *  txtFileBin: Arreglo de bits.
 *  sizeBit:    Tamaño de arreglo de bits.
 *  fileOutput: nombre del archivo
 */
string writeBinFile(bool *txtFileBin, long long int sizeBit, string fileOutput) {
    //Primero convertimos el arreglo de bits a caracteres
    string txtFileStr = "";
    int sum=0;
    int i=0;
    while(i<sizeBit) {
        for (int j=7;j>=0;j--,i++) {
            sum += txtFileBin[i]*int(pow(2,j));
            if (j==0) {
                txtFileStr.push_back(char(sum));
                sum=0;
            }
        }
    }
    if (fileOutput.compare("NA")!=0) {
        ofstream fileEncoded (fileOutput,ios::out|ios::trunc|ios::ate);
        if (fileEncoded.is_open()) {
            fileEncoded << txtFileStr;
            fileEncoded.close();
        } else {
            cout << "Se presentaron problemas escribiendo el archivo" << endl;
        }
    }
    return txtFileStr;
}
/* Metodo para convertir arreglo de caracteres a binario
 *
 * En este metodo se reciben los siguientes parámetros:
 *
 *  textBinary: Arreglo de bits por referencia para dar la respuesta.
 *  txtFile:    String a convertir
 *  size: tamaño del arreglo de caracteres
 */
void getBinary(bool textBinary[], string *txtFile, long long int size) {
    // Variables Locales
    long long int countBits=0; // Contador para recorrer los bits
    int valChar; // Variable para representar el caracter en numero
    for(long long int i=0; i < size;i++) { //Se recorre cada caracter convirtiendolo en binario
        valChar = int(txtFile->at(i)); //Se obtiene el valor numerico del caracter
        if (valChar < 0) {
            valChar+=256;
        }
        countBits = 8*(i+1); //Se configura la posicion en bits del arreglo binario
        while(valChar>0) {
            --countBits;
            (valChar % 2) ? textBinary[countBits]=true : textBinary[countBits]=false; //Se saca modulo del valor remanente del caracter
            valChar/=2; //Se actualiza el valor remanente del caracter.
        }
        //Si el valor no lleno los 8 bits, se llenan el resto con 0 (false)
        for (--countBits;countBits>=(8*i);--countBits) {
            textBinary[countBits]=false;
        }
    }
}
/*****************************************************************************************/
/* Funcion para creación de usuario
 */
void crearUsuario() {
    string cedulaUsuario;
    string claveUsuario;
    int saldo;
    system("CLS");
    cout << endl;
    cout << "Por favor ingrese cedula del usuario: ";
    cin >> cedulaUsuario;
    cout << "Por favor ingrese clave del usuario: ";
    cin >> claveUsuario;
    cout << "Ingrese el saldo: ";
    cin >> saldo;
    //Se guarda la clave del usuario
    encripcionStr(1,3,"str."+claveUsuario,cedulaUsuario+".txt",true);
    encripcionStr(1,3,"str."+to_string(saldo),cedulaUsuario+"_saldo.txt",true);
    cout << endl;
    cout << "Se ha creado el usuario.";
    system("PAUSE");
}
/* Menu de opciones del administrador
 */
bool menuAdmin() {
    int opcion;
    system("CLS");
    cout << endl;
    cout << "1. Crear Usuario" << endl;
    cout << "0. Salir" << endl;
    cout << endl << "Seleccione la opcion deseada: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        crearUsuario();
        return  true;
        break;
    case 0:
        return false;
        break;
    default:
        cout << "Se ha seleccionado una opcion invalida." <<endl;
        return true;
        break;
    }
}
/* Menu de opciones del usuario
 */
bool menuUser(string cedula) {
    int opcion;
    int saldo;
    int retiro;
    system("CLS");
    cout << endl;
    cout << "1. Consultar Saldo" << endl;
    cout << "2. Retirar Dinero" << endl;
    cout << "0. Salir" << endl;
    cout << endl << "Seleccione la opcion deseada: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        saldo = stoi(encripcionStr(1,3,cedula+"_saldo.txt","NA",false));
        saldo -= 1000;
        encripcionStr(1,3,"str."+to_string(saldo),cedula+"_saldo.txt",true);
        cout << endl << "El saldo de su cuenta es: " << saldo << endl;
        system("PAUSE");
        return  true;
        break;
    case 2:
        saldo = stoi(encripcionStr(1,3,cedula+"_saldo.txt","NA",false));
        saldo -= 1000;
        cout << endl << "Ingrese el valor del retiro: ";
        cin >> retiro;
        saldo -= retiro;
        encripcionStr(1,3,"str."+to_string(saldo),cedula+"_saldo.txt",true);
        cout << endl << "Retiro Exitoso" << endl;
        cout << "El nuevo saldo de su cuenta es: " << saldo << endl;
        system("PAUSE");
        return  true;
        break;
    case 0:
        return false;
        break;
    default:
        cout << "Se ha seleccionado una opcion invalida." <<endl;
        return true;
        break;
    }
}
/* Flujo de control para administrador
 */
void controlAdmin() {
    bool continuar = true;
    string claveIngresada;
    string claveAlmacenada;
    system("CLS");
    cout << endl;
    cout << "Por favor ingrese su clave: ";
    cin >> claveIngresada;
    // Se lee archivo donde esta la clave almacenada
    claveAlmacenada = encripcionStr(1,3,"sudo.txt","NA",false);
    //cout<<"La clave ingresada fue "<<claveIngresada << endl;
    //cout<<"La clave almacenada es "<<claveAlmacenada << endl;
    // Comparar clave ingresada con almacenada
    if (claveIngresada.compare(claveAlmacenada)==0) {
        while(continuar) {
            continuar = menuAdmin();
        }
    } else {
        cout << endl << "Los datos ingresados no son correctos.";
    }
    system("PAUSE");
}
/* Flujo de control para usuarios
 */
void controlUser() {
    bool continuar = true;
    string cedula;
    string claveIngresada;
    string claveAlmacenada;
    system("CLS");
    cout << endl;
    cout << "Por favor ingrese su cedula: ";
    cin >> cedula;
    cout << "Por favor ingrese su clave: ";
    cin >> claveIngresada;
    // Se lee archivo donde esta la clave almacenada
    claveAlmacenada = encripcionStr(1,3,cedula+".txt","NA",false);
    //cout<<"La clave ingresada fue "<<claveIngresada << endl;
    //cout<<"La clave almacenada es "<<claveAlmacenada << endl;
    // Comparar clave ingresada con almacenada
    if (claveIngresada.compare(claveAlmacenada)==0) {
        while(continuar) {
            continuar = menuUser(cedula);
        }

    } else {
        cout << endl << "Los datos ingresados no son correctos.";
    }
    system("PAUSE");
}
/* Menu de opciones del problema
 */
bool menuProblema() {
    int opcion;
    system("CLS");
    cout << endl;
    cout << "1. Ingresar como administrador" << endl;
    cout << "2. Ingresar como usuario" << endl;
    cout << "0. Salir" << endl;
    cout << endl << "Seleccione la opcion deseada: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        controlAdmin();
        return  true;
        break;
    case 2:
        controlUser();
        return true;
        break;
    case 0:
        return false;
        break;
    default:
        cout << "Se ha seleccionado una opcion invalida." <<endl;
        return true;
        break;
    }
}
/* Metodo para el desarrollo del problema de la practica
 */
void problema() {
    problemPlay = true;
    bool continuar = true;
    while (continuar) {
        //Mostrar menu de opciones
        continuar = menuProblema();
    }
}
#endif // UTILS_H
