#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const int MAX_PRODUCTOS = 100;

struct Producto {
    string nombre;
    float precio;
};

int main() {
	SetConsoleOutputCP(CP_UTF8);
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    char opcion;
    do {
        cout << "\n=== SISTEMA DE INVENTARIO Y VENTAS ===" << endl;
        cout << "A: Registrar un nuevo producto" << endl;
        cout << "B: Listar los productos registrados. "<< endl; 
		cout << "C: Buscar un producto por nombre. "<< endl;
		cout << "D: Actualizar los datos de un producto. "<< endl;
		cout << "E: Eliminar un producto. "<< endl;
		cout << "F: Registrar una venta. "<< endl;
		cout << "G: Listar las ventas realizadas."<< endl;
		cout << "H: Calcular el total de ventas realizadas."<< endl;
        cout << "S: Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        if (opcion == 'A' || opcion == 'a') {
            if (cantidadProductos >= MAX_PRODUCTOS) {
                cout << "No se pueden registrar más productos. Límite alcanzado." << endl;
            } else {
                cout << "\n--- Registro de nuevo producto ---" << endl;
                cout << "Nombre del producto: ";
                getline(cin, productos[cantidadProductos].nombre);
                cout << "Precio: ";
                cin >> productos[cantidadProductos].precio;
                cin.ignore();
                cantidadProductos++;
                cout << "* Producto registrado exitosamente *" << endl;
            }
		} else if (opcion == 'B' || opcion == 'b') {
            cout << "\n--- LISTADO DE PRODUCTOS ---" << endl;

            if (cantidadProductos == 0) {
                cout << "No hay productos registrados." << endl;
            } else {
                for (int i = 0; i < cantidadProductos; i++) {
                    cout << i + 1 << ") ";
                    cout << "Nombre: " << productos[i].nombre << " | ";
                    cout << "Precio: S/ " << productos[i].precio << endl;
                }
            }
		} else if (opcion == 'C' || opcion == 'c') {
            cout << "\n--- BUSCAR PRODUCTO POR NOMBRE ---" << endl;

            if (cantidadProductos == 0) {
                cout << "No hay productos registrados." << endl;
            } else {
                string nombreBuscado;
                bool encontrado = false;

                cout << "Ingrese el nombre del producto a buscar: ";
                getline(cin, nombreBuscado);

                for (int i = 0; i < cantidadProductos; i++) {
                    if (productos[i].nombre == nombreBuscado) {
                        cout << "\nProducto encontrado:" << endl;
                        cout << "Nombre: " << productos[i].nombre << endl;
                        cout << "Precio: S/ " << productos[i].precio << endl;
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Producto no encontrado." << endl;
                }
            }
		} else if (opcion == 'D' || opcion == 'd') {
            cout << "\n--- ACTUALIZAR PRODUCTO ---" << endl;

            if (cantidadProductos == 0) {
                cout << "No hay productos registrados." << endl;
            } else {
                string nombreActualizar;
                bool encontrado = false;

                cout << "Ingrese el nombre del producto a actualizar: ";
                getline(cin, nombreActualizar);

                for (int i = 0; i < cantidadProductos; i++) {
                    if (productos[i].nombre == nombreActualizar) {
                        cout << "Producto encontrado:" << endl;
                        cout << "Nombre actual: " << productos[i].nombre << endl;
                        cout << "Precio actual: S/ " << productos[i].precio << endl;

                        cout << "\nIngrese el nuevo nombre: ";
                        getline(cin, productos[i].nombre);
                        cout << "Ingrese el nuevo precio: ";
                        cin >> productos[i].precio;
                        cin.ignore();

                        cout << "* Producto actualizado exitosamente *" << endl;
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Producto no encontrado." << endl;
                }
            }
	} else if (opcion == 'S' || opcion == 's') {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 'S' && opcion != 's');
    return 0;
}
