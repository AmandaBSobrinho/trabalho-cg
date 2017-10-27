class Jogador{
	
	public:
	float pos_x;
	float pos_y;
	float pos_z;
	float limite;
	float velocidade;
	
	Jogador(int s){
		
		pos_x = 1.0f;
		pos_y = -250.0f;
		pos_z = 1.0f;
		limite = s/2;
		
		velocidade = 4.0f;
		
	};
	
	void transladar_aviao(){

		glPushMatrix();
		glTranslatef(pos_x, pos_y, pos_z);
		carregar_aviao();
		glPopMatrix();

	}
	
	void carregar_aviao(){

      	glScalef(20,20,20);
		
		glColor3ub(128,128,128); //DEFINE cor (R, G, B e percentual de transparência para o objeto)

	   	/* asas */
  		glBegin(GL_TRIANGLES); 
  		glVertex3f(-3.5,0.0,0.0);
  		glVertex3f(+3.5,0.0,0.0);
  		glVertex3f(0.0,0.0,3.0);
      	glScalef(20,20,20);
  		glEnd();
  		
  		/* corpo */
  		GLUquadricObj *quadric;
  		quadric = gluNewQuadric();
  		gluCylinder(quadric, 0.5, 0.5, 4, 12, 3);
  		
  		/* nariz */
  		glPushMatrix();
  		glTranslatef(0,0,4);
  		glutSolidCone(0.5, 1.5, 12, 3);
  		glPopMatrix();
		
		/* cauda */
		glBegin(GL_POLYGON); 
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,2.0,-1.0);
		glVertex3f(0.0,2.0,0.0);
		glVertex3f(0.0,0.0,2.0);
		glEnd();
	
	  	/* cabine do piloto */
	  	glTranslatef(0,0.3,3.5);
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
		
		transladar_aviao();
		glutPostRedisplay();
	}
	
};
