#ifndef __ANFIBIO_NATIVO_H__
#define __ANFIBIO_NATIVO_H__

#include "animal/anfibio/anfibio.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe AnfibioNativo
class AnfibioNativo : public Anfibio, AnimalNativo {
	public:
		/// Construtor de AnfibioNativo sem parâmetros.
		AnfibioNativo();

		/// Destrutor de AnfibioNativo.
		~AnfibioNativo();
};

#endif // __ANFIBIO_NATIVO_H__