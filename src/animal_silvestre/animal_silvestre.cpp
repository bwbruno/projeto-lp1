#include "animal_silvestre/animal_silvestre.h"

AnimalSilvestre::AnimalSilvestre(){
    autorizacao_ibama = 'NULL';
}

AnimalSilvestre::AnimalSilvestre(std::string auth){
    autorizacao_ibama = auth;
}

std::string AnimalSilvestre::getAutorizacao_Ibama(){
    return autorizacao_ibama;
}

void AnimalSilvestre::setAutorizacao_Ibama(std::string auth){
    autorizacao_ibama = auth;
}