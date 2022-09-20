#include "AlumnoVista.h"


using namespace std;

void ImprimirMenuDeAlumnos()
{
    system("cls");
    cout << "MENU DE ALUMNOS\n";
    cout << " 1) Alta de alumno. \n";
    cout << " 2) Listar alumnos. \n";
    cout << " 3) Regresar al menu principal. \n";
}

void MostrarPantallaAltaDeAlumno()
{
    string nombre;
    int matricula;
    int oportunidad;

    system("cls");
    cout << "ALTA DE ALUMNO\n";
    cout << "Ingresa la matricula del alumno: ";
    cin >> matricula;
    cout << "Ingresa el nombre del alumno: ";
    cin >> nombre;
    cout << "Ingresa la oportunidad del alumno: ";
    cin >> oportunidad;

    Alumno* alumno = CrearAlumno(nombre, matricula, oportunidad);
    AgregarAlumno(alumno);
}

void MostrarPantallaListadoDeAlumno()
{
    int contadorAlumnos = ObtenerContadorAlumnos();
    Alumno* listado = ObtenerListadoAlumnos();
    system("cls");
    cout << "LISTADO DE ALUMNOS\n\n";
    for (int i = 0; i < contadorAlumnos; i++)
    {
        cout << "Matricula:" << listado[i].matricula << " - Nombre: " << listado[i].nombre << endl;
    }
    cout << "\n\n";
    system("pause");
}

Alumno* MostrarPantallaBusquedaDeAlumnoPorMatricula()
{
    int matricula = 0;
    Alumno* alumno = NULL;
    char opcion = 'n';
    do {
        opcion = 'n';
        cout << "  Ingresa la matricula del alumno:";
        cin >> matricula;
        alumno = BuscarAlumnoPorMatricula(matricula);
        if (alumno == NULL)
        {
            cout << "  ** No se encontraron datos. **:";
            cout << "  Quieres buscar otro(S/N)?";
            cin >> opcion;
            if (opcion != 's' && opcion != 'S')
                return NULL;
        }
    } while (opcion == 's' || opcion == 'S');
    return alumno;
}

void MostrarPantallaAlumnos() {
    int opcion = 0;
    do {
        ImprimirMenuDeAlumnos();
        opcion = PreguntarEleccionDelMenu(3);
        switch (opcion)
        {
        case 1:
            MostrarPantallaAltaDeAlumno();
            break;
        case 2:
            MostrarPantallaListadoDeAlumno();
            break;
        }
    } while (opcion != 3);
}
