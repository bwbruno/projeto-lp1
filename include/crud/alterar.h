#ifndef __ALTERAR_H__
#define __ALTERAR_H__

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <istream>
#include <map>

#include "excecao/excecao.h"
#include "painel/painel.h"
#include "paineis.h"
#include "utilitarios.h"
#include "crud/operacoes_csv.h"
#include "funcionario/veterinario.h"
#include "funcionario/tratador.h"

//void alterar_VET(int opcao, Veterinario &vet);
//void alterar_TRAT(int opcao, Tratador &trat);


template <typename CLASSE>
void alterar(std::string enderecoArquivo, std::deque<std::string> caminho, std::string vet_trat){

    Painel alterar;
    OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<int, CLASSE> lista = csv.getLista();
    int selecao = 1;
    std::string tipo_do_funcionario;

    if(strcmp(vet_trat.c_str(), "TRATADORES") == 0){
        alterar.setTitulo("TRATADORES CADASTRADOS");
        tipo_do_funcionario = ("Tratador");
    }else{
        alterar.setTitulo("VETERINÁRIOS CADASTRADOS");
        tipo_do_funcionario = ("Veterinario");
    }
    caminho.push_back("ALTERAR");

    alterar.setCaminho(caminho);

    while(selecao != 0){

		try{
            std::cout << alterar;

			// Imprime a lista de funcionarios id-nome
	        typename std::map<int, CLASSE>::iterator it;
            for (it = lista.begin(); it != lista.end(); ++it)
                it->second.printIdNome();
            
            std::cout << "\n\t0. VOLTAR\n";
            std::cout << "\nSELECIONE O ID DO FUNCIONARIO OU ZERO [0] PARA VOLTAR: ";
            std::cin >> selecao;
        
			// Tratamento de erro, caso o usuário insira texto em vez de números
			if(std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(__INT_MAX__, '\n');
				throw Excecao("Valor inválido. Insira um valor númerico.");
			}

            painelAlterar(enderecoArquivo, selecao, lista, caminho, tipo_do_funcionario);
            std::cout << selecao <<"\n";
		}
		catch(Excecao& e){
			alterar.setExcecao(e);
		}
			
	}
   
}

