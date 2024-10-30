#include "InterfazTriatlonista.h"


string InterfazTriatlonista::leerCedula()
{
    string dato;
    cout << "Ingrese la cedula: ";
    cin >> dato;
    return dato;
}

string InterfazTriatlonista::leerNombre()
{
    string dato;
    cout << "Ingrese el nombre: ";
    cin >> dato;
    return dato;
}

string InterfazTriatlonista::leerTelefono()
{
    string dato;
    cout << "Ingrese el telefono: ";
    cin >> dato;
    return dato;
}

int InterfazTriatlonista::leerHorasEntre()
{
    int dato;
    cout << "Ingrese las horas de entrenamiento: ";
    cin >> dato;
    return dato;
}

double InterfazTriatlonista::leerTemPromedio()
{
    double dato;
    cout << "Ingrese la temeperatura promedio: ";
    cin >> dato;
    return dato;
}

char InterfazTriatlonista::leerSexo()
{
    char dato;
    cout << "Ingrese el sexo (F/M): ";
    cin >> dato;
    return dato;
}

double InterfazTriatlonista::leerEstatura()
{
    double dato;
    cout << "Ingrese la estatura: ";
    cin >> dato;
    return dato;
}

double InterfazTriatlonista::leerMasaMuscular()
{
    double dato;
    cout << "Ingrese el porcentaje de masa muscular: ";
    cin >> dato;
    return dato;
}

double InterfazTriatlonista::leerPeso()
{
    double dato;
    cout << "Ingrese el peso: ";
    cin >> dato;
    return dato;
}

double InterfazTriatlonista::leerGrasa()
{
    double dato;
    cout << "Ingrese el porcentaje de grasa corporal: ";
    cin >> dato;
    return dato;
}

int InterfazTriatlonista::leerCantIron()
{
    int dato;
    cout << "Ingrese la cantidad de participaciones en Iron Man: ";
    cin >> dato;
    return dato;
}

int InterfazTriatlonista::leerCantTriat()
{
    int dato;
    cout << "Ingrese la cantidad triatlones ganados: ";
    cin >> dato;
    return dato;
}

int InterfazTriatlonista::menuEditTriat()
{
    int opcion = 0;
    cout << "1-Cedula\n2-Nombre\n3-Fecha de nacimiento\n4-Telefono\n5-Horas de entrenamiento\n6-Temperatura promedio\n7-Sexo\n8-Estatura\n9-Masa Muscular\n10-peso\n11-Porcentaje de grasa corporal\n12-Participaciones en Iron Man\n13-Triatlones ganados\n";
    cout << "Ingrese la opcion que desea editar: ";
    cin >> opcion;
    return opcion;
}

int InterfazTriatlonista::menuEditInst()
{
    int opcion = 0;
    cout << "1-Cedula\n2-Nombre\n";
    cout << "Ingrese la opcion que desea editar: ";
    cin >> opcion;
    return opcion;
}

Fecha* InterfazTriatlonista::leerFecha()
{
    int dia = 0, mes = 0, anio = 0;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
    return new Fecha(dia, mes, anio);
}