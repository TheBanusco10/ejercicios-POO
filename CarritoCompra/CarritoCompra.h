/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CarritoCompra.h
 * Author: david
 *
 * Created on 21 de marzo de 2019, 10:30
 */

#ifndef CARRITOCOMPRA_H
#define CARRITOCOMPRA_H

#include "Articulo.h"
#include <stdexcept>

class CarritoCompra {
public:
    CarritoCompra();
    CarritoCompra(const CarritoCompra& orig);
    virtual ~CarritoCompra();
    
    static const int MAX_ARTICULOS = 10;
    static const int IVA = 4;
    
    int GetNumArticulosSeleccionados() const;
    void addArticulo(Articulo& articulo);
    void borrarArticulo(unsigned int cual);
    Articulo& getArticulo(unsigned int cual);
    std::string calcularPrecioFinaleIVA() const;
    void mostrarArticulos();
    void reducirNumArticulos(int idArticulo, unsigned int cuantos);
    
private:

    Articulo* articulos[MAX_ARTICULOS];
    int numArticulosSeleccionados = 0;
    
};

#endif /* CARRITOCOMPRA_H */

