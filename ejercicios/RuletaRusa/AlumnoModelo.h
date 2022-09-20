#pragma once
#ifndef _ALUMNO_MODELO_H_
#define _ALUMNO_MODELO_H_

#include <string>

using namespace std;

struct Alumno
{
    string nombre = "";
    int matricula = 0;
    int oportunidad = 0;
    void InicializarAlumno(string nombreParam, int matriculaParam, int oportunidadParam);
};

struct AlumnoBuf
{
    char nombre[100];
    int matricula = 0;
    int oportunidad = 0;
    void InicializarAlumno(string nombreParam, int matriculaParam, int oportunidadParam);
};

#endif // _ALUMNO_MODELO_H_
