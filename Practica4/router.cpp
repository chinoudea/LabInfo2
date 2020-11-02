#include "router.h"

// Constructor con nombre de router
router::router(string routerName)
{
    name = routerName;
}
// Destructor
router::~router()
{
    links.clear();
}
// Funcion para obtener el nombre del router
string router::getName() {
    return name;
}
// Funcion para obtener las relaciones del router
map<string,int> router::getLinks() {
    return links;
}
// Funcion para actualizar una relacion en el router
void router::updateLink(string routerName, int cost) {
    // Variables locales
    map<string,int>::iterator it;
    // Se valida que exista esa relación
    it = links.find(routerName);
    if (it != links.end()) {
        //Si ya existe se sobreescribe el costo
        it->second = cost;
    } else {
        //Si no existe se crea.
        links[routerName] = cost;
    }
}
// Funcion para eliminar una relacion en el router
void router::removeLink(string routerName) {
    //Variables locales
    map<string,int>::iterator it;
    //Se busca la relacion
    it = links.find(routerName);
    if (it != links.end()) {
        //Si existe la elimina
        links.erase(it);
    }
}
// Funcion para contar las relaciones de un router
int router::countLinks() {
    return int(links.size());
}
