class Inimigo{
	
	public:
	//Posições atuais
	float pos_x;
	float pos_y;
	float pos_z;

	//Limite da tela utilizada
	float limite;

	//velocidade da movimentação do inimigo em X
	float velocidade;
	
	//Escala do tamanho do inimigo
	float escala;

	//Largura e altura para interpretar as colisões
	float largura;
	float altura;

	//Tipo do inimigo: 1-Navio, 0-Helicoptero
	int tipo_inimigo;

	Inimigo(){}
	
	Inimigo (int s){

		//Posição inicial do inimigo
		//Atualmente todos iniciam no topo da tela e aleatoriamente em x
		pos_x = aleatorio(60, 30, 10);
		pos_y = 300.0f;
		pos_z = 20.0f;

		//Definição do limite da tela.
		limite = s;

		//Definição da velocidade inicial do inimigo em Y
		//velocidade = aleatorio(5, 0, -0.1f);
		velocidade = 0;

		//Definição da escala do inimigo
		escala = 10.0f;

		//Cálculo de largura e altura baseada na escala
		largura = 3.0f * escala;
		altura = 2.5f * escala;

		//Tipo de inimigo, atualmente fixo em 1 = navio
		tipo_inimigo = 0;
		
	};
	
	//Atualiza o desenho, transaladando e/ou rotacionando
	void atualizar_desenho(){

		glPushMatrix();
		//Translada o desenho para a posição atual
		glTranslatef(pos_x, pos_y, pos_z);

		//Desenha o inimigo
		desenhar();
		glPopMatrix();

	}
	
	//Desenha o inimigo baseado na escala e tipo de inimigo
	void desenhar(){

		if (tipo_inimigo == 1) { // inimigo é um navio

			desenhar_navio();
	    }

	    else { // inimigo é um helicóptero

	    	desenhar_helicoptero();
		}
		
	}
	
	//Movimenta o inimigo até o limite da camera
	void movimentar(float y){
		
		pos_y += y;
		if(pos_y <= -limite){
			reset();
		}
		
		atualizar_desenho();
		glutPostRedisplay();
	}
	
	//Função para gerar um número aleatorio baseado em 3 parametros
	float aleatorio(int a, int b, float c){
		return (float) ((rand() % a + 1) - b  )*c;
	}
	
	//Reinicializa a posição do inimigo, reutilizando o objeto ja criado
	void reset(){
		
		pos_x = aleatorio(60, 30, 10);
		pos_y = 300.0f;
		pos_z = 20.0f;
		
		velocidade = aleatorio(5, 0, -0.1f);
		
	}

