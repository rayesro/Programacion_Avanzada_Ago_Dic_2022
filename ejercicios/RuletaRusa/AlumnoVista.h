#pragma once
#ifndef _ALUMNO_VISTA_H
#define _ALUMNO_VISTA_H

#include <iostream>
#include "AlumnoControlador.h"
#include "VistaCommon.h"

void ImprimirMenuDeAlumnos();

void MostrarPantallaAltaDeAlumno();

void MostrarPantallaListadoDeAlumno();

Alumno* MostrarPantallaBusquedaDeAlumnoPorMatricula();

void MostrarPantallaAlumnos(); 

#endif // !_ALUMNO_VISTA_H
