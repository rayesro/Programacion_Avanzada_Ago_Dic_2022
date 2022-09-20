#include <iostream>
#include "AsistenciaVista.h"


using namespace std;

int opcionMenu = 0;

void ImprimirMenuDeAsistencia()
{
    system("cls");
    cout << "MENU DE ASISTENCIAS\n";
    cout << " 1) Capturar asistencia. \n";
    cout << " 2) Listar asistencias por alumno. \n";
    cout << " 3) Listar asistencias por fecha. \n";
    cout << " 4) Regresar al menu principal. \n";
}

void MostrarPantallaCapturaDeAsistencia()
{
    system("cls");
    cout << "Captura de Asistencia \n\n";

    Alumno* alumno = MostrarPantallaBusquedaDeAlumnoPorMatricula();
    if (alumno == NULL)
        return;

    char opcion = 'n';
    do {
        cout << " El alumno asistio a clase? (S/N): ";
        cin >> opcion;
    } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

    bool asistio =
        (opcion == 's' || opcion == 'S') ?
        true : false;

    //condicion ? si es verdadera : si es falta

    AsistenciaDeAlumno* asistencia = CrearAsistencia(alumno->matricula, asistio);
    AgregarAsistencia(asistencia);

    cout << " Asistencia capturada. \n\n";
    system("pause");
}

void MostrarPantallaAsistenciaPorMatricula()
{
    system("cls");
    cout << "Listado de asistencia por matricula \n\n";
    Alumno* alumno = MostrarPantallaBusquedaDeAlumnoPorMatricula();
    if (alumno == NULL)
        return;

    AsistenciaDeAlumno* listado = ObtenerListadoAsistencias();
    for (int i = 0; i < ObtenerCantidadTotalDeAsistencias(); i++)
    {
        if (listado[i].matricula != alumno->matricula)
            continue;
        cout << " " << listado[i].fechaDeAsistecia.ObtenerFecha();
        if (listado[i].alumnoAsistio)
            cout << " - SI ASISTIO" << endl;
        else
            cout << " - NO ASISTIO" << endl;
    }

    system("pause");
}

void ImprimirAsistenciasPorFecha(Fecha* fechaFiltroParam)
{
    int cantidadAlumnos = ObtenerCantidadTotalDeAsistencias();
    AsistenciaDeAlumno* asistencias = ObtenerListadoAsistencias();
    for (int i = 0; i < cantidadAlumnos; i++)
    {
        if (!asistencias[i].fechaDeAsistecia.EsLaMismaFecha(*fechaFiltroParam))
            continue;
        cout << asistencias[i].ObtenerCadenaDeFormatoDeAsistencia() << endl;
    }
    system("pause");
}

void MostrarPantallaAsistenciaPorFecha()
{
    Fecha* fechaABuscar = NULL;
    do {
        system("cls");
        cout << "MENU DE ASISTENCIA POR FECHA\n";
        cout << " 1) Buscar por fecha. \n";
        cout << " 2) Buscar por el dia de hoy. \n";
        cout << " 3) Regresar al menu principal. \n";
        opcionMenu = PreguntarEleccionDelMenu(3);
        switch (opcionMenu)
        {
        case 1:
            fechaABuscar = PreguntarFecha();
            break;
        case 2:
            fechaABuscar = new Fecha;
            fechaABuscar->InicializarFechaActual();
            break;
        }
        ImprimirAsistenciasPorFecha(fechaABuscar);

    } while (opcionMenu != 3);


}


void MostrarPantallaAsistencia()
{
    do {
        ImprimirMenuDeAsistencia();
        opcionMenu = PreguntarEleccionDelMenu(4);
        switch (opcionMenu)
        {
        case 1:
            MostrarPantallaCapturaDeAsistencia();
            break;
        case 2:
            MostrarPantallaAsistenciaPorMatricula();
            break;
        case 3:
            MostrarPantallaAsistenciaPorFecha();
            break;
        }
    } while (opcionMenu != 4);
}