#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
int cache[2][64];

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache()
{
	totaltime = 0.0;
	/* Escriu aqui el teu codi */
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 64; ++j)
		{
			cache[i][j] = -1;
		}
	}
}

/* La rutina reference es cridada per cada referencia a simular */
void reference(unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m;
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;		  // boolea que ens indica si es miss
	unsigned int replacement; // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	  // TAG de la linia reempla�ada
	float t1, t2;			  // Variables per mesurar el temps (NO modificar)

	t1 = GetTime();
	/* Escriu aqui el teu codi */

	//reseteamos variables booleanas
	miss = 0;
	replacement = 0;
	tag_out = 0;

	//calculo de las variables a partir de address

	//si en la supuesta posicion del tag no esta el tag que buscamos, es un miss
	if (cache[via_mc][conj_mc] != tag)
	{
		miss = 1;
		//si la supuesta posicion no estaba vacia, hay que reemplazar
		if (cache[via_mc][conj_mc] != -1)
		{
			replacement = 1;
			tag_out = cache[via_mc][conj_mc];
		}
		//insertamos el nuevo tag en la posicion
		cache[via_mc][conj_mc] = tag;
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2 = GetTime();
	totaltime += t2 - t1;
	test_and_print2(address, byte, bloque_m, conj_mc, via_mc, tag,
					miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void final()
{
	/* Escriu aqui el teu codi */
}
