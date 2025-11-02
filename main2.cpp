#include <iostream>
#include <string>

using namespace std;

class Pila {
private:
    char *arr;   // arreglo almacenar caracteres
    int tope;    // índice tope
    int tam;     // tamaño máximo pila

public:
    //Tamaño y Tope
    Pila(int n) {
        if (n < 1) n = 1;
        tam = n;
        arr = new char[tam];
        tope = -1;
    }

    //Libera memoria
    ~Pila() {
        delete[] arr;
    }

    //True si la pila está vacía
    bool estaVacia() const {
        return tope == -1;
    }

    //True si la pila está llena
    bool estaLlena() const {
        return tope == tam - 1;
    }

    //Inserta un carácter en el tope
    void apilar(char c) {
        if (!estaLlena()) {
            arr[++tope] = c;
        } else {
            cout << "Error: se intentó apilar pero la pila está llena.\n";
        }
    }

    //Elimina y devuelve el carácter del tope
    char desapilar() {
        if (!estaVacia()) {
            return arr[tope--];
        } else {
            cout << "Error: se intento desapilar pero la pila esta vacia.\n";
        }
    }
};

int main() {
    cout << "Invertir el texto usando TDA Pila\n";
    cout << "Ingrese una palabra o frase: ";
    string entrada;
    getline(cin, entrada);

    //Pila con tamaño exacto de la cadena
    Pila pila(entrada.length());

    //Apilar carácter de la cadena
    for (size_t i = 0; i < entrada.length(); ++i) {
        pila.apilar(entrada[i]);
    }

    //Reconstruir cadena invertida
    string invertida;
    while (!pila.estaVacia()) {
        char c = pila.desapilar();
        if (c != '\0') invertida.push_back(c);
    }
    cout << "\nResultado:\n";
    cout << "Cadena Original: " << entrada << "\n";
    cout << "Cadena Invertida: " << invertida << "\n";
    return 0;
}