/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Articulo.h
 * Author: david
 *
 * Created on 21 de marzo de 2019, 10:30
 */

#ifndef ARTICULO_H
#define ARTICULO_H

#include <string>

class Articulo {
public:
    Articulo();
    Articulo(std::string nombre, float precio, std::string descripcion);
    Articulo(bool auxiliar);
    Articulo(const Articulo& orig);
    virtual ~Articulo();
    void SetDescripcion(std::string descripcion);
    std::string GetDescripcion() const;
    void SetPrecio(float precio);
    float GetPrecio() const;
    void SetNombre(std::string nombre);
    std::string GetNombre() const;
    int GetId() const;
    int GetCantidad() const;
    void SetCantidad(int cantidad);
    Articulo& operator=(Articulo& otro);
    
    
    static int ID;
    
    
    
private:

    int id;
    std::string nombre = "---";
    float precio = 10;
    std::string descripcion = "Artículo listo para comprar";
    int cantidad = 1;
    bool auxiliar = false;

};

#endif /* ARTICULO_H */

