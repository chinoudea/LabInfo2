#include "lab.h"

void eliminar_repetidos(char *cad, int a){
    char *no_rep = new char[a+1];
    int k=0;
    no_rep[0]='\0';
    for(int i=0;cad[i]!='\0';i++){
        for(k=0; cad[i]!=no_rep[k] && no_rep[k]!='\0';k++);
        if(no_rep[k]=='\0'){
            no_rep[k]=cad[i];
            no_rep[k+1]='\0';
            cout << cad[i];
        }
    }
    cout << endl;
}
