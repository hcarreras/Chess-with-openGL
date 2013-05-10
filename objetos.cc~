//**************************************************************************
// Práctica 2
// Primitivas básicas para construir elementos sencillos que sirvan como 
// base para construir objetos más complejos por instanciación y jerarquías.
//
// Domingo Martin Perandres 2005-2012
// Pedro Cano Olivares 2012-2013
//          - Incluido estructuras y ejemplo de creacion de objeto jerárquico 
//          - Incluido control de animación
//
// GPL
//**************************************************************************

#include "objetos.h"
#include "estructuras.h"
#include "math.h"

#define amarillo 0
#define gris 1
#define rojo 2
#define	marron 3
#define celeste 4
#define marron2 5
#define verde 6
#define azul 7

/** Definicion de los colores usados.**/
float color[8][4]={{1,.8,.3,1.},{0.7,0.7,0.7,1},{1.0,0.0,0.0,1},
   		   {0.7,0.6,0.2,1},{0.2,1.0,1.0,1},{1.0,0.86,0.3,1},
		   {0.0,1.0,0.0,1.0}, {0.0,0.0,1.0,1.0}};


//*************************************************************************
// _object3D
//*************************************************************************
//*************************************************************************
//
//*************************************************************************

_object3D::_object3D()
{


Point_size=POINT_SIZE;
Line_width=LINE_WIDTH;
}

//*************************************************************************
//
//*************************************************************************

void _object3D::draw()
{

}


//*************************************************************************
// car
//*************************************************************************
//*************************************************************************
//
//*************************************************************************

_car::_car()
{
	giro_ruedas=0;
}

//*************************************************************************
//
//*************************************************************************

void _car::draw()
{
GLfloat Light_position[4]={5.0, 5.0, 10.0, 0.0};
GLfloat Ambient_component[4]={0.4,0.4,0.4,1};

glEnable(GL_CULL_FACE);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambient_component);
glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);

glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glLoadIdentity();
glLightfv(GL_LIGHT0,GL_POSITION,Light_position);
glPopMatrix();
glShadeModel(GL_FLAT);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

glPushMatrix(); 
	glScalef(2,2,2);
	
	glPushMatrix();
	glScalef(1,.5,2);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[rojo]);
	caja(1,1,1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,.5,-.2);
	glScalef(.8,.5,.8);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[verde]);
	caja(1,1,1);
	glPopMatrix();

	// ahora las ruedas
	// delantera izquierda
	glPushMatrix();
	glTranslatef(.4,0,.65);
	glRotatef(giro_ruedas,0,1,0);
	glColor3f(0,0,1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[azul]);
	glRotatef(-90,0,0,1);
	cilindrof(0,0,0,0,.15,0,.2,10); 
	glPopMatrix();

	// delantera derecha
	glPushMatrix();
	glTranslatef(-.4,0,.65);
	glRotatef(giro_ruedas,0,1,0);
	glColor3f(0,0,1);
	glRotatef(90,0,0,1);
	cilindrof(0,0,0,0,.15,0,.2,10); 
	glPopMatrix();

	// trasera izquierda
	glPushMatrix();
	glTranslatef(.4,0,-.65);
	glColor3f(0,0,1);
	glRotatef(-90,0,0,1);
	cilindrof(0,0,0,0,.15,0,.2,10); 
	glPopMatrix();

	// trasera derecha
	glPushMatrix();
	glTranslatef(-.4,0,-.65);
	glColor3f(0,0,1);
	glRotatef(90,0,0,1);
	cilindrof(0,0,0,0,.15,0,.2,10); 
	glPopMatrix();

	// ahora los focos
	glPushMatrix();
	glTranslatef(.35,.25,1.1);
	glRotatef(-90,1,0,0);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[amarillo]);
	conof(0,0,0,0,.25,0,.1,10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.35,.25,1.1);
	glRotatef(-90,1,0,0);
	glColor3f(0,1,1);
	conof(0,0,0,0,.25,0,.1,10);
	glPopMatrix();

