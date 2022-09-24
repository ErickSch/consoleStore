//  Producto.h
//  Proyecto integrador
//  Created by Erick Schiller Echavarria & Erick Flores Garcia on 11/30/21.
//  Copyright C 2021 Erick Schiller Echavarria & Erick Flores Garcia. All rights deserved.
//  Descripcion: Descripci�n de la clase Producto.
#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
using namespace std;
#include <string>

class Producto{
private:
    string descripcion, proveedor, nombre;
    float precio;
public:
    Producto();
    Producto(string, float, string, string);
    string getDescripcion();
    float getPrecio();
    string getProveedor();
    string getNombre();
    void setDescripcion(string);
    void setPrecio(float);
    void setProveedor(string);
    void setNombre(string);
};


Producto::Producto(){
    descripcion = "Sin descripcion";
    precio = 0;
    proveedor = "Sin proveedor";
    nombre = "Sin nombre";
}
Producto::Producto(string descripcion, float precio, string proveedor, string nombre){
    this->descripcion=descripcion;
    this->precio=precio;
    this->proveedor=proveedor;
    this->nombre=nombre;
}
string Producto::getDescripcion(){
    return descripcion;
}
float Producto::getPrecio(){
    return precio;
}
string Producto::getProveedor(){
    return proveedor;
}
string Producto::getNombre(){
    return nombre;
}
void Producto::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}
void Producto::setPrecio(float precio){
    this->precio=precio;
}
void Producto::setProveedor(string proveedor){
    this->proveedor=proveedor;
}
void Producto::setNombre(string nombre){
    this->nombre=nombre;
}

#endif // PRODUCTO_H_INCLUDED
