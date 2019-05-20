#ifndef __MAMIFERO_EXOTICO_H__
#define __MAMIFERO_EXOTICO_H__

#include "animal/mamifero/mamifero.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe MamiferoExotico
class MamiferoExotico : public Mamifero, AnimalExotico {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		MamiferoExotico();
		MamiferoExotico(int id);
		MamiferoExotico(std::string linhaCSV);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getTipo();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, MamiferoExotico &m);
		friend std::ostream& operator<< (std::ostream &o, MamiferoExotico const m);

		//---------------------------------------------------------------------- ///@}
};

#endif // __MAMIFERO_EXOTICO_H__