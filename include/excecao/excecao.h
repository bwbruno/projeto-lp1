#ifndef __EXCECAO_H__
#define __EXCECAO_H__

#include <exception>
#include <iostream>
#include <string>

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
        
		const std::string getMensagem() const;


        //---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
       
	    void setMensagem(std::string m);


        //---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
        Excecao& operator= (Excecao const &e);


        //---------------------------------------------------------------------- ///@}
		/// @name Métodos utilitários
		//---------------------------------------------------------------------- ///@{
		
        void limparMensagem();
        void printMensagem();
};

#endif // __EXCECAO_H__