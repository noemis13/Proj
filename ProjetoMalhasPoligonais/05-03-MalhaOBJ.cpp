#include "bibutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>

//#define DEBUG 1
// Vari�veis para controles de navega��o
GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini,y_ini,bot;
float transPlane = 50;


// Apontador para objeto
OBJ *objetoWall;
OBJ *objetoTree;
OBJ *objetoFountain;
OBJ *objetoAirplane;

/*//Fun��o para abrir a imagem da grama
imagem *LoadBMP(char *nomeImagem){
    FILE *arquivo = NULL;

    arquivo = fopen(nomeImagem, "r");

    if(arquivo){
        fclose(arquivo);
        return (arquivo);
    }
}
*/

// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void){
    // Limpa a janela de visualiza��o com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


    /*==========OBJeTO WALL===========*/
	GLfloat luzAmbiente[4]={0.1,0.1,0.1,1.0};
	GLfloat luzDifusa[4]={0.8, 0.5, 0.8,1.0};	   	// "cor"
	GLfloat luzEspecular[4]={8.0, 5.0, 8.0, 1.0};	// "brilho"
	GLfloat posicaoLuz[4]={50.0, 25.0, 100.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={2.0,3.0,3.0,1.0};
	GLint especMaterial = 90;

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );


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

	GLfloat luzAmbienteTree[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusaTree[4]={0.8, 0.5, 0.8,1.0};	   	// "cor"
	GLfloat luzEspecularTree[4]={8.0, 5.0, 8.0, 1.0};	// "brilho"
	GLfloat posicaoLuzTree[4]={50.0, 25.0, 100.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidadeTree[4]={2.0,3.0,3.0,1.0};
	GLint especMaterialTree = 90;

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidadeTree);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterialTree);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteTree);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbienteTree);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusaTree);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecularTree);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuzTree);


	glColor3f(0.60f, 0.80f, 0.19f);

	// Desenha o objeto 3D lido do arquivo com a cor corrente
	glPushMatrix();

    glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
    glTranslated(-100, -94, -400);
    glScalef(130, 200, 130);
	DesenhaObjeto(objetoTree);

    glPopMatrix();


    /*==========OBJeTO FOUNTAIN===========*/

	GLfloat luzAmbienteFountain[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusaFountain[4]={0.8, 0.5, 0.8,1.0};	   	// "cor"
	GLfloat luzEspecularFountain[4]={10.0, 8.0, 10.0, 1.0};	// "brilho"
	GLfloat posicaoLuzFountain[4]={50.0, 50.0, 200.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidadeFountain[4]={2.0,3.0,3.0,1.0};
	GLint especMaterialFountain = 90;

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidadeFountain);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterialFountain);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteFountain);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbienteFountain);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusaFountain);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecularFountain);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuzFountain);


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
	/*GLfloat luzAmbiente[4]={0.1,0.1,0.1,1.0};
	GLfloat luzDifusa[4]={0.8, 0.5, 0.8,1.0};	   	// "cor"
	GLfloat luzEspecular[4]={8.0, 5.0, 8.0, 1.0};	// "brilho"
	GLfloat posicaoLuz[4]={50.0, 25.0, 100.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={2.0,3.0,3.0,1.0};
	GLint especMaterial = 90;

	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

*/
    // Altera a cor do desenho para rosa
	//glColor3f(0.55f, 0.45f, 0.34f);

	// Desenha o objeto 3D lido do arquivo com a cor corrente
	glPushMatrix();

    glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
    glTranslatef(0, -150, 0);
    glScalef(100, 0, -50);
    glColor3f(0, 0.39f, 0);

	//glTexCoord2f(1.0, 1.0);
	glutSolidCube(100);

    glPopMatrix();

    /*==========OBJeTO Airplane===========*/

	GLfloat luzAmbienteAirplane[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusaAirplane[4]={0.8, 0.5, 0.8,1.0};	   	// "cor"
	GLfloat luzEspecularAirplane[4]={8.0, 5.0, 8.0, 1.0};	// "brilho"
	GLfloat posicaoLuzAirplane[4]={50.0, 25.0, 100.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidadeAirplane[4]={2.0,3.0,3.0,1.0};
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


	glColor3f(1, 0.55f, 0);

	// Desenha o objeto 3D lido do arquivo com a cor corrente
	glPushMatrix();

    glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);

    glScalef(10, 10, 10);
    glTranslated(transPlane, 10, -50);
    glRotatef(600, 0, 1, 0);
    glRotatef(-30, 0, 0, 1);

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
        case GLUT_KEY_RIGHT: transPlane -= 1;
							 break;
        case GLUT_KEY_LEFT: transPlane += 1;
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



// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void){

	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(0.53f, 0.81f, 0.93f, 1.0f);

	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);
	// Habilita a luz de n�mero 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
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

	// Carrega o objeto 3D
	objetoWall = CarregaObjeto("wall.obj",true);
    objetoTree = CarregaObjeto("tree.obj",true);
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
	glutInitWindowPosition(50,50);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(800,600);

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
