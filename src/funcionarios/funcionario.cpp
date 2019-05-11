#include "funcionarios/funcionario.h"

using namespace std;

// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

int Funcionario::getId(){
	return id;
}

string Funcionario::getNome(){
	return nome;
}

string Funcionario::getCPF(){
	return cpf;
}

short Funcionario::getIdade(){
	return idade;
}

string Funcionario::getTipo_sanguineo(){
	return tipo_sanguineo;
}

char Funcionario::getFator_rh(){
	return fator_rh;
}

string Funcionario::getEspecialidade(){
	return especialidade;
}

int Funcionario::getContadorCin(){
	return contador_cin;
}

// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void Funcionario::setId(int i){
	id = i;
}

void Funcionario::setNome(string n){
	nome = n;
}

void Funcionario::setCPF(string c){
	cpf = c;
}

void Funcionario::setIdade(short i){
	idade = i;
}

void Funcionario::setTipo_sanguineo(string ts){
	if(ts != "A" && ts != "B" && ts != "AB" && ts != "O")
		throw Excecao("Tipo sanguíneo inválido.");
	else
		tipo_sanguineo = ts;
}

void Funcionario::setFatorRh(char frh){
	if(frh != '+' && frh != '-')
		throw Excecao("Fator RH inválido.");
	else
		fator_rh = frh;	
}

void Funcionario::setEspecialidade(string e){
	especialidade = e;
}

void Funcionario::setContadorCin(int c){
	contador_cin = c;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void Funcionario::printIdNome(){
	cout << "\t" << id;
    cout << ". " << nome << endl;
}
