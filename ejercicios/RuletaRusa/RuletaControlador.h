#pragma once
#ifndef _RULETA_CONTROLADOR_H_
#define _RULETA_CONTROLADOR_H_

#include "RuletaModelo.h"

int calcularNumeroAlAzar();

int* GenerarNumeroAleatorios();

int ObtenerCantidadTotalDeRuletas();

Ruleta* ObtenerListadoRuletas();

void AgregarRuleta(Ruleta* ruletaParam);

Ruleta* CrearRuleta(Fecha fechaParam);

void EscribirRuletaEnArchivoBinario();

bool LeerRuletasDesdeArchivoBinario();

#endif // !_RULETA_CONTROLADOR_H_

