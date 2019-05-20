#include "animal/reptil/reptil_exotico.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

ReptilExotico::ReptilExotico(){
	limpar();
}

ReptilExotico::ReptilExotico(string linhaCSV){
	// ReptilExotico v("1;ReptilExotico;Daniel Oscar;123.456.789-10;30;O;+;Felinos;CRMV-GO 0406;;")
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
	
    getline(ss, pais_origem, ';');              // país de origem

    getline(ss, tmp, ';');                      // uf de origem

    getline(ss, autorizacao_ibama, ';');        // autorização
}

// ------------------------------------------------------------------------
//		Operadores
// ------------------------------------------------------------------------

istream& operator>> (istream &i, ReptilExotico &t) {
	t.contador_cin++;
	switch (t.getContadorCin()){
		case 1:
			cout << "\nINSERIR ID: ";
			i >> t.id;
			break;

		case 2:
			cout << "\nINSERIR NOME CIENTIFICO: ";
			i >> t.nome_cientifico;
			break;

		case 3:
			cout << "\nINSERIR SEXO: ";
			i >> t.sexo;
			break;

		case 4:
			cout << "\nINSERIR TAMANHO: ";
			i >> t.tamanho;
			break;

		case 5: {
			cout << "\nINSERIR DIETA: ";
			i >> t.dieta;
			break;
		}
		case 6: {
			cout << "\nINSERIR VETERINÁRIO RESPONSÁVEL [ID/-1]: ";
			int id;
            i >> id;
            t.veterinario.setId(id);
			break;
		}
		case 7:
			cout << "\nINSERIR TRATADOR RESPONSÁVEL: [ID/-1]";
			int id;
            i >> id;
            t.tratador.setId(id);
			break;

		case 8:
			cout << "\nINSERIR NOME DE BATISMO: ";
			i >> t.nome_batismo;
			break;

		case 9:
			cout << "\nÉ VENENOSO? [s/n]: ";
			i >> t.venenoso;
			break;

        case 10:
			cout << "\nINSERIR TIPO VENENO: ";
			i >> t.tipo_veneno;
			break;
        
        
        case 11:
			cout << "\nINSERIR PAÍS DE ORIGEM: ";
			i >> t.pais_origem;
			break;

		case 12:
			cout << "\nINSERIR AUTORIZAÇÃO DO IBAMA: ";
			i >> t.autorizacao_ibama;
			break;
			
		default:
			t.setContadorCin(-1); 
			break;
	}

	return i;
	
}

ostream& operator<< (ostream &o, ReptilExotico const a) {
    o << "\tId: " << (a.id != -1 ? to_string(a.id) : "") << endl;
	o << "\tClasse: " << a.classe << endl;
    o << "\tNome científico: " << a.nome_cientifico << endl;
    o << "\tSexo: " << a.sexo << endl;
    o << "\tTamanho: " << (a.tamanho != -1 ? to_string(a.tamanho) : "") << endl;
    o << "\tDieta: " << a.dieta << endl;
    o << "\tVeterinário: " << (a.veterinario.getId() != -1 ? to_string(a.veterinario.getId()) : "") << endl;
    o << "\tTratador: " << (a.tratador.getId() != -1 ? to_string(a.tratador.getId()) : "") << endl;
    o << "\tNome de batismo: " << a.nome_batismo << endl;
    o << "\tVenenoso: " << a.venenoso << endl;
    o << "\tTipo veneno: " << a.tipo_veneno << endl;
    o << "\tPaís de origem: " << a.pais_origem << endl;
    o << "\tAutorização do IBAMA: " << a.autorizacao_ibama << endl;
	return o;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void ReptilExotico::limpar(){
    id = -1;
    classe = "Amphibia";
    nome_cientifico = "";
    sexo = ' ';
    tamanho = -1;
    dieta = "";
    nome_batismo = "";
    venenoso = false;
    tipo_veneno = "";
    pais_origem = "";
    autorizacao_ibama = "";
}

string ReptilExotico::getStringFormatoCSV(){
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
	ss << pais_origem << ";";
	ss << ";"; // uf de origem
	ss << autorizacao_ibama << ";";
	ss << endl;
	return ss.str();
}
