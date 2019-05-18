#include "animal_silvestre/animal_nativo.h"

AnimalNativo::AnimalNativo(){
    uf_origem = "UF de origem não definida";
    autorizacao = "Sem autorização";
}

AnimalNativo::AnimalNativo(std::string UO, std::string auth){
    uf_origem = UO;
    autorizacao = auth;
}

std::string AnimalNativo::getUf_Origem(){
    return uf_origem;
}

void AnimalNativo::setUf_Origem(std::string UO){
    uf_origem = UO;
}
std::string AnimalNativo::getAutorizacao(){
    return autorizacao;
}

void AnimalNativo::setAutorizacao(std::string auth){
    autorizacao = auth;
}