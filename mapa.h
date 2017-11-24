//tiles (x,y) = (120,75)
//tile minimo = (120, 25)


typedef struct Tiles{
	float pos_x;
	float pos_y;
	float escala = 8.0f;
	float escala2 = 6.0f;
	//Tipos:
	//0- Manter
	//1- Aumentar Terreno
	//2- Diminuir Terreno
	int tipo;
	int qnt_largura;
	int qnt_altura;

}TTiles;

class Mapa{
	
	public:
	//Limite da tela utilizada
	float limite;

	//velocidade de movimentação do mapa em Y
	float velocidade;

	//Largura e altura de cada tile do terreno
	float largura;
	float altura;
	int qnt_tiles;

	int test;

	TTiles terreno[8];

	Mapa(int s){

		limite = s/2;
		qnt_tiles = 8;

		largura = limite/10;
		altura = limite/3;

		largura /= 2;
		altura /= 2;

		velocidade = -3.3f;

		for(int i = 0; i< qnt_tiles; i++){
			terreno[i].tipo = 0;
			terreno[i].qnt_largura = 1;
			terreno[i].qnt_altura = -1+i;
			terreno[i].pos_x = limite - (terreno[i].qnt_largura * largura);
			terreno[i].pos_y = limite - (terreno[i].qnt_altura * 2 * altura) + altura;

		}

	}

	void atualizar(){

		for(int i = 0; i< qnt_tiles; i++){
			terreno[i].pos_y += velocidade;
		}

		for(int i = 0; i< qnt_tiles; i++){

			if(terreno[i].pos_y < -(qnt_tiles * altura)){

				if(i == qnt_tiles-1){
					terreno[i].pos_y = terreno[0].pos_y + 2*altura;
				}else{
					terreno[i].pos_y = terreno[i+1].pos_y + 2*altura;
				}

				test = (int)aleatorio(11,0,1.0f);
				terreno[i].qnt_largura = test;

			}

		}

		desenhar();
		glutPostRedisplay();
	}

	//Função para gerar um número aleatorio baseado em 3 parametros
	float aleatorio(int a, int b, float c){
		return (float) ((rand() % a + 1) - b  )*c;
	}

	void desenhar(){

		int z_terreno = 0;


		for(int i = 0; i<qnt_tiles; i++){

			glColor3ub(0,100,0);

			glPushMatrix();
			glTranslatef(terreno[i].pos_x, terreno[i].pos_y,0);
			
			glBegin(GL_POLYGON); 
			glVertex3f(-(terreno[i].qnt_largura * largura), (altura), z_terreno);
			glVertex3f(-(terreno[i].qnt_largura * largura),-(altura), z_terreno);
			glVertex3f((terreno[i].qnt_largura * largura),-(altura), z_terreno);
			glVertex3f((terreno[i].qnt_largura * largura),(altura), z_terreno);
			glEnd();

			glPopMatrix();
			
			glPushMatrix();
			glTranslatef(-terreno[i].pos_x, terreno[i].pos_y,0);

			glBegin(GL_POLYGON); 
			glVertex3f(-(terreno[i].qnt_largura * largura), (altura), z_terreno);
			glVertex3f(-(terreno[i].qnt_largura * largura),-(altura), z_terreno);
			glVertex3f((terreno[i].qnt_largura * largura),-(altura), z_terreno);
			glVertex3f((terreno[i].qnt_largura * largura),(altura), z_terreno);
			glEnd();

			glPopMatrix();

		}


	}

