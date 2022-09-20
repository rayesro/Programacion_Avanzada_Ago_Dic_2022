#include "AlumnoModelo.h"

void Alumno::InicializarAlumno(string nombreParam, int matriculaParam, int oportunidadParam)
{
    nombre = nombreParam;
    matricula = matriculaParam;
    oportunidad = oportunidadParam;
}

void AlumnoBuf::InicializarAlumno(string nombreParam, int matriculaParam, int oportunidadParam)
{
    strcpy_s(nombre, nombreParam.c_str());
    matricula = matriculaParam;
    oportunidad = oportunidadParam;
}