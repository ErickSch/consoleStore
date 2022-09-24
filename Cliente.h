//  Cliente
//  Proyecto integrador
//  Created by Erick Schiller Echavarria & Erick Flores Garcia on 11/30/21.
//  Copyright C 2021 Erick Schiller Echavarria & Erick Flores Garcia. All rights deserved.
//  Descripcion: Descripci�n de la clase Cliente.
#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Carrito.h"


class Cliente
{
    public:
        Cliente();
        Cliente(string, string);
        string getNombre();
        void setNombre(string);
        string getPais();
        void setPais(string);
        Carrito carrito;
        void imprimirInfo();



    private:
        string nombre, pais;
        
};

Cliente::Cliente() {
    nombre = "Sin nombre";
    pais = "Sin pais";
    carrito = Carrito();
}
Cliente::Cliente(string nombre, string pais) {
    this->nombre = nombre;
    this->pais = pais;
    carrito = Carrito();
}
string Cliente::getNombre() {
    return nombre;
}
void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}
string Cliente::getPais() {
    return pais;
}
void Cliente::setPais(string pais) {
    this->pais = pais;
}

void Cliente::imprimirInfo(){
  cout << "Cliente: "<< nombre << endl;
  cout << "-------------\nProductos:" << endl;
  for(int i = 0; i<5; i++){
    cout << carrito.productosCarrito[i].getNombre() << endl;
  }
  cout << "-----------" << endl;
  cout << "Total: $" << carrito.getTotalPagar() << endl;
}

#endif // CLIENTE_H
