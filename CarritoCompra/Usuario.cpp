/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: david
 * 
 * Created on 21 de marzo de 2019, 10:30
 */

#include "Usuario.h"

Usuario::Usuario(std::string nombre, std::string apellidos, std::string correoElectronico):
nombre(nombre), apellidos(apellidos), correoElectronico(correoElectronico) {

}

Usuario::Usuario(std::string nombre, std::string apellidos, std::string correoElectronico, CarritoCompra carritoCompra):
nombre(nombre), apellidos(apellidos), correoElectronico(correoElectronico), carritoCompra(carritoCompra) {

}



Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
    
}

void Usuario::SetCarritoCompra(CarritoCompra& carritoCompra) {
    this->carritoCompra = carritoCompra;
}

CarritoCompra& Usuario::GetCarritoCompra() {
    return carritoCompra;
}

void Usuario::SetCorreoElectronico(std::string correoElectronico) {
    this->correoElectronico = correoElectronico;
}

std::string Usuario::GetCorreoElectronico() const {
    return correoElectronico;
}

void Usuario::SetApellidos(std::string apellidos) {
    this->apellidos = apellidos;
}

std::string Usuario::GetApellidos() const {
    return apellidos;
}

void Usuario::SetNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Usuario::GetNombre() const {
    return nombre;
}

