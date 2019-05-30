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
 
		AnimalSilvestre();


		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
     	
		//! @brief Retorna a autorização do ibama
		std::string getAutorizacaoIbama();

		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
			
		//! @brief Seta a autorização do ibama
		void setAutorizacaoIbama(std::string auth);

		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_SILVESTRE_H__