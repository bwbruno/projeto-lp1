#ifndef __REPTIL_NATIVO_H__
#define __REPTIL_NATIVO_H__

#include "animal/reptil/reptil.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe ReptilNativo
class ReptilNativo : public Reptil, AnimalNativo {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		ReptilNativo();
		ReptilNativo(std::string linhaCSV);

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, ReptilNativo &r);
		friend std::ostream& operator<< (std::ostream &o, ReptilNativo const r);

		//---------------------------------------------------------------------- ///@}
};

#endif // __REPTIL_NATIVO_H__