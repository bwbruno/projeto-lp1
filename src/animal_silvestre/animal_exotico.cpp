#include "animal_silvestre/animal_exotico.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

AnimalExotico::AnimalExotico(){
    pais_origem =  "País não definido";
}


// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

string AnimalExotico::getPaisOrigem(){
    return pais_origem;
}


// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void AnimalExotico::setPaisOrigem(string PO){
    pais_origem = PO;
}