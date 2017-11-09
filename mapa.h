//tiles (x,y) = (120,75)
//tile minimo = (120, 25)


typedef struct Tiles{
	float pos_x;
	float pos_y;
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


};

