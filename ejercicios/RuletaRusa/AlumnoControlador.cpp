#include "AlumnoControlador.h"

#include<fstream>
#include "Constantes.h"


const string RUTA_ARCHIVO_BINARIO = "C:\\archivos\\Alumnos.bin";
const string RUTA_ARCHIVO_TEXTO = "solo_nombres.txt";

Alumno* G_listadoAlumnos = NULL;
int G_contadorAlumnos;

void AgregarAlumno(Alumno* alumnoParam)
{
    if (G_listadoAlumnos == NULL)
    {
        G_listadoAlumnos = new Alumno[MAX_ALUMNOS];
    }
    G_listadoAlumnos[G_contadorAlumnos] = *alumnoParam;
    G_contadorAlumnos++;
}

Alumno* CrearAlumno(string nombreParam, int matriculaParam, int oportunidadParam)
{
    Alumno* nuevoAlumno = new Alumno;
    nuevoAlumno->InicializarAlumno(nombreParam, matriculaParam, oportunidadParam);
    return nuevoAlumno;
}

Alumno* BuscarAlumnoPorMatricula(int matriculaParam)
{
    Alumno* alumnoABuscar = NULL;
    for (int i = 0; i < G_contadorAlumnos; i++)
    {
        if (G_listadoAlumnos[i].matricula != matriculaParam)
            continue;
        alumnoABuscar = &G_listadoAlumnos[i];
        break;
    }
    return alumnoABuscar;
}

Alumno* ObtenerListadoDeAlumnos()
{
    return G_listadoAlumnos;
}

void EscribirAlumnosEnArchivoBinario()
{
    fstream archivo;
    archivo.open(RUTA_ARCHIVO_BINARIO, ios::out | ios::binary);
    if (!archivo.is_open()) return;
    for (int i = 0; i < G_contadorAlumnos; i++)
    {
        AlumnoBuf* tempBuffer = ClonarAlumno(&G_listadoAlumnos[i]);//(G_listadoAlumnos + i);
        archivo.write(reinterpret_cast<char*>(tempBuffer), sizeof(AlumnoBuf));
    }
    archivo.close();
}


bool LeerAlumnosDesdeArchivoBinario()
{
    int totalByteSize = 0;
    fstream archivo;
    archivo.open(RUTA_ARCHIVO_BINARIO, ios::in | ios::binary | ios::ate);//at the end
    if (!archivo.is_open())
        return false;
    totalByteSize = archivo.tellg();//nos dice la posicion del puntero de lectura
    for (int i = 0; i < totalByteSize / sizeof(AlumnoBuf); i++)
    {
        AlumnoBuf* tempBuffer = new AlumnoBuf;
        archivo.seekg(i * sizeof(AlumnoBuf));//seekg establece el puntero de lectura en una posicion deseada
        archivo.read(reinterpret_cast<char*>(tempBuffer), sizeof(AlumnoBuf));
        Alumno* alumno = ClonarAlumno(tempBuffer);
        AgregarAlumno(alumno);
        delete tempBuffer;
    }
    archivo.close();
    return true;
}

bool LeerSoloNombresDeAlumnosDesdeArchivo()
{
    string linea;
    fstream archivo;
    archivo.open(RUTA_ARCHIVO_TEXTO, ios::in);
    while (!archivo.eof())
    {
        getline(archivo, linea);
        AgregarAlumno(CrearAlumno(linea));
    }
    archivo.close();
    return true;
}

void LeerAlumnosDesdeArchivo()
{
    bool cargaCorrecta = LeerAlumnosDesdeArchivoBinario();
    if (cargaCorrecta)
        return;
    LeerSoloNombresDeAlumnosDesdeArchivo();
}

AlumnoBuf* ClonarAlumno(Alumno* alumnoParam)
{
    AlumnoBuf* temp = new AlumnoBuf;
    temp->InicializarAlumno(alumnoParam->nombre, alumnoParam->matricula, alumnoParam->oportunidad);
    return temp;
}

Alumno* ClonarAlumno(AlumnoBuf* alumnoParam)
{
    Alumno* temp = new Alumno;
    temp->InicializarAlumno(alumnoParam->nombre, alumnoParam->matricula, alumnoParam->oportunidad);
    return temp;
}

int ObtenerContadorAlumnos()
{
    return G_contadorAlumnos;
}

Alumno* ObtenerListadoAlumnos()
{
    return G_listadoAlumnos;
}