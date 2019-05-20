#ifndef __REPTIL_EXOTICO_H__
#define __REPTIL_EXOTICO_H__

#include "animal/reptil/reptil.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe ReptilExotico
class ReptilExotico : public Reptil, AnimalExotico {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		ReptilExotico();
		ReptilExotico(std::string linhaCSV);

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, ReptilExotico &r);
		friend std::ostream& operator<< (std::ostream &o, ReptilExotico const r);

		//---------------------------------------------------------------------- ///@}
};

#endif // __REPTIL_EXOTICO_H__