#include <fstream>
#include "AsistenciaControlador.h"	
#include "Constantes.h"


const string RUTA_ARCHIVO_BINARIO = "C:\\archivos\\Asistencias.bin";

AsistenciaDeAlumno* G_listadoAsistencias = NULL;

int G_contadorAsistencias;

int ObtenerCantidadTotalDeAsistencias()
{
    return G_contadorAsistencias;
}

AsistenciaDeAlumno* ObtenerListadoAsistencias()
{
    return G_listadoAsistencias;
}

void AgregarAsistencia(AsistenciaDeAlumno* asistenciaParam)
{
    if (G_listadoAsistencias == NULL)
    {
        G_listadoAsistencias = new AsistenciaDeAlumno[MAX_ALUMNOS];
    }

    bool tieneAlumnoAsistenciaYaRegistrada = false;
    for (int i = 0; i < G_contadorAsistencias; i++)
    {
        if (
            asistenciaParam->matricula == G_listadoAsistencias[i].matricula
            &&
            G_listadoAsistencias[i].fechaDeAsistecia.EsLaMismaFecha(asistenciaParam->fechaDeAsistecia))
        {
            tieneAlumnoAsistenciaYaRegistrada = true;
            break;
        }
    }

    if (!tieneAlumnoAsistenciaYaRegistrada)
        G_listadoAsistencias[G_contadorAsistencias++] = *asistenciaParam;
}

AsistenciaDeAlumno* BuscarAsistencia(int matriculaParam, Fecha fechaParam)
{
    AsistenciaDeAlumno* asistencia = NULL;
    for (int i = 0; i < G_contadorAsistencias; i++)
    {
        if (matriculaParam == G_listadoAsistencias[i].matricula &&
            G_listadoAsistencias[i].fechaDeAsistecia.EsLaMismaFecha(fechaParam))
        {
            asistencia = &G_listadoAsistencias[i];
            break;
        }
    }
    return asistencia;
}

AsistenciaDeAlumno* CrearAsistencia(int matriculaParam, bool hayAsistenciaParam)
{
    AsistenciaDeAlumno* asistencia = new AsistenciaDeAlumno;
    asistencia->InicializarAsistencia(matriculaParam, hayAsistenciaParam);
    return asistencia;
}


void EscribirAsistenciasEnArchivoBinario()
{
    fstream archivo;
    archivo.open(RUTA_ARCHIVO_BINARIO, ios::out | ios::binary);
    if (!archivo.is_open()) return;
    for (int i = 0; i < G_contadorAsistencias; i++)
    {
        archivo.write(reinterpret_cast<char*>(G_listadoAsistencias + i), sizeof(AsistenciaDeAlumno));
    }
    archivo.close();
}

bool LeerAsistenciasDesdeArchivoBinario()
{
    int totalByteSize = 0;
    fstream archivo;
    archivo.open(RUTA_ARCHIVO_BINARIO, ios::in | ios::binary | ios::ate);
    if (!archivo.is_open())
        return false;
    totalByteSize = archivo.tellg();
    for (int i = 0; i < totalByteSize / sizeof(AsistenciaDeAlumno); i++)
    {
        AsistenciaDeAlumno* asistencia = new AsistenciaDeAlumno;
        archivo.seekg(i * sizeof(AsistenciaDeAlumno));
        archivo.read(reinterpret_cast<char*>(asistencia), sizeof(AsistenciaDeAlumno));
        AgregarAsistencia(asistencia);
    }
    archivo.close();
    return true;
}