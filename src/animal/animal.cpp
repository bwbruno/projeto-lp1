#include "animal/animal.h"

Animal::Animal(int cod, std::string clas){
   id = cod;
   classe = clas;
}

int Animal::getId(){
   return id;
}

void Animal::setId(int cod){
   id = cod;
}

std::string Animal::getClasse(){
   return classe;
}

void Animal::setClasse(std::string clas){
   classe = clas;
}   

std::string Animal::getNome_Cientifico(){
   return nome_cientifico;
}

void Animal::setNome_Cientifico(std::string cientific_name){
   nome_cientifico = cientific_name;
}

char Animal::getSexo(){
   return sexo;
}

void Animal::setSexo(char gender){
   sexo = gender;
}

double Animal::getTamanho(){
   return tamanho ;
}

void Animal::setTamanho(double size){
   tamanho = size;
}

std::string Animal::getDieta(){
   return dieta;
}

void Animal::setDieta(std::string diet){
   dieta = diet;
}

Veterinario Animal::getVeterinario(){
   return veterinario;
}

void Animal::setVeterinario(Veterinario vet){
   veterinario = vet;
}

Tratador Animal::getTratador(){
   return tratador;
}

void Animal::setTratador(Tratador caregiver){
   tratador = caregiver;
}

std::string Animal::getNome_Batismo(){
   return nome_batismo;
}

void Animal::setNome_Batismo(std::string baptism_name){
   nome_batismo = baptism_name;
}