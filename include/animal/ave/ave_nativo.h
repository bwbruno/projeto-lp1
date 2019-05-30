#ifndef __AVE_NATIVO_H__
#define __AVE_NATIVO_H__

#include "animal/ave/ave.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe AveNativo
class AveNativo : public Ave, AnimalNativo {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{

		AveNativo();
		AveNativo(std::string linhaCSV, std::string linhaDetalhesCSV);
		//~AveNativo();

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getStringCSV();
		std::string getStringDetalhesCSV();
		std::vector<std::string> vectorAtributos();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, AveNativo &a);
		friend std::ostream& operator<< (std::ostream &o, AveNativo const a);

		//---------------------------------------------------------------------- ///@}
};

#endif // __AVE_NATIVO_H__