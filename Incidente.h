#pragma once
#include "EventoIncidente.h"
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>

class Incidente {
public:
    using Observador = std::function<void(const EventoIncidente&)>;

    explicit Incidente(int id) : id(id) {}

    int getId() const { return id; }
    EstadoIncidente getEstado() const { return estado; }

    void agregarObservador(Observador observador) {
        if (!observador) {
            throw std::invalid_argument("El observador no puede estar vacio");
        }
        observadores.push_back(std::move(observador));
    }

    void cambiarEstado(EstadoIncidente nuevoEstado) {
        if (nuevoEstado == estado) return;
        if (static_cast<int>(nuevoEstado) != static_cast<int>(estado) + 1) {
            throw std::invalid_argument("Transicion de estado no permitida");
        }
        const EventoIncidente evento{id, estado, nuevoEstado};
        estado = nuevoEstado;
        // La copia permite registrar observadores durante una notificacion.
        // Estos recibiran los eventos siguientes, no el evento en curso.
        const auto receptores = observadores;
        for (const auto& observador : receptores) observador(evento);
    }

private:
    int id;
    EstadoIncidente estado = EstadoIncidente::PENDIENTE;
    std::vector<Observador> observadores;
};
