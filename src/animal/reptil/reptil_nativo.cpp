#include "animal/reptil/reptil_nativo.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

ReptilNativo::ReptilNativo(){
	limpar();
}

ReptilNativo::ReptilNativo(string linhaCSV, string linhaDetalhesCSV){
	// ReptilNativo v("1;ReptilNativo;Daniel Oscar;123.456.789-10;30;O;+;Felinos;CRMV-GO 0406;;")
	string tmp;
	
	// Linha do arquivo animais
	istringstream ss(linhaCSV);
	getline(ss, tmp, ';');                      // id
	id = atoi(tmp.c_str());
    getline(ss, classe, ';');                   // classe
    getline(ss, especie, ';');                  // especie
    getline(ss, nome_cientifico, ';');          // nome científico
    getline(ss, tmp, ';');                      // sexo
    sexo = tmp[0];
    getline(ss, tmp, ';');                      // tamanho
	tamanho = atoi(tmp.c_str());
    getline(ss, dieta, ';');                    // dieta
    getline(ss, tmp, ';');                      // veterinario
    int v_id = atoi(tmp.c_str());             
    veterinario.setId(id);
	getline(ss, tmp, ';');                      // tratador
    int t_id = atoi(tmp.c_str());             
	tratador.setId(t_id); 
    getline(ss, nome_batismo, ';');             // nome batismo

	// Linha do arquivo detalhes animais
	istringstream iss(linhaDetalhesCSV);
	getline(iss, tmp, ';');						// id
	getline(iss, tmp, ';');						// classe
	getline(iss, tmp, ';');						// venenoso
	setVenenoso(tmp);
	getline(iss, tipo_veneno, ';');				// tipo veneno
    getline(iss, uf_origem, ';');               // uf de origem
    getline(iss, autorizacao_ibama, ';');       // autorização
}

// ------------------------------------------------------------------------
//		Operadores
// ------------------------------------------------------------------------

istream& operator>> (istream &i, ReptilNativo &t) {
	t.contador_cin++;
	switch (t.getContadorCin()){
		case 1:
			cout << "\nINSERIR ESPÉCIE: ";
			i >> t.especie;
			break;

		case 2:
			cout << "\nINSERIR NOME CIENTIFICO: ";
			i >> t.nome_cientifico;
			break;

		case 3:
			cout << "\nINSERIR SEXO [M/F]: ";
			char sexo;
			i >> sexo;
			t.setSexo(sexo);
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
			cout << "\nINSERIR VETERINÁRIO RESPONSÁVEL [ID/0]: ";
			int id;
            i >> id;
            t.veterinario.setId(id);
			break;
		}
		case 7:
			cout << "\nINSERIR TRATADOR RESPONSÁVEL [ID/0]: ";
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
			cout << "\nINSERIR UF DE ORIGEM: ";
			i >> t.uf_origem;
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

ostream& operator<< (ostream &o, ReptilNativo const a) {
    o << "\tId: " << (a.id != -1 ? intParaString(a.id) : "") << endl;
	o << "\tClasse: " << a.classe << endl;
	o << "\tEspécie: " << a.especie << endl;
    o << "\tNome científico: " << a.nome_cientifico << endl;
    o << "\tSexo: " << a.sexo << endl;
    o << "\tTamanho: " << (a.tamanho != -1 ? intParaString(a.tamanho) : "") << endl;
    o << "\tDieta: " << a.dieta << endl;
    o << "\tVeterinário: " << (a.veterinario.getId() != -1 ? intParaString(a.veterinario.getId()) : "") << endl;
    o << "\tTratador: " << (a.tratador.getId() != -1 ? intParaString(a.tratador.getId()) : "") << endl;
    o << "\tNome de batismo: " << a.nome_batismo << endl;
    o << "\tVenenoso: " << a.venenoso << endl;
    o << "\tTipo veneno: " << a.tipo_veneno << endl;
    o << "\tUF de origem: " << a.uf_origem << endl;
    o << "\tAutorização do IBAMA: " << a.autorizacao_ibama << endl;
	return o;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void ReptilNativo::limpar(){
    id = -1;
    classe = "Reptilia Nativo";
    nome_cientifico = "";
    sexo = ' ';
    tamanho = -1;
    dieta = "";
    nome_batismo = "";
	contador_cin = 0;
    venenoso = false;
    tipo_veneno = "";
    uf_origem = "";
    autorizacao_ibama = "";
}

string ReptilNativo::getStringCSV(){
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
	ss << endl;
	return ss.str();
}

string ReptilNativo::getStringDetalhesCSV(){
	stringstream ss;
	ss << id << ";";
	ss << classe << ";";
	ss << venenoso << ";";
	ss << tipo_veneno << ";";
	ss << uf_origem << ";";
	ss << autorizacao_ibama << ";";
	ss << endl;
	return ss.str();
}

std::vector<std::string> ReptilNativo::vectorAtributos(){
	
	vector<string> atributos;
	atributos.push_back("VOLTAR");
	atributos.push_back("ESPÉCIE");
	atributos.push_back("NOME CIENTÍFICO");
	atributos.push_back("SEXO");
	atributos.push_back("TAMANHO");
	atributos.push_back("DIETA");
	atributos.push_back("VETERINÁRIO");
	atributos.push_back("TRATADOR");
	atributos.push_back("NOME BATISMO");
	atributos.push_back("VENENOSO");
	atributos.push_back("TIPO DO VENENO");
	atributos.push_back("UF DE ORIGEM");
	atributos.push_back("AUTORIZAÇÃO DO IBAMA");

	return atributos;
}