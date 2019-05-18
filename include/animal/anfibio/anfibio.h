#ifndef __ANFIBIO_H__
#define __ANFIBIO_H__

#include "animal/animal.h"


/// Animal que possui também registro da última data de troca de pele e do total de mudas que sofreu.
class Anfibio : public Animal {
	protected:
		int total_de_mudas; ///< Indica o total de vezes que a pele do anfíbio foi trocada.
		//Data ultima_muda; ///< Indica a data da última muda.

	public:
		/// Construtor de Anfibio sem parâmetros.
		Anfibio();
		
		/// Destrutor de Anfibio.
		~Anfibio();
};

#endif // __ANFIBIO_H__