	void desenhar_navio(){
		
		glScalef(escala, escala, escala);

		glColor3ub(128,128,128); //DEFINE cor (R, G, B e percentual de transparência para o objeto)

		glPushMatrix();

	   	/* base */
      	glBegin(GL_POLYGON); 
      	glVertex3f(-2.5,-1.5,0.0);
      	glVertex3f(2.5,-1.5,0.0);
      	glVertex3f(2.5,1.5,0.0);
      	glVertex3f(-2.5,1.5,0.0);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(2.5,-1.5,0.0);
      	glVertex3f(2.5,1.5,0.0);
      	glVertex3f(3.5,1.5,2.5);
      	glVertex3f(3.5,-1.5,2.5);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(-2.5,-1.5,0.0);
      	glVertex3f(-2.5,1.5,0.0);
      	glVertex3f(-3.5,1.5,2.5);
      	glVertex3f(-3.5,-1.5,2.5);
      	glEnd();
      	
      	glColor3ub(169,169,169);
      	glBegin(GL_POLYGON); 
      	glVertex3f(3.5,1.5,2.5);
      	glVertex3f(3.5,-1.5,2.5);
      	glVertex3f(-3.5,-1.5,2.5);
      	glVertex3f(-3.5,1.5,2.5);
      	glEnd();
      	
      	glColor3ub(105,105,105);
      	glBegin(GL_POLYGON); 
      	glVertex3f(2.5,1.5,0.0);
      	glVertex3f(3.5,1.5,2.5);
      	glVertex3f(-3.5,1.5,2.5);
      	glVertex3f(-2.5,1.5,0.0);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(2.5,-1.5,0.0);
      	glVertex3f(3.5,-1.5,2.5);
      	glVertex3f(-3.5,-1.5,2.5);
      	glVertex3f(-2.5,-1.5,0.0);
      	glEnd();
      	
  		/*meio*/
      	glColor3ub(128,0,0);
      	glBegin(GL_POLYGON); 
      	glVertex3f(-2.5,-1.0,2.5);
      	glVertex3f(-2.5,-1.0,4.0);
      	glVertex3f(2.5,-1.0,4.0);
      	glVertex3f(2.5,-1.0,2.5);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(2.5,-1.0,2.5);
      	glVertex3f(2.5,1.0,2.5);
      	glVertex3f(2.5,1.0,4.0);
      	glVertex3f(2.5,-1.0,4.0);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(-2.5,-1.0,2.5);
      	glVertex3f(-2.5,1.0,2.5);
      	glVertex3f(-2.5,1.0,4.0);
      	glVertex3f(-2.5,-1.0,4.0);
      	glEnd();
      	  
      	glBegin(GL_POLYGON); 
      	glVertex3f(-2.5,1.0,2.5);
      	glVertex3f(-2.5,1.0,4.0);
      	glVertex3f(2.5,1.0,4.0);
      	glVertex3f(2.5,1.0,2.5);
      	glEnd();
      	
      	glColor3ub(165,42,42);
      	glBegin(GL_POLYGON); 
      	glVertex3f(-2.5,-1.0,4.0);
      	glVertex3f(2.5,-1.0,4.0);
      	glVertex3f(2.5,1.0,4.0);
      	glVertex3f(-2.5,1.0,4.0);
      	glEnd();
      	
      	glPopMatrix();
      	/*janelas*/
      	/*glColor3ub(30,144,255);
      	glPushMatrix();
      	glBegin(GL_POLYGON); 
      	glVertex3f(-2.0,-1.0,2.5);
      	glVertex3f(2.0,-1.0,2.5);
      	glVertex3f(2.0,-1.0,3.75);
      	glVertex3f(-2.0,-1.0,3.75);
      	glEnd();
      	glPopMatrix();

      	glPushMatrix();
      	glBegin(GL_POLYGON); 
      	glVertex3f(-2.0,1.0,2.5);
      	glVertex3f(2.0,1.0,2.5);
      	glVertex3f(2.0,1.0,3.75);
      	glVertex3f(-2.0,1.0,3.75);
      	glEnd();
      	glPopMatrix();*/

      	/* chaminés */
      	glColor3ub(211,211,211);
      	glPushMatrix();
      	glTranslatef(-1.5,0.0,3.0);
      	gluCylinder(gluNewQuadric(), 0.5, 0.5, 3, 12, 3);
      	glPopMatrix();

      	glColor3ub(0,0,0);
      	glPushMatrix();
      	glTranslatef(-1.5,0.0,6.0);
      	gluDisk(gluNewQuadric(), 0.0, 0.5, 30, 1);
      	glPopMatrix();

      	glColor3ub(211,211,211);
      	glPushMatrix();
      	glTranslatef(1.5,0.0,3.0);
      	gluCylinder(gluNewQuadric(), 0.5, 0.5, 3, 12, 3);
      	glPopMatrix();

      	glColor3ub(0,0,0);
      	glPushMatrix();
      	glTranslatef(1.5,0.0,6.0);
      	gluDisk(gluNewQuadric(), 0.0, 0.5, 30, 1);
      	glPopMatrix();

	}

	void desenhar_helicoptero(){
		glScalef(escala, escala, escala);

    	glColor3ub(135,206,235); //DEFINE cor (R, G, B e percentual de transparência para o objeto)

	    /* cabine do piloto */
	    glPushMatrix();
	    glTranslatef(-2.0,0.0,0.0);
	    glScalef(1.5,1.0,1.0);
	    glutSolidSphere(1.0, 20, 20);
	    glPopMatrix();

	    /*base hélice*/
	    glColor3ub(211,211,211);
	    glPushMatrix();
	    glTranslatef(-2.0,0.0,0.0);
	    glScalef(0.5,0.5,0.5);
	    gluCylinder(gluNewQuadric(), 0.3, 0.3, 2.5, 12, 3);
	    glPopMatrix();

	    /*hélice superior*/
	    glColor3ub(128,128,128);
	    glPushMatrix();
	    glTranslatef(-2.0,1.25,1.3);
	    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	    glScalef(0.5,0.1,0.5);
	    gluCylinder(gluNewQuadric(), 0.3, 0.3, 5.0, 12, 3);
	    glPopMatrix();

	    /*cauda*/
	    glColor3ub(211,211,211);
	    glPushMatrix();
	    glTranslatef(-0.55,0.0,0.0);
	    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	    gluCylinder(gluNewQuadric(), 0.3, 0.15, 4.0, 12, 3);
	    glPopMatrix();

	    glPushMatrix();
	    glTranslatef(3.5,0.0,0.0);
	    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	    gluDisk(gluNewQuadric(), 0.0, 0.15, 30, 1);
	    glPopMatrix();

	    /*hélice cauda*/
	    glColor3ub(128,128,128);
	    glPushMatrix();
	    glTranslatef(3.5,0.2,-0.75);
	    glScalef(0.4,0.1,0.3);
	    gluCylinder(gluNewQuadric(), 0.3, 0.3, 5.0, 12, 3);
	    glPopMatrix();
	}
	
};
