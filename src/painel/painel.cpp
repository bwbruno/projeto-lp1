#include "painel/painel.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

Painel::Painel() : abrir(true){ }

Painel::Painel(string t, deque<string> c) : titulo(t), caminho(c), abrir(true){ }

Painel::Painel(string t, vector<string> o) : titulo(t), opcoes(vectorParaMap(o)), abrir(true){ }

Painel::Painel(string t, vector<string> o, deque<string> c) : titulo(t), opcoes(vectorParaMap(o)), caminho(c), abrir(true) { }

Painel::Painel(string t, map<string, string> co) : titulo(t), opcoes(co), abrir(true){ }

Painel::Painel(string t, map<string, string> co, deque<string> c) : titulo(t), opcoes(co), caminho(c), abrir(true){ }

// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

string Painel::getTitulo(){
	return titulo;
}

map<string, string> Painel::getOpcoes(){
	return opcoes;
}

deque<string> Painel::getCaminho(){
	return caminho;
}

string Painel::getPergunta(){
	return pergunta;
}

string Painel::getResposta(){
	string s = resposta;
	resposta.erase();
	return s;
}

bool Painel::getAbrir(){
	return abrir;
}

Excecao Painel::getExcecao(){
	return excecao;
}

// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void Painel::setTitulo(string t){
	titulo = t;
}

void Painel::setCaminho(deque<string> c){
	caminho = c;
}

void Painel::setOpcoes(map<string, string> o){
	opcoes = o;
}

void Painel::setOpcoes(vector<string> o){
	opcoes = vectorParaMap(o);
}

void Painel::setPergunta(string p){
	pergunta = p;
}

void Painel::setResposta(string r){
	// Verifica se a chave 'r' não existe no map opcoes
	typename map<string, string>::iterator it;
	it = opcoes.find(r);
    if(it == opcoes.end()){
        throw Excecao("Opção inválida. Tente Novamente."); 
    } else if(r == "0") {
		abrir = false;
	} else {
		resposta = r;
	}
}

void Painel::setAbrir(bool a){
	abrir = a;
}

void Painel::setExcecao(Excecao &e){
	excecao = e;
}

// ------------------------------------------------------------------------
//		Operadores
// ------------------------------------------------------------------------

ostream& operator<< (ostream &o, Painel p){
	system("clear");
	cout << endl << "PET FERA" << endl;
	p.printCaminho();

	p.excecao.printMensagem();
	p.excecao.limparMensagem();

	cout << endl << p.titulo << endl;
	
	if(!p.opcoes.empty())
		p.printOpcoes();
	
	if(!p.pergunta.empty())
		cout << endl << p.pergunta;
		
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void Painel::printCaminho(){

	if(!caminho.empty()){
		cout << endl;
		deque<string>::iterator it;
		for (it = caminho.begin(); it != caminho.end(); ++it){
			cout << *it;
			if(it != caminho.end()-1)
				cout << " >> ";
		}
		cout << endl;
	}
}

void Painel::printOpcoes(){

	if(!opcoes.empty()){
        typename map<string, string>::iterator it;
		for (it = ++opcoes.begin(); it != opcoes.end(); ++it){

			cout << "\t" << it->first;
			cout << ". " << it->second << endl;
		}
		
		it = opcoes.begin();
		cout << "\n\t" << it->first;
		cout << ". " << it->second << endl;
	}
}

