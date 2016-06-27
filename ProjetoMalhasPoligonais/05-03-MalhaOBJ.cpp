#include "bibutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>

//#define DEBUG 1
// Vari�veis para controles de navega��o
GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini,y_ini,bot;
float transPlane = 50, rotaPlane = 0;
<<<<<<< HEAD
//nevoa
static GLint fogMode;
//valor densidade da nevoa
float densidadeNevoa = 0.0009;
=======

static int angulox = 0, anguloy = 0;
int posicaoluz = 0;
int orientacao = 1;
GLubyte * earthTex;
>>>>>>> sombra

// Apontador para objeto
OBJ *objetoWall;
OBJ *objetoTree;
OBJ *objetoFountain;
OBJ *objetoAirplane;


// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void){
    // Limpa a janela de visualiza��o com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


    /*==========OBJeTO WALL===========*/
	GLfloat luzAmbiente[4]={0.2, 0.2, 0.2,1.0};
	GLfloat luzDifusa[4]={1.0, 0.89, 0.71,1.0};	   	// "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1., 1.0};	// "brilho"
	GLfloat posicaoLuz[4]={0, 10, 100, 1.0};

    // Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT2, GL_POSITION, posicaoLuz );


	// Altera a cor do desenho para rosa
	glColor3f(0.55f, 0.45f, 0.34f);

	// Desenha o objeto 3D lido do arquivo com a cor corrente
	glPushMatrix();
    glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
    glTranslatef(0, -21, 0);

	DesenhaObjeto(objetoWall);
    glPopMatrix();

    /*==========OBJeTO TREE===========*/


	GLfloat luzAmbienteTree[4]={0.1, 0.1, 0.1,1.0};
	GLfloat luzDifusaTree[4]={0.8, 0.8, 0.8,1.0};	   	// "cor"
	GLfloat luzEspecularTree[4]={0.1, 0.1, 0.1, 0.0};	// "brilho"
	GLfloat posicaoLuzTree[4]={0.0, -158, 7.5, 1.0};

    // Capacidade de brilho do material
	GLfloat especularidadeTree[4]={2.0, 2.0, 2.0, 1.0};
	GLint especMaterialTree = 110;

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidadeTree);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterialTree);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteTree);

	// Define os par�metros da luz
	glLightfv(GL_LIGHT2, GL_AMBIENT, luzAmbienteTree); //Ka
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusaTree); //Kd
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecularTree); //Ks
	glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuzTree);



	glColor3f(0.20f, 0.80f, 0.20f);

	// Desenha o objeto 3D lido do arquivo com a cor corrente
	glPushMatrix();

    glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
    glTranslated(0, -155, -100);
    glScalef(15.0, 15.0, 15.0);
    DesenhaObjeto(objetoTree);

    glPopMatrix();


    /*==========OBJeTO FOUNTAIN===========*/


	GLfloat luzAmbienteFountain[4]={0.1,0.1,0.1,1.0};
	GLfloat luzDifusaFountain[4]={1, 0.89, 0.77,1.0};	//meio alaranjado claro
	GLfloat luzEspecularFountain[4]={0.0, 0.0, 0.0,1.0};	// "brilho"
	GLfloat posicaoLuzFountain[4]={0, -159, 251, 2.0};


	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteFountain);

	// Define os par�metros da luz
	glLightfv(GL_LIGHT3, GL_POSITION, posicaoLuzFountain);
	glLightfv(GL_LIGHT2, GL_AMBIENT, luzAmbienteFountain);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, luzDifusaFountain);
	glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecularFountain);


	glColor3f(0.82f, 0.82f, 0.82f);

	// Desenha o objeto 3D lido do arquivo com a cor corrente
	glPushMatrix();



    glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
    glTranslated(-5, -149, 150);
    glScalef(2.0f, 2.0f, 2.0f);
	DesenhaObjeto(objetoFountain);

    glPopMatrix();

	/*==========OBJeTO GRASS===========*/
