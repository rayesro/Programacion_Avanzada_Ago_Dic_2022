#include <windows.h>
#include "resource.h"

HINSTANCE G_hInstance;

INT_PTR CALLBACK fnMiDialogo2(
    HWND hParentDialog, //handler o manejador del dialogo que se creo o que se esta ejecutando
    UINT uMsg, //identificador del mensaje o evento generado en un dialog
    WPARAM wParam, //datos adicionales del evento o mensaje generado, depende del tipo de evento 
    LPARAM lParam  //datos adicionales del evento o mensaje generado, depende del tipo de evento  
)
{
    switch (uMsg)
    {
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDOK:
        {
            MessageBox(
                hParentDialog, //handler del dialogo padre
                L"HEMOS LLEGADO AL FINAL", //cuerpo del mensaje
                L"EXITO", //titulo
                MB_OK | MB_ICONINFORMATION); //bandera para definir el comportamiento del message box
        }
        break;


        }
    }
    break;

    default:
        break;
    }

    return FALSE;
}

INT_PTR CALLBACK fnMiDialogo(
    HWND hParentDialog, //handler o manejador del dialogo que se creo o que se esta ejecutando
    UINT uMsg, //identificador del mensaje o evento generado en un dialog
    WPARAM wParam, //datos adicionales del evento o mensaje generado, depende del tipo de evento 
    LPARAM lParam  //datos adicionales del evento o mensaje generado, depende del tipo de evento  
)
{
    switch (uMsg)
    {
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDOK:
        {
            MessageBox(
                hParentDialog, //handler del dialogo padre
                L"Has dado clic en el boton aceptar", //cuerpo del mensaje
                L"ACEPTADO", //titulo
                MB_OKCANCEL | MB_ICONERROR); //bandera para definir el comportamiento del message box
        }
        break;

        case IDCANCEL:
        {
            MessageBox(
                hParentDialog, //handler del dialogo padre
                L"Has dado clic en el boton CANCELAR", //cuerpo del mensaje
                L"CANCELADO", //titulo
                MB_OKCANCEL | MB_ICONHAND); //bandera para definir el comportamiento del message box
        }
        break;

        case BTN_DIALOGO2_CARGARDIALOGO1:
        {
            //creando un dialogo
            HWND hMiDialogo1 = CreateDialogW(
                G_hInstance,//la instancia de la aplicacion
                MAKEINTRESOURCE(IDD_DIALOG4),//el ID del dialogo (que esta en el archivo resource.h) que queremos crear
                NULL,//parametro obsoleto, se puede dejar como NULO
                fnMiDialogo2
            );
            //mostramos el dialogo
            ShowWindow(hMiDialogo1, SW_SHOW);

        }
        break;

        }
    }
    break;

    default:
        break;
    }

    return FALSE;
}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    G_hInstance = hInstance;

    //creando un dialogo
    HWND hMiDialogo = CreateDialogW(
        G_hInstance,//la instancia de la aplicacion
        MAKEINTRESOURCE(IDD_DIALOG4),//el ID del dialogo (que esta en el archivo resource.h) que queremos crear
        NULL,//parametro obsoleto, se puede dejar como NULO
        fnMiDialogo
    );
    //mostramos el dialogo
    ShowWindow(hMiDialogo, SW_SHOW);

    //escuchamos cualquier mensaje en el message loop
    MSG msg = { };
 
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
