#include "animal/ave/ave.h"

using namespace std;

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

Ave::Ave(){
	limpar();
}

Ave::Ave(string linhaCSV){
	// Ave v("1;Ave;Daniel Oscar;123.456.789-10;30;O;+;Felinos;CRMV-GO 0406;;")
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

}

// ------------------------------------------------------------------------
//		Operadores
// ------------------------------------------------------------------------

istream& operator>> (istream &i, Ave &t) {
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
			cout << "\nINSERIR TAMANHO DO BICO EM CM: ";
			i >> t.tamanho_do_bico_cm;
			break;

        case 10:
			cout << "\nINSERIR ENVERGADURA DAS ASAS EM CM: ";
			i >> t.envergadura_das_asas_cm;
			break;
        			
		default:
			t.setContadorCin(-1); 
			break;
	}

	return i;
	
}

ostream& operator<< (ostream &o, Ave const a) {
    o << "\tId: " << (a.id != -1 ? to_string(a.id) : "") << endl;
	o << "\tClasse: " << a.classe << endl;
    o << "\tNome científico: " << a.nome_cientifico << endl;
    o << "\tSexo: " << a.sexo << endl;
    o << "\tTamanho: " << (a.tamanho != -1 ? to_string(a.tamanho) : "") << endl;
    o << "\tDieta: " << a.dieta << endl;
    o << "\tVeterinário: " << (a.veterinario.getId() != -1 ? to_string(a.veterinario.getId()) : "") << endl;
    o << "\tTratador: " << (a.tratador.getId() != -1 ? to_string(a.tratador.getId()) : "") << endl;
    o << "\tNome de batismo: " << a.nome_batismo << endl;
    o << "\tTamanho do bico: " << (a.tamanho_do_bico_cm != -1 ? to_string(a.tamanho_do_bico_cm) : "") << " cm"<< endl;
    o << "\tEnvergadura das asas: " << (a.envergadura_das_asas_cm != -1 ? to_string(a.envergadura_das_asas_cm) : "") << " cm" << endl;
	return o;
}

// ------------------------------------------------------------------------
//		Métodos utilitários
// ------------------------------------------------------------------------

void Ave::limpar(){
    id = -1;
    classe = "Amphibia";
    nome_cientifico = "";
    sexo = ' ';
    tamanho = -1;
    dieta = "";
    nome_batismo = "";
    tamanho_do_bico_cm = -1;
    envergadura_das_asas_cm = -1;
}

string Ave::getStringFormatoCSV(){
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
