#ifndef __ANIMAL_NATIVO_H__
#define __ANIMAL_NATIVO_H__

#include <string>

#include "animal_silvestre/animal_silvestre.h"

/// Classe AnimalNativo
/**
 * AnimalNativo é a classe onde se registra as permissões para manutenção e o
 * uso dos animais nativos da fauna brasileira, além do estado brasileiro de
 * origem desses animais.
 */
class AnimalNativo : public AnimalSilvestre {
	protected:
		std::string uf_origem; ///< Estado de origem
		std::string autorizacao; ///< Autorização do IBAMA
		
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		/// Construtor de AnimalNativo sem parâmetros.
		AnimalNativo();

		/// Construtor de AnimalNativo com parâmetros.
		AnimalNativo(std::string UO, std::string auth);
		
		/// Destrutor de AnimalNativo.
		~AnimalNativo();
		

		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Retorna a UF de origem.
		std::string getUf_Origem();
		
		//! @brief Retorna a Autorização.
		std::string getAutorizacao();
		

		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{

		//! @brief Seta a UF de origem. 
		//! @param UO 
		void setUf_Origem(std::string UO);

		//! @brief Seta a Autorização.
		//! @param auth 
		void setAutorizacao(std::string auth);

		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_NATIVO_H__