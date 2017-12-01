#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

typedef struct InfoTerrenos{

	float x;

	float altura;
	float largura;

	//interna ou externa	
	float tipo;

}InfoT;


#include "jogador.h"
#include "inimigo.h"
#include "terreno.h"
#include "mapa.h"
#include "tiro.h"
#include "jogabilidade.h"

void DISPLAY ();
int main(int argc,char **argv);
float aleatorio_x();


int screen_size = 800;

int n = 1;
int vista = 1;

float fovy = 45.0f;
float aspect = 1.0f;
float zNear = 10.0f;
float zFar = 1000.0f;

float cx = 0;
float cy = -435;
float cz = 70;


Jogador p1 = Jogador(screen_size);
Mapa map = Mapa(screen_size);
Tiro tiro = Tiro(screen_size, p1.pos_x, p1.pos_y, p1.pos_z);
Jogabilidade jogabilidade = Jogabilidade();
float mov = 0.0f;
float mov_tiro = 0.0f;

void keypress (unsigned char key, int x, int y);
void keyup (unsigned char key, int x, int y);


void resetar(){

	map.reset();
	p1.reset();
	
}

//Loop principal do jogo para separação entre lógica utilizada e rotinas do OpenGL
void loop_jogo(){

	//Controle de teclas keypress e keyup
	glutKeyboardFunc(keypress);
	glutKeyboardUpFunc(keyup);

	p1.movimentar(mov);
	tiro.movimentar(mov_tiro, p1.pos_x, p1.pos_y, p1.pos_z);

	for(int i=0; i<map.num_inimigos; i++){

		if(p1.colidir(map.inimigos[i].pos_x, map.inimigos[i].pos_y, map.inimigos[i].largura, map.inimigos[i].altura))
			resetar();

		if(tiro.colidir(map.inimigos[i].pos_x, map.inimigos[i].pos_y, map.inimigos[i].largura, map.inimigos[i].altura)){
			map.inimigos[i].reset();
			jogabilidade.atualizar_pontuacao(map.inimigos[i].tipo_inimigo);
		}
	}

	for(int i=0; i<map.num_terrenos; i++){

		if(p1.colidir(
				-(map.terrenos[i].tipo*map.limite) + map.terrenos[i].pos_x,
				 map.terrenos[i].pos_y,
				 map.terrenos[i].largura,
				 map.terrenos[i].altura))
			resetar();

		if(p1.colidir(
				(map.terrenos[i].tipo*map.limite) - map.terrenos[i].pos_x,
				 map.terrenos[i].pos_y,
				 map.terrenos[i].largura,
				 map.terrenos[i].altura))
			resetar();
	}

	if(p1.colidir(
				 map.limite - map.largura_minima,
				 0,
				 map.largura_minima,
				 map.limite))
			resetar();

	if(p1.colidir(
			 - map.limite + map.largura_minima,
			 0,
			 map.largura_minima,
			 map.limite))
		resetar();

	jogabilidade.desenhar_display();
	jogabilidade.atualizar_combustivel();

	map.atualizar();

}

//Função Display padrão do OpenGL
void DISPLAY (){

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);


	glEnable(GL_SMOOTH);
	glEnable(GL_BLEND);

	glClearColor(0.5, 0.5, 0.5, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Camera
	if (vista){ // posição da câmera na vista superior
		glOrtho(-screen_size/2, screen_size/2, -screen_size/2, screen_size/2, -screen_size/2, screen_size/2);
		gluLookAt( 0, 0, 50, 0, 0, 0, 0, 1, 0);
	} else{
		gluPerspective(fovy,aspect,zNear,zFar);
		gluLookAt( p1.pos_x, cy, cz, p1.pos_x, 0, 0, 0, 0, 1);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Chamada para a separação do Loop do jogo
	loop_jogo();

    glutSwapBuffers();

}

int main(int argc,char **argv){

	srand(time(NULL));

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screen_size, screen_size);
	glutInitWindowPosition(100,100);
	glutCreateWindow("River Raid");
	glutDisplayFunc(DISPLAY);
	glutMainLoop();
	return 0;
}

//Key press utilizado para iniciar a ação do jogador
void keypress (unsigned char key, int x, int y){

	switch(key){
		case 'd':
			mov = p1.velocidade;
			p1.movimentando = 1;
		break;

		case 'a':
			mov = -p1.velocidade;
			p1.movimentando = -1;
		break;

		case 'p':
			if(map.velocidade == 0.0f)
				map.velocidade = -3.0f;
			else
				map.velocidade = 0.0f;
		break;

		case 32:
			mov_tiro = tiro.velocidade;
			tiro.movimentando = 1;
			tiro.atirou = 1;
		break;

		case 'c':
			if (vista) {
				vista = 0;
				jogabilidade.vista = 0;
			} else {
				vista = 1;
				jogabilidade.vista = 1;
			}
		break;

		case 'u':
			cx+=1.0f;
			break;
		case 'j':
			cx-=1.0f;
			break;

		case 'i':
			cy+=1.0f;
			break;
		case 'k':
			cy-=1.0f;
			break;

		case 'o':
			cz+=1.0f;
			break;
		case 'l':
			cz-=1.0f;
			break;
		
		case 'm':
			printf("x: %f, y: %f, z: %f\n", cx, cy, cz);
		break;

		case 27:
			exit(0);
		break;

	}

	glutPostRedisplay();
}

//Key up utilizado para encerrar uma ação iniciada pelo jogador
void keyup (unsigned char key, int x, int y) {

	switch(key){

		case 'd':
			p1.movimentando = 0;
			mov = 0.0f;
		break;

		case 'a':
			p1.movimentando = 0;
			mov = 0.0f;
		break;

	}

	glutPostRedisplay();

}

