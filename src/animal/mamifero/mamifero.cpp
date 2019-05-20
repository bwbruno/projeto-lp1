#include "animal/mamifero/mamifero.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

Mamifero::Mamifero(){
	limpar();
}

Mamifero::Mamifero(string linhaCSV){
	// Mamifero v("1;Mamifero;Daniel Oscar;123.456.789-10;30;O;+;Felinos;CRMV-GO 0406;;")
	string tmp;
	istringstream ss(linhaCSV);
	
	getline(ss, tmp, ';');                      // id
	id = atoi(tmp.c_str());
	
    getline(ss, classe, ';');                   // classe
	
    getline(ss, nome_cientifico, ';');          // nome científico
	
    getline(ss, tmp, ';');                      // sexo
    sexo = tmp[0];
	
    getline(ss, tmp, ';');                      // tamanho
	tamanho = atoi(tmp.c_str());
	
    getline(ss, dieta, ';');                    // dieta
	
    getline(ss, tmp, ';');                      // veterinario
    int id = atoi(tmp.c_str());             
    veterinario.setId(id);

	getline(ss, tmp, ';');                      // tratador
    id = atoi(tmp.c_str());             
	tratador.setId(id); 
	
    getline(ss, nome_batismo, ';');             // nome batismo
	
    getline(ss, tmp, ';');                      // uf ou país de origem

    getline(ss, tmp, ';');                      // autorização
}

// ------------------------------------------------------------------------
//		Getters
// ------------------------------------------------------------------------

string Mamifero::getCorPelo(){
	return cor_pelo;
}

// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

void Mamifero::setCorPelo(string cp){
	cor_pelo = cp;
}

// ------------------------------------------------------------------------
//		Operadores
// ------------------------------------------------------------------------

istream& operator>> (istream &i, Mamifero &m) {
	m.contador_cin++;
	switch (m.getContadorCin()){
		case 1:
			cout << "\nINSERIR ID: ";
			i >> m.id;
			break;

		case 2:
			cout << "\nINSERIR NOME CIENTIFICO: ";
			i >> m.nome_cientifico;
			break;

		case 3:
			cout << "\nINSERIR SEXO: ";
			i >> m.sexo;
			break;

		case 4:
			cout << "\nINSERIR TAMANHO: ";
			i >> m.tamanho;
			break;

		case 5: {
			cout << "\nINSERIR DIETA: ";
			i >> m.dieta;
			break;
		}
		case 6: {
			cout << "\nINSERIR VETERINÁRIO RESPONSÁVEL [ID/-1]: ";
			int id;
            i >> id;
            m.veterinario.setId(id);
			break;
		}
		case 7:
			cout << "\nINSERIR TRATADOR RESPONSÁVEL: [ID/-1]";
			int id;
            i >> id;
            m.tratador.setId(id);
			break;

		case 8:
			cout << "\nINSERIR NOME DE BATISMO: ";
			i >> m.nome_batismo;
			break;

		case 9:
			cout << "\nINSERIR COR DO PELO: ";
			i >> m.cor_pelo;
			break;
			
		default:
			m.setContadorCin(-1); 
			break;
	}

	return i;
	
}

ostream& operator<< (ostream &o, Mamifero const m) {
    o << "\tId: " << (m.id != -1 ? intParaString(m.id) : "") << endl;
	o << "\tClasse: " << m.classe << endl;
    o << "\tNome científico: " << m.nome_cientifico << endl;
    o << "\tSexo: " << m.sexo << endl;
    o << "\tTamanho: " << (m.tamanho != -1 ? intParaString(m.tamanho) : "") << endl;
    o << "\tDieta: " << m.dieta << endl;
    o << "\tVeterinário: " << (m.veterinario.getId() != -1 ? intParaString(m.veterinario.getId()) : "") << endl;
    o << "\tTratador: " << (m.tratador.getId() != -1 ? intParaString(m.tratador.getId()) : "") << endl;
    o << "\tNome de batismo: " << m.nome_batismo << endl;
    o << "\tCor pelo: " << m.cor_pelo << endl;
	return o;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void Mamifero::limpar(){
    id = -1;
    classe = "Mammalia";
    nome_cientifico = "";
    sexo = ' ';
    tamanho = -1;
    dieta = "";
    nome_batismo = "";
	contador_cin = 1;
    cor_pelo = "";
}

string Mamifero::getTipo(){
	return "Mammalia";
}

string Mamifero::getStringFormatoCSV(){
	stringstream ss;
	ss << id << ";";
	ss << classe << ";";
    ss << nome_cientifico << ";";
    ss << sexo << ";";
    ss << tamanho << ";";
    ss << dieta << ";";
    ss << veterinario.getId() << ";";
    ss << tratador.getId() << ";";
    ss << nome_batismo << ";";
	ss << ";"; // país de origem
	ss << ";"; // uf de origem
	ss << ";"; // autorizacao
	ss << endl;
	return ss.str();
}
