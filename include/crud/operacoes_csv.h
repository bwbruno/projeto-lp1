#ifndef __OPERACOES_CSV_H__
#define __OPERACOES_CSV_H__

#include <map>
#include <fstream>
#include <iterator>

/// Classe que manipula arquivos CSV
template<class CLASSE>
class OperacoesCSV {
	private:
		std::map<int, std::string> linhas; ///< Lista de tratadores
        std::string enderecoArquivo; ///< Endereço do arquivo

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
		
		//! @brief Construtor padrão não inicializa nenhum dos atributos
		OperacoesCSV();

		//! @brief Esse construtor instancia a lista de funcionarios a partir do arquivo CSV informado
		//! @param linha endereço do arquivo CSV
		OperacoesCSV(std::string enderecoArquivo);
   
		//---------------------------------------------------------------------- ///@}
		/// @name Operações
		//---------------------------------------------------------------------- ///@{
		
        //! @brief Insere a linha no arquivo CSV
        void inserirLinha(std::string linha);
        
        //! @brief Remove a linha de acordo com o id informado
        void removerLinha(int id);

        //! @brief Retorna a linha de acordo com o id informado
        std::string consultarLinha(int id);

        //! @brief Retorna true se a linha com o id informado existe
        bool existeLinha(int id);
        
        //! @brief Retorna o conteúdo da coluna x na linha
        std::string getColuna(std::string linha, int coluna);

        //! @brief Retorna a lista de opções de acordo com a classe passada no template<>
        std::map<std::string, std::string> gerarOpcoes();

        //! @brief Gera um id válido para não haver repetição
        int gerarId();
        
		//---------------------------------------------------------------------- ///@{
};

// ------------------------------------------------------------------------
//		Construtores e destrutor
// ------------------------------------------------------------------------

template <class CLASSE>
OperacoesCSV<CLASSE>::OperacoesCSV(std::string ea){

    enderecoArquivo = ea;
    std::ifstream arquivo;
    arquivo.open(enderecoArquivo.c_str());

    std::string linha;

    while (!arquivo.eof()){
        getline(arquivo, linha);
        
        std::string coluna = getColuna(linha, 1);
        int id = atoi(coluna.c_str());

        std::pair<int, std::string> par;
        par.first = id;
        par.second = linha;

        linhas.insert(par);
    }
}


// ------------------------------------------------------------------------
//		Operações
// ------------------------------------------------------------------------

template <class CLASSE>
std::string OperacoesCSV<CLASSE>::getColuna(std::string linha, int coluna){

    std::istringstream ss(linha);
    std::string scoluna;

    for(int i = 0; i < coluna; i++){
        //if(ss.eof())
            getline(ss, scoluna, ';');
        //else
            //throw Excecao("Erro ao ler coluna " + intParaString(i) + " no arquivo " + enderecoArquivo);
    }

    return scoluna;
}

template <class CLASSE>
void OperacoesCSV<CLASSE>::inserirLinha(std::string linha){

    std::ofstream of;
	of.open(enderecoArquivo.c_str(), std::ios::app);

	if(of.is_open()){
		of << linha;
	} else {
		throw Excecao("Erro ao abrir arquivo para escrita.");
	}
}

template <class CLASSE>
void OperacoesCSV<CLASSE>::removerLinha(int id){
    // Verifica se a linha com o id informado existe
    if(!existeLinha(id))
        throw Excecao("O id informado é inválido. Tente novamente.");
    
    // Se sim, apaga a linha
    linhas.erase(id);
    
    // Reescreve o arquivo sem a linha
    std::ofstream of;
    of.open(enderecoArquivo.c_str());

    if(of.is_open()){
        typename std::map<int, std::string>::iterator it;    
        for(it = linhas.begin(); it != linhas.end(); ++it){
            of << it->second;
            of << "\n";
        }

    } else {
        throw Excecao("Erro ao abrir arquivo para escrita.");
    }

}

template <class CLASSE>
bool OperacoesCSV<CLASSE>::existeLinha(int id){

    typename std::map<int, std::string>::iterator it;
    it = linhas.find(id);

    if(it == linhas.end())
        throw Excecao("O id informado é inválido. Tente novamente.");
    else
        return true;
    
}

template <class CLASSE>
std::string OperacoesCSV<CLASSE>::consultarLinha(int id){
    
    if(existeLinha(id)){
        typename std::map<int, std::string>::iterator it;
        it = linhas.find(id);
        return it->second;
    }
}

template <class CLASSE>
std::map<std::string, std::string> OperacoesCSV<CLASSE>::gerarOpcoes(){

    CLASSE classe;
    std::string tipoClasse = classe.getTipo();
    std::string linha;
    std::string tipoLinha;
    std::map<std::string, std::string> opcoes;
    std::pair<std::string, std::string> par;

    par.first = "0";
    par.second = "VOLTAR";
    opcoes.insert(par);

    typename std::map<int, std::string>::iterator it;    
    for(it = linhas.begin(); it != linhas.end(); ++it){
        
        int id = it->first;
        linha = it->second;
        tipoLinha = getColuna(it->second, 2);
        
        if(tipoClasse == tipoLinha){
            par.first = intParaString(id);
            par.second = it->second;
            opcoes.insert(par);
        }
    }
    
    return opcoes;
}

template <class CLASSE>
int OperacoesCSV<CLASSE>::gerarId(){
    typename std::map<int, std::string>::iterator it;
    it = linhas.end();
    it--;
    return it->first + 1;
}

#endif // __OPERACOES_CSV_H__