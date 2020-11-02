#ifndef ROUTER_H
#define ROUTER_H
#include <map>
#include <iostream>
using namespace std;
class router
{
private:
    string name;
    map<string,int> links;
public:
    // Constructor con nombre de router
    router(string routerName);
    // Destructor
    ~router();
    // Funcion para obtener el nombre del router
    string getName();
    // Funcion para obtener las relaciones del router
    map<string,int> getLinks();
    // Funcion para actualizar una relacion en el router
    void updateLink(string routerName, int cost);
    // Funcion para eliminar una relacion en el router
    void removeLink(string routerName);
    // Funcion para contar las relaciones de un router
    int countLinks();
};

#endif // ROUTER_H
