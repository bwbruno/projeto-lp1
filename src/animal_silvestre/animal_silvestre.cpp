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

string AnimalSilvestre::getAutorizacao_Ibama(){
    return autorizacao_ibama;
}


// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void AnimalSilvestre::setAutorizacao_Ibama(string auth){
    autorizacao_ibama = auth;
}