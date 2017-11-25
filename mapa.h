class Mapa{
	
	public:
	//Limite da tela utilizada
	float limite;
	float limite_inferior;
	float largura_minima;

	//velocidade de movimentação do mapa em Y
	float velocidade;

	int num_inimigos;
	Inimigo inimigos[1];

	int num_terrenos;
	Terreno terrenos[8];
	int terreno_carregado;
	int flag_carregado;

	InfoT InfTerrenos[2][24];

	int i;

	int dificuldade;

	Mapa(int s){

		limite = s/2;
		limite_inferior= -2.0f * s;
		largura_minima = 15.0f;

		num_inimigos = 1;
		num_terrenos = 8;

		velocidade = -3.0f;

		terreno_carregado = 0;
		Gerar_Mapa_Inicial();

		for(i=0; i<num_inimigos; i++)
			inimigos[i] = Inimigo(limite);

		for(i=0; i<num_terrenos; i++){

			terrenos[i] = Terreno(limite, InfTerrenos[flag_carregado][i], limite_inferior + (i * (2.0f * InfTerrenos[flag_carregado][i].altura)), i);
			terreno_carregado++;

		}

	}

	void reset(){

		terreno_carregado = 0;

		for(i=0; i<num_inimigos; i++)
			inimigos[i] = Inimigo(limite);

		for(i=0; i<num_terrenos; i++){

			terrenos[i] = Terreno(limite, InfTerrenos[flag_carregado][i], limite_inferior + (i * (2.0f * InfTerrenos[flag_carregado][i].altura)), i);
			terreno_carregado++;
		}
	}

	void atualizar(){

		for(i=0; i<num_inimigos; i++){
			inimigos[i].movimentar(velocidade);
		}

		for(i=0; i<num_terrenos; i++){
			terrenos[i].movimentar(velocidade);
		}

		i = terreno_carregado % num_terrenos;
		if(terrenos[i].pos_y < limite_inferior){
			terrenos[i].resetar(InfTerrenos[flag_carregado][terreno_carregado], -2.0f*limite_inferior);

			terreno_carregado++;

			if(terreno_carregado>=24){
				terreno_carregado=0;
				
				if(flag_carregado == 0)
					flag_carregado = 1;
				else
					flag_carregado = 0;
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

		glColor3ub(0,100,0);

		glPushMatrix();

		glTranslatef(limite - largura_minima,0,0);

		glBegin(GL_POLYGON); 
		glVertex3f(-largura_minima, (limite), 0);
		glVertex3f(-largura_minima,-(limite), 0);
		glVertex3f( largura_minima,-(limite), 0);
		glVertex3f( largura_minima, (limite), 0);
		glEnd();

		glPopMatrix();

		glPushMatrix();

		glTranslatef(-(limite - largura_minima),0,0);

		glBegin(GL_POLYGON); 
		glVertex3f(-largura_minima, (limite), 0);
		glVertex3f(-largura_minima,-(limite), 0);
		glVertex3f( largura_minima,-(limite), 0);
		glVertex3f( largura_minima, (limite), 0);
		glEnd();

		glPopMatrix();

/*
		glColor3ub(0,0,200);

		glBegin(GL_POLYGON); 
		glVertex3f(-limite, (limite), 0);
		glVertex3f(-limite,-(limite), 0);
		glVertex3f( limite,-(limite), 0);
		glVertex3f( limite, (limite), 0);
		glEnd();*/

	}

	void Gerar_Mapa_Inicial(){

		for(i=0; i<24;i++){

			InfTerrenos[0][i].altura = limite/2;
			InfTerrenos[0][i].largura = 20 + aleatorio(70,0,1);

			InfTerrenos[0][i].tipo = aleatorio(100,0,1);
			if(InfTerrenos[0][i].tipo > 70)
				InfTerrenos[0][i].tipo = 0;
			else
				InfTerrenos[0][i].tipo = 1;

			InfTerrenos[0][i].x = limite - InfTerrenos[0][i].largura/2;
		}

		for(i=0; i<24;i++){
			InfTerrenos[1][i].altura = limite/2;
			InfTerrenos[1][i].largura = 20 + aleatorio(100,0,1);

			InfTerrenos[0][i].tipo = aleatorio(100,0,1);
			if(InfTerrenos[0][i].tipo > 70)
				InfTerrenos[0][i].tipo = 0;
			else
				InfTerrenos[0][i].tipo = 1;

			InfTerrenos[1][i].x = limite - InfTerrenos[1][i].largura/2;
		}

		dificuldade = 2;

	}

};
