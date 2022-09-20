#pragma once
#ifndef _RULETA_MODELO_H_
#define _RULETA_MODELO_H_

#include "FechaModelo.h"

struct Ruleta
{
    int asistentes = 0;
    int inasistentes = 0;
    int participaciones = 0;
    Fecha fechaDeRegistroParticipacion;
    int numerosAleatorios[50];

    void AsignarNumeroAleatorios(int* numerosParam);
};
#endif // !_RULETA_MODELO_H_
