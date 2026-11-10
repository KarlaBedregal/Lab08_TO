// persona.h
#pragma once
#include <iostream>
#include <string>

class Persona
{
protected:
    std::string nombre;
    std::string codigo;

public:
    Persona(std::string nombre, std::string codigo)
        : nombre(nombre), codigo(codigo) {}
    virtual ~Persona() {}
    virtual void presentarse() const = 0;

    // Getters const: garantizan que no modifican el objeto
    std::string getNombre() const { return nombre; }
    std::string getCodigo() const { return codigo; }

    // Cada clase hija retornara un puntero a SU propio tipo (covarianza)
    virtual Persona *clonar() const = 0;

    // Operadores del Lab 06. Se definen aqui dentro (friend en linea) para que
    // persona.h sea autocontenido y no dependan de main.cpp.
    friend bool operator==(const Persona &a, const Persona &b)
    {
        return a.codigo == b.codigo;
    }
    friend bool operator!=(const Persona &a, const Persona &b)
    {
        return !(a == b);
    }
    friend bool operator<(const Persona &a, const Persona &b)
    {
        return a.codigo < b.codigo;
    }
    friend std::ostream &operator<<(std::ostream &os, const Persona &p)
    {
        os << p.nombre << " (" << p.codigo << ")";
        return os;
    }
};
