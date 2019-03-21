/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CarritoCompra.cpp
 * Author: david
 * 
 * Created on 21 de marzo de 2019, 10:30
 */

#include "CarritoCompra.h"
#include <sstream>
#include <iostream>

CarritoCompra::CarritoCompra() {
}

CarritoCompra::CarritoCompra(const CarritoCompra& orig) {
}

CarritoCompra::~CarritoCompra() {
}

int CarritoCompra::GetNumArticulosSeleccionados() const {
    return numArticulosSeleccionados;
}

//TODO Añadir excepción para comprobar si el artículo que quiere introducir YA está en el carrito.
void CarritoCompra::addArticulo(Articulo& articulo) {

    bool articuloEnCarrito = false;

    if (numArticulosSeleccionados == MAX_ARTICULOS)
        throw std::domain_error("CarritoCompra::addArticulo, ya no caben más artículos en el carrito");
    
    for (int i = 0; i < numArticulosSeleccionados && !articuloEnCarrito; i++) {
        
        if (articulo.GetId() == articulos[i]->GetId()) {
            articulos[i]->SetCantidad(articulos[i]->GetCantidad() + 1);
            articuloEnCarrito = true;
        }
        
    }

    if (!articuloEnCarrito) {
        articulos[numArticulosSeleccionados] = &articulo;
        numArticulosSeleccionados++;
    }

}

void CarritoCompra::borrarArticulo(unsigned int cual) {

    if (cual == 0 || cual > numArticulosSeleccionados)
        throw std::out_of_range("CarritoCompra::borrarArticulo, varible 'cual' fuera de los límites: " + cual);
    
    articulos[cual-1] = nullptr;

}

Articulo& CarritoCompra::getArticulo(unsigned int cual) {

    if (cual == 0 || cual > numArticulosSeleccionados)
        throw std::out_of_range("CarritoCompra::getArticulo, varible 'cual' fuera de los límites: " + cual);
    
    return *articulos[cual-1];

}

std::string CarritoCompra::calcularPrecioFinaleIVA() const {

    std::stringstream ss;
    
    float precioSinIVA = 0, precioIVA = 0, porcentajeIVA = 0;

    for (int i = 0; i < numArticulosSeleccionados; i++) {

        precioSinIVA += articulos[i]->GetPrecio() * articulos[i]->GetCantidad();

    }

    porcentajeIVA = IVA / 100.;

    precioIVA = (precioSinIVA * porcentajeIVA) + precioSinIVA;
    
    ss << "Precio sin IVA: " << precioSinIVA << " euros" << "  " << "Precio con IVA[" << IVA << "%]: " << precioIVA 
            << " euros" << "    " <<  "Precio final: " << precioIVA << " euros";
    
    return ss.str();
}

void CarritoCompra::mostrarArticulos() {

    std::cout << "\n\n\n======================="
            << "\nArtículos comprados"
            << "\n=======================" << std::endl;

    for (int i = 0; i < numArticulosSeleccionados; i++) {

        std::cout << "ID: " << articulos[i]->GetId()
                << "\nNombre: " << articulos[i]->GetNombre()
                << "\nPrecio: " << articulos[i]->GetPrecio() << " euro(s)"
                << "\nDescripción: " << articulos[i]->GetDescripcion()
                << "\nCantidad: " << articulos[i]->GetCantidad()
                << "\n====================\n\n";

    }


}




