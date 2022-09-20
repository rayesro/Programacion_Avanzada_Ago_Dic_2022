#include "AsistenciaModelo.h"

void AsistenciaDeAlumno::InicializarAsistencia(int matriculaParam, bool alumnoAsistioParam)
{
    matricula = matriculaParam;
    fechaDeAsistecia.InicializarFechaActual();
    alumnoAsistio = alumnoAsistioParam;
    puntosParticipacion = 0;
}

string AsistenciaDeAlumno::ObtenerCadenaDeFormatoDeAsistencia()
{
    string str = "El alumno con matricula ";
    str.append(to_string(matricula));
    str.append(" en la fecha ");
    str.append(fechaDeAsistecia.ObtenerFecha());
    str.append(" - ");
    str.append(alumnoAsistio ? "SI" : "NO");
    str.append(" ASISTIO");
    return str;
}