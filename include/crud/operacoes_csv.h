#ifndef __OPERACOES_CSV_H__
#define __OPERACOES_CSV_H__

#include <map>
#include <fstream>
#include <iterator>

/// Essa classe representa o funcionario que possui um 'nivel de segurança' para tratar os animais.
/**
 * Nível de segurança representa o grau de experiência do tratador na manipulação de certos animais.
 */
template<class CLASSE>
class OperacoesCSV {
	private:
		std::map<int, std::string> linhas; ///< Lista de tratadores
		std::map<int, CLASSE> lista; ///< Lista de tratadores
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
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
        
        //! @brief 
        std::map<int, CLASSE> getLista();

        //---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{

        void setLista(std::map<int, CLASSE> l);
        
		//---------------------------------------------------------------------- ///@}
		/// @name Operações
		//---------------------------------------------------------------------- ///@{
		
        void inserirLinha(std::string linha);
        
        void removerLinha(int id);

        //! @brief Retorna true se a linha com o id informado existe
        bool existeLinha(int id);
		
        //! @brief Retorna o tipo do funcionario de acordo com a linha do arquivo CSV
		//! @param linha endereço do arquivo CSV
        std::string getTipoDaLinha(std::string linha);

        std::string getIDDaLinha(std::string linha);

        std::string getColuna(std::string linha, int coluna);

        int tamanhoMapLinhas();

        std::map<std::string, std::string> getOpcoes();

        //! @brief 
        void print();

        CLASSE consultar(int id);
        std::string consultarLinha(int id);

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

        std::string tipoLinha = getTipoDaLinha(linha);

        CLASSE tmp;
        if(tipoLinha == tmp.getTipo()){
            CLASSE c(linha);
            std::pair<int, CLASSE> par;
            par.first = c.getId();
            par.second = c;

            lista.insert(par);
        }
    }

    arquivo.close();

    arquivo.open(enderecoArquivo.c_str());

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
//		Getters
// ------------------------------------------------------------------------

template <class CLASSE>
std::map<int, CLASSE> OperacoesCSV<CLASSE>::getLista(){
   return lista;
}


// ------------------------------------------------------------------------
//		Setters
// ------------------------------------------------------------------------

template <class CLASSE>
void OperacoesCSV<CLASSE>::setLista(std::map<int, CLASSE> l){

    std::ofstream of;
	of.open(enderecoArquivo.c_str());
	
    if(of.is_open()){
        typename std::map<int, CLASSE>::iterator it;
        for (it = l.begin(); it != l.end(); ++it)
            of << it->second.getStringFormatoCSV();

	} else {
		throw Excecao("Erro ao abrir arquivo para escrita.");
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
        if(!ss.eof())
            getline(ss, scoluna, ';');
        else
            throw Excecao("Erro ao ler coluna " + intParaString(i) + " no arquivo " + enderecoArquivo);
    }

    return scoluna;
}

template <class CLASSE>
std::string OperacoesCSV<CLASSE>::getTipoDaLinha(std::string linha){
    std::string tipo;
    std::istringstream ss(linha);
    getline(ss, tipo, ';');
    getline(ss, tipo, ';');
    return tipo;
}

template <class CLASSE>
std::string OperacoesCSV<CLASSE>::getIDDaLinha(std::string linha){
    std::string tipo;
    std::istringstream ss(linha);
    getline(ss, tipo, ';');
    return tipo;
}

template <class CLASSE>
void OperacoesCSV<CLASSE>::print(){

    typename std::map<int, CLASSE>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        std::cout << "\t" << it->second.getId();
        std::cout << ". " << it->second.getNome() << std::endl;
    }
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
        for(it = linhas.begin(); it != linhas.end(); ++it)
            of << it->second;

    } else {
        throw Excecao("Erro ao abrir arquivo para escrita.");
    }

}

template <class CLASSE>
bool OperacoesCSV<CLASSE>::existeLinha(int id){

    typename std::map<int, std::string>::iterator it;
    it = linhas.find(id);

    if(it == linhas.end())
        return false;
    else
        return true;
    
}

template <class CLASSE>
int OperacoesCSV<CLASSE>::tamanhoMapLinhas(){
    
    return linhas.size();
}

template <class CLASSE>
CLASSE OperacoesCSV<CLASSE>::consultar(int id){
    
    typename std::map<int, CLASSE>::iterator it;
    it = lista.find(id);

    if(it == lista.end())
        throw Excecao("O id informado é inválido. Tente novamente."); 

    return it->second;
}

template <class CLASSE>
std::string OperacoesCSV<CLASSE>::consultarLinha(int id){
    
    if(!existeLinha(id))
        throw Excecao("O id informado é inválido. Tente novamente.");

    typename std::map<int, CLASSE>::iterator it;
    it = linhas.find(id);

    return it->second;
}

template <class CLASSE>
std::map<std::string, std::string> OperacoesCSV<CLASSE>::getOpcoes(){

    CLASSE classe;
    std::string tipoClasse = classe.getTipo();
    std::string linha;
    std::string tipoLinha;
    std::map<std::string, std::string> opcoes;
    std::pair<std::string, std::string> par;
/*
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
    
*/
    

    par.first = "0";
    par.second = "VOLTAR";
    opcoes.insert(par);

    typename std::map<int, CLASSE>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it){
        int id = it->second.getId();
        par.first = intParaString(id);
        par.second = it->second.getNome();
        opcoes.insert(par);
    }

    return opcoes;
}

#endif // __OPERACOES_CSV_H__