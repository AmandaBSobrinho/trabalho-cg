#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "jogador.h"
#include "inimigo.h"
#include "mapa.h"
#include "tiro.h"
#include "jogabilidade.h"

void DISPLAY ();
int main(int argc,char **argv);
float aleatorio_x();


int screen_size = 600;
int n = 1;
Inimigo t[1];
Jogador p1 = Jogador(screen_size);
Mapa map = Mapa(screen_size);
Tiro tiro = Tiro(screen_size, p1.pos_x, p1.pos_y, p1.pos_z);
Jogabilidade jogabilidade = Jogabilidade();
float mov = 0.0f;
float mov_tiro = 0.0f;

void keypress (unsigned char key, int x, int y);
void keyup (unsigned char key, int x, int y);


//Loop principal do jogo para separação entre lógica utilizada e rotinas do OpenGL
void loop_jogo(){

	//Controle de teclas keypress e keyup
	glutKeyboardFunc(keypress);
	glutKeyboardUpFunc(keyup);

	p1.movimentar(mov);
	tiro.movimentar(mov_tiro, p1.pos_x, p1.pos_y, p1.pos_z);

	for(int i=0; i<n; i++){
		t[i].movimentar(map.velocidade);

		if(p1.colidir(t[i].pos_x, t[i].pos_y, t[i].largura, t[i].altura)){
			t[i].reset();
			jogabilidade.atualizar_pontuacao(t[i].tipo_inimigo);
		}

		if(tiro.colidir(t[i].pos_x, t[i].pos_y, t[i].largura, t[i].altura)){
			t[i].reset();
			jogabilidade.atualizar_pontuacao(t[i].tipo_inimigo);
		}
	}

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

	glClearColor(0.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    glOrtho(-screen_size/2, screen_size/2, -screen_size/2, screen_size/2, -screen_size/2, screen_size/2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Camera
	gluLookAt( 0, 0, 3, 0, 0, 0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Chamada para a separação do Loop do jogo
	loop_jogo();

    glutSwapBuffers();

}

int main(int argc,char **argv){

	srand(time(NULL));

	for(int i=0; i<n; i++)
		t[i] = Inimigo(screen_size);

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screen_size, screen_size);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Attack!!!!");
	glutDisplayFunc(DISPLAY);
	glutMainLoop();
	return 0;
}

//Key press utilizado para iniciar a ação do jogador
void keypress (unsigned char key, int x, int y){

	if (key=='d'){
		mov = p1.velocidade;
		p1.movimentando = 1;
	}
	else if (key=='a'){

		mov = -p1.velocidade;
		p1.movimentando = -1;

	}
	else if (key==32) {
		mov_tiro = tiro.velocidade;
		tiro.movimentando = 1;
		tiro.atirou = 1;
	}

	else if (key==27){ exit(0); }

	glutPostRedisplay();
}

//Key up utilizado para encerrar uma ação iniciada pelo jogador
void keyup (unsigned char key, int x, int y) {

	if(key=='d' || key=='a'){
		p1.movimentando = 0;
		mov = 0.0f;
	}

	glutPostRedisplay();

}

