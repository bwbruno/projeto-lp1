#ifndef __ANFIBIO_EXOTICO_H__
#define __ANFIBIO_EXOTICO_H__

#include "animal/anfibio/anfibio.h"
#include "animal_silvestre/animal_exotico.h"

/// Anfibio Exotico
class AnfibioExotico : public Anfibio, AnimalExotico {
	public:
		/// Construtor de AnfibioExotico sem parâmetros.
		AnfibioExotico();

		/// Destrutor de AnfibioExotico.
		~AnfibioExotico();
};

#endif // __ANFIBIO_EXOTICO_H__