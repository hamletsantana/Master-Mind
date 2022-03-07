/*
Enunciado: Programa que resuelve el caso para beginners de Master Mind

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268

Fecha: 15/02/2022
*/

#include <iostream>
#include <typeinfo>
using namespace std;

int main(int argc, const char *argv[])
{
    int clave_oculta[4], jugadas[4], intentos;
    char pistas[4];

    cout << "Bienvenidos a nuestro Master Mind" << endl;
    cout << "";
    cout << "Inserte una clave oculta para ser adivinada" << endl;
    cout << "";

    // Se plantea la clave
    for (int x = 0; x < 4; x++)
    {

        cout << "Introduzca un numero: " << endl;
        cout << "";
        cin >> clave_oculta[x];
        if (clave_oculta[x] < 1 || clave_oculta[x] > 6)
        {
            cout << "El numero debe estar entre 0 y 6" << endl;
            cout << "";
            x--;
        }
    }
    /*
     Muestra la clave oculta para usos de prueba
            cout << "La clave es: " ;
            cout << "";
            for (int x = 0; x < 4; x++)
            {
                cout << clave_oculta[x]<<endl;
            }
    */

    intentos = 0;

    for (int z = 0; z < 10; z++)
    {
        intentos++;
        cout << "";
        cout << "INSERTE UN INTENTO ";
        cout << "";
        // El usuario ingresa su intento
        for (int c = 0; c < 4; c++)
        {
            cout << "";
            cout << "Introduzca un numero: " << endl;
            cin >> jugadas[c];
            if (jugadas[c] < 1 || jugadas[c] > 6)
            {
                cout << "El numero debe estar entre 0 y 6" << endl;
                cout << "";
                c--;
            }
        }
        // Comprobacion entre arrays
        for (int i = 0; i < 4; i++)
        {
            //'X' No esta en el arreglo
            pistas[i] = 'X';
            for (int j = 0; j < 4; j++)
            {
                if (jugadas[i] == clave_oculta[j] && (i == j))
                {
                    //'C' Significa que esta en la misma posicion
                    pistas[i] = 'C';
                }
                else if (jugadas[i] == clave_oculta[j] && (i != j))
                {
                    //'F' Significa que esta el numero pero no en la misma posicion
                    pistas[i] = 'F';
                }
            }
        }
        // Imprime las pistas
        for (int a = 0; a < 4; a++)
        {
            cout << pistas[a];
        }
        cout << "";
        // Revisa si ganaste
        if (pistas[0] == 'C' && pistas[1] == 'C' && pistas[2] == 'C' && pistas[3] == 'C')
        {
            cout << "";
            cout << "Felicidades, has ganado en " << intentos << " intentos" << endl;
            z = 10;
        }
        else if (intentos == 10)
        {
            cout << "";
            cout << "Lo siento, has perdido" << endl;
            z = 10;
        }
    }
    return 0;
}