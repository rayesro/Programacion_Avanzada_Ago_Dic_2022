#include "Arranque.h"
#include <direct.h>
void GuardarDatosAlArchivo()
{
    EscribirAlumnosEnArchivoBinario();
    EscribirAsistenciasEnArchivoBinario();
    EscribirRuletaEnArchivoBinario();
}

void CargarDatosDesdeArchivo()
{
    LeerAlumnosDesdeArchivo();
    LeerAsistenciasDesdeArchivoBinario();
    LeerRuletasDesdeArchivoBinario();
}

void InicializarApp()
{
    mkdir("C:/archivos");
}