template <typename CLASSE>
int painelAlterar(std::string ea, int &id, std::map<int, CLASSE> &lista, std::deque<std::string> caminho,
 std::string tipo_do_funcionario){

    typename std::map<int, CLASSE>::iterator it;
    it = lista.find(id);

    if(it == lista.end())
        throw Excecao("O id informado é inválido. Tente novamente."); 
    
    caminho.push_back("ALTERAR FUNCIONÁRIO");
	std::string titulo = "DETALHES DO FUNCIONARIO";	
	
	Painel detalhes(titulo, caminho);	

    int selecao = -1;

	while(selecao != 0 && selecao !=1){

		try{
			std::cout << detalhes;

            //std::cout << it->second;
            printDetalhes(it->second, tipo_do_funcionario);
        
            std::cout << "\n\t0. CANCELAR ALTERAÇÃO";
            std::cout << "\n\nESCOLHA SUA OPÇÃO: ";
            std::cin >> selecao;

			// Tratamento de erro, caso o usuário insira texto em vez de números
			if(std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(__INT_MAX__, '\n');
				throw Excecao("Valor inválido. Insira um valor númerico.");
			}

            if(selecao != 0){
                OperacoesCSV<CLASSE> csv_alterar(ea);
                
                std::fstream aqv_original;//arquivo original com as informações dos funcionarios
                aqv_original.open(ea.c_str(), std::ios::in);//vou apenas ler esse arquivo

                std::map<int, Veterinario> map_veterinarios;//map q armazena os veterinarios
                std::map<int, Tratador> map_tratadores;//map q armazena os tratadores
                std::string line;//linha de leitura do arquivo

                if(aqv_original.is_open()){
                    
                    while(getline(aqv_original, line)){

                        std::string id_aqv = csv_alterar.getIDDaLinha(line);
                        int id_teste = atoi(id_aqv.c_str());

                        std::string *tipo_aqv = new std::string;
                        *tipo_aqv = csv_alterar.getTipoDaLinha(line);

                        if(*tipo_aqv == "Veterinario"){
                            Veterinario vet(line);
                            map_veterinarios.insert(std::pair<int , Veterinario>(id_teste, vet));
                        }
                        else if(*tipo_aqv == "Tratador"){
                            Tratador trat(line);
                            map_tratadores.insert(std::pair<int, Tratador>(id_teste, trat));
                        }

                        delete tipo_aqv;

                    }

                    if(tipo_do_funcionario == "Veterinario"){
                        if(selecao == 1){
                            int *novo_id = new int;
                            std::cout << "Novo ID: ";
                            std::cin >> *novo_id;
                            map_veterinarios[id].setId(*novo_id);
                            delete novo_id;
                        }else if(selecao == 2){
                            std::string *novo = new std::string;
                            std::cout << "Novo Nome: ";
                            std::cin >> *novo;
                            map_veterinarios[id].setNome(*novo);
                            delete novo;
                        }else if(selecao == 3){
                            std::string *novo_c = new std::string;
                            std::cout << "Novo CPF: ";
                            std::cin >> *novo_c;
                            map_veterinarios[id].setCPF(*novo_c);
                            delete novo_c;
                        }else if(selecao == 4){
                            int *novo_i = new int;
                            std::cout << "Nova Idade: ";
                            std::cin >> *novo_i;
                            map_veterinarios[id].setIdade(*novo_i);
                            delete novo_i;
                        }else if(selecao == 5){
                            std::string *novo_ts = new std::string;
                            std::cout << "Novo Tipo Sanguineo: ";
                            std::cin >> *novo_ts;
                            map_veterinarios[id].setTipo_sanguineo(*novo_ts);
                            delete novo_ts;
                        }else if(selecao == 6){
                            char *novo_f = new char;
                            std::cout << "Novo Fator RH: ";
                            std::cin >> *novo_f;
                            map_veterinarios[id].setFatorRh(*novo_f);
                            delete novo_f;
                        }else if(selecao == 7){
                            std::string *novo_es = new std::string;
                            std::cout << "Nova Especialidade: ";
                            std::cin >> *novo_es;
                            map_veterinarios[id].setEspecialidade(*novo_es);
                            delete novo_es;
                        }


                    }
                    else if(tipo_do_funcionario == "Tratador"){
                        if(selecao == 1){
                            int *novo_id = new int;
                            std::cout << "Novo ID: ";
                            std::cin >> *novo_id;
                            map_tratadores[id].setId(*novo_id);
                            delete novo_id;
                        }else if(selecao == 2){
                            std::string *novo = new std::string;
                            std::cout << "Novo Nome: ";
                            std::cin >> *novo;
                            map_tratadores[id].setNome(*novo);
                            delete novo;
                        }else if(selecao == 3){
                            std::string *novo = new std::string;
                            std::cout << "Novo CPF: ";
                            std::cin >> *novo;
                            map_tratadores[id].setCPF(*novo);
                            delete novo;
                        }else if(selecao == 4){
                            int *novo = new int;
                            std::cout << "Nova Idade: ";
                            std::cin >> *novo;
                            map_tratadores[id].setIdade(*novo);
                            delete novo;
                        }else if(selecao == 5){
                            std::string *novo = new std::string;
                            std::cout << "Novo Tipo Sanguineo: ";
                            std::cin >> *novo;
                            map_tratadores[id].setTipo_sanguineo(*novo);
                            delete novo;
                        }else if(selecao == 6){
                            char *novo = new char;
                            std::cout << "Novo Fator RH: ";
                            std::cin >> *novo;
                            map_tratadores[id].setFatorRh(*novo);
                            delete novo;
                        }else if(selecao == 7){
                            std::string *novo = new std::string;
                            std::cout << "Nova Especialidade: ";
                            std::cin >> *novo;
                            map_tratadores[id].setEspecialidade(*novo);
                            delete novo;
                        }
                    }

                    

                    //std::cout << map_veterinarios[id].getNome();
                    //int tt;
                    //std::cin >> tt;

                }else{
                    std::cout << "Arquivo inválido!" << std::endl;
                }

                aqv_original.close();

                std::map<int, Veterinario>::iterator itv;
                std::map<int, Tratador>::iterator itt;

                OperacoesCSV<Veterinario> csv_v(ea);
                OperacoesCSV<Tratador> csv_t(ea);

                std::ofstream aqv_alterado;
                aqv_alterado.open(ea.c_str());

                for(itv = map_veterinarios.begin(); itv != map_veterinarios.end(); ++itv){
                    aqv_alterado << itv->second.getStringFormatoCSV() << "\n";

                }
                for(itt = map_tratadores.begin(); itt != map_tratadores.end(); ++itt){
                    aqv_alterado << itt->second.getStringFormatoCSV() << "\n"; 
                }

                aqv_alterado.close();
                
                while(id != 0){
                    Painel removido("FUNCIONARIO ALTERADO COM SUCESSO!", caminho);
                    std::cout << removido;
                    std::cout << "\n\t0. VOLTAR";
                    std::cin >> id;
                }
                return id;
            }

		}
		catch(Excecao& e){
			detalhes.setExcecao(e);
		}
			
	}
}

template <typename CLASSE>
void printDetalhes(CLASSE f, std::string tipo_f){
    //if(tipo_f == "Veterinario"){
        std::cout << "\t1. Id: " << (f.getId() != -1 ? intParaString(f.getId()) : "") << std::endl;
	    std::cout << "\t2. Nome: " << f.getNome() << std::endl;
	    std::cout << "\t3. CPF: " << f.getCPF() << std::endl;
	    std::cout << "\t4. Idade: " << (f.getIdade() != -1 ? intParaString(f.getIdade()) : "") << std::endl;
	    std::cout << "\t5. Tipo sanguíneo: " << f.getTipo_sanguineo() << std::endl;
	    std::cout << "\t6. Fator RH: " << f.getFator_rh() << std::endl;
	    std::cout << "\t7. Especialidade: " << f.getEspecialidade() << std::endl;
	    //std::cout << "\t8. CRMV: " << f.getCRMV << std::endl;
    //}
    /*elseif(tipo_f == "Tratador"){
        std::cout << "\t1. Id: " << (f.getId() != -1 ? intParaString(f.getId()) : "") << std::endl;
	    std::cout << "\t2. Nome: " << f.getNome() << std::endl;
	    std::cout << "\t3. CPF: " << f.getCPF() << std::endl;
	    std::cout << "\t4. Idade: " << (f.getIdade() != -1 ? intParaString(f.getIdade()) : "") << std::endl;
	    std::cout << "\t5. Tipo sanguíneo: " << f.getTipo_sanguineo() << std::endl;
	    std::cout << "\t6. Fator RH: " << f.getFator_rh() << std::endl;
	    std::cout << "\t7. Especialidade: " << f.getEspecialidade() << std::endl;
	    //std::cout << "\t8. CRMV: " << f.getCRMV << std::endl;
    }*/

}
/*    
void alterar_VET(int opcao, Veterinario &vet){
    
}
void alterar_TRAT(int opcao, Tratador &trat){

}*/

#endif