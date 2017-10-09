class Inimigo{
	
	public:
	float pos_x;
	float pos_y;
	float pos_z;
	float limite;
	float velocidade;
	
	Inimigo(){
	}
	
	Inimigo(int s){
		
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
		
		glColor3ub( 0, 0, 0);
		glutSolidCube(30.0);
		
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
	
};
