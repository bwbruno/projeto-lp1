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
		MamiferoExotico(std::string linhaCSV, std::string linhaDetalhesCSV);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getStringCSV();
		std::string getStringDetalhesCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, MamiferoExotico &m);
		friend std::ostream& operator<< (std::ostream &o, MamiferoExotico const m);

		//---------------------------------------------------------------------- ///@}
};

#endif // __MAMIFERO_EXOTICO_H__