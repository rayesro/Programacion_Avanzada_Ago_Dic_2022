#include "FechaModelo.h"

void Fecha::InicializarFechaActual()
{
    time_t tiempo;
    struct tm fechaLocal;
    time(&tiempo);
    localtime_s(&fechaLocal, &tiempo);

    anio = 1900 + fechaLocal.tm_year;
    mes = 1 + fechaLocal.tm_mon;
    dia = fechaLocal.tm_mday;
}

string Fecha::ObtenerFecha()
{
    string fecha = to_string(anio);
    fecha.append("-");
    fecha.append((to_string(mes)));
    fecha.append("-");
    fecha.append(to_string(dia));
    return fecha;
}

bool Fecha::EsLaMismaFecha(Fecha fechaACompararParam)
{
    if (fechaACompararParam.anio == anio &&
        fechaACompararParam.mes == mes &&
        fechaACompararParam.dia == dia)
        return true;
    return false;
}