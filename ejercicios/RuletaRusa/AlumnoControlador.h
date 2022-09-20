#pragma once
#ifndef _ALUMNO_CONTROLADOR_H
#define _ALUMNO_CONTROLADOR_H

#include "AlumnoModelo.h"


void AgregarAlumno(Alumno* alumnoParam);

Alumno* CrearAlumno(string nombreParam, int matriculaParam = 0, int oportunidadParam = 0);

Alumno* BuscarAlumnoPorMatricula(int matriculaParam);

Alumno* ObtenerListadoDeAlumnos();

void EscribirAlumnosEnArchivoBinario();

bool LeerAlumnosDesdeArchivoBinario();

bool LeerSoloNombresDeAlumnosDesdeArchivo();

void LeerAlumnosDesdeArchivo();

AlumnoBuf* ClonarAlumno(Alumno* alumnoParam);

Alumno* ClonarAlumno(AlumnoBuf* alumnoParam);

int ObtenerContadorAlumnos();

Alumno* ObtenerListadoAlumnos();

#endif // !_ALUMNO_CONTROLADOR_H

