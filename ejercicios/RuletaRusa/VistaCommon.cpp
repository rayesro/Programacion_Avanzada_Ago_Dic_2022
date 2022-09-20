#include <iostream>
#include "VistaCommon.h"

int PreguntarEleccionDelMenu(int opcionMaxParam, int opcionMinParam)
{
    int opcion = 0;
    bool estaFueraDeRango;
    do {
        estaFueraDeRango = false;
        cout << "    Elige una opcion [" << opcionMinParam << "-" << opcionMaxParam << "]:";
        cin >> opcion;
        if (opcion < opcionMinParam || opcion > opcionMaxParam) {
            estaFueraDeRango = true;
            cout << " ** La opcion ingresada no es valida. ** \n";
        }
    } while (estaFueraDeRango);
    return opcion;
}

Fecha* PreguntarFecha()
{
    Fecha* fecha = new Fecha;
    cout << "   Introduce el dia de la fecha: ";
    cin >> fecha->dia;
    cout << "   Introduce el mes de la fecha: ";
    cin >> fecha->mes;
    cout << "   Introduce el año de la fecha: ";
    cin >> fecha->anio;
    return fecha;
}
