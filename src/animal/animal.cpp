#include "animal/animal.h"

using namespace std;

// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

int Animal::getId(){
   return id;
}

string Animal::getClasse(){
   return classe;
}

string Animal::getEspecie(){
   return especie;
}

string Animal::getNome_Cientifico(){
   return nome_cientifico;
}

char Animal::getSexo(){
   return sexo;
}

double Animal::getTamanho(){
   return tamanho ;
}

string Animal::getDieta(){
   return dieta;
}

Veterinario Animal::getVeterinario(){
   return veterinario;
}

Tratador Animal::getTratador(){
   return tratador;
}

string Animal::getNome_Batismo(){
   return nome_batismo;
}

int Animal::getContadorCin(){
   return contador_cin;
}

// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void Animal::setId(int cod){
   id = cod;
}

void Animal::setClasse(string clas){
   classe = clas;
}

void Animal::setEspecie(string species){
   especie = species;
}

void Animal::setNome_Cientifico(string cientific_name){
   nome_cientifico = cientific_name;
}

void Animal::setSexo(char gender){
   if(gender != 'M' && gender != 'F')
      throw Excecao("Sexo inválido. Tente Novamente.");
   sexo = gender;
}

void Animal::setDieta(string diet){
   dieta = diet;
}

void Animal::setTamanho(double size){
   tamanho = size;
}

void Animal::setVeterinario(int idVeterinario){
   Veterinario v;
   v.setId(idVeterinario);
   veterinario = v;
}

void Animal::setTratador(int idTratador){
   Tratador t;
   t.setId(idTratador);
   tratador = t;
}

void Animal::setNome_Batismo(string baptism_name){
   nome_batismo = baptism_name;
}

void Animal::setContadorCin(int c){
   contador_cin = c;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

std::string Animal::getTipo(){
   return classe;
}