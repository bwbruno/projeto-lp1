#ifndef __MAMIFERO_H__
#define __MAMIFERO_H__

#include <string>

#include "animal/animal.h"

/// Animal que também possui registro da cor do pelo.
class Mamifero : public Animal {
	protected:
		std::string cor_pelo; ///< Cor do pelo

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		Mamifero();
		Mamifero(std::string linhaCSV, std::string linhaDetalhesCSV);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
		
		std::string getCorPelo();
		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
 
		void setCorPelo(std::string cp);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getTipo();
		std::string getStringCSV();
		std::string getStringDetalhesCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, Mamifero &m);
		friend std::ostream& operator<< (std::ostream &o, Mamifero const m);

		//---------------------------------------------------------------------- ///@}
};

#endif // __MAMIFERO_H__