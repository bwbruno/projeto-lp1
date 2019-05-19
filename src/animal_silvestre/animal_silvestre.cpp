#include "animal_silvestre/animal_silvestre.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

AnimalSilvestre::AnimalSilvestre(){
    autorizacao_ibama = 'NULL';
}

AnimalSilvestre::AnimalSilvestre(string auth){
    autorizacao_ibama = auth;
}


// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

string AnimalSilvestre::getAutorizacaoIbama(){
    return autorizacao_ibama;
}


// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void AnimalSilvestre::setAutorizacaoIbama(string auth){
    autorizacao_ibama = auth;
}