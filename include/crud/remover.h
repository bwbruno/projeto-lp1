#ifndef __REMOVER_H__
#define __REMOVER_H__

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <istream>
#include <queue>

#include "excecao/excecao.h"
#include "painel/painel.h"
#include "utilitarios.h"
#include "crud/operacoes_csv.h"

/*
typedef struct InformacoesFuncionario{
    std::string id;
    std::string tipo_funcionario;
    //std::string resto_linha;

} TFunc;
*/

template <typename CLASSE>
void remover(std::string enderecoArquivo, std::deque<std::string> caminho, std::string vet_trat){

    Painel remover;
    OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<int, CLASSE> lista = csv.getLista();
    int selecao = 1;
    std::string tipo_do_funcionario;

    if(strcmp(vet_trat.c_str(), "TRATADORES") == 0){
        remover.setTitulo("TRATADORES CADASTRADOS");
        tipo_do_funcionario = ("Tratador");
    }else{
        remover.setTitulo("VETERINÁRIOS CADASTRADOS");
        tipo_do_funcionario = ("Veterinario");
    }
    caminho.push_back("REMOVER");

    remover.setCaminho(caminho);

    while(selecao != 0){

		try{
            std::cout << remover;

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

            painelRemover(enderecoArquivo, selecao, lista, caminho, tipo_do_funcionario);
            std::cout << selecao <<"\n";
		}
		catch(Excecao& e){
			remover.setExcecao(e);
		}
			
	}
   
}

template <typename CLASSE>
int painelRemover(std::string ea, int &id, std::map<int, CLASSE> &lista, std::deque<std::string> caminho,
 std::string tipo_do_funcionario){

    typename std::map<int, CLASSE>::iterator it;
    it = lista.find(id);

    if(it == lista.end())
        throw Excecao("O id informado é inválido. Tente novamente."); 
    
    caminho.push_back("REMOVER FUNCIONARIO");
	std::string titulo = "DETALHES DO FUNCIONARIO";	
	
	Painel detalhes(titulo, caminho);	

    int selecao = -1;

	while(selecao != 0 && selecao !=1){

		try{
			std::cout << detalhes;

            std::cout << it->second;
        
            std::cout << "\nOPÇÕES";
            std::cout << "\n\t1. REMOVER FUNCIONARIO";
            std::cout << "\n\t0. CANCELAR REMOÇÃO";
            std::cout << "\n\nESCOLHA SUA OPÇÃO: ";
            std::cin >> selecao;

			// Tratamento de erro, caso o usuário insira texto em vez de números
			if(std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(__INT_MAX__, '\n');
				throw Excecao("Valor inválido. Insira um valor númerico.");
			}

            if(selecao == 1){
                OperacoesCSV<CLASSE> csv_remover(ea);
                
                std::fstream aqv_remover;//arquivo original com as informações dos funcionarios
                aqv_remover.open(ea.c_str(), std::ios::in);//vou apenas ler esse arquivo

                std::queue<std::string> fila_func;
                std::string line;

                if(aqv_remover.is_open()){
                    
                    while(getline(aqv_remover, line)){

                        std::string id_aqv = csv_remover.getIDDaLinha(line);
                        int id_teste = atoi(id_aqv.c_str());

                        std::string *tipo_aqv = new std::string;
                        *tipo_aqv = csv_remover.getTipoDaLinha(line);

/*
Armazena na fila todos os funcionarios com exceção daquele excluido
*/
                        if(tipo_do_funcionario != *tipo_aqv || id_teste != id){
                            fila_func.push(line);
                        }

                        std::cout << *tipo_aqv <<"\n" << id_aqv << "\n";

                        delete tipo_aqv;

                    }
                }else{
                    std::cout << "Arquivo inválido!" << std::endl;
                }

                aqv_remover.close();

                std::ofstream aqv_removido;//esse arquivo ira sobreescrever o antigo arquivo de funcionarios
                aqv_removido.open(ea.c_str());

                while(!fila_func.empty()){
                    aqv_removido << fila_func.front() << "\n";
                    fila_func.pop();
                }
                
                while(id != 0){
                    Painel removido("FUNCIONARIO REMOVIDO COM SUCESSO!", caminho);
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


#endif