// antes.cpp
#include "persona.h"
#include "estudiante.h"
#include "docente.h"
#include <iostream>

// ANTES: creacion dispersa, dificil de extender.
// Cada lugar del programa que necesita una Persona construye
// directamente la subclase concreta con 'new'.
int main()
{
    Persona *p1 = new Estudiante("Ana Torres", "20261234", "Ing. de Sistemas");
    Persona *p2 = new Docente("Mg. Roxana Limache", "D-0456", "Ing. de Sistemas");

    p1->presentarse();
    p2->presentarse();

    // Si manana aparece un tercer tipo de Persona (p.ej. Administrativo),
    // hay que salir a buscar TODOS los lugares del programa que hacen
    // 'new Estudiante' / 'new Docente' para agregarlo ahi tambien.

    delete p1;
    delete p2;
    return 0;
}
