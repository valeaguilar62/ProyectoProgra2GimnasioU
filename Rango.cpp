#include"Rango.h"

int Rango::obtenerRango(int val,int min, int max) {
    
   if (min <= val && val <= max)
       return val;
   else
       throw new ExcepcionRango();
}