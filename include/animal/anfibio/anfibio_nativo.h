#ifndef __ANFIBIO_NATIVO_H__
#define __ANFIBIO_NATIVO_H__

#include "animal/anfibio/anfibio.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe AnfibioNativo
class AnfibioNativo : public Anfibio, AnimalNativo {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{

		AnfibioNativo();
		AnfibioNativo(std::string linhaCSV);
		~AnfibioNativo();

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getTipo();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, AnfibioNativo &a);
		friend std::ostream& operator<< (std::ostream &o, AnfibioNativo const a);

		//---------------------------------------------------------------------- ///@}
};

#endif // __ANFIBIO_NATIVO_H__