// docente.h
#pragma once
#include "persona.h"

class Docente : public Persona
{
private:
    std::string departamento;

public:
    Docente(std::string nombre, std::string codigo, std::string departamento)
        : Persona(nombre, codigo), departamento(departamento) {}

    std::string getDepartamento() const { return departamento; }

    void presentarse() const override
    {
        std::cout << "Soy el/la docente " << nombre
                  << " (" << codigo << "), del departamento de " << departamento << std::endl;
    }

    Docente *clonar() const override
    {
        return new Docente(*this);
    }
};
