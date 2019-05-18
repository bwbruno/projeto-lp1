#ifndef __ANFIBIO_H__
#define __ANFIBIO_H__

#include "animal/animal.h"

/// Classe Anfibio
/**
 * O Anfibio é um Animal que além dos atributos comuns, possui o registro do total
 * de mudas que sofreu e também da última data em que a troca de pele ocorreu.
 */
class Anfibio : public Animal {
	public:
		/// Construtor de Anfibio sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		Anfibio();
		/// Destrutor de Anfibio.
		/**
		*  A more elaborate description of the destructor.
		*/
		~Anfibio();

	protected:
		int total_de_mudas; ///< Indica o total de vezes que a pele do anfíbio foi trocada.
		//Data ultima_muda; ///< Indica a data da última muda.
		
};

#endif // __ANFIBIO_H__