class Jogador{
	
	public:
	float pos_x;
	float pos_y;
	float pos_z;
	float limite;
	float velocidade;
	float escala;
	float largura;
	float altura;
	
	Jogador(int s){
		
		pos_x = 1.0f;
		pos_y = -250.0f;
		pos_z = 1.0f;
		limite = s/2;
		
		velocidade = 4.0f;

		escala = 8.0f;

		altura = 3.5f * escala;
		largura = 3.5f * escala;
		
	};
	
	void transladar(){

		glPushMatrix();
		glTranslatef(pos_x, pos_y, pos_z);
		carregar();
		glPopMatrix();

	}
	
	void carregar(){

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
	
	void movimentar(float x){
		
		pos_x += x;
		if(pos_x <= -limite){
			pos_x = -limite;
		}else if (pos_x >= limite){
			pos_x = limite;
		}
		
		transladar();
		glutPostRedisplay();
	}
	
};
