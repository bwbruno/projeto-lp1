#include "animal_silvestre/animal_nativo.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

AnimalNativo::AnimalNativo(){
    uf_origem = "UF de origem não definida";
    autorizacao = "Sem autorização";
}

AnimalNativo::AnimalNativo(string UO, string auth){
    uf_origem = UO;
    autorizacao = auth;
}


// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

string AnimalNativo::getUf_Origem(){
    return uf_origem;
}

string AnimalNativo::getAutorizacao(){
    return autorizacao;
}


// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void AnimalNativo::setUf_Origem(string UO){
    uf_origem = UO;
}

void AnimalNativo::setAutorizacao(string auth){
    autorizacao = auth;
}