class Combustivel{

	public:

	float pos_x;
	float pos_y;
	float pos_z;

	int limite;

	int atividade;

	float largura;
	float altura;

	float escala;

	Combustivel(){}

	Combustivel(int s){

		limite = s;
		atividade = 0;

		escala = 20.0f;

		largura = 1.0f*escala;
		altura = 1.4f*escala;

		pos_z = 10.0f;

	}

	void movimentar(float velocidade){
		if(atividade > 0){

			pos_y += velocidade;
			atualizar_desenho();
		}
		glutPostRedisplay();
	}

	void atualizar_desenho(){

		glPushMatrix();
		//Translada o desenho para a posição atual
		glTranslatef(pos_x, pos_y, pos_z);

		//Desenha o inimigo
		desenhar();
		glPopMatrix();
	}

	void setCombustivel(float y, float x){

		pos_x = x;
		pos_y = y;
		atividade = 1;

	}

	void desenhar(){
		glScalef(escala, escala, escala);
    glRotatef(90, 0, 0, 1);

    glPushMatrix();


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
      glPopMatrix();
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
	
};