#include "funcionario/tratador.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

Tratador::Tratador(){
	limpar();
}

Tratador::Tratador(string linhaCSV){
	// Tratador t("1;Tratador;João Alberto;007.404.200-98;45;AB;-;Répteis e Aves;;1;")
	string tmp;
	istringstream ss(linhaCSV);
	
	getline(ss, tmp, ';');							// id
	id = atoi(tmp.c_str());
	
	getline(ss, tmp, ';');							// tipo

	getline(ss, nome, ';');							// nome
	
	getline(ss, cpf, ';');							// cpf
	
	getline(ss, tmp, ';');							// idade
	idade = atoi(tmp.c_str());
	
	getline(ss, tipo_sanguineo, ';');				// tipo sanguineo

	getline(ss, tmp, ';'); 							// fator_rh
	fator_rh = tmp[0];
	
	getline(ss, especialidade, ';'); 				// especialidade

	getline(ss, tmp, ';'); 							// crmv

	getline(ss, tmp, ';');							// nivel seguranca
	nivel_de_seguranca = atoi(tmp.c_str());
}


// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

int Tratador::getNivelDeSeguranca(){
	return nivel_de_seguranca;
}


// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void Tratador::setNivelDeSeguranca(int nds){
	if(!((0 <= nds)&&(nds <= 2))) //Se nds não estiver entre 0 e 2
		throw Excecao("Nível de Segurança inválido.");
	else
		nivel_de_seguranca = nds;
}


// ------------------------------------------------------------------------
//		Operadores
// ------------------------------------------------------------------------

istream& operator>> (istream &i, Tratador &t) {
	t.contador_cin++;
	switch (t.getContadorCin()){
		case 1:
			cout << "\nINSERIR ID: ";
			i >> t.id;
			break;

		case 2:
			cout << "\nINSERIR NOME: ";
			i >> t.nome;
			break;

		case 3:
			cout << "\nINSERIR CPF: ";
			i >> t.cpf;
			break;

		case 4:
			cout << "\nINSERIR IDADE: ";
			i >> t.idade;
			break;

		case 5: {
			cout << "\nINSERIR TIPO SANGUINEO [A/B/AB/O]: ";
			string ts;
			i >> ts;
			t.setTipo_sanguineo(ts);
			break;
		}
		case 6: {
			cout << "\nINSERIR FATOR RH: [+/-]: ";
			char frh;
			i >> frh;
			t.setFatorRh(frh);
			break;
		}
		case 7:
			cout << "\nINSERIR ESPECIALIDADE: ";
			i >> t.especialidade;
			break;

		case 8:
			cout << "\nINSERIR NIVEL DE SEGURANCA [0/1/2]: ";
			int nds;
			i >> nds;
			t.setNivelDeSeguranca(nds);
			break;
			
		default:
			t.setContadorCin(-1); 
			break;
	}

	return i;
	
}

ostream& operator<< (ostream &o, Tratador const t) {
	o << "\tId: " << (t.id != -1 ? intParaString(t.id) : "") << endl;
	o << "\tNome: " << t.nome << endl;
	o << "\tCPF: " << t.cpf << endl;
	o << "\tIdade: " << (t.idade != -1 ? intParaString(t.idade) : "") << endl;
	o << "\tTipo sanguíneo: " << t.tipo_sanguineo << endl;
	o << "\tFator RH: " << t.fator_rh << endl;
	o << "\tEspecialidade: " << t.especialidade << endl;
	o << "\tNível de segurança: " << (t.nivel_de_seguranca != -1 ? intParaString(t.nivel_de_seguranca) : "") << endl;
	return o;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void Tratador::limpar(){
	id = -1;
	nome = "";
	cpf = "";
	idade = -1;
	tipo_sanguineo = ' ';
	fator_rh = ' ';
	especialidade = ' ';
	nivel_de_seguranca = -1;
	contador_cin = 1;
}


string Tratador::getTipo(){
	return "Tratador";
}

string Tratador::getStringFormatoCSV(){

	stringstream ss;
	ss << id << ";";
	ss << getTipo() << ";";
	ss << nome << ";";
	ss << cpf << ";";
	ss << idade << ";";
	ss << tipo_sanguineo << ";";
	ss << fator_rh << ";";
	ss << especialidade << ";";
	ss << ";";
	ss << nivel_de_seguranca << ";";
	ss << endl;
	return ss.str();
}
