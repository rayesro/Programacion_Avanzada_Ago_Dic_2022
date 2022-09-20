
#include <iostream>

#include "Arranque.h"
#include "AlumnoVista.h"
#include "AsistenciaVista.h"
#include "RuletaVista.h"

using namespace std;


void MostrarPantallaPrincipal()
{
    int opcion = 0;
    do {
        system("cls");
        cout << "MENU PRINCIPAL\n";
        cout << " 1) Menu de Alumnos. \n";
        cout << " 2) Menu de Asistencia. \n";
        cout << " 3) Modo ruleta. \n";
        cout << " 4) Salir. \n";
        opcion = PreguntarEleccionDelMenu(4);
        switch (opcion)
        {
        case 1:
            MostrarPantallaAlumnos();
            break;
        case 2:
            MostrarPantallaAsistencia();
            break;
        case 3:
            MostrarPantallaRuleta();
            break;
        }
    } while (opcion != 4);
}

void main()
{
    CargarDatosDesdeArchivo();
    MostrarPantallaPrincipal();
    GuardarDatosAlArchivo();
}
