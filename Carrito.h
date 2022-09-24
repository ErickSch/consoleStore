//  Carrito.h
//  Proyecto integrador
//  Created by Erick Schiller Echavarria & Erick Flores Garcia on 11/30/21.
//  Copyright C 2021 Erick Schiller Echavarria & Erick Flores Garcia. All rights deserved.
//  Descripcion: Descripci�n de la clase Carrito.
#ifndef CARRITO_H
#define CARRITO_H

#include <string>
#include "Cliente.h"
#include "Producto.h"


class Carrito
{
    public:
        Carrito();
        Carrito(float, float);
        void setCostoEnvio(float);
        void sumarATotalPagar(float);
        float getCostoEnvio();
        float getTotalPagar();
        void imprimirInfo();
        Producto productosCarrito[5];


    private:
        float costoEnvio, totalPagar;
        
};

Carrito::Carrito(){
    costoEnvio = 0;
    totalPagar = 0;
    Producto productosCarrito[5];
}
Carrito::Carrito(float costoEnvio, float totalPagar){
    this->costoEnvio = costoEnvio;
    this->totalPagar = totalPagar;
    Producto productosCarrito[5];
}
void Carrito::setCostoEnvio(float costoEnvio){
    this->costoEnvio = costoEnvio;
}
void Carrito::sumarATotalPagar(float totalPagar){
    this->totalPagar += totalPagar;
}

float Carrito::getCostoEnvio(){
    return costoEnvio;
}
float Carrito::getTotalPagar(){
    return totalPagar;
}


#endif // CARRITO_H
