#pragma once
#ifndef _FECHA_MODELO_H_
#define _FECHA_MODELO_H_

#include <string>
#include <ctime>
using namespace std;
struct Fecha
{
    int dia;
    int mes;
    int anio;
    void InicializarFechaActual();
    string ObtenerFecha();
    bool EsLaMismaFecha(Fecha fechaACompararParam);
};

#endif // !_FECHA_MODELO_H_
