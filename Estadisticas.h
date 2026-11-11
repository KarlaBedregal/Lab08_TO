#pragma once
#include "EventoIncidente.h"

class Estadisticas {
public:
    // Llamar una vez por incidente, al registrarlo en estado PENDIENTE.
    void registrarIncidente() { ++pendientes; }

    void actualizar(const EventoIncidente& evento) {
        if (evento.estadoActual == EstadoIncidente::ATENDIDO &&
            evento.estadoAnterior != EstadoIncidente::ATENDIDO) {
            ++atendidos;
            if (pendientes > 0) --pendientes;
        }
    }

    int getPendientes() const { return pendientes; }
    int getAtendidos() const { return atendidos; }

private:
    // Pendientes significa incidentes aun no finalizados, incluidos los asignados.
    int pendientes = 0;
    int atendidos = 0;
};
