#include "animal_silvestre/animal_exotico.h"

AnimalExotico::AnimalExotico(){
    pais_origem =  "País não definido";
    autorizacao = "Sem autorização";
}

AnimalExotico::AnimalExotico(std::string PO, std::string auth){
    pais_origem =  PO;
    autorizacao = auth; 
}

std::string AnimalExotico::getPais_Origem(){
    return pais_origem;
}

void AnimalExotico::setPais_Origem(std::string PO){
    pais_origem = PO;
}