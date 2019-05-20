#ifndef __AVE_EXOTICO_H__
#define __AVE_EXOTICO_H__

#include "animal/ave/ave.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe AveExotico
class AveExotico : public Ave, AnimalExotico {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{

		AveExotico();
		AveExotico(std::string linhaCSV);
		~AveExotico();

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getTipo();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, AveExotico &a);
		friend std::ostream& operator<< (std::ostream &o, AveExotico const a);

		//---------------------------------------------------------------------- ///@}
};

#endif // __AVE_EXOTICO_H__