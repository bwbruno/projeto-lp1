#ifndef __ANFIBIO_H__
#define __ANFIBIO_H__

#include "animal/animal.h"

/// Animal que possui também registro da última data de troca de pele e do total de mudas que sofreu.
class Anfibio : public Animal {
	protected:
		int total_de_mudas; ///< Indica o total de vezes que a pele do anfíbio foi trocada.
		//Data ultima_muda; ///< Indica a data da última muda.

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		Anfibio();
		Anfibio(std::string linhaCSV, std::string linhaDetalhesCSV);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
		
		int getTotalDeMudas();
		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
 
		void setTotalDeMudas(int tdm);
		
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
		
		friend std::istream& operator>> (std::istream &i, Anfibio &a);
		friend std::ostream& operator<< (std::ostream &o, Anfibio const a);

		//---------------------------------------------------------------------- ///@}
};

#endif // __ANFIBIO_H__