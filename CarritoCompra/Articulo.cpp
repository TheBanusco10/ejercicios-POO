/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Articulo.cpp
 * Author: david
 * 
 * Created on 21 de marzo de 2019, 10:30
 */

#include <stdexcept>

#include "Articulo.h"

int Articulo::ID(0);

Articulo::Articulo() {
    
    ID++;
    id = ID;
    
}

//TODO Añadir excepción para el precio
Articulo::Articulo(std::string nombre, float precio, std::string descripcion): nombre(nombre), precio(precio), descripcion(descripcion) {

    if(precio <= 0)
        throw std::invalid_argument("Articulo::Articulo, precio <= 0: " + nombre);
    
    ID++;
    id = ID;
    
}

Articulo::Articulo(bool auxiliar): auxiliar(auxiliar) {
    
}

Articulo::Articulo(const Articulo& orig) {
}

Articulo::~Articulo() {
}

void Articulo::SetDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

std::string Articulo::GetDescripcion() const {
    return descripcion;
}

void Articulo::SetPrecio(float precio) {
    this->precio = precio;
}

float Articulo::GetPrecio() const {
    return precio;
}

void Articulo::SetNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Articulo::GetNombre() const {
    return nombre;
}

int Articulo::GetId() const {
    return id;
}

int Articulo::GetCantidad() const {
    return cantidad;
}

void Articulo::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

Articulo& Articulo::operator=(Articulo& otro) {

    if (this != &otro) {
        
        this->id = otro.id;
        this->nombre = otro.nombre;
        this->descripcion = otro.descripcion;
        this->precio = otro.precio;
        this->cantidad = otro.cantidad;
    
    }

}

