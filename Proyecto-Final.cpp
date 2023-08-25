/*#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>

#define dim10 10

using namespace std;

int ingresar_cedula(long int &a) {
    string entrada;
    int valido = 0;

    while (!valido) {
        cout << "\nIngrese el numero de cedula: ";
        cin >> entrada;

        valido = 1;
        for (size_t i = 0; i < entrada.length(); i++) {
            if (!isdigit(entrada[i])) {
                cout << "Error: Ingrese solo numeros. Intentelo nuevamente." << endl;
                valido = 0;
                break;
            }
        }
    }

    a = strtol(entrada.c_str(), NULL, 10);
    return a;
}

int validar_cedula(long int x, int y[dim10]) {
    long int coc;
    int mul, sumpar = 0, sumimpar = 0, sumtotal, res;

    for (int i = 9; i >= 0; i--) {
        coc = x / 10;
        y[i] = x % 10;
        x = coc;
    }

    for (int i = 0; i < dim10; i += 2) {
        mul = y[i] * 2;
        if (mul > 9)
            mul -= 9;
        sumpar += mul;
    }
    for (int i = 1; i < dim10 - 2; i += 2)
        sumimpar += y[i];

    sumtotal = sumimpar + sumpar;
    res = 10 - (sumtotal % 10);

    if (res == 10)
        res = 0;
    if (res == y[9]) {
        return 1;
    } else {
        cout << "\nCedula invalida, por favor vuelva a ingresar." << endl;
        return 0;
    }
}

int main() {
    long int cedu;

    int cedula[dim10], veri, ddig;

    do {
        do {
            ingresar_cedula(cedu);
            ddig = trunc(cedu / 100000000);
            if (cedu > 3059999999 || cedu < 1000000000 || ddig == 25 || ddig == 26 || ddig == 27 || ddig == 28 || ddig == 29) {
                cout << "\nCedula incorrecta, por favor ingresela nuevamente." << endl;
            }
        } while (cedu > 3059999999 || cedu < 1000000000 || ddig == 25 || ddig == 26 || ddig == 27 || ddig == 28 || ddig == 29);
        veri = validar_cedula(cedu, cedula);
    } while (veri != 1);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define ANSI_BACKGROUND_YELLOW "\x1b[43m"
#define ANSI_BACKGROUND_GREEN "\x1b[42m"
#define ANSI_BACKGROUND_BLUE "\x1b[44m"
#define ANSI_BACKGROUND_MAGENTA "\x1b[45m"
#define ANSI_BACKGROUND_CYAN "\x1b[46m"
#define ANSI_COLOR_RESET "\x1b[0m"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void lineasV(int c, int f) {
    int i;
    for (i = 1; i < f; i++) {
        gotoxy(c, i);
        printf("%c", 176);
    }
}

void lineasH(int c, int f) {
    int i;
    for (i = 1; i < c; i++) {
        gotoxy(i, f);
        printf("%c", 176);
    }
}

void imprimirTextoEnRecuadro(int x, int y, const char *texto) {
    int i, len;
    len = strlen(texto);

    gotoxy(x, y);
    printf("%c", 176);

    for (i = 1; i <= len + 2; i++) {
        printf("%c", 176);
    }
    printf("%c", 176);

    gotoxy(x, y + 1);
    printf("%c", 176);

    gotoxy(x + len + 3, y + 1);
    printf("%c", 176);

    gotoxy(x, y + 2);
    printf("%c", 176);

    for (i = 1; i <= len + 2; i++) {
        printf("%c", 176);
    }
    printf("%c", 176);

    gotoxy(x + 2, y + 1);
    printf("%s", texto);
}

void imprimirCaratula() {
    printf(ANSI_BACKGROUND_YELLOW);
    lineasV(1, 24);
    lineasV(86, 24);
    lineasH(86, 1);
    lineasH(86, 24);
    gotoxy(1, 1);
    printf("%c", 176);
    gotoxy(1, 24);
    printf("%c", 176);
    gotoxy(86, 1);
    printf("%c", 176);
    gotoxy(86, 24);
    printf("%c", 176);
    getch();

    printf(ANSI_BACKGROUND_CYAN);
    imprimirTextoEnRecuadro(29, 2, "Universidad De Las");
    imprimirTextoEnRecuadro(31, 4.6, "Fuerzas Armadas");
    imprimirTextoEnRecuadro(36.5, 6.6, "ESPE");

    printf(ANSI_BACKGROUND_GREEN);
    imprimirTextoEnRecuadro(14, 10, "Fecha: 25/08/2023");
    imprimirTextoEnRecuadro(44, 10, "Integrantes: Pastuna-Cahuatijo-Mejia");

    printf(ANSI_BACKGROUND_BLUE);
    imprimirTextoEnRecuadro(14, 14, "NRC:9890");
    imprimirTextoEnRecuadro(44, 14, "Profesor: ING.Fernando Solis");

    printf(ANSI_BACKGROUND_MAGENTA);
    imprimirTextoEnRecuadro(14, 18, "Tercer Parcial");
    imprimirTextoEnRecuadro(44, 18, "Periodo: Mayo2023-Septiembre2023");

    printf(ANSI_COLOR_RESET);
}

bool validarCedula(const char *cedula) {
    if (strlen(cedula) != 10)
        return false;

    for (size_t i = 0; i < strlen(cedula); ++i) {
        if (!isdigit(cedula[i]))
            return false;
    }

    return true;
}

bool validarTexto(const char *texto) {
    for (size_t i = 0; i < strlen(texto); ++i) {
        if (!isalpha(texto[i]))
            return false;
    }
    return true;
}

bool validarNumero(const char *numero) {
    for (size_t i = 0; i < strlen(numero); ++i) {
        if (!isdigit(numero[i]) && numero[i] != '.') // Permitir decimales
            return false;
    }
    return true;
}

bool validarNota(double nota) {
    return (nota >= 0 && nota <= 20);
}

void ingresarDatos() {
    system("cls");
    printf("Sistema de Calificaciones Estudiantil\n");
    printf("------------------------------------\n");
    char cedula[11];
    printf("Opcion: Ingreso de datos del estudiante\n");

    do {
        printf("Ingrese la cedula: ");
        scanf("%s", cedula);

        if (!validarCedula(cedula))
            printf("Error: Cedula invalida. Por favor vuela a ingresar.\n");
    } while (!validarCedula(cedula));

    char primerNombre[50], apellido[50];
    int edad;

    do {
        printf("Ingrese el primer nombre: ");
        scanf("%s", primerNombre);

        if (!validarTexto(primerNombre))
            printf("Error: Ingrese solo letras.\n");
    } while (!validarTexto(primerNombre));

    do {
        printf("Ingrese el apellido: ");
        scanf("%s", apellido);

        if (!validarTexto(apellido))
            printf("Error: Ingrese solo letras.\n");
    } while (!validarTexto(apellido));

    char edadStr[50];
    int edadValida = 0;
    while (!edadValida) {
        printf("Ingrese la edad (entre 1 y 50): ");
        scanf("%s", edadStr);

        if (validarNumero(edadStr)) {
            edad = atoi(edadStr);
            if (edad >= 1 && edad <= 50) {
                edadValida = 1;
            } else {
                printf("Error: Ingrese una edad válida entre 1 y 50.\n");
            }
        } else {
            printf("Error: Ingrese solo numeros.\n");
        }
    }

    printf("Datos ingresados:\n");
    printf("Cedula: %s\n", cedula);
    printf("Primer Nombre: %s\n", primerNombre);
    printf("Apellido: %s\n", apellido);
    printf("Edad: %d\n", edad);

    printf("Pulsa una tecla para continuar...");
    _getch();
}

void ingresarNotasAsignatura(const char *cedula) {
    double notas[10];
    int numNotas = 0;

    while (numNotas < 5) {
        char notaStr[50];
        double nota;

        do {
            system("cls");
            printf("Sistema de Calificaciones Estudiantil\n");
            printf("------------------------------------\n");
            printf("Opcion: Ingreso de notas del estudiante\n");
            printf("Cedula del estudiante: %s\n", cedula);
            printf("Asignatura %d: ", numNotas + 1);
            scanf("%s", notaStr);

            if (validarNumero(notaStr)) {
                nota = atof(notaStr);
                if (validarNota(nota)) {
                    notas[numNotas] = nota;
                    numNotas++;
                    break;
                } else {
                    printf("Error: Ingrese una nota entre 0 y 20.\n");
                    _getch();
                }
            } else {
                printf("Error: Ingrese solo numeros.\n");
                _getch();
            }
        } while (1);
    }

    int opcion = -1;
    while (opcion != 0 && numNotas < 10) {
        printf("Desea ingresar mas notas? (1: Si, 0: No): ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            char notaStr[50];
            double nota;

            do {
                system("cls");
                printf("Sistema de Calificaciones Estudiantil\n");
                printf("------------------------------------\n");
                printf("Opcion: Ingreso de notas del estudiante\n");
                printf("Cedula del estudiante: %s\n", cedula);
                printf("Asignatura %d: ", numNotas + 1);
                scanf("%s", notaStr);

                if (validarNumero(notaStr)) {
                    nota = atof(notaStr);
                    if (validarNota(nota)) {
                        notas[numNotas] = nota;
                        numNotas++;
                        break;
                    } else {
                        printf("Error: Ingrese una nota entre 0 y 20.\n");
                        _getch();
                    }
                } else {
                    printf("Error: Ingrese solo numeros.\n");
                    _getch();
                }
            } while (1);
        }
    }

    printf("Notas ingresadas:\n");
    for (int i = 0; i < numNotas; ++i) {
        printf("Asignatura %d: %.2f\n", i + 1, notas[i]);
    }

    while (1) {
        printf("Desea editar alguna nota? (1: Si, 0: No): ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            int numNotaEditar;
            printf("Ingrese el número de la nota que desea editar (1-%d): ", numNotas);
            scanf("%d", &numNotaEditar);

            if (numNotaEditar >= 1 && numNotaEditar <= numNotas) {
                char notaStr[50];
                double nota;

                do {
                    printf("Ingrese la nueva nota %d: ", numNotaEditar);
                    scanf("%s", notaStr);

                    if (validarNumero(notaStr)) {
                        nota = atof(notaStr);
                        if (validarNota(nota)) {
                            notas[numNotaEditar - 1] = nota;
                            break;
                        } else {
                            printf("Error: Ingrese una nota entre 0 y 20.\n");
                        }
                    } else {
                        printf("Error: Ingrese solo numeros.\n");
                    }
                } while (1);
            } else {
                printf("Número de nota inválido.\n");
            }
        } else {
            break;
        }
    }

    printf("Notas actualizadas:\n");
    for (int i = 0; i < numNotas; ++i) {
        printf("Asignatura %d: %.2f\n", i + 1, notas[i]);
    }

    printf("Pulsa una tecla para continuar...");
    _getch();
}

void generarCorreos() {
    system("cls");
    printf("Sistema de Calificaciones Estudiantil\n");
    printf("------------------------------------\n");
    printf("Opcion: Generador de correos electronicos\n");

    char nombre[50], apellido[50];
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del estudiante: ");
    scanf("%s", apellido);

    printf("Correo electronico generado: %s@espe.edu.ec\n", nombre);

    printf("Pulsa una tecla para continuar...");
    _getch();
}

int main() {
    imprimirCaratula();
    printf("\n");
    printf("\n");
    printf("\npresiona Enter para continuar...");

    getchar();

    int opcion = 1;
    const int NUMERO_OPCIONES = 4;
    int opcionMateria = 1;
    char cedulaEstudiante[11];

    while (1) {
        system("cls");

        printf("*Registro de Estudiantes y Profesores*\n");
        printf("**************\n");
        printf((opcion == 1 ? "- " : "  "));
        printf("*1. Ingreso de datos del estudiante*\n");
        printf("**************\n");
        printf((opcion == 2 ? "- " : "  "));
        printf("*2. Ingreso de notas del estudiante*\n");
        printf("**************\n");
        printf((opcion == 3 ? "- " : "  "));
        printf("*3. Generador de correos electronicos*\n");
        printf("**************\n");
        printf((opcion == 4 ? "- " : "  "));
        printf("*4. Salir***********\n");

        int tecla = _getch();

        if (tecla == 224) {
            tecla = _getch();
            switch (tecla) {
                case 72:
                    opcion = (opcion > 1) ? opcion - 1 : NUMERO_OPCIONES;
                    break;
                case 80:
                    opcion = (opcion < NUMERO_OPCIONES) ? opcion + 1 : 1;
                    break;
            }
        } else if (tecla == 13) {
            switch (opcion) {
                case 1:
                    ingresarDatos();
                    break;
                case 2:
                	system ("cls");
                	printf("\n");
                    printf("Ingrese la cedula del estudiante: ");
                    scanf("%s", cedulaEstudiante);
                    ingresarNotasAsignatura(cedulaEstudiante);
                    break;
                case 3:
                    generarCorreos();
                    break;
                case 4:
                    printf("Saliendo del programa...\n");
                    return 0;
                default:
                    break;
            }
            printf("Pulsa una tecla para continuar...");
            _getch();
        }
    }

    return 0;
}
