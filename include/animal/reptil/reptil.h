#ifndef __REPTIL_H__
#define __REPTIL_H__

#include <string>

#include "animal/animal.h"

/// Animal que também possui registro sobre a produção de veneno ou não.
class Reptil : public Animal {
	protected:
		bool venenoso; ///< Se é venenoso ou não
		std::string tipo_veneno; ///< Tipo do veneno
		
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		Reptil();
		Reptil(int id);
		Reptil(std::string linhaCSV);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
		
		bool getVenenoso();
		std::string getTipoVeneno();
		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
 
		void setVenenoso(bool v);
		void setTipoVeneno(std::string tv);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getTipo();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, Reptil &r);
		friend std::ostream& operator<< (std::ostream &o, Reptil const r);

		//---------------------------------------------------------------------- ///@}
};

#endif // __REPTIL_H__