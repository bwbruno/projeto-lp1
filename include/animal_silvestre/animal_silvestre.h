#ifndef __ANIMAL_SILVESTRE_H__
#define __ANIMAL_SILVESTRE_H__

#include <string>

/// Classe onde se registra as permissões para manutenção e o uso das diferentes espécies.
class AnimalSilvestre {
	protected:
		std::string autorizacao_ibama; ///< Autorização do IBAMA
		
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		AnimalSilvestre(std::string auth);
		AnimalSilvestre();
		//~AnimalSilvestre();
	

		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
 
		std::string getAutorizacaoIbama();

		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
			
		void setAutorizacaoIbama(std::string auth);

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos utilitários
		//---------------------------------------------------------------------- ///@{

		virtual std::string tipo() = 0;
		
		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_SILVESTRE_H__