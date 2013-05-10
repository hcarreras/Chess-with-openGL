#include <GL/glu.h>
#include <GL/glut.h>
#include "aux-p4.hpp"
#include "materiales.hpp"



//**********************************************************************

Textura::Textura( const std::string & nombreArchivoJPG ) 
{
   
}

//----------------------------------------------------------------------

Textura::~Textura( ) 
{
   
}

//----------------------------------------------------------------------

void Textura::activar( ) 
{
   
}

//**********************************************************************

Material::Material() 
{
   iluminacion = false ;
   tex = NULL ;
   
   coloresCero() ;
}

//----------------------------------------------------------------------

Material::Material( const std::string & nombreArchivoJPG ) 
{
   iluminacion    = false ;
   tex            = new Textura( nombreArchivoJPG ) ;
   
   coloresCero();
   
   del.difusa = vectorRGB( 0.5, 0.5, 0.5 );
   tra.difusa = vectorRGB( 0.2, 0.2, 0.2 );
   
   del.especular = vectorRGB( 1.0, 1.0, 1.0 );
   tra.especular = vectorRGB( 0.2, 0.2, 0.2 );
}

//----------------------------------------------------------------------

void Material::coloresCero()
{
   const vectorRGB ceroRGB(0.0,0.0,0.0);
   
   color         = 
   
   del.emision   = 
   del.ambiente  = 
   del.difusa    = 
   del.especular = 

   tra.emision   = 
   tra.ambiente  = 
   tra.difusa    = 
   tra.especular = ceroRGB ;
   
   del.exp_brillo = 
   tra.exp_brillo = 1.0 ;
}

//----------------------------------------------------------------------

Material::~Material() 
{      
   if ( tex != NULL )
   {  delete tex ;
      tex = NULL ;
   }
}


//----------------------------------------------------------------------

void Material::activar(){
	glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR ) ;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	if(iluminacion)
		glEnable(GL_LIGHTING); // activa evaluacion del MIL

	if(tex != NULL)
		tex->activar();


}
  
//**********************************************************************

FuenteLuz::FuenteLuz( GLenum p_ind_fuente, GLfloat p_longi_ini, GLfloat p_lati_ini, const vectorRGB & p_color )
{
   assert( glGetError() == GL_NO_ERROR );
   
   // guardar el indice opengl de la fuente, y comprobar que es 
   // alguno de GL_LIGHT0, GL_LIGHT1, etc.....
   
   ind_fuente = p_ind_fuente ;
   GLenum max_num_fuentes ;
   
   glGetIntegerv( GL_MAX_LIGHTS, (GLint *) &max_num_fuentes );
   assert( GL_LIGHT0 <= ind_fuente );
   assert( ind_fuente <= GL_LIGHT0 + max_num_fuentes );
   
   // inicializar parámetros de la fuente de luz
   longi_ini = p_longi_ini ;
   lati_ini  = p_lati_ini  ;
   longi = longi_ini ;
   lati  = lati_ini ;
   

   col_ambiente[0]  = p_color.x;
   col_ambiente[1]  = p_color.y;
   col_ambiente[2]  = p_color.z;
   col_ambiente[3]  = 1.0;

   col_difuso[0]  = p_color.x;
   col_difuso[1]  = p_color.y;
   col_difuso[2]  = p_color.z;
   col_difuso[3]  = 1.0;

   col_especular[0]  = p_color.x;
   col_especular[1]  = p_color.y;
   col_especular[2]  = p_color.z;
   col_especular[3]  = 1.0;

   //col_difuso    = p_color ;
   //col_especular = p_color ;
   
   assert( glGetError() == GL_NO_ERROR );
}

//----------------------------------------------------------------------

void FuenteLuz::activar(){

	float colores[4] =  {0.0, 0.5, 0.4, 0.1};
	for(int i = 0; i < 8; i++){
		glEnable(GL_LIGHT0 + i) ;

		glLightfv(GL_LIGHT0 + i,GL_AMBIENT,col_ambiente) ;
		glLightfv(GL_LIGHT0 + i,GL_DIFFUSE, col_difuso) ; 
		glLightfv(GL_LIGHT0 + i,GL_SPECULAR,col_especular) ;


		glMatrixMode( GL_MODELVIEW ) ;
		glPushMatrix();
			glRotatef( longi, 0.0, 1.0, 0.0 ) ;
			glRotatef( lati, 1.0, 0.0, 0.0 ) ;
			glLightf(GL_LIGHT0 + i,GL_POSITION, 0.0);
		glPopMatrix() ;
	}
}

//----------------------------------------------------------------------

bool FuenteLuz::gestionarEventoTeclaEspecial( int key ) 
{
   bool actualizar = true ;
   const float incr = 3.0f ;
   
   switch( key )
   {
      case GLUT_KEY_RIGHT:
         longi = longi+incr ;
         break ;
      case GLUT_KEY_LEFT:
         longi = longi-incr ;
         break ;
      case GLUT_KEY_UP:
         lati = minim( lati+incr, 90.0) ;
         break ;
      case GLUT_KEY_DOWN:
         lati = maxim( lati-incr, -90.0 ) ;
         break ;
      case GLUT_KEY_HOME:
         lati  = lati_ini ;
         longi = longi_ini ;
         break ;
      default :
         actualizar = false ;
         cout << "tecla no usable para la fuente de luz." << endl << flush ;
   }
   
   //if ( actualizar )
   //   cout << "fuente de luz cambiada: longi == " << longi << ", lati == " << lati << endl << flush ;
   return actualizar ;
}
