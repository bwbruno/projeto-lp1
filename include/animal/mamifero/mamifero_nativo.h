#ifndef __MAMIFERO_NATIVO_H__
#define __MAMIFERO_NATIVO_H__

#include "animal/mamifero/mamifero.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe MamiferoNativo
class MamiferoNativo : public Mamifero, AnimalNativo {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		MamiferoNativo();
		MamiferoNativo(int id);
		MamiferoNativo(std::string linhaCSV);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getTipo();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, MamiferoNativo &m);
		friend std::ostream& operator<< (std::ostream &o, MamiferoNativo const m);

		//---------------------------------------------------------------------- ///@}
};

#endif // __MAMIFERO_NATIVO_H__