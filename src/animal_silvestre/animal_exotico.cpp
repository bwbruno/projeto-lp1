#include "animal_silvestre/animal_exotico.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

AnimalExotico::AnimalExotico(){
    pais_origem =  "País não definido";
    autorizacao = "Sem autorização";
}

AnimalExotico::AnimalExotico(string PO, string auth){
    pais_origem =  PO;
    autorizacao = auth; 
}


// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

string AnimalExotico::getPais_Origem(){
    return pais_origem;
}


// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void AnimalExotico::setPais_Origem(string PO){
    pais_origem = PO;
}