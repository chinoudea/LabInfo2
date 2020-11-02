#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <vector>
#include <router.h>
using namespace std;

class network {
    private:
        vector<router> nodes;
        string name;
        void setName(string nameNetwork);
        //Funcion para mostrar la ruta mas optima y su costo para el envío de un paquete.
        map<string,int> pathCalculate(string start, string end);
        // Funcion auxiliar en el proceso de busqueda de ruta optima
        string minCostRouter(map<string,int> pathCost, map<string,bool> readyRouters);
        //Sobrecarga de la funcion para cargar la configuracion desde un archivo.
        void loadConfig(string nameNetwork, string filePath);
        //Funcion para validar si un router existe en la red.
        bool existRouter(string nameRouter);
        //Funcion para obtener un router
        router* getRouter(string nameRouter);
    public:
        //Constructor predeterminado
        network();
        //Funcion para mostrar en pantalla la descripcion de la red.
        void show();
        //Funcion para agregar un router a la red.
        void addRouter();
        //Funcion para eliminar un router de la red.
        void removeRouter();
        //Funcion para mostrar la ruta mas optima y su costo para el envío de un paquete.
        void pathCalculate();
        //Funcion para cargar la configuracion desde un archivo.
        void loadConfig();
        //Funcion para cargar una configuracion aleatoria de red.
        void loadRandom();
};

#endif // NETWORK_H
