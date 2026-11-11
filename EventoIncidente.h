#pragma once

enum class EstadoIncidente { PENDIENTE, ASIGNADO, EN_ATENCION, ATENDIDO };
enum class TipoIncidente { INCENDIO, ACCIDENTE, ROBO, URGENCIA_MEDICA };
enum class PrioridadIncidente { BAJA, MEDIA, ALTA, CRITICA };

struct EventoIncidente {
    int idIncidente;
    EstadoIncidente estadoAnterior;
    EstadoIncidente estadoActual;
};
