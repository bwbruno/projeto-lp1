#include "excecao/excecao.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

Excecao::Excecao(){
	mensagem.erase();
}

Excecao::Excecao(string m) : mensagem(m){}

Excecao::~Excecao() throw(){}

Excecao::Excecao(const Excecao &e){
	mensagem = e.getMensagem();
}

// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

const string Excecao::getMensagem() const {	
	return mensagem;
}

// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void Excecao::setMensagem(string m){
	mensagem = m;
}

// ------------------------------------------------------------------------
//		Operadores
// ------------------------------------------------------------------------

Excecao& Excecao::operator= (Excecao const &e) {
	mensagem = e.mensagem;
	return *this;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void Excecao::limparMensagem(){
	mensagem.erase();
}

void Excecao::printMensagem(){
	if(!mensagem.empty())
		cout << endl << mensagem << endl;
}