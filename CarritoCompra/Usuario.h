/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: david
 *
 * Created on 21 de marzo de 2019, 10:30
 */

#ifndef USUARIO_H
#define USUARIO_H

#include "CarritoCompra.h"
#include <string>

class Usuario {
public:
    Usuario() = default;
    Usuario(std::string nombre, std::string apellidos, std::string correoElectronico);
    Usuario(std::string nombre, std::string apellidos, std::string correoElectronico, CarritoCompra carritoCompra);
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    void SetCarritoCompra(CarritoCompra& carritoCompra);
    CarritoCompra& GetCarritoCompra();
    void SetCorreoElectronico(std::string correoElectronico);
    std::string GetCorreoElectronico() const;
    void SetApellidos(std::string apellidos);
    std::string GetApellidos() const;
    void SetNombre(std::string nombre);
    std::string GetNombre() const;
    
    
    
private:

    std::string nombre = "---";
    std::string apellidos = "---";
    std::string correoElectronico = "---";
    CarritoCompra carritoCompra;
    
};

#endif /* USUARIO_H */

