#include "animal_silvestre/animal_nativo.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

AnimalNativo::AnimalNativo(){
    uf_origem = "UF de origem não definida";
}


// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

string AnimalNativo::getUfOrigem(){
    return uf_origem;
}


// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void AnimalNativo::setUfOrigem(string UO){
    uf_origem = UO;
}