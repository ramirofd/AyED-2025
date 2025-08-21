#ifndef SENSOR_H
#define SENSOR_H

#include <string>

// Declarar un struct Sensor que tenga un nombre (string), valor (flotante) y unidad (string
    struct Sensor{
        std::string nombre;
        float valor;
        std::string unidad; 
    };

// Prototipos
void imprimir(const Sensor* lista, int n);


int cargarDesdeArchivo(const std::string& ruta, Sensor* lista, int n);


#endif
