#pragma once
#ifndef _ASISTENCIA_MODELO_H_
#define _ASISTENCIA_MODELO_H_

#include "FechaModelo.h"

struct AsistenciaDeAlumno
{
    int matricula;
    Fecha fechaDeAsistecia;
    bool alumnoAsistio;
    int puntosParticipacion;
    void InicializarAsistencia(int matriculaParam, bool alumnoAsistioParam);

    string ObtenerCadenaDeFormatoDeAsistencia();
};

#endif // _ASISTENCIA_MODELO_H_
