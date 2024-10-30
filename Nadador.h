#pragma once
#include "Deportista.h"
class Nadador {
private:
    double masaMuscular;
    double peso;
    double porcGrasaCorporal;
public:
    Nadador(double = 0.0, double = 0.0, double = 0.0);
    virtual ~Nadador();
    virtual void guardar(ostream&);
    static Nadador* recuperar(istream&);
  /*  virtual int getHorasEntrenamiento();
    virtual double getTemPromedio();
    virtual char getSexo();
    virtual double getEstatura();*/
    virtual double getMasaMuscular();
    virtual double getPeso();
    virtual double getPorcGrasaCorporal();
   /* virtual int getCantParticIronMan();
    virtual int getCantTriatGanados();
    virtual void setHorasEntrenamiento(int);
    virtual void setTemPromedio(double);
    virtual void setSexo(char);
    virtual void setEstatura(double);*/
    virtual void setMasaMuscular(double);
    virtual void setPeso(double);
    virtual void setPorcGrasa(double);
   /* void setCantIronMan(int);
    void setCantTriat(int);*/
    friend ostream& operator <<(ostream&, const Nadador&);
};