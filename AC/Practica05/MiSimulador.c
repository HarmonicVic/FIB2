#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
//creamos cache simulada de 128 filas (4Kb / 32b), donde se guardan los tags
int cache[128];
int byte_mask = 0x1F;
int mc_mask = 0xFE0;
int hit_c = 0;
int miss_c = 0;

	/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
	void init_cache()
{
	totaltime = 0.0;
	/* Escriu aqui el teu codi */
	//limpiamos todo el cache poniendolo a -1 (tambien serviria cualquier numero "imposible", como -2, -3, etc.)
	for (int i = 0; i < 128; i++)
		cache[i] = -1;
}

/* La rutina reference es cridada per cada referencia a simular */
void reference(unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m;
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;		  // boolea que ens indica si es miss
	unsigned int replacement; // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	  // TAG de la linia reempla�ada
	float t1, t2;			  // Variables per mesurar el temps (NO modificar)

	t1 = GetTime();
	/* Escriu aqui el teu codi */

	//reseteamos todos los valores booleanos
	miss = 0;
	replacement = 0;
	tag_out = 0;

	//calculamos el byte, el bloque_m, el bloque_mc y el tag a partir de address
	byte = address & 0b00000000000000000000000000011111;
	tag = address >> 12;
	bloque_m = address >> 7;
	linea_mc = address & 0b00000000000000000000111111100000;

	// byte = address%32;
	// bloque_m = address/32;
	// linea_mc = bloque_m%128;
	// tag = bloque_m/128;

	//si la linea del cache no corresponde al tag
	if (cache[linea_mc] != tag)
	{
		miss = 1;
		miss_c++;
		//si la linea tiene un valor, significa que no esta vacia, es decir tiene un tag, es decir hay un reemplazo con el miss
		if (cache[linea_mc] != -1)
		{
			replacement = 1;
			tag_out = cache[linea_mc];
		}
		cache[linea_mc] = tag;
	}
	else
		hit_c++;

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2 = GetTime();
	totaltime += t2 - t1;
	test_and_print(address, byte, bloque_m, linea_mc, tag,
				   miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void final()
{
	/* Escriu aqui el teu codi */
	printf("%d misses, %d hits", miss_c, hit_c);
}
