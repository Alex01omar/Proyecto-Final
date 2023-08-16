#include <iostream>
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
        cout << "\nIngrese el número de cédula: ";
        cin >> entrada;

        valido = 1;
        for (size_t i = 0; i < entrada.length(); i++) {
            if (!isdigit(entrada[i])) {
                cout << "Error: Ingrese solo números. Inténtelo nuevamente." << endl;
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
        cout << "\nCédula inválida, por favor vuelva a ingresar." << endl;
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
                cout << "\nCédula incorrecta, por favor ingrésela nuevamente." << endl;
            }
        } while (cedu > 3059999999 || cedu < 1000000000 || ddig == 25 || ddig == 26 || ddig == 27 || ddig == 28 || ddig == 29);
        veri = validar_cedula(cedu, cedula);
    } while (veri != 1);

    return 0;
}
