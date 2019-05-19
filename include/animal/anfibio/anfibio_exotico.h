#ifndef __ANFIBIO_EXOTICO_H__
#define __ANFIBIO_EXOTICO_H__

#include "animal/anfibio/anfibio.h"
#include "animal_silvestre/animal_exotico.h"

/// Anfibio Exotico
class AnfibioExotico : public Anfibio, AnimalExotico {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{

		AnfibioExotico();
		AnfibioExotico(std::string linhaCSV);
		~AnfibioExotico();

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getTipo();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, AnfibioExotico &a);
		friend std::ostream& operator<< (std::ostream &o, AnfibioExotico const a);

		//---------------------------------------------------------------------- ///@}
};

#endif // __ANFIBIO_EXOTICO_H__