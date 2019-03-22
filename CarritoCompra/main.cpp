/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 21 de marzo de 2019, 10:29
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "Usuario.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int idArticulo = 1;
    
    try {
        
        Usuario david("David", "Jiménez Villarejo", "david@gmail.com");
        CarritoCompra carritoTienda;
        CarritoCompra carritoUsuario;
        Articulo aux(1);
        
        david.SetCarritoCompra(carritoUsuario);
        
        Articulo manzana("Manzana", 0.5, "Manzana reluciente y muy rica");
        Articulo libro("Libro programación Java, UML y C++", 15, "Libro para ser un maestro en las artes de la programación");
        
        carritoTienda.addArticulo(manzana);
        carritoTienda.addArticulo(libro);
        
        
        cout << "Usuario conectado: \n"
             << "\nNombre: " << david.GetNombre()
             << "\nApellidos: " << david.GetApellidos()
             << "\nE-mail: " << david.GetCorreoElectronico() << "\n\n";
        
        cout << "====================="
             << "\nArtículos disponibles"
             << "\n=====================\n" << endl;
        
        
        
        
        while(idArticulo > 0 && idArticulo <= carritoTienda.GetNumArticulosSeleccionados()) {
            
            for (int i = 1; i <= carritoTienda.GetNumArticulosSeleccionados(); i++) {
                
                aux = carritoTienda.getArticulo(i);

                cout << "ID: " << aux.GetId()//carritoTienda.getArticulo(i).GetId()
                     << "\nNombre: " << aux.GetNombre()
                     << "\nPrecio: " << aux.GetPrecio()
                     << "\nDescripción: " << aux.GetDescripcion()
                     << "\n=====================\n\n";

            }
            
            cout << "Escriba la ID de un producto para comprarlo (ID negativo o fuera de la cantidad de productos para salir): ";
            cin >> idArticulo;
            
            if(idArticulo > 0 && idArticulo <= carritoTienda.GetNumArticulosSeleccionados())
                david.GetCarritoCompra().addArticulo(carritoTienda.getArticulo(idArticulo));
            
            
        }
        
        david.GetCarritoCompra().mostrarArticulos();
        
        david.GetCarritoCompra().mostrarArticulos();
        
        cout << david.GetCarritoCompra().calcularPrecioFinaleIVA() << endl;
        
    }catch (std::domain_error& de) {
        
        std::cerr << "Error: " + std::string(de.what());
        
        
    }catch (std::out_of_range& oof) {
     
        std::cerr << "Error: " + std::string(oof.what());
        
    }catch (std::invalid_argument& ia) {
        
        std::cerr << "Error: " + std::string(ia.what());
        
    }
    
    return 0;
}

