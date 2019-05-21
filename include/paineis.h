#ifndef __PAINEIS_H__
#define __PAINEIS_H__

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

#include "painel/painel.h"
#include "crud/cadastrar.h"
#include "crud/teste.h"
#include "crud/consultar.h"
#include "crud/remover.h"
#include "funcionario/tratador.h"
#include "funcionario/veterinario.h"
#include "animal/anfibio/anfibio.h"
#include "animal/anfibio/anfibio_exotico.h"
#include "animal/anfibio/anfibio_nativo.h"
#include "animal/ave/ave.h"
#include "animal/ave/ave_exotico.h"
#include "animal/ave/ave_nativo.h"
#include "animal/mamifero/mamifero.h"
#include "animal/mamifero/mamifero_exotico.h"
#include "animal/mamifero/mamifero_nativo.h"
#include "animal/reptil/reptil.h"
#include "animal/reptil/reptil_exotico.h"
#include "animal/reptil/reptil_nativo.h"

void painelPrincipal();
void painelAnimais(std::deque<std::string> caminho);
void painelAnimaisConsulta(std::deque<std::string> caminho);
void painelFuncionarios(std::deque<std::string> caminho);

template <typename CLASSE>
void painelCrudF(std::string titulo, std::deque<std::string> caminho, std::string endereco){
	
	Painel painel;
	std::vector<std::string> opcoes;
	std::string opcao;

	caminho.push_back(titulo);
	
	opcoes.push_back("VOLTAR");
	opcoes.push_back("CADASTRAR");
	opcoes.push_back("REMOVER");
	opcoes.push_back("ALTERAR");
	opcoes.push_back("CONSULTAR");
	
	painel.setTitulo(titulo);
	painel.setCaminho(caminho);
	painel.setOpcoes(opcoes);
	painel.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(painel.getAbrir()){

		try{
			std::cout << painel;
			std::cin >> opcao;
			painel.setResposta(opcao);

			if(opcao == "1"){
				cadastrar<CLASSE>(endereco, caminho);

			} else if(opcao == "2"){
				remover<CLASSE>(endereco, caminho, painel.getTitulo());

			} else if(opcao == "3"){
				// FAZER

			} else if(opcao == "4"){
				consultar<CLASSE>(endereco, caminho);
			}
		}
		catch(Excecao& e){
			painel.setExcecao(e);
		}
			
	}
}

template <typename CLASSE>
void painelCrud(std::string titulo, std::deque<std::string> caminho, std::string endereco){
	
	Painel painel;
	std::vector<std::string> opcoes;
	std::string opcao;

	caminho.push_back(titulo);
	
	opcoes.push_back("VOLTAR");
	opcoes.push_back("CADASTRAR");
	opcoes.push_back("REMOVER");
	opcoes.push_back("ALTERAR");
	opcoes.push_back("CONSULTAR");
	
	painel.setTitulo(titulo);
	painel.setCaminho(caminho);
	painel.setOpcoes(opcoes);
	painel.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(painel.getAbrir()){

		try{
			std::cout << painel;
			std::cin >> opcao;
			painel.setResposta(opcao);

			if(opcao == "1"){
				cadastrar<CLASSE>(endereco, caminho);

			} else if(opcao == "2"){
				//remover<CLASSE>(endereco, caminho, painel.getTitulo());

			} else if(opcao == "3"){
				// FAZER

			} else if(opcao == "4"){
				consultar<CLASSE>(endereco, caminho);
			}
		}
		catch(Excecao& e){
			painel.setExcecao(e);
		}
			
	}
}

Painel getPainelTipo(std::string titulo, std::deque<std::string> caminho);

template <typename ANIMAIS>
void painelTipo(std::string titulo, std::deque<std::string> caminho, std::string endereco){
	
	Painel painel = getPainelTipo(titulo, caminho);
	std::string opcao;
	std::string end = endereco;

	while(painel.getAbrir()){

		try{
			std::cout << painel;
			std::cin >> opcao;
			painel.setResposta(opcao);

			if(opcao == "1"){
				
			} else if(opcao == "2"){

			}
		}
		catch(Excecao& e){
			painel.setExcecao(e);
		}
	}
}




#endif // __PAINEIS_H__