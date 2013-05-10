/**
  * 
  *  interaccion.cpp
  * Archivo fuente del módulo de interacción de la practica 5
  * 
  * Informática Gráfica 
  *  3º Grado en Ingeniería Informática
  * Universidad de Granada
  * 
  *  Curso 2012/13
  *  Autor: J.C. Torres
  * 
  *  Versión 1.0
  *  Diciembre 2012
  *   
  **/
#include <GL/glut.h>
#include <iostream>
#include "interaccion.hpp"
#include "tablero.hpp"
#include <stdio.h>


extern tablero *  obj_tablero;
using namespace std;


/**
 
void clickRaton( int boton, int estado, int x, int y );

Procedimiento para gestionar los eventos de pulsacion de los botones del raton.

Argumentos:

boton: Codigo glut del boton que ha manipulado el usuario.

estado: Estado en el que esta el boton que se ha pulsado.

x,y: Posicion, en coordenadas de pantalla, en que se encuantra el cursor.

**/
/*void clickRaton( int boton, int estado, int x, int y )
{

}

*/

/**

void RatonMovido( int x, int y );

Procedimiento para gestionar los eventos de movimiento del raton.

Argumentos:

x,y: Posicion, en coordenadas de pantalla, en que se encuantra el cursor.

**/

/*void RatonMovido( int x, int y )
{

}

*/


/**
int pick(int x, int y, int modo, int * is, int * js);

    Función de selección
    
Entrada
  x,y Posición del cursor
  modo=0 selecciona casilla
  modo=1 selecciona pieza jugador 1
  modo=2 selecciona pieza jugador 2

Devuelve 
  0 si no se ha seleccionado nada
  1 cuando hay objeto seleccionado según el modo
	  
Salida
  is,js coordenadas de la celda seleccionada

**/ 

int pick(int x, int y, int modo, int * is, int * js)
{
 
}



