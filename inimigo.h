class Inimigo{
	
	public:
	float pos_x;
	float pos_y;
	float pos_z;
	float limite;
	float velocidade;
	float escala;
	float largura;
	float altura;

	int tipo_inimigo;
	
	Inimigo(){

	}
	
	Inimigo(int s){
		
		escala = 10.0f;
		largura = 3.0f * escala;
		altura = 2.5f * escala;
		tipo_inimigo = 1;

		pos_x = aleatorio(60, 30, 10);
		pos_y = 300.0f;
		pos_z = 1.0f;
		limite = s;
		
		velocidade = aleatorio(5, 0, -0.1f);
		
	};
	
	void transladar(){

		glPushMatrix();
		glTranslatef(pos_x, pos_y, pos_z);
		carregar();
		glPopMatrix();

	}
	
	void carregar(){

		if (tipo_inimigo == 1) { // inimigo é um navio

			carregar_navio();
	    }

	    else { // inimigo é um helicóptero

	    	carregar_helicoptero();
		}
		
	}
	
	void movimentar(float y){
		
		pos_y += y;
		if(pos_y <= -limite){
			reset();
		}
		
		transladar();
		glutPostRedisplay();
	}
	
	float aleatorio(int a, int b, float c){
		return (float) ((rand() % a + 1) - b  )*c;
	}
	
	void reset(){
		
		pos_x = aleatorio(60, 30, 10);
		pos_y = 300.0f;
		pos_z = 1.0f;
		
		velocidade = aleatorio(5, 0, -0.1f);
		
	}

	bool colidir(float x, float y, float l, float a){

		if(pos_y < 0 && y + a >= pos_y - altura)
			if(x + largura >= pos_x - largura && x - largura <= pos_x + largura )
				return true;

		return false;

	}

	void carregar_navio(){
		glScalef(escala, escala, escala);
			

/* box test */
      	glColor3ub(0,0,0);
		glBegin(GL_POLYGON); 
		glVertex3f(-largura/escala,altura/escala, 0.0);
		glVertex3f(-largura/escala,-altura/escala, 0.0);
		glVertex3f(largura/escala,-altura/escala, 0.0);
		glVertex3f(largura/escala,altura/escala, 0.0);
		glEnd();


		glColor3ub(128,128,128); //DEFINE cor (R, G, B e percentual de transparência para o objeto)

		glPushMatrix();

	   	/* base */
      	glBegin(GL_POLYGON); 
      	glVertex3f(0.0,0.0,0.0);
      	glVertex3f(5.0,0.0,0.0);
      	glVertex3f(5.0,3.0,0.0);
      	glVertex3f(0.0,3.0,0.0);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(5.0,0.0,0.0);
      	glVertex3f(5.0,3.0,0.0);
      	glVertex3f(6.0,3.0,2.5);
      	glVertex3f(6.0,0.0,2.5);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(0.0,0.0,0.0);
      	glVertex3f(0.0,3.0,0.0);
      	glVertex3f(-1.0,3.0,2.5);
      	glVertex3f(-1.0,0.0,2.5);
      	glEnd();
      	
      	glColor3ub(169,169,169);
      	glBegin(GL_POLYGON); 
      	glVertex3f(6.0,3.0,2.5);
      	glVertex3f(6.0,0.0,2.5);
      	glVertex3f(-1.0,0.0,2.5);
      	glVertex3f(-1.0,3.0,2.5);
      	glEnd();
      	
      	glColor3ub(105,105,105);
      	glBegin(GL_POLYGON); 
      	glVertex3f(5.0,3.0,0.0);
      	glVertex3f(6.0,3.0,2.5);
      	glVertex3f(-1.0,3.0,2.5);
      	glVertex3f(0.0,3.0,0.0);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(5.0,0.0,0.0);
      	glVertex3f(6.0,0.0,2.5);
      	glVertex3f(-1.0,0.0,2.5);
      	glVertex3f(0.0,0.0,0.0);
      	glEnd();
      	
  		/*meio*/
      	glColor3ub(128,0,0);
      	glBegin(GL_POLYGON); 
      	glVertex3f(0.0,0.5,2.5);
      	glVertex3f(0.0,0.5,4.0);
      	glVertex3f(5.0,0.5,4.0);
      	glVertex3f(5.0,0.5,2.5);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(5.0,0.5,2.5);
      	glVertex3f(5.0,2.5,2.5);
      	glVertex3f(5.0,2.5,4.0);
      	glVertex3f(5.0,0.5,4.0);
      	glEnd();
      	
      	glBegin(GL_POLYGON); 
      	glVertex3f(0.0,0.5,2.5);
      	glVertex3f(0.0,2.5,2.5);
      	glVertex3f(0.0,2.5,4.0);
      	glVertex3f(0.0,0.5,4.0);
      	glEnd();
      	  
      	glBegin(GL_POLYGON); 
      	glVertex3f(0.0,2.5,2.5);
      	glVertex3f(0.0,2.5,4.0);
      	glVertex3f(5.0,2.5,4.0);
      	glVertex3f(5.0,2.5,2.5);
      	glEnd();
      	
      	glColor3ub(165,42,42);
      	glBegin(GL_POLYGON); 
      	glVertex3f(0.0,0.5,4.0);
      	glVertex3f(5.0,0.5,4.0);
      	glVertex3f(5.0,2.5,4.0);
      	glVertex3f(0.0,2.5,4.0);
      	glEnd();
      	
      	glPopMatrix();
      	/*janelas*/
      	/*glColor3ub(30,144,255);
      	glPushMatrix();
      	glBegin(GL_POLYGON); 
      	glVertex3f(0.5,0.5,2.5);
      	glVertex3f(4.5,0.5,2.5);
      	glVertex3f(4.5,0.5,3.75);
      	glVertex3f(0.5,0.5,3.75);
      	glEnd();
      	glPopMatrix();

      	glPushMatrix();
      	glBegin(GL_POLYGON); 
      	glVertex3f(0.5,2.5,2.5);
      	glVertex3f(4.5,2.5,2.5);
      	glVertex3f(4.5,2.5,3.75);
      	glVertex3f(0.5,2.5,3.75);
      	glEnd();
      	glPopMatrix();*/

      	/* chaminés */
      	glColor3ub(211,211,211);
      	glPushMatrix();
      	GLUquadricObj *quadric;
      	quadric = gluNewQuadric();
      	glTranslatef(1.0,1.5,3.0);
      	gluCylinder(quadric, 0.5, 0.5, 3, 12, 3);
      	glPopMatrix();

      	glColor3ub(0,0,0);
      	glPushMatrix();
      	glTranslatef(1.0,1.5,6.0);
      	gluDisk(quadric, 0.0, 0.5, 30, 1);
      	glPopMatrix();

      	glColor3ub(211,211,211);
      	glPushMatrix();
      	quadric = gluNewQuadric();
      	glTranslatef(4.0,1.5,3.0);
      	gluCylinder(quadric, 0.5, 0.5, 3, 12, 3);
      	glPopMatrix();

      	glColor3ub(0,0,0);
      	glPushMatrix();
      	glTranslatef(4.0,1.5,6.0);
      	gluDisk(quadric, 0.0, 0.5, 30, 1);
      	glPopMatrix();
	}

	void carregar_helicoptero(){
		glScalef(escala, escala, escala);

    	glColor3ub(135,206,235); //DEFINE cor (R, G, B e percentual de transparência para o objeto)

	    /* cabine do piloto */
	    glPushMatrix();
	    glScalef(1.5,1.0,1.0);
	    glutSolidSphere(1.0, 20, 20);
	    glPopMatrix();

	    /*base hélice*/
	    glColor3ub(211,211,211);
	    glPushMatrix();
	    GLUquadricObj *quadric;
	    quadric = gluNewQuadric();
	    glScalef(0.5,0.5,0.5);
	    gluCylinder(quadric, 0.3, 0.3, 2.5, 12, 3);
	    glPopMatrix();

	    /*hélice superior*/
	    glColor3ub(128,128,128);
	    glPushMatrix();
	    glTranslatef(0.0,1.25,1.3);
	    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	    glScalef(0.5,0.1,0.5);
	    gluCylinder(quadric, 0.3, 0.3, 5.0, 12, 3);
	    glPopMatrix();

	    /*cauda*/
	    glColor3ub(211,211,211);
	    glPushMatrix();
	    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	    gluCylinder(quadric, 0.3, 0.15, 4.0, 12, 3);
	    glPopMatrix();

	    glPushMatrix();
	    glTranslatef(4.0,0.0,0.0);
	    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	    gluDisk(quadric, 0.0, 0.15, 30, 1);
	    glPopMatrix();

	    /*hélice cauda*/
	    glColor3ub(128,128,128);
	    glPushMatrix();
	    glTranslatef(4.0,0.2,-0.75);
	    glScalef(0.4,0.1,0.3);
	    gluCylinder(quadric, 0.3, 0.3, 5.0, 12, 3);
	    glPopMatrix();
	}
	
};
