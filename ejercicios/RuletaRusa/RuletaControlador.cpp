#include "RuletaControlador.h"
#include <fstream>

#include <cstdlib>

const string RUTA_ARCHIVO_RULETA_BINARIO = "C:\\archivos\\Ruletas.bin";

Ruleta* G_listadoRuletas = NULL;

int G_contadorRuletas;

const int MAX_NUM = 50;
int G_contadorNumerosSacados;
int G_numerosAleatorios[MAX_NUM];

int calcularNumeroAlAzar()
{
    //calculando un numero random de 1 a MAX_NUM
    int numero_al_azar = (rand() % MAX_NUM) + 1;
    return numero_al_azar;
}

int* GenerarNumeroAleatorios()
{
    int numero_al_azar = 0;
    srand(time(NULL));
    G_contadorNumerosSacados = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        int numero = calcularNumeroAlAzar();
        bool numeroRandomEstaAsignado = false;
        for (int j = 0; j < G_contadorNumerosSacados; j++)
        {
            if (G_numerosAleatorios[j] == numero)
            {
                i--;
                numeroRandomEstaAsignado = true;
                break;
            }
        }
        if (!numeroRandomEstaAsignado) {
            G_numerosAleatorios[G_contadorNumerosSacados++] = numero;
        }
    }
    return G_numerosAleatorios;
}

int ObtenerCantidadTotalDeRuletas()
{
    return G_contadorRuletas;
}

Ruleta* ObtenerListadoRuletas()
{
    return G_listadoRuletas;
}

void AgregarRuleta(Ruleta* ruletaParam)
{
    if (G_listadoRuletas == NULL)
        G_listadoRuletas = new Ruleta[MAX_NUM];

    ruletaParam->fechaDeRegistroParticipacion.InicializarFechaActual();
    G_listadoRuletas[G_contadorRuletas++] = *ruletaParam;
}

Ruleta* CrearRuleta(Fecha fechaParam)
{
    for (int i = 0; i < G_contadorRuletas; i++)
    {
        if (G_listadoRuletas[i].fechaDeRegistroParticipacion.EsLaMismaFecha(fechaParam))
            return &G_listadoRuletas[i];
    }
    Ruleta* ruleta = new Ruleta;
    int* numAleatorios = GenerarNumeroAleatorios();
    ruleta->AsignarNumeroAleatorios(numAleatorios);
    AgregarRuleta(ruleta);
    return ruleta;
}

void EscribirRuletaEnArchivoBinario()
{
    fstream archivo;
    archivo.open(RUTA_ARCHIVO_RULETA_BINARIO, ios::out | ios::binary);
    if (!archivo.is_open()) return;
    for (int i = 0; i < G_contadorRuletas; i++)
    {
        archivo.write(reinterpret_cast<char*>(G_listadoRuletas + i), sizeof(Ruleta));
    }
    archivo.close();
}

bool LeerRuletasDesdeArchivoBinario()
{
    int totalByteSize = 0;
    fstream archivo;
    archivo.open(RUTA_ARCHIVO_RULETA_BINARIO, ios::in | ios::binary | ios::ate);
    if (!archivo.is_open())
        return false;
    totalByteSize = archivo.tellg();
    for (int i = 0; i < totalByteSize / sizeof(Ruleta); i++)
    {
        Ruleta* ruletaTemp = new Ruleta;
        archivo.seekg(i * sizeof(Ruleta));
        archivo.read(reinterpret_cast<char*>(ruletaTemp), sizeof(Ruleta));
        AgregarRuleta(ruletaTemp);
    }
    archivo.close();
    return true;
}