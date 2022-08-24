// Loteria.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


// Crear una programa que almacene 

struct alumno
{
    string nombre;
    int op;
};

string nombres[] = {
"ALMAGUER ARIAS URIEL",
 "CABRERA SANCHEZ JUAN OMAR",
 "CHAPA GUAJARDO DANIEL",
 "DAVILA REYES FRANCO GABRIEL",
 "DAVILA ROSALES ALISON JUDITH",
 "DIAZ ORTA ALEJANDRO SAHID",
 "GONZALEZ MORIN JORGE HUMBERTO",
 "MARTINEZ MARQUEZ LUCAS DAMIAN",
 "MARTINEZ RODRIGUEZ AXEL MAXIMILIANO",
 "MIRANDA GONZALEZ MARIANA ABIGAIL",
 "MONTALVO SANCHEZ JUAN ANTONIO",
 "PONCE RAMIREZ SAMUEL",
 "REYES RODRIGUEZ DANIEL",
 "ROMO RODRIGUEZ RICARDO",
 "SERRANO CABALLERO JORGE ARMANDO",
 "SERRATO MARTINEZ ERIKA VANESA",
 "SIFUENTES PIÑON YAHIR ALEJANDRO",
 "SIMBRON OLVERA EMMANUEL",
 "TAPIA ARREDONDO PAMELA CECILLE",
 "ZAMORA GRAJEDA MATEO",
 "ZAPATA CANTU JAIR ALEJANDRO",
 "AGUILAR MUÑIZ ALEXIS",
 "ALEMAN RIVERA ANGEL ALDAIR",
 "BUSTOS GUZMAN JOSE MANUEL",
 "CASTAÑON HERRERA JAROL GUADALUPE",
 "CHAPA NAVA ROBERTO MAURICIO",
 "CHARLES MALDONADO MAURICIO ALEJANDRO",
 "CORONADO CHÁVEZ BERNARDO",
 "CORTES ANDRADE DANTE",
 "DELGADO TORRES BRIAN GABRIEL",
 "GARCIA RAMOS IVONNE",
 "GONZALEZ ERASMO DENISSE",
 "GONZALEZ ESCALERA OSCAR MARIO",
 "GONZALEZ GONZALEZ DIEGO JESUS",
 "HERNANDEZ MACIAS GERARDO ANDRES",
 "ORTA AGUIRRE JORDY GERARDO",
 "RODRÍGUEZ GARCÍA CARLOS ADRIAN",
 "RODRIGUEZ ROSALES ARATH ABISAY",
 "SALAZAR GOMEZ MOISES",
 "SEGOVIA REYES MARICZA JAQUELINE",
 "CRUZ PEREZ DIEGO ALAN",
 "ELIAS PEÑA FERNANDO AXEL",
 "GARCIA MORALES ALEXIS",
 "LEZAMA RODRIGUEZ BETHSABE",
 "MARTINEZ HERNANDEZ SINUHE",
 "MENDEZ CISNEROS VICTOR ALEJANDRO",
 "PEREZ CHAVEZ DARIEL",
 "RODRÍGUEZ ZAPATA JOSÉ JUAN",
 "RUIZ OLIVARES MARIANA ANGELICA",
 "VEGA CAMACHO MIGUEL SAUL"
};

int cartas[];
int cartasEscogidas[50];
int contadorCartasEscogidas = 0;
const int MAX_NUM = 50;

int calcularNumeroAlAzar()
{
    //calculando un numero random de 1 a MAX_NUM
    int numero_al_azar = (rand() % MAX_NUM) + 1;
    return numero_al_azar;
}
void sacarCartasSinDuplicados()
{
    int numero_al_azar = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        int numero = calcularNumeroAlAzar();
        bool cartaYaExiste = false;
        for (int j = 0; j < contadorCartasEscogidas; j++)
        {
            if (cartasEscogidas[j] == numero)
            {
                cartaYaExiste = true;
                i--;
            }
        }
        if (cartaYaExiste == false) {
            cartasEscogidas[contadorCartasEscogidas] = numero;
            contadorCartasEscogidas++;
        }
    }
}
int main()
{
    srand(time(0));
    sacarCartasSinDuplicados();
    for (int i = 0; i < MAX_NUM; i++)
    {
        int op = 0;
        cout << i +1 << ": " << nombres[cartasEscogidas[i]] << endl;
        cin >> op;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
