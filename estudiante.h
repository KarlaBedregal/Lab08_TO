// estudiante.h
#pragma once
#include "persona.h"

class Estudiante : public Persona
{
private:
    std::string carrera;

public:
    Estudiante(std::string nombre, std::string codigo, std::string carrera)
        : Persona(nombre, codigo), carrera(carrera) {}

    std::string getCarrera() const { return carrera; }

    void presentarse() const override
    {
        std::cout << "Soy el/la estudiante " << nombre
                  << " (" << codigo << "), de " << carrera << std::endl;
    }

    Estudiante *clonar() const override
    {
        return new Estudiante(*this);
    }
};
