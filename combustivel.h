class Combustivel{

	public:

	float pos_x;
	float pos_y;
	float pos_z;

	int limite;

	int atividade;

	Combustivel(){}

	Combustivel(int s){

		limite = s;
		atividade = 0;

	}

	void movimentar(float velocidade){

		atualizar_desenho();
		glutPostRedisplay();
	}

	void atualizar_desenho(){

		desenhar();
		glutPostRedisplay();
	}

	void desenhar(){}
	
};