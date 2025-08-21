#include <iostream>
#include <fstream>
#include "sensor.h"

using namespace std;

int cargarDesdeArchivo(const std::string& ruta, Sensor* lista, int n){
    std::ifstream archivo(ruta);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo: " << ruta << std::endl;
        return 0;
    }

    int i = 0;
    while (i < n && archivo >> lista[i].nombre >> lista[i].valor >> lista[i].unidad) {
        i++;
    }

    return i;
}

void imprimir(const Sensor* lista, int n){
    for(int i=0; i < n; i++){
        //cout << "Sensor: " << lista[i].nombre 
          //   << ", Valor: " << lista[i].valor 
            // << ", Unidad: " << lista[i].unidad << endl;
            cout<< "Sensor: " << (lista + i)->nombre 
                << ", Valor: " << (lista + i)->valor 
                << ", Unidad: " << (lista + i)->unidad << endl; 
    }
}


int main() {
    
    Sensor sCocina;
    sCocina.nombre = "Cocina";
    sCocina.valor = 25.5;
    sCocina.unidad = "C";

    Sensor* sHabitacion = new Sensor;
    sHabitacion->nombre = "TempHabitacion";
    sHabitacion->valor = 22.0;
    sHabitacion->unidad = "C";


    int N;
    cout << "Cantidad de sensores: ";
    cin >> N;

    //TODO: Instanciar un array de Sensores de forma dinamica y de tamaño N
    Sensor* sensores = new Sensor[N];

    string archivoEntrada;
    cout << "Archivo de entrada: ";
    cin >> archivoEntrada;

    int leidos = cargarDesdeArchivo(archivoEntrada,sensores, N);
    cout << "Se leyeron " << leidos << " sensores.\n";

    imprimir(sensores, leidos);

    // TODO: Que habria que hacer aca??
    return 0;
}


