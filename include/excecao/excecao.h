#ifndef __EXCECAO_H__
#define __EXCECAO_H__

#include <exception>
#include <iostream>
#include <string>

/// Classe exceção
/**
 * ![Diagrama de classe Excecao](excecao.png)
 */
class Excecao : public std::exception {
	private:
		std::string mensagem;

    public:
        //---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
		
		Excecao();
		Excecao(const std::string m);
        Excecao(const Excecao &e);
		~Excecao() throw ();
    

        //---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
        
		//! @brief Retorna a mensagem de erro
		const std::string getMensagem() const;


        //---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
       
		//! @brief Seta a mensagem de erro
	    void setMensagem(std::string m);


        //---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		//! @brief Sobrecarga do operador igual
        Excecao& operator= (Excecao const &e);


        //---------------------------------------------------------------------- ///@}
		/// @name Métodos utilitários
		//---------------------------------------------------------------------- ///@{
        
		//! @brief Imprime a mensagem de erro
		void printMensagem();
		
		//! @brief Limpa a mensagem de erro
		//! @note Útil na hora de remover a mensagem de erro do painel	
        void limparMensagem();
};

#endif // __EXCECAO_H__