#include "funcionario/veterinario.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

Veterinario::Veterinario(){
	limpar();
}

Veterinario::Veterinario(string linhaCSV){
	// Veterinario v("1;Veterinario;Daniel Oscar;123.456.789-10;30;O;+;Felinos;CRMV-GO 0406;;")
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

	getline(ss, crmv, ';'); 						// crmv

	getline(ss, tmp, ';');							// nivel seguranca
}

// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

string Veterinario::getCRMV(){
	return crmv;
}

// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void Veterinario::setCRMV(string c){
	crmv = c;
}

// ------------------------------------------------------------------------
//		Operadores
// ------------------------------------------------------------------------

istream& operator>> (istream &i, Veterinario &t) {
	t.contador_cin++;
	switch (t.getContadorCin()){
		case 1:
			cout << "\nINSERIR NOME: ";
			i >> t.nome;
			break;

		case 2:
			cout << "\nINSERIR CPF: ";
			i >> t.cpf;
			break;

		case 3:
			cout << "\nINSERIR IDADE: ";
			i >> t.idade;
			break;

		case 4: {
			cout << "\nINSERIR TIPO SANGUINEO [A/B/AB/O]: ";
			string ts;
			i >> ts;
			t.setTipo_sanguineo(ts);
			break;
		}
		case 5: {
			cout << "\nINSERIR FATOR RH: [+/-]: ";
			char frh;
			i >> frh;
			t.setFatorRh(frh);
			break;
		}
		case 6:
			cout << "\nINSERIR ESPECIALIDADE: ";
			i >> t.especialidade;
			break;

		case 7:
			cout << "\nINSERIR CRMV: ";
			i >> t.crmv;
			break;
			
		default:
			t.setContadorCin(-1); 
			break;
	}

	return i;
	
}

ostream& operator<< (ostream &o, Veterinario const t) {
	o << "\tId: " << (t.id != -1 ? intParaString(t.id) : "") << endl;
	o << "\tNome: " << t.nome << endl;
	o << "\tCPF: " << t.cpf << endl;
	o << "\tIdade: " << (t.idade != -1 ? intParaString(t.idade) : "") << endl;
	o << "\tTipo sanguíneo: " << t.tipo_sanguineo << endl;
	o << "\tFator RH: " << t.fator_rh << endl;
	o << "\tEspecialidade: " << t.especialidade << endl;
	o << "\tCRMV: " << t.crmv << endl;
	return o;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void Veterinario::limpar(){
	id = -1;
	nome = "";
	cpf = "";
	idade = -1;
	tipo_sanguineo = ' ';
	fator_rh = ' ';
	especialidade = ' ';
	crmv = "";
	contador_cin = 0;
}

string Veterinario::getTipo(){
	return "Veterinario";
}

string Veterinario::getStringCSV(){

	stringstream ss;
	ss << id << ";";
	ss << getTipo() << ";";
	ss << nome << ";";
	ss << cpf << ";";
	ss << idade << ";";
	ss << tipo_sanguineo << ";";
	ss << fator_rh << ";";
	ss << especialidade << ";";
	ss << crmv << ";";
	ss << ";";
	ss << endl;
	return ss.str();
}

std::vector<std::string> Veterinario::vectorAtributos(){
	
	vector<string> atributos;
	atributos.push_back("VOLTAR");
	atributos.push_back("NOME");
	atributos.push_back("CPF");
	atributos.push_back("IDADE");
	atributos.push_back("TIPO SANGUÍNEO");
	atributos.push_back("FATOR RH");
	atributos.push_back("ESPECIALIDADE");
	atributos.push_back("CRMV");

	return atributos;
}