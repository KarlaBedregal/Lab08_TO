#pragma once
#include <iostream>
#include <string>

class CentralDespacho {
private:
    // Constructor privado (Singleton)
    CentralDespacho() {
        std::cout << "Iniciando la UNICA Central de Despacho del sistema...\n";
    }
    
    CentralDespacho(const CentralDespacho&) = delete;
    CentralDespacho& operator=(const CentralDespacho&) = delete;

public:
    static CentralDespacho& getInstance() {
        static CentralDespacho instancia;
        return instancia;
    }

    void despacharUnidad(std::string unidad, int idIncidente) {
        std::cout << "Despachando " << unidad << " al incidente " << idIncidente << std::endl;
    }
};