/*	GLfloat luzAmbiente[4]={0.1,0.1,0.1,1.0};
	GLfloat luzDifusa[4]={0.8, 0.5, 0.8,1.0};	   	// "cor"
	GLfloat luzEspecular[4]={8.0, 5.0, 8.0, 1.0};	// "brilho"
	GLfloat posicaoLuz[4]={50.0, 25.0, 100.0, 1.0};

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );


  */  // Altera a cor do desenho para rosa
	//glColor3f(0.55f, 0.45f, 0.34f);

	// Desenha o objeto 3D lido do arquivo com a cor corrente
	glPushMatrix();

    //ativar atenua��o
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.5f);

    glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
    glTranslatef(0, -150, 0);
    glScalef(100, 0, -50);
    glColor3f(0, 0.39f, 0);

    glBindTexture(GL_TEXTURE_1D, texName);

	glutSolidCube(100);

    glPopMatrix();

    /*==========OBJeTO Airplane===========*/

	GLfloat luzAmbienteAirplane[4]={0.1, 0.1, 0.1, 1.0};
	GLfloat luzDifusaAirplane[4]={1.0,1.0,1.0,1.0};	   	// "cor"
	GLfloat luzEspecularAirplane[4]={0.0f, 0.0f, 0.0f, 1.0};	// "brilho"
	GLfloat posicaoLuzAirplane[4]={transPlane, 25, -5, 0.0};

	// Capacidade de brilho do material
	GLfloat especularidadeAirplane[4]={5.0,5.0,5.0,1.0};
	GLint especMaterialAirplane = 90;

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidadeAirplane);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterialAirplane);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteAirplane);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbienteAirplane);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusaAirplane);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecularAirplane);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuzAirplane);

    //ativar atenua��o
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.8f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.8f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.8f);


	glColor3f(0.98, 0.98, 0.98);

	// Desenha o objeto 3D lido do arquivo com a cor corrente
	glPushMatrix();

    glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);

    glScalef(5, 5, 5);
    glTranslated(transPlane, 10, -90);
    glRotatef(600, 0, 1, 0);
    glRotatef(-30, 0, 0, 1);
    glRotatef(rotaPlane, 1, 0, 0);

    DesenhaObjeto(objetoAirplane);

    glPopMatrix();

    /*==================================*/

    // Executa os comandos OpenGL
	glutSwapBuffers();

	glFlush();
}

// Fun��o usada para especificar a posi��o do observador virtual
void PosicionaObservador(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();//carrega a matriz de identidade
    gluLookAt(obsX,obsY,obsZ,//posi��o da c�mera
              0.0,1.0,0.0,//para onde a c�mera aponta
              0.0,1.0,0.0);//vetor view-up//
}

// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void){

	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva(angulo,aspecto,dnear,dfar)
	gluPerspective(angle,fAspect, 0.01, 1200);

	// Chama as fun��es que especificam os par�metros da c�mera e os par�metros de ilumina��o
	PosicionaObservador();

	//DefineIluminacao();
	Desenha();

}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	// Para previnir uma divis�o por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimens�es da viewport
	glViewport(0, 0, w, h);

	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Fun��o callback chamada para gerenciar eventos de teclas normais (ESC)
void Teclas (unsigned char tecla, int x, int y){

	if(tecla==27) {// ESC ?
		// Libera mem�ria e finaliza programa
		LiberaObjeto(objetoWall);
		LiberaObjeto(objetoTree);
		LiberaObjeto(objetoFountain);
		LiberaObjeto(objetoAirplane);
		exit(0);
	}
	if(tecla=='m'){
		if(glIsEnabled(GL_LIGHTING))
			glDisable(GL_LIGHTING);
		else
            glEnable(GL_LIGHTING);
	}
	if(tecla=='n'){
        densidadeNevoa+=0.00001;
        printf("Densidade: %f \n",densidadeNevoa);
	}
	if(tecla=='b'){
        densidadeNevoa-=0.00001;
        printf("Densidade: %f \n",densidadeNevoa);
	}
	glutPostRedisplay();
}

