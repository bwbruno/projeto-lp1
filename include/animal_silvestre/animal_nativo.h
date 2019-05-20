#ifndef __ANIMAL_NATIVO_H__
#define __ANIMAL_NATIVO_H__

#include <string>

#include "animal_silvestre/animal_silvestre.h"

///  Classe onde se registra o uf de origem de animais nativos, além da autorização do IBAMA.
class AnimalNativo : public AnimalSilvestre {
	protected:
		std::string uf_origem; ///< Estado de origem
		
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		AnimalNativo();
		AnimalNativo(std::string UO, std::string auth);
		//~AnimalNativo();
		

		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
 
		std::string getUfOrigem();		
		

		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{

		void setUfOrigem(std::string UO);

		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_NATIVO_H__