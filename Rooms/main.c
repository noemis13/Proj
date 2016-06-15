#include "bibutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>

// Variáveis para controles de navegação
GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini,y_ini,bot;

// Apontador para objeto
OBJ *objeto;

// Função responsável pela especificação dos parâmetros de iluminação
void DefineIluminacao (void){

}
// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();//carrega a matriz de identidade
    gluLookAt(obsX,obsY,obsZ,//posição da câmera
              0.0,0.0,0.0,//para onde a câmera aponta
              0.0,1.0,0.0);//vetor view-up//
}

// Função callback de redesenho da janela de visualização
void Desenha(void){

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();//carrega a matriz de identidade
    gluLookAt(obsX,obsY,obsZ,//posição da câmera
              0.0,0.0,0.0,//para onde a câmera aponta
              0.0,1.0,0.0);//vetor view-up//
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void){

	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,dnear,dfar)
	gluPerspective(angle,fAspect,0.01,1200);

	// Chama as funções que especificam os parâmetros da câmera e os parâmetros de iluminação
	PosicionaObservador();
	/** chamar depois
	DefineIluminacao();**/

}


// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}
//------------------------------------------------------------
}
/**Implementar depois da cena pronta, o q fazer com os objetos**/
// Função callback chamada para gerenciar eventos de teclas normais (ESC)
void Teclas (unsigned char tecla, int x, int y){

// Função callback para tratar eventos de teclas especiais
void TeclasEspeciais (int tecla, int x, int y){}

// Função callback para eventos de botões do mouse
void GerenciaMouse(int button, int state, int x, int y){
}

// Função callback para eventos de movimento do mouse
#define SENS_ROT	5.0
#define SENS_OBS	15.0
#define SENS_TRANSL	20.0
void GerenciaMovim(int x, int y){}

//----------------------------------------------------------



}
// Função responsável por inicializar parâmetros e variáveis
void Inicializa (void){
	char nomeArquivo[30];

	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	// Habilita o modelo de tonalização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Inicializa a variável que especifica o ângulo da projeção
	// perspectiva
	angle=55;

	// Inicializa as variáveis usadas para alterar a posição do
	// observador virtual
	obsX = obsY = 0;
	obsZ = 100;

	// Carrega o objeto 3D
	objeto = CarregaObjeto("sala.obj", true);
    printf("Objeto carregado!");

	// E calcula o vetor normal em cada face
	if(objeto->normais){
		// Se já existirem normais no arquivo, apaga elas
		free(objeto->normais);
		objeto->normais_por_vertice = false;
	}
	CalculaNormaisPorFace(objeto);
}


int main(int argc, char *argv[]){
    glutInit(&argc, argv);
	// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Especifica a posição inicial da janela GLUT
	glutInitWindowPosition(5,5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(450,450);

	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("cena 3D");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(Desenha);

	// Registra a função callback de redimensionamento da janela de visualização
//	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a função callback para tratamento das teclas normais
//	glutKeyboardFunc(Teclas);

	// Registra a função callback para tratamento das teclas especiais
//	glutSpecialFunc(TeclasEspeciais);

	// Registra a função callback para eventos de botões do mouse
//	glutMouseFunc(GerenciaMouse);

	// Registra a função callback para eventos de movimento do mouse
//	glutMotionFunc(GerenciaMovim);

	// Chama a função responsável por fazer as inicializações
	Inicializa();

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}

