// RegistroPersonas.h
#pragma once
#include "persona.h"
#include <vector>
#include <memory>
#include <functional>

class RegistroPersonas {
private:
    std::vector<std::unique_ptr<Persona>> personas;
    std::vector<std::function<void(const Persona&)>> observadores;
public:
    void agregarObservador(std::function<void(const Persona&)> obs) {
        observadores.push_back(obs);
    }
    void agregarPersona(std::unique_ptr<Persona> p) {
        const Persona &ref = *p;
        personas.push_back(std::move(p));
        for (auto &obs : observadores) obs(ref); // notifica a TODOS los observadores
    }
    size_t cantidad() const { return personas.size(); }
};
