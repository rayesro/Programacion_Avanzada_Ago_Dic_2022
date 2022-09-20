#include <iostream>
#include <Windows.h>
#include "RuletaVista.h"

using namespace std;

void ImprimirMenuDeRuleta()
{
    system("cls");
    cout << "MODO RULETA\n";
    cout << " 1) Iniciar ruleta. \n";
    cout << " 4) Regresar al menu principal. \n";
}

void ImpimirModoRuleta()
{
    Fecha fechaDeHoy;
    fechaDeHoy.InicializarFechaActual();
    Ruleta* ruleta = CrearRuleta(fechaDeHoy);

    int inicio = !ruleta->fechaDeRegistroParticipacion.EsLaMismaFecha(fechaDeHoy) ?
        0 : ruleta->asistentes + ruleta->inasistentes;

    Alumno* listado = ObtenerListadoDeAlumnos();

    for (int i = 0; i < 50; i++)
    {
        AsistenciaDeAlumno* inasistencia = CrearAsistencia(listado[i].matricula, false);
        AgregarAsistencia(inasistencia);
    }


    for (int i = inicio; i < 50; i++)
    {
        int indiceDeAlumno = ruleta->numerosAleatorios[i];
        Alumno* alumnoSeleccionado = &listado[indiceDeAlumno];


        system("cls");
        cout << "**************************\n";
        cout << "** MODO RULETA ACTIVADO **\n";
        cout << "**************************\n\n";

        cout << ">>> ATENTOS!!! " << endl;
        cout << ">>> De los " << 50 - i << " faltantes por participar, el siguiente voluntario sera ";
        for (int i = 0; i < 0; i++)
        {
            Sleep(1000);
            cout << ".";
        }

        cout << endl << endl << " ===== " << alumnoSeleccionado->nombre << " ===== " << endl << endl;

        if (alumnoSeleccionado->matricula == 0)
        {
            cout << ">>>>>>> El alumno no cuenta con una matricula." << endl;
            cout << ">>>>>>> Ingresa la matricula del alumno: ";
            cin >> alumnoSeleccionado->matricula;
        }

        int opcion = 0;
        cout << endl;
        do {
            cout << ">>> Ingresa: " << endl;
            cout << ">>>>> 0 para Inasitencia " << endl;
            cout << ">>>>> 1 para Asitencia " << endl;
            cout << ">>>>> 2 para Participacion " << endl;
            opcion = PreguntarEleccionDelMenu(2, 0);
        } while (opcion < 0 || opcion > 2);

        /* if (opcion == 2)
         {
             AsistenciaDeAlumno* asistencia = BuscarAsistencia(alumnoSeleccionado->matricula, fechaDeHoy);
             asistencia->alumnoAsistio = true;
         }*/
        AsistenciaDeAlumno* nuevaAsistencia = CrearAsistencia(alumnoSeleccionado->matricula, opcion);
        if (opcion == 2)
            nuevaAsistencia->puntosParticipacion++;
        AgregarAsistencia(nuevaAsistencia);

        switch (opcion)
        {
        case 0:
            ruleta->inasistentes++;
            break;
        case 1:
            ruleta->asistentes++;
            break;
        case 2:
            ruleta->asistentes++;
            ruleta->participaciones++;
            break;
        }

        cout << endl << endl;
        cout << ">>> Resultados al momento: " << endl;
        cout << ">>>>> Asistentes.........: " << ruleta->asistentes << endl;
        cout << ">>>>> Inasistentes.......: " << ruleta->inasistentes << endl;
        cout << ">>>>> Participaciones....: " << ruleta->participaciones << endl << endl;

        EscribirAlumnosEnArchivoBinario();
        EscribirAsistenciasEnArchivoBinario();
        EscribirRuletaEnArchivoBinario();

        char opcionChar;
        cout << ">>> Deseas continuar con la ruleta? [S/N]: ";
        cin >> opcionChar;
        if (opcionChar != 's' && opcionChar != 'S')
            break;

    }
}

void MostrarPantallaRuleta() {
    int opcionMenu = 0;
    do {
        ImprimirMenuDeRuleta();
        opcionMenu = PreguntarEleccionDelMenu(4);
        switch (opcionMenu)
        {
        case 1:
            ImpimirModoRuleta();
            break;
        case 2:
            //MostrarPantallaAsistenciaPorMatricula();
            break;
        case 3:
            // MostrarPantallaAsistenciaPorFecha();
            break;
        case 4:
            //MostrarPantalla();
            break;
        }
    } while (opcionMenu != 4);
}
