#include "network.h"

//Constructor por defecto
network::network(){
    name = "Default Network";
}
// Funcion para configurar el nombre de la red.
void network::setName(string newName){
    name = newName;
}
// Funcion para validar si la red contiene un router
bool network::existRouter(string nameRouter) {
    for (router element : nodes) {
        //Si se encuentra el router lo elimina
        if (nameRouter.compare(element.getName()) == 0 ) {
            return true;
        }
    }
    return false;
}
// Funcion para mostrar la red
void network::show(){
    //Se limpia la consola
    system("CLS");
    cout << "\t" << "*********    DIAGRAMA RED    *********" << endl << endl;
    //Se verifica el numero de elementos de la red
    if (nodes.size()>0) {
        //Se recorren los elementos de la red
        for (router element : nodes) {
            cout << "\t" << "Router: " << element.getName();
            if (element.countLinks()>0) {
                cout << endl << "\t\tENLACE\t\t| COSTO"<<endl;
                cout << "\t\t----------------|------"<<endl;
                for (auto link : element.getLinks()) {
                    cout << "\t\t" << link.first << "\t\t| " << link.second << endl;
                }
            } else {
                cout << " sin enlaces." << endl;
            }
        }
    } else {
        cout << "\t" << "\t" << "La red no tiene nodos." << endl;
    }
    cout << endl << endl << "\t";
    system("PAUSE");
}
// Funcion para adicionar un router a la red.
void network::addRouter(){
    // Variables Locales
    string nameRouter, nameLinkRouter;
    int linkCost = 0, count = 0;
    char optionLink = 'S', optionRouter='S';
    //Se limpia la consola
    system("CLS");
    cout << "\t" << "*********   AGREGAR ROUTER   *********" << endl << endl;
    //Se solicita configuraciones de router a adicionar
    cout << "\t" << "Ingrese el nombre del router: ";
    cin >> nameRouter;
    //Se valida si el router existe
    if (existRouter(nameRouter) ) {
        cout << "\t" << endl << "El Router <"<<nameRouter<<"> que se quiere adicionar ya existe." << endl;
        cout << endl << endl << "\t";
        system("PAUSE");
        return;
    }
    // Si no existe se crea
    router newRouter(nameRouter);
    // Se solicitan enlaces del router
    do {
        count++; // Contador de enlaces
        switch (optionLink) {
            case 'S':
            case 's':
                cout << endl << "\t" << "ENLACE " << count << endl;
                cout << "\t" << "Nombre del router a enlazar: ";
                cin >> nameLinkRouter;
                cout << "\t" << "Costo de enlace: ";
                cin >> linkCost;
                // Se valida si existe el router a enlazar
                if (!existRouter(nameLinkRouter) ) {
                    router linkRouter(nameLinkRouter);
                    cout << endl << "\t" << "El Router <" << nameLinkRouter << "> que se quiere enlazar tampoco existe, desea agregarlo (S/N): ";
                    cin >> optionRouter;
                    switch (optionRouter) {
                        case 'S':
                        case 's':
                            linkRouter.updateLink(nameRouter,linkCost);
                            newRouter.updateLink(nameLinkRouter,linkCost);
                            nodes.push_back(linkRouter);
                            break;
                        case 'N':
                        case 'n':
                            count--;
                            break;
                        default:
                            cout << endl << "\t" << "La opcion ingresada no es valida";
                            count--;
                            break;
                    }
                } else {
                    newRouter.updateLink(nameLinkRouter,linkCost);
                    getRouter(nameLinkRouter)->updateLink(nameRouter, linkCost);
                }
                break;
            case 'N':
            case 'n':
                if (newRouter.countLinks() == 0) {
                    cout << endl << "\t" << "No se puede agregar un router desconectado." << endl;
                    optionLink = 'x';
                    continue;
                }
            default:
                cout << endl << "\t" << "La opcion ingresada no es valida" << endl;
                break;
        }
        if (newRouter.countLinks() > 0) {
            cout << endl << "\t" << "Desea adicionar mas enlaces para el router <" << nameRouter << ">? (S/N): ";
            cin >> optionLink;
        }
    } while (optionLink!='n' && optionLink!='N');

    //Se agrega router.
    nodes.push_back(newRouter);
}
// Funcion para eliminar un router de la red
void network::removeRouter(){
    //Variables locales
    int count = 0;
    int position;
    bool flag = false;
    string nameRouter;
    //Se limpia la consola
    system("CLS");
    cout << "\t" << "*********   ELIMINAR ROUTER   *********" << endl << endl;
    //Se solicita nombre de router
    cout << "\t" << "Ingrese el nombre del router: ";
    cin >> nameRouter;
    // Se recorre el vector de routers
    for (router& element : nodes) {
        //Si se encuentra el router lo elimina
        if (nameRouter.compare(element.getName()) == 0 ) {
            position = count;
            flag = true;
        } else {
            element.removeLink(nameRouter);
        }
        count++;
    }
    if (!flag) {
        cout << endl << "\t" << "El nombre del router ingresado no existe." << endl;
    } else {
        nodes.erase(nodes.begin()+position);
        cout << endl << "\t" << "El router <" << nameRouter << "> ha sido eliminado." << endl;
    }
    cout << endl << endl << "\t";
    system("PAUSE");
}
// Funcion para calcular la ruta entre routers (parte grafica)
void network::pathCalculate(){
    //Variables Locales
    string startRouter, endRouter;
    map<string,int> result;
    //Se limpia la consola
    system("CLS");
    cout << "\t" << "*********     RUTA OPTIMA    *********" << endl << endl;
    //Preguntar al usuario nodos del envio
    cout << "\t" << "Ingrese el nombre del router origen: ";
    cin >> startRouter;
    cout << "\t" << "Ingrese el nombre del router destino: ";
    cin >> endRouter;
    //Se valida la información solicitada al usuario
    if (!existRouter(startRouter)) {
        cout << endl << "\t" << "El router <"<<startRouter<<"> no existe en la red.";
    } else if (!existRouter(endRouter)) {
        cout << endl << "\t" << "El router <"<<endRouter<<"> no existe en la red.";
    } else {
        result = pathCalculate(startRouter,endRouter);
        if (result.begin()->first.compare("ERROR") == 0) {
            cout << endl << "\t" << "La ruta seleccionada no fue encontrada en la red." << endl;
        } else {
            cout << endl << "\t" << "Para recorrer de <" << startRouter << "> hasta <" << endRouter << "> :" << endl;
            cout << endl << "\t" << "El costo es: " << result.begin()->second;
            cout << "\t" << "La ruta es: "<< result.begin()->first;
        }
    }
    cout << endl << endl << "\t";
    system("PAUSE");
}
// Funcion para calcular la ruta entre routers (sobrecarga parte operativa)
map<string,int> network::pathCalculate(string start, string end) {
    //Variables Locales
    map<string,int> pathCost;
    map<string,string> pathRoute;
    map<string,bool> readyRouters;
    map<string,int> result;
    string ruta;
    for (router nodo : nodes) {
        pathCost[nodo.getName()] = INT_MAX-1;
        pathRoute[nodo.getName()] = start;
        readyRouters[nodo.getName()] = false;
    }
    pathCost[start] = 0;

    // Ciclo para garantizar que todos los nodos sean verificados
    int max = int(nodes.size());
    for (int i=0;i<max;i++) {
        //Se elige el router con menor costo y aun no procesado
        string next = minCostRouter(pathCost, readyRouters);
        //
        ruta = pathRoute[next];
        //Se actualiza los costos de los routers adyacentes
        router* tempRouter = getRouter(next);
        map<string,int> links = tempRouter->getLinks();
        for(auto element : links) {
            if (!readyRouters[element.first] && (pathCost[next]!=(INT_MAX-1)) && (pathCost[next] + element.second < pathCost[element.first])) {
                pathCost[element.first] = pathCost[next] + element.second;
                pathRoute[element.first] = ruta + ">" + element.first;
            }
        }
        //Se marca el router como procesado
        readyRouters[next] = true;
        if (next.compare(end) == 0) {
            if (pathCost[next]!=(INT_MAX-1)) {
                result[pathRoute[next]] = pathCost[next];
                return result;
            } else {
                result["ERROR"] = 0;
                return result;
            }
        }
    }
    result["ERROR"] = 0;
    return result;
}
// Funcion para cargar configuracion de la red desde un archivo (parte grafica)
void network::loadConfig(){
    //Variables locales
    string networkName, archivo;
    //Se limpia la consola
    system("CLS");
    cout << "\t" << "*********    CARGAR ARCHIVO    *********" << endl << endl;
    //Se solicita el nombre de la red
    cout << "\t" << "Ingrese el nombre de la red: ";
    cin >> networkName;
    //Se solicita la ruta al archivo
    cout << "\t" << "Ingrese la ruta del archivo: ";
    cin >> archivo;
    //Se inicializa red
    loadConfig(networkName, archivo);
    cout << endl << endl << "\t";
    system("PAUSE");
}
// Funcion para cargar configuracion de la red desde un archivo (sobrecarga parte operativa)
void network::loadConfig(string nameNetwork, string filePath){
    //variables locales
    string line, routerName, routerLink;
    int linkCost;
    bool flagValid = true, routerAFind = false, routerBFind = false;
    vector<router> routers;
    //Se configura el nombre de la red.
    setName(nameNetwork);
    // Se abre el archivo
    ifstream myfile (filePath);
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
          routerAFind = false;
          routerBFind = false;
          std::istringstream lineStream(line);
          if (!(lineStream >> routerName >> routerLink >> linkCost)) {
              flagValid=false;
              break;
          } // error
          for (router& element : routers) {
              //Si el router ya se habia creado, se actualiza el link
              if (routerName.compare(element.getName()) == 0 ) {
                  element.updateLink(routerLink,linkCost);
                  routerAFind = true;
              }
              if (routerLink.compare(element.getName()) == 0 ) {
                  element.updateLink(routerName,linkCost);
                  routerBFind = true;
              }
          }
          if (!routerAFind) {
              router newRouter(routerName);
              newRouter.updateLink(routerLink,linkCost);
              routers.push_back(newRouter);
          }
          if (!routerBFind) {
              router newRouter(routerLink);
              newRouter.updateLink(routerName,linkCost);
              routers.push_back(newRouter);
          }
          //cout << "El router " << routerName << " esta conectado con el router " << routerLink << " y el enlace tiene un costo de " << linkCost << endl;
        }
        myfile.close();
        if (flagValid) {
            cout << endl << "\t" << "Fue cargada la configuracion de red.";
            nodes = routers;
        } else {
            cout << endl << "\t" << "No fue posible inicializar la red, fallo la lectura del archivo";
        }
    } else {
        cout << endl << "\t" << "No fue posible inicializar la red, fallo la lectura del archivo";
    }
}
// Funcion para obtener un router
router* network::getRouter(string nameRouter) {
    for (router& element : nodes) {
        if (nameRouter.compare(element.getName()) == 0 ) {
            return &element;
        }
    }
}
// Funcion auxiliar en el proceso de busqueda de ruta optima
string network::minCostRouter(map<string,int> pathCost, map<string,bool> readyRouters) {
    //Variables locales
    int minimunCost = INT_MAX;
    string nextRouter, tempRouter;
    for(auto element : pathCost) {
        tempRouter = element.first;
        if (!readyRouters[tempRouter] && element.second < minimunCost) {
            minimunCost = element.second;
            nextRouter = tempRouter;
        }
    }
    return nextRouter;
}
// Funcion para cargar un red aleatoria
void network::loadRandom(){
    //Variables locales
    vector<string> listRouter;
    int numRouters, numA, numB;
    char inicial = 'A';
    char nameChar;
    string nameString;
    //Se limpia la consola
    system("CLS");
    cout << "\t" << "*********    RED ALEATORIA    *********" << endl << endl;
    //Se configura el seed para garantizar aleatoriedad
    srand (time(NULL));
    //Numero aleatorio de elementos de nodos en la red y enlaces
    numRouters = rand() % 9 + 2;
    //Se configuran los nombres de los nodos
    for (int var = 0; var < numRouters; ++var) {
        nameString = "";
        nameChar = inicial+var;
        nameString += nameChar;
        listRouter.push_back(nameString);
    }
    //Se crean los enlaces
    ofstream configfile;
    configfile.open ("random.txt", ios::out | ios::trunc);
    if (configfile.is_open()) {
        for (int i=0;i<numRouters;++i){
            numA = rand() % numRouters;
            do {
                numB = rand() % numRouters;
            } while (numA==numB);
            configfile << listRouter[numA] << " " << listRouter[numB] << " " << (rand() % 100 + 1) << "\n";
        }
        configfile.close();
        loadConfig("Random","random.txt");
    } else {
        cout << endl << "\tSe ha presentado un error creando la red aleatoria.";
    }
    cout << endl << endl << "\t";
    system("PAUSE");
}