glPopMatrix();
}

//*************************************************************************

void _car::ruedas_right()
{
	giro_ruedas-=1;
}

//*************************************************************************

void _car::ruedas_left()
{
	giro_ruedas+=1;
}

//*************************************************************************

void _car::ruedas_stop()
{
	giro_ruedas=0;
}

//*************************************************************************

void _car::control_animacion()
{
    if(giro_ruedas>30) giro_ruedas =30;
    if(giro_ruedas<-30) giro_ruedas = -30;
}

void _man::draw(){
	static GLUquadric *ojo = gluNewQuadric() ;


	GLfloat Light_position[4]={5.0, 5.0, 10.0, 0.0};
	GLfloat Ambient_component[4]={0.4,0.4,0.4,1};

	glEnable(GL_CULL_FACE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambient_component);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glLightfv(GL_LIGHT0,GL_POSITION,Light_position);
	glPopMatrix();
	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);




	//cadera	
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[azul]);	
	caja(2,1,1);
	glRotatef(giro_torso,0,1,0);

	glPushMatrix();
		//torso
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[verde]);
		glTranslatef(0,1,0);
		caja(2,4,1);

		//Brazos
		glPushMatrix();
			glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[marron2]);
			glTranslatef(0,3,0);
			glRotatef(180,1,0,0);
			glRotatef(giro_brazos,1,0,0);
			glPushMatrix();
				glTranslatef(-1.5,0,0);
				caja(1,2,1);
				glPushMatrix();
					glTranslatef(0,1,0);
					glTranslatef(0,saca_brazos,0);
					caja(1,1,1);
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(1.5,0,0);
				caja(1,2,1);
				glPushMatrix();
					glTranslatef(0,1,0);
					glTranslatef(0,saca_brazos,0);
					caja(1,1,1);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	

		//Cabeza

		glPushMatrix();
			glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[rojo]);
			glTranslatef(0,4,0);
			glRotatef(giro_cabeza, 1, 0, 0);
			caja(1,0.75,0.75);
			glPushMatrix();
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[marron]);
				glTranslatef(0,0.5,0.5);
				//ojos
				glPushMatrix();
					glTranslatef(0.25, 0, 0);
					gluSphere(ojo, 0.15,30,30);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-0.25, 0, 0);
					gluSphere(ojo, 0.15,30,30);
				glPopMatrix();
			
			glPopMatrix();
		glPopMatrix();		
	glPopMatrix();


/*
	glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[marron2]);
		caja(2,1,1);
		glPushMatrix();
			glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[marron]);
			glTranslatef(0,1,0);
			caja(2,4,1);
		glPopMatrix();
	glPopMatrix();*/

}


void _man::brazosArriba(){
	giro_brazos-=1;
}



void _man::brazosAbajo(){
	giro_brazos+=1;
}

void _man::cabezaIzq(){
	giro_cabeza+=1;
}


void _man::cabezaDer(){
	giro_cabeza-=1;
}

void _man::torsoIzq(){
	giro_torso+=1;
}


void _man::torsoDer(){
	giro_torso-=1;
}

void _man::sacaBrazos(){
	saca_brazos+=0.1;
}
void _man::meteBrazos(){
	saca_brazos-=0.1;
}
void _man::control_animacion()
{
    if(giro_brazos > 50) giro_brazos = 50;
    if(giro_brazos < -200) giro_brazos = -200;
    if(giro_cabeza > 50) giro_cabeza = 50;
    if(giro_cabeza < -50) giro_cabeza = -50;
    if(giro_torso > 50) giro_torso = 50;
    if(giro_torso < -50) giro_torso = -50;
	if(saca_brazos < -1) saca_brazos = -1;
	if(saca_brazos > 1) saca_brazos = 1;


}
