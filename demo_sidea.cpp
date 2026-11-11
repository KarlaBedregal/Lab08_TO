#include "CentralDespacho.h"
#include "Incidente.h"
#include "Estadisticas.h"
#include <iostream>

const char* nombreEstado(EstadoIncidente estado) {
    switch (estado) {
        case EstadoIncidente::PENDIENTE: return "PENDIENTE";
        case EstadoIncidente::ASIGNADO: return "ASIGNADO";
        case EstadoIncidente::EN_ATENCION: return "EN_ATENCION";
        case EstadoIncidente::ATENDIDO: return "ATENDIDO";
    }
    return "DESCONOCIDO";
}

int main() {
    auto& central = CentralDespacho::getInstance();
    auto& mismaCentral = CentralDespacho::getInstance();
    std::cout << "Misma central: "
              << (&central == &mismaCentral ? "SI" : "NO") << '\n';

    Estadisticas estadisticas;
    int notificacionesLog = 0;
    Incidente incidente(101);
    estadisticas.registrarIncidente();

    incidente.agregarObservador([&estadisticas](const EventoIncidente& evento) {
        estadisticas.actualizar(evento);
    });
    incidente.agregarObservador([&notificacionesLog](const EventoIncidente& evento) {
        ++notificacionesLog;
        std::cout << "[LOG] Incidente " << evento.idIncidente << ": "
                  << nombreEstado(evento.estadoAnterior) << " -> "
                  << nombreEstado(evento.estadoActual) << '\n';
    });

    central.despacharUnidad("Ambulancia A-01", incidente.getId());
    incidente.cambiarEstado(EstadoIncidente::ASIGNADO);
    incidente.cambiarEstado(EstadoIncidente::EN_ATENCION);
    incidente.cambiarEstado(EstadoIncidente::ATENDIDO);
    incidente.cambiarEstado(EstadoIncidente::ATENDIDO); // No duplica el evento.

    bool retrocesoRechazado = false;
    try {
        incidente.cambiarEstado(EstadoIncidente::PENDIENTE);
    } catch (const std::invalid_argument&) {
        retrocesoRechazado = true;
    }

    std::cout << "Pendientes: " << estadisticas.getPendientes() << '\n'
              << "Atendidos: " << estadisticas.getAtendidos() << '\n'
              << "Notificaciones de log: " << notificacionesLog << '\n'
              << "Retroceso rechazado: " << (retrocesoRechazado ? "SI" : "NO") << '\n';

    return (&central == &mismaCentral && estadisticas.getPendientes() == 0 &&
            estadisticas.getAtendidos() == 1 && notificacionesLog == 3 &&
            retrocesoRechazado) ? 0 : 1;
}
