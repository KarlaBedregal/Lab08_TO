// main.cpp
#include "persona.h"
#include "estudiante.h"
#include "docente.h"
#include "PersonaFactory.h"
#include "RegistroPersonas.h"
#include <iostream>

int main() {
    RegistroPersonas registro;
    // Observador 1: solo deja constancia (log) de que alguien se registro
    registro.agregarObservador([](const Persona &p) {
        std::cout << "[LOG] Nueva persona registrada: " << p.getNombre() << std::endl;
    });
    // Observador 2: le da la bienvenida
    registro.agregarObservador([](const Persona &p) {
        std::cout << "[NOTIFICACION] Bienvenido/a, " << p.getNombre() << std::endl;
    });
    // Factory Method decide que subclase crear; el codigo de abajo no usa
    // "new Estudiante" ni "new Docente" directamente.
    registro.agregarPersona(PersonaFactory::crearPersona(TipoPersona::ESTUDIANTE, "Ana Torres", "20261234", "Ing. de Sistemas"));
    registro.agregarPersona(PersonaFactory::crearPersona(TipoPersona::DOCENTE, "Mg. Roxana Limache", "D-0456", "Ing. de Sistemas"));
    std::cout << "--- Total de personas registradas: " << registro.cantidad() << " ---" << std::endl;
    return 0;
}
