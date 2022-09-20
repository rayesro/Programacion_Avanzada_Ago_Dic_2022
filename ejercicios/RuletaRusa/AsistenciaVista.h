#pragma once
#ifndef _ASISTENCIA_VISTA_H_
#define _ASISTENCIA_VISTA_H_

#include "AsistenciaControlador.h"
#include "AlumnoVista.h"
#include "VistaCommon.h"

void ImprimirMenuDeAsistencia();

void MostrarPantallaCapturaDeAsistencia();

void MostrarPantallaAsistenciaPorMatricula();

void ImprimirAsistenciasPorFecha(Fecha* fechaFiltroParam);

void MostrarPantallaAsistenciaPorFecha();

void MostrarPantallaAsistencia();

#endif // !_ASISTENCIA_VISTA_H_
