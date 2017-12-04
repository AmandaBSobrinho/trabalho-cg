class Terreno{
	
	public:
	//Limite da tela utilizada
	float limite;

	//largura e altura de cada tile do terreno
	float largura;
	float altura;
  float tipo;

  float pos_x;
  float pos_y;

  Inimigo inimigos[2];
  Combustivel comb;

	float escala;

  Terreno(){}

	Terreno(int s, InfoT t, float y){

		limite = s;
    setDimensao(t.altura, t.largura);
    setPosicao(t.x, y);
    tipo = t.tipo;

    inimigos[0] = Inimigo(s);
    inimigos[1] = Inimigo(s);

    comb = Combustivel(s);

    Gerar_Combustivel();

    Gerar_Inimigos(t.num_inimigos);

	}

  void setDimensao(float a, float l){
    altura = a;
    largura = l;
  }

  void setPosicao(float x, float y){

    pos_x = x;
    pos_y = y;

  }

  void movimentar(float velocidade){

    pos_y += velocidade;

    atualizar_desenho();

    inimigos[0].movimentar(velocidade);
    inimigos[1].movimentar(velocidade);

    comb.movimentar(velocidade);

    glutPostRedisplay();

  }

	void atualizar_desenho(){

    /* Lado direito */
    glPushMatrix();

    glTranslatef(tipo*limite - pos_x, pos_y,0);
    desenhar();
    glPopMatrix();

    /* Lado esquerdo */
    glPushMatrix();

    glTranslatef(-(tipo*limite) + pos_x, pos_y,0);
    
    desenhar();
    glPopMatrix();

	}

  void resetar(InfoT t, float y){

    setDimensao(t.altura, t.largura);
    setPosicao(t.x, pos_y + y);
    tipo = t.tipo;

    Gerar_Combustivel();
    Gerar_Inimigos(t.num_inimigos);

  }

	void desenhar(){

		int z_terreno = 80;

    glColor3ub(0,100,0);

    glScalef(2*largura, 2*altura, 2*z_terreno);
    glutSolidCube(1.0f);
    
  }

  void Gerar_Inimigos(int qnt){

    if(qnt > 0){

      if(qnt != 2){
        inimigos[0].atividade = 1;

        inimigos[0].pos_x = (tipo * largura) + (int)aleatorio((limite-(tipo*10)-largura - inimigos[0].largura), 0, 1);

        if((int)aleatorio(100, 0, 1)%50 > 0)
          inimigos[0].pos_x *= (-1);

        inimigos[0].pos_y = pos_y + altura/2;
      }

      if(qnt != 1){
        inimigos[1].atividade = 1;

        inimigos[1].pos_x = (tipo * largura) + (int)aleatorio((limite-(tipo*10)-largura - inimigos[1].largura), 0, 1);

        if((int)aleatorio(100, 0, 1)%20 > 0)
          inimigos[0].pos_x *= (-1);

        inimigos[1].pos_y = pos_y - altura/2;
      }
      
    }

  }

  void Gerar_Combustivel(){

    int aux = (int)aleatorio(100,0,1)%50;
    if(aux > 0){
      aux = (tipo * largura) + (int)aleatorio((limite-(tipo*10)-largura - inimigos[1].largura), 0, 1);
      if((int)aleatorio(100,0,1)%50)
        comb.setCombustivel(pos_y, aux);
      else
        comb.setCombustivel(pos_y, aux);
    }

  }

  //Função para gerar um número aleatorio baseado em 3 parametros
  float aleatorio(int a, int b, float c){
    return (float) ((rand() % a + 1) - b  )*c;
  }

};

