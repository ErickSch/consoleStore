//  main.cpp
//  Proyecto integrador
//  Created by Erick Schiller Echavarria & Erick Flores Garciaon 11/30/21.
//  Copyright C 2021 Erick Schiller Echavarria & Erick Flores Garcia. All rights deserved.
//  Descripcion: Tienda de Ecommerce.

// Compilación:
// g++ -std=c++17 *.cpp -Wall -o main 


#include <iostream>
#include <string>
#include "Cliente.h"
#include "Producto.h"


using namespace std;

int main()
{
    int cantProductos = 5;
    int cantClientes = 5;
    Producto productos[cantProductos];
    Cliente clientes[cantClientes];

    int numInterfaz;
    do
    {
        cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n"
        "1) Dar de alta el inventario\n"
        "2) Mostrar inventario\n"
        "3) Alta clientes\n"
        "4) Mostrar clientes\n"
        "5) Venta directa\n"
        "6) Mostrar carrito de cliente\n"
        "7) Salir\n"
        "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW \n"<< endl;
        cout << "Seleccione una accion: ";
        cin >> numInterfaz;
        switch (numInterfaz)
        {
        case 1:
            {
                string repetir, descripcionProducto, proveedor, nombreProducto;
                float precioProducto;

                do
                {
                    int length = 0;
                    for (int i = 0; i < cantProductos; i++){
                        if (productos[i].getNombre() != "Sin nombre"){
                            length++;
                        }
                    }
                    cout << "Ingrese nombre del producto: ";
                    cin.ignore(1, '/n'); // Esta linea es para que el getline() de abajo obtenga el valor del usuario, si no nombreProducto da igual a \n (enter)
                    getline(cin, nombreProducto);
                    productos[length].setNombre(nombreProducto);

                    cout << "Ingrese descripcion del producto: ";
                    getline(cin, descripcionProducto);
                    productos[length].setDescripcion(descripcionProducto);

                    cout << "Ingrese proveedor del producto: ";
                    //cin.ignore(1, '\n');
                    getline(cin, proveedor);
                    productos[length].setProveedor(proveedor);

                    cout << "Ingrese precio del producto: ";
                    cin >> precioProducto;
                    productos[length].setPrecio(precioProducto);

                    cout << "Producto dado de alta exitosamente!!" << endl;
                    cout << "Desea continuar con otro producto? (si/no): ";
                    cin >> repetir;
                } while (repetir != "no");
            }

        break;

        case 2:
            {
                int length = 0;
                for (int i = 0; i < cantProductos; i++){
                    if (productos[i].getNombre() != "Sin nombre"){
                        length++;
                    }
                }
                cout << "__________________________" << endl;
                cout << "INVENTARIO" << endl;
                if (length == 0){
                    cout << "Inventario vacio";
                }
                else{
                    for(int n = 0; n < length; n++){
                        int num = n + 1;
                        cout << "----------" << endl;
                        cout << "   Producto " << num << endl;
                        cout << "       Nombre: " << productos[n].getNombre() << endl;
                        cout << "       Descripcion: " << productos[n].getDescripcion() << endl;
                        cout << "       Proveedor: " << productos[n].getProveedor() << endl;
                        cout << "       Precio: " << productos[n].getPrecio() << endl;
                    }
                }
                cout << "__________________________" << endl;
            }
        break;

        case 3:
            {
                string repetir, nombreCliente, paisCliente;
                do {
                    int length = 0;
                    for (int i = 0; i < cantClientes; i++){
                        if (clientes[i].getNombre() != "Sin nombre"){
                            length++;
                        }
                    }
                    cout << "Ingresa nombre de cliente: ";
                    cin.ignore(1, '\n');
                    getline(cin, nombreCliente);
                    clientes[length].setNombre(nombreCliente);

                    cout << "Ingresa pais de origen: ";
                    cin >> paisCliente;
                    clientes[length].setPais(paisCliente);

                    cout << "Cliente dado de alta extosamente!!" << endl;
                    cout << "Nombre del cliente: " << clientes[length].getNombre() << endl;

                    if (length == 0){
                        ;
                    }
                    else{
                        cout << "Nombre del primer cliente: " << clientes[0].getNombre() << endl;
                    }
                    cout << "Desea continuar con otro cliente? (si/no): ";
                    cin >> repetir;
                } while (repetir != "no");

            }
        break;

        case 4:
            {
                int length = 0;
                for (int i = 0; i < cantClientes; i++){
                    if (clientes[i].getNombre() != "Sin nombre"){
                        length++;
                    }
                }

                cout << "__________________________" << endl;
                cout << "CLIENTES" << endl;
                if (length == 0){
                    cout << "No existen clientes";
                }
                else{
                    for(int n = 0; n < length; n++){
                        int num = n + 1;
                        cout << "----------" << endl;
                        cout << "   Cliente " << num << endl;
                        cout << "       Nombre: " << clientes[n].getNombre() << endl;
                        cout << "       Pais de origen: " << clientes[n].getPais() << endl;
                    }
                }
                cout << "__________________________" << endl;
            }
        break;

        case 5:
            {
                string repetir, nombreCliente, nombreProducto;
                do{
                    bool verificarCliente = false;
                    do{
                        cout << "Ingrese el nombre del Cliente:";
                        cin >> nombreCliente;
                        for (int n = 0; n < cantClientes; n++){
                            if (nombreCliente == clientes[n].getNombre()){
                                verificarCliente = true;
                                bool verificarProducto = false;
                                int length = 0;
                                 for (int m = 0; m < cantProductos; m++){
                                  if (clientes[n].carrito.productosCarrito[m].getNombre() != "Sin nombre"){
                                        length++;
                                  }
                                 }
                                do{
                                    cout << "Ingrese el nombre del Producto:";
                                    cin >> nombreProducto;
                                    
                                    for (int i = 0; i < cantProductos; i++){
                                        if (nombreProducto == productos[i].getNombre()){
                                            verificarProducto = true;

                                            clientes[n].carrito.productosCarrito[length] = productos[i];
                                        }
                                        if (verificarCliente == false){
                                            cout << "Error: El cliente no existe" << endl;
                                        }
                                    
                                    }
                                }while (verificarProducto == false);
                        }
                        }
                          
                    }while(verificarCliente == false);
                    cout << "Vendido el producto " << nombreProducto<< " a " << nombreCliente << endl;
                    

                    cout << "Desea realizar otra venta directa? (si/no): ";
                    cin >> repetir;
                }while (repetir != "no");

            }
        break;
        case 6:
          {
          string cliente;
          int length = 0;
          cout << "Nombre de cliente del carrito: ";
          cin >> cliente;
          
            for(int i = 0; i<cantClientes; i++){
              if(clientes[i].getNombre() == cliente){
                            
              for (int n = 0; n < cantProductos; n++){
                if (clientes[i].carrito.productosCarrito[n].getNombre() != "Sin nombre"){
                  length++;
                }
              }
                
              for(int n = 0; n<length; n++){
                cout << "---------\nProducto:" << clientes[i].carrito.productosCarrito[n].getNombre() << endl;
                cout << "Precio:" << clientes[i].carrito.productosCarrito[n].getPrecio()<< "\n--------" << endl;
                clientes[i].carrito.sumarATotalPagar(clientes[i].carrito.productosCarrito[n].getPrecio());
                
              }
              cout << "Total: " << clientes[i].carrito.getTotalPagar() << endl;
              }
            }
            
          }
        break;
        case 7:
          {
            return 0;
          }
        break;
          
        default:
            cout << "ERROR: El valor ingresado no es una opcion";
        }

    } while (numInterfaz != 7);

    return 0;
}
