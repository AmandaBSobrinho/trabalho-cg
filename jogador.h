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
		
		glColor3ub( 0, 0, 0);
		glutWireTeapot(20);
		
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
