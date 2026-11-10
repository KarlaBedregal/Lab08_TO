// PersonaFactory.h
#pragma once
#include "persona.h"
#include "estudiante.h"
#include "docente.h"
#include <memory>
#include <stdexcept>

enum class TipoPersona { ESTUDIANTE, DOCENTE };

class PersonaFactory
{
public:
    static std::unique_ptr<Persona> crearPersona(
        TipoPersona tipo, std::string nombre, std::string codigo,
        std::string extra)
    {
        switch (tipo)
        {
        case TipoPersona::ESTUDIANTE:
            return std::make_unique<Estudiante>(nombre, codigo, extra);
        case TipoPersona::DOCENTE:
            return std::make_unique<Docente>(nombre, codigo, extra);
        }
        throw std::invalid_argument("Tipo de Persona no reconocido");
    }
};
