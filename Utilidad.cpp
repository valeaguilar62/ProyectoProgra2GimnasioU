#include "Utilidad.h"


int convertirInt(string cadena) {
    stringstream r(cadena);
    int v;
    r >> v;
    return v;
}
double convertirDouble(string cadena) {
    stringstream r(cadena);
    double v;
    r >> v;
    return v;
}

char convertirChar(string cadena) {
    stringstream r(cadena);
    char v;
    r >> v;
    return v;
}