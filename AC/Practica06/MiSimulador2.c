#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
//cache de 128 filas (4KB/32B)
struct linea_cache{
    int tag;
    int dirty_bit;
};

struct linea_cache cache[128];

int hit_count = 0;
int miss_count = 0;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache()
{
    /* Escriu aqui el teu codi */
    for (int i = 0; i < 128; ++i)
    {
        //no funciona con 0 en todo
        cache[i].tag = -1;
        cache[i].dirty_bit = 0;
    }
}

/* La rutina reference es cridada per cada referencia a simular */
void reference(unsigned int address, unsigned int LE)
{
    unsigned int byte;
    unsigned int bloque_m;
    unsigned int linea_mc;
    unsigned int tag;
    unsigned int miss;
    unsigned int lec_mp;
    unsigned int mida_lec_mp;
    unsigned int esc_mp;
    unsigned int mida_esc_mp;
    unsigned int replacement;
    unsigned int tag_out;

    /* Escriu aqui el teu codi */
    byte = address % 32;
    bloque_m = address / 32;
    linea_mc = bloque_m % 128;
    tag = address / 4096;

    tag_out = 0;

    //booleans
    replacement = 0;
    miss = 0;
    lec_mp = 0;
    esc_mp = 0;

    //intercambiando lectura con comprobacion de tag no funciona
    if (LE == lectura)
    {
        if (cache[linea_mc].tag != tag) //miss
        {
            miss = 1;
            miss_count++;
            //se lee todo el bloque
            lec_mp = 1;
            mida_lec_mp = 32;
            if (cache[linea_mc].tag != -1)
            {
                replacement = 1;
                if(cache[linea_mc].dirty_bit){
                    esc_mp = 1;
                    //se escribe toda la linea
                    mida_esc_mp = 32;
                    //la linea ya se ha guardado en mp
                    cache[linea_mc].dirty_bit = 0;
                }
                tag_out = cache[linea_mc].tag;
            }
            cache[linea_mc].tag = tag;
        }
        else hit_count++;
    }
    else //escritura
    {
        if (cache[linea_mc].tag != tag) //miss
        {
            miss = 1;
            miss_count++;
            //se lee todo el bloque
            lec_mp = 1;
            mida_lec_mp = 32;
            if (cache[linea_mc].tag != -1)
            {
                replacement = 1;
                if(cache[linea_mc].dirty_bit){
                    esc_mp = 1;
                    //se escribe toda la linea
                    mida_esc_mp = 32;
                    //la linea ya se ha guardado en mp
                    cache[linea_mc].dirty_bit = 0;
                }
                tag_out = cache[linea_mc].tag;
            }
            cache[linea_mc].tag = tag;
        }
        else hit_count++;

        cache[linea_mc].dirty_bit = 1;
    }

    /* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
    test_and_print(address, LE, byte, bloque_m, linea_mc, tag,
                   miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
                   replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void final()
{
    /* Escriu aqui el teu codi */
    printf("Numero de hits: %d, numero de misses: %d\n", hit_count, miss_count);
}
