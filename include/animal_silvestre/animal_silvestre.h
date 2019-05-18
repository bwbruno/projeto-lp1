#ifndef __ANIMAL_SILVESTRE_H__
#define __ANIMAL_SILVESTRE_H__

#include <string>

/// Classe AnimalSilvestre
/**
 * AnimalSilvestre é a classe onde se registra as permissões para manutenção e o
 * uso das diferentes espécies.
 */
class AnimalSilvestre {
	protected:
		std::string autorizacao_ibama; ///< Autorização do IBAMA
		
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		/// Construtor parametrizado de AnimalSilvestre.
		AnimalSilvestre(std::string auth);

		/// Construtor de AnimalSilvestre sem parâmetros.
		AnimalSilvestre();
		
		/// Destrutor de AnimalSilvestre.
		~AnimalSilvestre();
	

		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Retorna a autorização do IBAMA.
		std::string getAutorizacao_Ibama();

		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
			
		//! @brief Seta a autorização do IBAMA.
		void setAutorizacao_Ibama(std::string auth);

		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_SILVESTRE_H__