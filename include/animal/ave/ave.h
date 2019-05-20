#ifndef __AVE_H__
#define __AVE_H__

#include "animal/animal.h"

/// Animal que possui registro do tamanho do bico em cm e a envergadura das asas.
class Ave : public Animal {
	protected:
		double tamanho_do_bico_cm; ///< Tamanho do bico em CM
		double envergadura_das_asas_cm; ///< Envergadura das asas em CM
		
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		Ave();
		Ave(int id);
		Ave(std::string linhaCSV);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
		
		double getTamanhoDoBicoCM();
		double getEnvergaduraDasAsasCM();
		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
 
		void setTamanhoDoBicoCM(double tdb);
		void setEnvergaduraDasAsasCM(double eda);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		void limpar();
		std::string getTipo();
		std::string getStringFormatoCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		friend std::istream& operator>> (std::istream &i, Ave &a);
		friend std::ostream& operator<< (std::ostream &o, Ave const a);

		//---------------------------------------------------------------------- ///@}
};

#endif // __AVE_H__