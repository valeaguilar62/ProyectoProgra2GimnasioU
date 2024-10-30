#pragma once
#include "Corredor.h"
#include "Nadador.h"   
#include "Ciclista.h"

class Triatlonista :public Corredor {
private:
    string estado;
    Fecha* fechaRegistro;
    int cantParticiEnIronMan;
    int cantTriatGanados;
    Nadador* ptrNadador;
    Ciclista* ptrCiclista;
public:
    Triatlonista(string = "", string = "", string = "", Fecha* = NULL, char = ' ', double = 0.0, int = 0, double = 0.0, double = 0.0, double = 0.0, double = 0.0, int = 0, int = 0, Fecha* = NULL);
    Triatlonista(Triatlonista&);
    virtual ~Triatlonista();
    virtual void guardar(ostream&);
    static Triatlonista* recuperar(istream&);
    string getCedula();
    string getNombre(); 
    string getTelefono();
    Fecha* getFechaNacimiento();
    int getHorasEntrenamiento();
    double getTemPromedio();
    double getMasaMuscular();
    double getPeso();
    double getPorcGrasaCorporal();
    int getCantParticIronMan();
    int getCantTriatGanados();
    Fecha* getFechaRegistro();
    string getEstado();
    void setCedula(string);
    void setNombre(string);
    void setTelefono(string);
    void setFechaNacimiento(Fecha*);
    char getSexo();
    double getEstatura();
    void setSexo(char sex);
    void setEstatura(double esta);
    void setHorasEntrenamiento(int);
    void setTemPromedio(double);
    void setMasaMuscular(double);
    void setPeso(double);
    void setPorcGrasa(double);
    void setCantIronMan(int);
    void setCantTriat(int);
    void setFechaRegistro(Fecha*);
    void setEstado(string);
    friend ostream& operator << (ostream&, const Triatlonista&);
    string toString();
    bool operator != (const Triatlonista&);
};