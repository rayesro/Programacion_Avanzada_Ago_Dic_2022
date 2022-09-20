#include "RuletaModelo.h"

void Ruleta::AsignarNumeroAleatorios(int* numerosParam)
{
    for (int i = 0; i < 50; i++)
    {
        numerosAleatorios[i] = numerosParam[i];
    }
}