	void desenhar_casa(){
		glScalef(escala, escala, escala);

		// fundação
		glColor3ub(216,216,191);
  		glBegin(GL_QUADS);
  		glVertex3f(-20, -10, 0.2);
  		glVertex3f(20, -10, 0.2);
  		glVertex3f(20, 10, 0.2);
  		glVertex3f(-20, 10, 0.2);
  		glEnd();

  		// parede esquerda
		glColor3ub(255,255,255);
  		glBegin(GL_QUADS);
  		glVertex3f(-20, -10, 0);
  		glVertex3f(-20, 10, 0);
  		glVertex3f(-20, 10, 10);
  		glVertex3f(-20, -10, 10);
  		glEnd();

  		// parede direita
  		glBegin(GL_QUADS);
  		glVertex3f(20, -10, 0);
  		glVertex3f(20, 10, 0);
  		glVertex3f(20, 10, 10);
  		glVertex3f(20, -10, 10);
  		glEnd();

  		// parede frente A
  		glBegin(GL_QUADS);
  		glVertex3f(-20, -10, 0);
  		glVertex3f(-20, -10, 8);
  		glVertex3f(10, -10, 8);
  		glVertex3f(10, -10, 0);
  		glEnd();

  		// parede frente B
  		glBegin(GL_QUADS);
  		glVertex3f(15, -10, 0);
  		glVertex3f(15, -10, 8);
  		glVertex3f(20, -10, 8);
  		glVertex3f(20, -10, 0);
  		glEnd();

  		// parede frente C
  		glBegin(GL_QUADS);
  		glVertex3f(-20, -10, 8);
  		glVertex3f(-20, -10, 10);
  		glVertex3f(20, -10, 10);
  		glVertex3f(20, -10, 8);
  		glEnd();


  		// parede fundo A
  		glBegin(GL_QUADS);
  		glVertex3f(-20, 10, 0);
  		glVertex3f(-20, 10, 3);
  		glVertex3f(20, 10, 3);
  		glVertex3f(20, 10, 0);
  		glEnd();

  		// parede fundo B
  		glBegin(GL_QUADS);
  		glVertex3f(-20, 10, 7);
  		glVertex3f(-20, 10, 10);
  		glVertex3f(20, 10, 10);
  		glVertex3f(20, 10, 7);
  		glEnd();

  		// parede fundo C
  		glBegin(GL_QUADS);
  		glVertex3f(-20, 10, 3);
  		glVertex3f(-20, 10, 7);
  		glVertex3f(-10, 10, 7);
  		glVertex3f(-10, 10, 3);
  		glEnd();

  		// parede fundo D
  		glBegin(GL_QUADS);
  		glVertex3f(-5, 10, 3);
  		glVertex3f(-5, 10, 7);
  		glVertex3f(20, 10, 7);
  		glVertex3f(20, 10, 3);
  		glEnd();

      	// telhado direito
      	glColor3ub(255,165,0);
      	glBegin(GL_QUADS);
      	glVertex3f(22, -10.5, 9.5);
      	glVertex3f(22, 10.5, 9.5);
      	glVertex3f(0, 10.5, 15);
      	glVertex3f(0, -10.5, 15);
      	glEnd();

      	// telhado esquerdo
      	glBegin(GL_QUADS);
      	glVertex3f(-22, -10.5, 9.5);
      	glVertex3f(-22, 10.5, 9.5);
      	glVertex3f(0, 10.5, 15);
      	glVertex3f(0, -10.5, 15);
      	glEnd();

      	// telhado frente 
      	glBegin(GL_TRIANGLES);
      	glVertex3f(-22, 10.5, 9.5);
      	glVertex3f(0, 10.5, 15);
      	glVertex3f(22, 10.5, 9.5);
      	glEnd();

      	// telhado trás 
      	glBegin(GL_TRIANGLES);
      	glVertex3f(-22, -10.5, 9.5);
      	glVertex3f(0, -10.5, 15);
      	glVertex3f(22, -10.5, 9.5);
      	glEnd();
	}

	void desenhar_arvore(){
		glScalef(escala, escala, escala);

		// Copa
		glPushMatrix();
  		glTranslatef(0, 0, 1.5);
  		glPushMatrix();
  		glColor3ub(50,205,50);
  		glutSolidCone(1.75, 3.5, 20, 20);
  		glPopMatrix();
  		glPopMatrix();

  		// Tronco
  		glPushMatrix();
  		glColor3ub(100, 80, 60);
  		gluCylinder(gluNewQuadric(), 0.5, 0.5, 2, 20, 20);
  		glPopMatrix();
	}

	void desenhar_combustivel(){
		glScalef(escala2, escala2, escala2);

		glPushMatrix();
    	glTranslatef(-1.5, 0, 0);
    	glRotatef(90, 0, 1, 0);
    	glColor3ub(250, 128, 114);
    	gluCylinder(gluNewQuadric(), 0.5, 0.5, 1, 20, 20);
    	glPopMatrix();

    	glPushMatrix();
    	glTranslatef(-0.5, 0, 0);
    	glRotatef(90, 0, 1, 0);
    	glColor3ub(255, 255, 255);
    	gluCylinder(gluNewQuadric(), 0.5, 0.5, 1, 20, 20);
    	glPopMatrix();

    	glPushMatrix();
    	glTranslatef(0.5, 0, 0);
    	glRotatef(90, 0, 1, 0);
    	glColor3ub(250, 128, 114);
    	gluCylinder(gluNewQuadric(), 0.5, 0.5, 1, 20, 20);
    	glPopMatrix();

    	glPushMatrix();
    	glTranslatef(1.5, 0, 0);
    	glRotatef(90, 0, 1, 0);
    	glColor3ub(255, 255, 255);
    	gluCylinder(gluNewQuadric(), 0.5, 0.5, 1, 20, 20);
    	glPopMatrix();
    	glPopMatrix();

    	glPushMatrix();
    	glTranslatef(2.0,0.0,0.0);
    	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    	gluDisk(gluNewQuadric(), 0.0, 0.5, 30, 1);
    	glPopMatrix();

    	glPushMatrix();
    	glColor3ub(250, 128, 114);
    	glTranslatef(-1.5,0.0,0.0);
    	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    	gluDisk(gluNewQuadric(), 0.0, 0.5, 30, 1);
    	glPopMatrix();
	}

};

