#include <iostream>
#include <string>

using namespace std;

class Matriz {
private:
    int filas;
    int columnas;
    int matriz[10][10];  //Arreglo bidimensional, maximo 100 numeros

public:
    Matriz(int, int);
    void suma(Matriz);
    void resta(Matriz);
    void multiplicacion(Matriz);
    void ingresarValores();
};

Matriz::Matriz(int f, int c) : filas(f), columnas(c) {}//constructor

void Matriz::suma(Matriz B) {
    if (filas != B.filas || columnas != B.columnas) {
        cout << "No se puede operar" << endl;
        return;
    }

    Matriz resultado(filas, columnas); // declaramos un objeto matriz que va a ser la matriz resultante

    for (int f = 0; f < filas; f++) { // contador hasta que no pase el numero de filas de la matriz
        for (int c = 0; c < columnas; c++) { // contador hasta que no pase el numero de columnas
            resultado.matriz[f][c] = matriz[f][c] + B.matriz[f][c]; //suma los valores de la matriz en las posiciones de filas y columnas, dependiento del contador
        }
    }

    cout << "Resultado: " << endl;
    for (int f = 0; f < filas; f++) { //ve cuantas filas tiene
        for (int c = 0; c < columnas; c++) { //cuantas columnas
            cout << resultado.matriz[f][c]; //imprime los resultados hasta que el contador de filas y columnas pare.
        }
        cout << endl;
    }
}

void Matriz::resta(Matriz B) {

}

void Matriz::multiplicacion(Matriz B) {

}

void Matriz::ingresarValores() {
    cout << "Ingrese los valores de la matriz por filas (separados por espacios):" << endl;
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            cin >> matriz[f][c]; //ingreso de datos dependiendo de filas y columnas que escribio el usuario anteroirmente.
        }
    }
}

bool validarInput(int tipoOperacion, int& filasA, int& columnasA, int& filasB, int& columnasB) {
    if (tipoOperacion == 1 || tipoOperacion == 2 || tipoOperacion == 3) {
        // Validar filas y columnas
        if (tipoOperacion == 1 || tipoOperacion == 2) {
            // Suma o resta
            if (filasA == filasB && columnasA == columnasB) {
                return true;
            }
        }
        if (tipoOperacion == 3) {
            // Multiplicación
            if (columnasA == filasB) {
                return true;
            }
        }
        cout << "No se puede operar" << endl;
    }
    else {
        cout << "Seleccione una operación válida." << endl;
    }
    return false;
}

void ingresoDeDatos() {
    int filasA, columnasA, filasB, columnasB;

    cout << "Matriz A" << endl;
    cout << "Filas: ";
    cin >> filasA;
    cout << "Columnas: ";
    cin >> columnasA;
    cout << endl;
    cout << "Matriz B" << endl;
    cout << "Filas: ";
    cin >> filasB;
    cout << "Columnas: ";
    cin >> columnasB;
    cout << endl;

    if (filasA > 10 || columnasA > 10 || filasB > 10 || columnasB > 10) {
        cout << "tiene que ser maximo 10x10" << endl;
    }
    else {
        Matriz A(filasA, columnasA);
        Matriz B(filasB, columnasB);

        cout << "Valores de Matriz A:" << endl;
        A.ingresarValores();

        cout << "Valores de Matriz B:" << endl;
        B.ingresarValores();

        int tipoOperacion;
        cout << "Seleccione una operación" << endl;
        cout << "1. Suma" << endl << "2. Resta" << endl << "3. Multiplicación" << endl;
        cin >> tipoOperacion;

        if (validarInput(tipoOperacion, filasA, columnasA, filasB, columnasB)) {
            switch (tipoOperacion) {
            case 1:
                cout << endl << "Suma" << endl;
                A.suma(B);
                break;

            case 2:
                cout << endl << "Resta" << endl;
                A.resta(B);
                break;

            case 3:
                cout << endl << "Multiplicación" << endl;
                A.multiplicacion(B);
                break;

            default:
                cout << "Ocurrió un error inesperado." << endl;
                break;
            }
        }
    }
}

int main() {
    cout << "MATRICES CON OBJETOS" << endl << endl;
    ingresoDeDatos();
    return 0;
}
