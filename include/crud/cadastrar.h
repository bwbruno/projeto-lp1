#ifndef __CADASTRAR_H__
#define __CADASTRAR_H__

#include "excecao/excecao.h"
#include "painel/painel.h"
#include "utilitarios.h"
#include "crud/operacoes_csv.h"

template <typename C>
void cadastrar(std::string enderecoArquivo, std::deque<std::string> caminho){
	
	OperacoesCSV<C> csv(enderecoArquivo);
	Painel cadastro;
	C classe;

	caminho.push_back("CADASTRAR");
	
	cadastro.setTitulo("CADASTRAR");
	cadastro.setCaminho(caminho);

	while(classe.getContadorCin() != -1){

		try{
			std::cout << cadastro;
			
			// Escolhe o id
			int tamanhoLista = csv.getLista().size();
			classe.setId(tamanhoLista+1);

			std::cout << classe;
			std::cin >> classe;
			
			// Tratamento de erro, caso o usuário insira texto em vez de números
			if(std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(__INT_MAX__, '\n');
				throw Excecao("Valor inválido. Insira um valor númerico.");
			}
		}
		catch(Excecao& e){
			
			classe.setContadorCin(classe.getContadorCin()-1);
			cadastro.setExcecao(e);
		}
			
	}
	
	confirmarCadastro(enderecoArquivo, classe, cadastro);
}

template <typename C>
void confirmarCadastro(std::string enderecoArquivo, C classe, Painel &p){
	
	std::string continuar;
	std::string linha;

	std::cout << p;
	std::cout << classe;
	std::cout << "\nCONFIRMAR CADASTRO (s/n): ";
	std::cin >> continuar;

	OperacoesCSV<C> csv(enderecoArquivo);

	if(continuar == "s"){
		linha = classe.getStringFormatoCSV();
		csv.inserirLinha(linha);
		throw Excecao("Cadastrado com sucesso.");
	} else {
		throw Excecao("O cadastrato não foi efetuado. Tente novamente.");
	}

}

#endif // __CADASTRAR_H__