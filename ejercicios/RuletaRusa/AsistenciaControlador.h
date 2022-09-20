#pragma once
#ifndef _ASISTENCIA_CONTROLADOR_H
#define _ASISTENCIA_CONTROLADOR_H

#include "AsistenciaModelo.h"

int ObtenerCantidadTotalDeAsistencias();

AsistenciaDeAlumno* ObtenerListadoAsistencias();

void AgregarAsistencia(AsistenciaDeAlumno* asistenciaParam);

AsistenciaDeAlumno* BuscarAsistencia(int matriculaParam, Fecha fechaParam);

AsistenciaDeAlumno* CrearAsistencia(int matriculaParam, bool hayAsistenciaParam);

void EscribirAsistenciasEnArchivoBinario();

bool LeerAsistenciasDesdeArchivoBinario();

#endif // !_ASISTENCIA_CONTROLADOR_H
