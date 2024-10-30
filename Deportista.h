#pragma once
#include "Fecha.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Deportista :public exception {
protected:
    string cedula;
    string nombre;
    string telefono;
    Fecha* fechaNacimiento;
public:
    Deportista(string = "", string = "", string = "", Fecha* = NULL);
    virtual ~Deportista();
    virtual string getCedula() = 0;
    virtual string getNombre() = 0;
    virtual string getTelefono() = 0;
    virtual Fecha* getFechaNacimiento() = 0;
    virtual Fecha* getFechaRegistro() = 0;
    virtual string getEstado() = 0;
    virtual  void setCedula(string) = 0;
    virtual void setNombre(string) = 0;
    virtual void setTelefono(string) = 0;
    virtual void setFechaNacimiento(Fecha*) = 0;
    virtual void setFechaRegistro(Fecha*) = 0;
    virtual void setEstado(string) = 0;
    virtual void guardar(ostream&) = 0;
    virtual int getHorasEntrenamiento() = 0;
    virtual double getTemPromedio() = 0;
    virtual char getSexo() = 0;
    virtual double getEstatura() = 0;
    virtual double getMasaMuscular() = 0;
    virtual double getPeso() = 0;
    virtual double getPorcGrasaCorporal() = 0;
    virtual int getCantParticIronMan() = 0;
    virtual int getCantTriatGanados() = 0;
    virtual void setHorasEntrenamiento(int) = 0;
    virtual void setTemPromedio(double) = 0;
    virtual void setSexo(char) = 0;
    virtual void setEstatura(double) = 0;
    virtual void setMasaMuscular(double) = 0;
    virtual void setPeso(double) = 0;
    virtual void setPorcGrasa(double) = 0;
    virtual void setCantIronMan(int) = 0;
    virtual void setCantTriat(int) = 0;
    virtual string toString() = 0;
};