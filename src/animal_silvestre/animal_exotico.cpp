#include "animal_silvestre/animal_exotico.h"

using namespace std;

AnimalExotico::AnimalExotico()
{
    pais_origem =  "País não definido";
}

string AnimalExotico::getPaisOrigem()
{
    return pais_origem;
}

void AnimalExotico::setPaisOrigem(string PO)
{
    pais_origem = PO;
}
