#include <iostream>
#include <stack>

using namespace std;

//Pila original:
void printStack(stack<int> s) {
    if (s.empty()) {
        cout << "(vacía)";
    } else {
        while (!s.empty()) {
            cout << s.top();
            s.pop();
            if (!s.empty()) cout << " ";
        }
    }
    cout << endl;
}

//Multiplica los elementos de la pila usando push y pop.
void multiplyStack(stack<int>& s, int factor) {
    stack<int> aux;

    //Paso 1: invertir orden
    while (!s.empty()) {
        aux.push(s.top());
        s.pop();
    }

    //Paso 2: orden original recuperado
    while (!aux.empty()) {
        int val = aux.top();
        aux.pop();
        s.push(val * factor);
    }
}

int main() {
    stack<int> st;
    int n;

    cout << "Multiplicacion de elementos en una Pila\n";
    cout << "Ingrese la cantidad de elementos de la pila: ";
    cin >> n;

    if (n < 0) {
        cout << "Cantidad invalida.\n";
        return 1;
    }

    cout << "Ingrese los " << n << " elementos:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cout << "Elemento " << i+1 << ": ";
        cin >> x;
        st.push(x);
    }

    cout << "\nPila original: ";
    printStack(st);

    int factor;
    cout << "Ingrese el factor para multiplicar: ";
    cin >> factor;

    multiplyStack(st, factor);

    cout << "\nPila resultante al multiplicar por " << factor << ": ";
    printStack(st);

    return 0;
}