// Fun��o callback para tratar eventos de teclas especiais
void TeclasEspeciais (int tecla, int x, int y){
	switch (tecla)
	{
		case GLUT_KEY_HOME:	if(angle>=10)  angle -=5;
							break;
		case GLUT_KEY_END:	if(angle<=150) angle +=5;
							break;
        case GLUT_KEY_LEFT: if(transPlane>=-150) transPlane -= 1;
                            else transPlane = 50;
                            break;
        case GLUT_KEY_UP: rotaPlane -= 1;
                          break;
        case GLUT_KEY_DOWN: rotaPlane += 1;
                          break;

	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Fun��o callback para eventos de bot�es do mouse
void GerenciaMouse(int button, int state, int x, int y){

	if(state==GLUT_DOWN){
		// Salva os par�metros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}

// Fun��o callback para eventos de movimento do mouse
#define SENS_ROT	5.0
#define SENS_OBS	15.0
#define SENS_TRANSL	20.0
void GerenciaMovim(int x, int y){
	// Bot�o esquerdo
	if(bot==GLUT_LEFT_BUTTON){
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica �ngulos
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	// Bot�o direito (zoom-in e zoom-out)
	else if(bot==GLUT_RIGHT_BUTTON){
		// Calcula diferen�a
		int deltaz = y_ini - y;
		// E modifica dist�ncia do observador
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	// Bot�o do meio
	else if(bot==GLUT_MIDDLE_BUTTON){
		// Calcula diferen�as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posi��es
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}

void makeStripeImage(void){
    int j;
    for (j = 0; j < stripeImageWidth; j++){
        stripeImage[4*j] = (GLubyte) ((j<=4) ? 255 : 0);
        stripeImage[4*j+1] = (GLubyte) ((j>4) ? 255 : 0);
        stripeImage[4*j+2] = (GLubyte) 0;
        stripeImage[4*j+3] = (GLubyte) 255;
    }
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void){

	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(0.53f, 0.81f, 0.93f, 1.0f);

	///TEXTURA==========
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    makeStripeImage();


    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texName);
    glGenTextures(GL_TEXTURE_1D, texName);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0, GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    currentCoeff = xequalzero;
    currentGenMode = GL_OBJECT_LINEAR;
    currentPlane = GL_OBJECT_PLANE;

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
    glTexGenfv(GL_S, currentPlane, currentCoeff);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_1D);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);

    glMaterialf (GL_FRONT, GL_SHININESS, 64.0);
///==================



	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);
	// Habilita a luz de n�mero 0, 1, 2
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

	// Habilita o teste de pronfundidade
	glEnable(GL_DEPTH_TEST);

	// Habilita o modelo de tonaliza��o de Gouraud
	glShadeModel(GL_SMOOTH);

	// Inicializa a vari�vel que especifica o �ngulo da proje��o
	// perspectiva
	angle=75;

	// Inicializa as vari�veis usadas para alterar a posi��o do
	// observador virtual
	obsX = obsY = 100;
	obsZ = 350;

	//textura para o ch�o
	//textura da grama
    GLuint idTextura;
	glGenTextures(1, &idTextura);
	glBindTexture(GL_TEXTURE_2D, idTextura);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    FILE *file = fopen("texto-grama-1.jpg", "r");

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 660, 400, 0, GL_RGB, GL_UNSIGNED_BYTE, file);

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 13);

    //Inicializa a nevoa
       GLfloat position[] = { 0.5, 0.5, 3.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   {
      GLfloat mat[3] = {0.1745, 0.01175, 0.01175};
      glMaterialfv (GL_FRONT, GL_AMBIENT, mat);
      mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;
      glMaterialfv (GL_FRONT, GL_DIFFUSE, mat);
      mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
      glMaterialfv (GL_FRONT, GL_SPECULAR, mat);
      glMaterialf (GL_FRONT, GL_SHININESS, 0.6*128.0);
   }

   glEnable(GL_FOG);
   {
    GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};

      fogMode = GL_EXP;
      glFogi (GL_FOG_MODE, fogMode);
      glFogfv (GL_FOG_COLOR, fogColor);
      glFogf (GL_FOG_DENSITY, densidadeNevoa);
      glHint (GL_FOG_HINT, GL_DONT_CARE);
      glFogf (GL_FOG_START, 1.0);
      glFogf (GL_FOG_END, 5.0);
   }
   glClearColor(0.52, 0.51, 0.5, 1.0);  /* fog color */

	// Carrega o objeto 3D
	objetoWall = CarregaObjeto("wall.obj",true);
    objetoTree = CarregaObjeto("Pine_Tree.obj",true);
    objetoFountain = CarregaObjeto("fountain.obj",true);
    objetoAirplane = CarregaObjeto("airplane.obj", true);

    printf("Objeto carregado!");

    //=================WALL===============
	// E calcula o vetor normal em cada face
	if(objetoWall->normais){
		// Se j� existirem normais no arquivo, apaga elas
		free(objetoWall->normais);
		objetoWall->normais_por_vertice = false;
	}

	CalculaNormaisPorFace(objetoWall);

	//=================TREE===============

	if(objetoTree->normais){
		// Se j� existirem normais no arquivo, apaga elas
		free(objetoTree->normais);
		objetoTree->normais_por_vertice = false;
	}

	CalculaNormaisPorFace(objetoTree);

	//==============FOUNTAIN===============

	if(objetoFountain->normais){
		// Se j� existirem normais no arquivo, apaga elas
		free(objetoFountain->normais);
		objetoFountain->normais_por_vertice = false;
	}

	CalculaNormaisPorFace(objetoFountain);

    //==============AIRPLANE===============

	if(objetoAirplane->normais){
		// Se j� existirem normais no arquivo, apaga elas
		free(objetoAirplane->normais);
		objetoAirplane->normais_por_vertice = false;
	}

	CalculaNormaisPorFace(objetoAirplane);

}

// Programa Principal
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
	// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Especifica a posi��o inicial da janela GLUT
	glutInitWindowPosition(190,50);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(910,650);

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Parque");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);

	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a fun��o callback para tratamento das teclas normais
	glutKeyboardFunc (Teclas);

	// Registra a fun��o callback para tratamento das teclas especiais
	glutSpecialFunc (TeclasEspeciais);

	// Registra a fun��o callback para eventos de bot�es do mouse
	glutMouseFunc(GerenciaMouse);

	// Registra a fun��o callback para eventos de movimento do mouse
	glutMotionFunc(GerenciaMovim);

	// Chama a fun��o respons�vel por fazer as inicializa��es
	Inicializa();

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();

	return 0;
}
