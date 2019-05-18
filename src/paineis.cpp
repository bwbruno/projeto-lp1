#include "paineis.h"

using namespace std;

void painelPrincipal(){

	Painel gerenciar;
	deque<string> caminho;
	vector<string> opcoes;
	string opcao;

	caminho.push_back("GERENCIAR");

	opcoes.push_back("SAIR");
	opcoes.push_back("ANIMAIS");
	opcoes.push_back("FUNCIONÁRIOS");

	gerenciar.setTitulo("GERENCIAR");
	gerenciar.setOpcoes(opcoes);
	gerenciar.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(gerenciar.getAbrir()){

		try
		{
			cout << gerenciar;
			cin >> opcao;
			gerenciar.setResposta(opcao);

			if(opcao == "1"){
				painelAnimais(caminho);
			} else if(opcao == "2"){
				painelFuncionarios(caminho);
			}
		}
		catch(Excecao& e)
		{
			gerenciar.setExcecao(e);
		}
			
	}
}


void painelFuncionarios(deque<string> caminho){
	
	Painel funcionarios;
	vector<string> opcoes;
	string opcao;
	
	caminho.push_back("FUNCIONÁRIOS");

	opcoes.push_back("VOLTAR");
	opcoes.push_back("TRATADORES");
	opcoes.push_back("VETERINÁRIOS");

	funcionarios.setTitulo("GERENCIAR");
	funcionarios.setCaminho(caminho);
	funcionarios.setOpcoes(opcoes);
	funcionarios.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(funcionarios.getAbrir()){

		try{
			cout << funcionarios;
			cin >> opcao;
			funcionarios.setResposta(opcao);

			if(opcao == "1"){
				string titulo = "TRATADORES";
				painelFuncionarios<Tratador>(titulo, caminho);

			} else if(opcao == "2"){
				string titulo = "VETERINARIOS";
				painelFuncionarios<Veterinario>(titulo, caminho);
			}
		}
		catch(Excecao& e){
			funcionarios.setExcecao(e);
		}
			
	}

}


// Animais ---------------------------
void painelAnimais(deque<string> caminho){
	caminho.push_back("ANIMAIS");
	string titulo = "ANIMAIS";
	vector<string> opcoes;
	opcoes.push_back("VOLTAR");
	opcoes.push_back("CADASTRAR");
	opcoes.push_back("REMOVER");
	opcoes.push_back("ALTERAR");
	opcoes.push_back("CONSULTAR");
	string opcao;
	Painel animais(titulo, opcoes, caminho);
	animais.setPergunta("Selecione uma das opções: ");
	void selecionarClasse(deque<string> caminho, int operacao);
	while(animais.getAbrir()){

		


		try{
			cout << animais;
			cin >> opcao;
			animais.setResposta(opcao);
			if(opcao == "1"){
				selecionarClasse(caminho, stoi(opcao));
			} else if(opcao == "2"){
				selecionarClasse(caminho, stoi(opcao));
			} else if(opcao == "3"){
				selecionarClasse(caminho, stoi(opcao));
			} else if(opcao == "4"){
				selecionarClasse(caminho, stoi(opcao));
			}
		}
		catch(Excecao& e){
			animais.setExcecao(e);
		}
		

		/* animais.printPainel();
		string opcao = animais.getSelecao();

		if(opcao == "1"){
			animais.setMensagem("CADASTRAR");

		} else if(opcao == "2"){
			animais.setMensagem("REMOVER");

		} else if(opcao == "3"){
			animais.setMensagem("ALTERAR");

		} else if(opcao == "4"){
			painelAnimaisConsulta(caminho);
		} */
	}
}

void selecionarClasse(deque<string> caminho, int operacao){
	vector <string> opcoes;
	opcoes.push_back("Voltar");
	opcoes.push_back("Anfíbio");
	opcoes.push_back("Ave");
	opcoes.push_back("Mamífero");
	opcoes.push_back("Réptil");
	
	string titulo = "CLASSES";
	string selecao;
	Painel classes(titulo, caminho);
	caminho.push_back("CADASTRAR");
	classes.setCaminho(caminho);
	classes.setPergunta("Escolha a classe do animal: ");
	classes.setOpcoes(opcoes);
	void selecionarTipo(string id, deque<string> caminho, int operacao);
	while(classes.getAbrir()){
		
		try{
			cout << classes;
			cin >> selecao;
			classes.setResposta(selecao);
			
			if(selecao == "1"){
				selecionarTipo("Anfíbio", caminho, operacao);
				
			} else if(selecao == "2"){
				selecionarTipo("Ave", caminho, operacao);
				// Chamar crud para criar um animal ave
			} else if(selecao == "3"){
				selecionarTipo("Mamífero", caminho, operacao);
				// Chamar crud para criar um animal mamífero
			} else if(selecao == "4"){
				selecionarTipo("Réptil", caminho, operacao);
				// Chamar crud para criar um animal réptil
			}
		}
		catch(Excecao& e)
		{
			classes.setExcecao(e);
		}
		
	}
	
}

void selecionarTipo(string id, deque<string> caminho, int operacao){
	
	vector <string> op;
	string classe;
	op.push_back("Voltar");
	
	op.push_back(id+" exotico");
	op.push_back(id+" nativo");
	string titulo = "Tipo";
	string escolha;
	Painel mamifero(titulo, caminho);
	mamifero.setPergunta("Escolha o tipo do(a) "+id+": ");
	for(int i=1; i<id.length(); i++) id[i] = toupper(id[i]);
	caminho.push_back(id);
	mamifero.setCaminho(caminho);
	mamifero.setOpcoes(op);
	switch (operacao)
	{
	case 1: //cadastro
		cout << mamifero;
		cin >> escolha;
		// Chamar crud para criar um animal anfíbio
		break;
	case 2: //remover
		cout << mamifero;
		cin >> escolha;
		// Chamar crud para remover um animal anfíbio
		break;
	case 3: //alterar
		cout << mamifero;
		cin >> escolha;
		// Chamar crud para alterar um animal anfíbio
		break;
	case 4: //consultar
		cout << mamifero;
		cin >> escolha;
		// Chamar crud para consultar um animal anfíbio
		break;
	
	default:
		break;
	}
	
}
/* 
void painelAnimaisConsulta(deque<string> caminho){
	caminho.push_back("CONSULTAR");
	string titulo = "CONSULTAR ANIMAIS POR";
	string vetor_opcoes[] = {"VOLTAR", "NOME DE BATISMO", "ESPÉCIE", "CLASSE", "VETERINÁRIO RESPONSÁVEL", "TRATADOR RESPONSÁVEL"};
	vector<string> opcoes(vetor_opcoes, vetor_opcoes + sizeof(vetor_opcoes) / sizeof(string));
	Painel consultar(titulo, opcoes, caminho);
	
	while(consultar.getAbrir()){
		consultar.printPainel();
		string opcao = consultar.getSelecao();

		if(opcao == "1"){
			consultar.setMensagem("NOME DE BATISMO");

		} else if(opcao == "2"){
			consultar.setMensagem("ESPÉCIE");

		} else if(opcao == "3"){
			consultar.setMensagem("CLASSE");

		} else if(opcao == "4"){
			consultar.setMensagem("VETERINÁRIO RESPONSÁVEL");

		}  else if(opcao == "5"){
			consultar.setMensagem("TRATADOR RESPONSÁVEL");
		}
	}
}

 */