class Mapa{
	
	public:
	//Limite da tela utilizada
	float limite;
	float limite_inferior;
	float largura_minima;

	//velocidade de movimentação do mapa em Y
	float velocidade;
	float velocidade_padrao;

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
		largura_minima = 10.0f;

		num_terrenos = 8;

		velocidade_padrao = -9.0f;
		velocidade = velocidade_padrao;

		terreno_carregado = 0;
		Gerar_Mapa_Inicial();

		for(i=0; i<num_terrenos; i++){

			terrenos[i] = Terreno(limite, InfTerrenos[flag_carregado][i], limite_inferior + (i * (2.0f * InfTerrenos[flag_carregado][i].altura)));
			terreno_carregado++;

		}

	}

	void reset(){

		terreno_carregado = 0;

		for(i=0; i<num_terrenos; i++){

			terrenos[i] = Terreno(limite, InfTerrenos[flag_carregado][i], limite_inferior + (i * (2.0f * InfTerrenos[flag_carregado][i].altura)));
			terreno_carregado++;
		}
	}

	void atualizar(){

		for(i=0; i<num_terrenos; i++){
			terrenos[i].movimentar(velocidade);
		}

		i = terreno_carregado % num_terrenos;
		if(terrenos[i].pos_y < limite_inferior){
			terrenos[i].resetar(InfTerrenos[flag_carregado][terreno_carregado], -2.0f*limite_inferior);
			terreno_carregado++;

			if(terreno_carregado>=24){
				terreno_carregado=0;

				Gerar_Mapa(flag_carregado);
				
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

		glScalef(2*largura_minima, 2*limite, 2*100);
    	glutSolidCube(1.0f);

		glPopMatrix();

		glPushMatrix();

		glTranslatef(-(limite - largura_minima),0,0);

		glScalef(2*largura_minima, 2*limite, 2*100);
    	glutSolidCube(1.0f);
		glPopMatrix();


		glColor3ub(0,0,200);

		glBegin(GL_POLYGON); 
		glVertex3f(-limite, (limite), 0);
		glVertex3f(-limite,-(limite), 0);
		glVertex3f( limite,-(limite), 0);
		glVertex3f( limite, (limite), 0);
		glEnd();

	}

	void Gerar_Mapa_Inicial(){

		int flag = 0;

		for(i=0; i<7; i++){
			InfTerrenos[flag][i].altura = limite/2;
			InfTerrenos[flag][i].largura = largura_minima*3;

			InfTerrenos[flag][i].tipo = 0;

			Gerar_Inimigo(flag, i);

			InfTerrenos[flag][i].x = limite - InfTerrenos[flag][i].largura/2;
		}

		for(i=7; i<20;i++){

			InfTerrenos[flag][i].altura = limite/2;
			InfTerrenos[flag][i].largura = largura_minima + aleatorio(70,0,1);

			InfTerrenos[flag][i].tipo = aleatorio(100,0,1);

			if(InfTerrenos[flag][i].tipo > 70)
				InfTerrenos[flag][i].tipo = 0;
			else
				InfTerrenos[flag][i].tipo = 1;

			Gerar_Inimigo(flag, i);

			InfTerrenos[flag][i].x = limite - InfTerrenos[flag][i].largura/2;
		}

		Gerar_Checkpoint(flag);
		flag++;

		Gerar_Mapa(flag);

		dificuldade = 2;

	}

	void Gerar_Mapa(int flag){

		Gerar_Pos_Checkpoint(flag);

		for(i=7; i<20;i++){
			InfTerrenos[flag][i].altura = limite/2;
			InfTerrenos[flag][i].largura = largura_minima + aleatorio(100,0,1);

			InfTerrenos[flag][i].tipo = aleatorio(100,0,1);
			if(InfTerrenos[flag][i].tipo > 30)
				InfTerrenos[flag][i].tipo = 0;
			else
				InfTerrenos[flag][i].tipo = 1;

			Gerar_Inimigo(flag, i);;

			InfTerrenos[flag][i].x = limite - InfTerrenos[1][i].largura/2;
		}

		Gerar_Checkpoint(flag);

	}

	void Gerar_Checkpoint(int flag){

		for(i=20; i<24; i++){

			InfTerrenos[flag][i].altura = limite/2;
			InfTerrenos[flag][i].largura = largura_minima + 10 * (i-18);
			InfTerrenos[flag][i].tipo = 0;

			Gerar_Inimigo(flag, i);

			InfTerrenos[flag][i].x = limite - InfTerrenos[flag][i].largura/2;

		}

	}

	void Gerar_Pos_Checkpoint(int flag){
		dificuldade++;

		for(i=0; i<7;i++){
			InfTerrenos[flag][i].altura = limite/2;
			InfTerrenos[flag][i].largura = largura_minima;

			InfTerrenos[flag][i].tipo = 0;

			Gerar_Inimigo(flag, i);

			InfTerrenos[flag][i].x = limite - InfTerrenos[1][i].largura/2;
		}

	}

	void Gerar_Inimigo(int flag, int i){
		InfTerrenos[flag][i].num_inimigos = (int) aleatorio(100, 0, 1);

		if(InfTerrenos[flag][i].num_inimigos < 40-dificuldade)
			InfTerrenos[flag][i].num_inimigos = 0;
		else if(InfTerrenos[flag][i].num_inimigos < 65-dificuldade)
			InfTerrenos[flag][i].num_inimigos = 1;
		else if(InfTerrenos[flag][i].num_inimigos < 90-dificuldade)
			InfTerrenos[flag][i].num_inimigos = 2;
		else
			InfTerrenos[flag][i].num_inimigos = 3;
	}

};
