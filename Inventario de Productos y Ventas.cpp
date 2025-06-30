#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const int MAX_PRODUCTOS = 100;
const int MAX_VENTAS = 100;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

int main() {
	SetConsoleOutputCP(CP_UTF8);
    Producto productos[MAX_PRODUCTOS];
    Venta ventas[MAX_VENTAS];
    int cantidadVentas = 0;
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
	} else if (opcion == 'F' || opcion == 'f') {
            cout << "\n--- REGISTRAR VENTA ---" << endl;

            if (cantidadProductos == 0) {
                cout << "No hay productos registrados para vender." << endl;
            } else if (cantidadVentas >= MAX_VENTAS) {
                cout << "No se pueden registrar más ventas. Límite alcanzado." << endl;
            } else {
                string nombreProducto;
                bool encontrado = false;
                int cantidadVendida;
                float precioUnitario = 0.0;

                cout << "Ingrese el nombre del producto vendido: ";
                getline(cin, nombreProducto);

                for (int i = 0; i < cantidadProductos; i++) {
                    if (productos[i].nombre == nombreProducto) {
                        encontrado = true;
                        precioUnitario = productos[i].precio;

                        cout << "Ingrese la cantidad vendida: ";
                        cin >> cantidadVendida;
                        cin.ignore();

                        ventas[cantidadVentas].idVenta = cantidadVentas + 1;
                        ventas[cantidadVentas].producto = nombreProducto;
                        ventas[cantidadVentas].cantidad = cantidadVendida;
                        ventas[cantidadVentas].precioTotal = precioUnitario * cantidadVendida;

                        cantidadVentas++;

                        cout << "* Venta registrada correctamente *" << endl;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Producto no encontrado. No se puede registrar la venta." << endl;
                }
            }
	} else if (opcion == 'E' || opcion == 'e') {
            cout << "\n--- ELIMINAR PRODUCTO ---" << endl;
            if (cantidadProductos == 0) {
                cout << "No hay productos registrados." << endl;
            } else {
                string nombreEliminar;
                bool eliminado = false;

                cout << "Ingrese el nombre del producto a eliminar: ";
                getline(cin, nombreEliminar);

                for (int i = 0; i < cantidadProductos; i++) {
                    if (productos[i].nombre == nombreEliminar) {
                        // Mover los siguientes productos una posición hacia arriba
                        for (int j = i; j < cantidadProductos - 1; j++) {
                            productos[j] = productos[j + 1];
                        }
                        cantidadProductos--;
                        eliminado = true;
                        cout << "* Producto eliminado correctamente *" << endl;
                        break;
                    }
                }
                if (!eliminado) {
                    cout << "Producto no encontrado." << endl;
                }
            }
		} else if (opcion == 'F' || opcion == 'f') {
            cout << "\n--- REGISTRAR VENTA ---" << endl;
            if (cantidadProductos == 0) {
                cout << "No hay productos registrados para vender." << endl;
            } else if (cantidadVentas >= MAX_VENTAS) {
                cout << "No se pueden registrar más ventas. Límite alcanzado." << endl;
            } else {
                string nombreProducto;
                bool encontrado = false;
                int cantidadVendida;
                float precioUnitario = 0.0;
                cout << "Ingrese el nombre del producto vendido: ";
                getline(cin, nombreProducto);
                for (int i = 0; i < cantidadProductos; i++) {
                    if (productos[i].nombre == nombreProducto) {
                        encontrado = true;
                        precioUnitario = productos[i].precio;
                        cout << "Ingrese la cantidad vendida: ";
                        cin >> cantidadVendida;
                        cin.ignore();
                        ventas[cantidadVentas].idVenta = cantidadVentas + 1;
                        ventas[cantidadVentas].producto = nombreProducto;
                        ventas[cantidadVentas].cantidad = cantidadVendida;
                        ventas[cantidadVentas].precioTotal = precioUnitario * cantidadVendida;
                        cantidadVentas++;
                        cout << "* Venta registrada correctamente *" << endl;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Producto no encontrado. No se puede registrar la venta." << endl;
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
