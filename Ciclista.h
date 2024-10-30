#pragma once
#include "Deportista.h"

class Ciclista{
private:
    int horasEntrenamiento;
    double temPromedio;
public:
    Ciclista(int = 0, double = 0.0);
    virtual ~Ciclista();
    void guardar(ostream&);
    static Ciclista* recuperar(istream&);
    int getHorasEntrenamiento();
    double getTemPromedio();
    /*char getSexo();
    double getEstatura();
    double getMasaMuscular();
    double getPeso();
    double getPorcGrasaCorporal();
    int getCantParticIronMan();
    int getCantTriatGanados();*/
    void setHorasEntrenamiento(int);
    void setTemPromedio(double);
   /* void setSexo(char);
    void setEstatura(double);
    void setMasaMuscular(double);
    void setPeso(double);
    void setPorcGrasa(double);
    void setCantIronMan(int);
    void setCantTriat(int);*/
    friend ostream& operator <<(ostream&, const Ciclista&);

};