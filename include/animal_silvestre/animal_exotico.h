#ifndef __ANIMAL_EXOTICO_H__
#define __ANIMAL_EXOTICO_H__

#include <string>

#include "animal_silvestre/animal_silvestre.h"

/// Classe onde se registra o país de origem de animais exóticos, além da autorização do IBAMA.
class AnimalExotico : public AnimalSilvestre {
	protected:
		std::string pais_origem; ///< País de origem

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		AnimalExotico();
		AnimalExotico(std::string PO, std::string auth);
		//~AnimalExotico();
		

		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
 
		std::string getPaisOrigem();
		

		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
 
 		void setPaisOrigem(std::string PO);

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos utilitários
		//---------------------------------------------------------------------- ///@{

		std::string tipo();
		
		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_EXOTICO_H__