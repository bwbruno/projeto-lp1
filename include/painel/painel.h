#ifndef __PAINEL_H__
#define __PAINEL_H__

#include "utilitarios.h"
#include "excecao/excecao.h"

/// Responsável por gerar um painel de controle a partir de um vector de strings
/**
 * ![Diagrama de classe Painel](painel.png)
 */
class Painel{
	private:
		std::string titulo; ///< Titulo do painel
		std::deque<std::string> caminho; ///< Deque com caminho de opções escolhidas até o painel atual
		std::map<std::string, std::string> opcoes; ///< Vector com opções que serão exibidas no painel
		std::string pergunta; ///< 
		std::string resposta; ///< Valor da opção selecionada
		bool abrir; ///< Opção de controle de abertura e término do painel
		Excecao excecao;

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{

		Painel();

		//! @brief Construtor de Painel com título e vector de opções.
		//! @param t Título do painel
		//! @param o Vector de opções
		Painel(std::string t, std::vector<std::string> o);

		Painel(std::string t, std::deque<std::string> c);
		
		//! @brief Construtor de Painel sem caminho.
		//! @param t Título do painel
		//! @param o Vector de opções
		//! @param c Deque de caminho
		Painel(std::string t, std::vector<std::string> o, std::deque<std::string> c);

		Painel(std::string t, std::map<std::string, std::string> c);
		Painel(std::map<std::string, std::string> c);
		Painel(std::string t, std::map<std::string, std::string> co, std::deque<std::string> c);
		
		// Destrutor de Painel
		//~Painel();

		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
		
		//! @brief Retorna o título do painel
		std::string getTitulo();

		//! @brief Retorna o deque das opções que foram escolhidas até chegar no painel atual
		std::deque<std::string> getCaminho();

		//! @brief Retorna o map com as opções do painel
		std::map<std::string, std::string> getOpcoes();

		//! @brief Retorna a perguta do painel
		std::string getPergunta();

		//! @brief Retorna a resposta do usuário
		std::string getResposta();

		//! @brief Retorna o estado controle de abertura e término do painel
		bool getAbrir();

		//! @brief Retorna o estado controle de abertura e término do painel
		Excecao getExcecao();

		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{

		//! @brief Seta o título do painel
		//! @param t titulo
		void setTitulo(std::string t);

		//! @brief 
		void setCaminho(std::deque<std::string> c);

		//! @brief Seta o map de opções do painel
		//! @param o map de opções do painel
		void setOpcoes(std::map<std::string, std::string> o);

		void setOpcoes(std::vector<std::string> o);

		void setPergunta(std::string p);

		//! @brief Se o valor informado for válido, ele é setado na resposta
		/*! Se o inteiro 'r' não estiver entre 0 (zero) e o tamanho do map 'opcoes'.
		 *  Um aviso de erro é setado na variável 'mensagem'. */
		//! @param r resposta
		void setResposta(std::string r);

		//! @brief Seta !!!
		//! @param a !!!
		void setAbrir(bool a);

		void setExcecao(Excecao &e);

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{

		friend std::istream& operator>> (std::istream &i, Painel &p);

		friend std::ostream& operator<< (std::ostream &o, Painel p);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{

		//! @brief Imprime o painel

		void printCaminho();

		void printOpcoes();

		//---------------------------------------------------------------------- ///@}
};

#endif // __PAINEL_H__