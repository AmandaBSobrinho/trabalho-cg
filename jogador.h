class Jogador{
	
	public:
	//Posições atuais
	float pos_x;
	float pos_y;
	float pos_z;

	//Limite da tela utilizada
	float limite;

	//velocidade de movimentação do jogador em X
	float velocidade;
	//Escala do tamanho do jogador
	float escala;

	//Largura e altura para interpretar as colisões
	float largura;
	float altura;

	//Estado que indica se está movimentando ou não, para animação: 0-parado, -1-esquerda, 1-direita
	int movimentando;
	
	Jogador(int s){
		
		//posição inicial no centro inferior da tela		
		pos_x = 1.0f;
		pos_y = -280.0f;
		pos_z = 1.0f;

		//Definição do limite da tela.
		limite = s/2;
		
		//Definição da velocidade inicial do jogador em X
		velocidade = 4.0f;

		//Definição da escala do jogador
		escala = 8.0f;

		//Cálculo de largura e altura baseada na escala
		altura = 3.5f * escala;
		largura = 3.5f * escala;

		//Estado inicial de movimentação = 0-parado
		movimentando = 0;
		
	};
	
	//Atualiza o desenho, transaladando e/ou rotacionando
	void atualizar_desenho(){

		glPushMatrix();
		//Translada o desenho para a posição atual
		glTranslatef(pos_x, pos_y, pos_z);

		//De acordo com o estado movimentando direciona o avião
		if(movimentando > 0)
			glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
		else if(movimentando < 0)
			glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);

		//Desenha o avião
		desenhar();
		glPopMatrix();

	}

	//Cálculo da colisão
	bool colidir(float x, float y, float l, float a){

		if(y < 0 && pos_y + altura >= y - a)
			if(pos_x + l >= x - l && pos_x - l <= x + l )
				return true;

		return false;

	}
	
	//Desenha o avião do jogador baseado na escala
	void desenhar(){

      	glScalef(escala, escala, escala);

		/* caixa preta para teste de colisão */
      	/*glColor3ub(0,0,0);
		glBegin(GL_POLYGON); 
		glVertex3f(-largura/escala,altura/escala, 0.0);
		glVertex3f(-largura/escala,-altura/escala, 0.0);
		glVertex3f(largura/escala,-altura/escala, 0.0);
		glVertex3f(largura/escala,altura/escala, 0.0);
		glEnd();*/

		
		glColor3ub(128,128,128); //DEFINE cor (R, G, B e percentual de transparência para o objeto)

	   	/* asas */
  		glBegin(GL_TRIANGLES); 
  		glVertex3f(-3.5,0.0,0.0);
  		glVertex3f(+3.5,0.0,0.0);
  		glVertex3f(0.0,3.0,0.0);
  		glEnd();

  		/* cauda */
		glBegin(GL_POLYGON); 
		glVertex3f(0.0,-0.5,0.0);
		glVertex3f(0.0,-1.5,1.5);
		glVertex3f(0.0,-0.5,1.5);
		glVertex3f(0.0,1.5,0.0);
		glEnd();
  		
  		/* corpo */
  		glColor3ub(192,192,192);
  		GLUquadricObj *quadric;
  		quadric = gluNewQuadric();
  		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
  		glTranslatef(0.0,0.0,-3.7);
  		gluCylinder(quadric, 0.5, 0.5, 4, 12, 3);
  		
  		/* nariz */
  		glColor3ub(169,169,169);
  		glPushMatrix();
  		glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
  		//glTranslatef(0,0,4);
  		glutSolidCone(0.5, 1.5, 12, 3);
  		glPopMatrix();
		
	  	/* cabine do piloto */
	  	glTranslatef(0,0.3,0.5);
	  	glPushMatrix();
      	glScalef(0.7,0.7,2.0);
      	glColor3f(0.3,0.5,1);
      	glutSolidSphere(0.5, 12, 12);
      	glPopMatrix();

	}
	
	//Movimenta o avião até o limite da camera
	void movimentar(float x){
		
		pos_x += x;
		if(pos_x <= -limite){
			pos_x = -limite;
		}else if (pos_x >= limite){
			pos_x = limite;
		}
		
		atualizar_desenho();
		glutPostRedisplay();
	}
	
};
