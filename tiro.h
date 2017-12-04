class Tiro{
    
    public:
    //Posições atuais
    float pos_x;
    float pos_y;
    float pos_z;
    float antiga_pos_y;

    //Limite da tela utilizada
    float limite;

    //velocidade de movimentação do tiro em Y
    float velocidade;
    
    //Escala do tamanho do tiro
    float escala;

    //Estado que indica se está movimentando ou não, para animação: 0-parado, 1-movimentando
    int movimentando;
    //Estado que indica se atirou ou não, para animação: 0-não atirou, 1-atirou
    int atirou;
    //Estado que indica se o tiro colidiu ou não, para animação: 0-não colidiu, 1-colidiu
    int colidiu;

    //Largura e altura para interpretar as colisões
	float largura;
	float altura;

    Tiro(int s, float pos_x_jogador, float pos_y_jogador, float pos_z_jogador){

        //Posição inicial do tiro (dentro do avião)
        pos_x = pos_x_jogador;
        pos_y = pos_y_jogador + 15.0;
        pos_z = pos_z_jogador;

        //Definição da velocidade inicial do tiro em Y
        velocidade = 30.0f;

        //Definição do limite da tela
        limite = s;

        //Definição da escala do tiro
        escala = 5.0f;

        //Cálculo de largura e altura baseada na escala
		altura = 3.0f * escala;
		largura = 1.0f * escala;

        //Estado inicial de movimentação = 0-parado
        movimentando = 0;
        atirou = 0;
        colidiu = 0;
    };
    
    //Atualiza o desenho
    void atualizar_desenho(){

        glPushMatrix();
        //Translada o desenho para a posição atual
        glTranslatef(pos_x, pos_y, pos_z);
        
        //Desenha o tiro
        if (atirou)
            desenhar_tiro();
        
        glPopMatrix();

    }
    
    //Movimenta o tiro até o limite da câmera
    void movimentar(float y, float novo_x_jogador, float novo_y_jogador, float novo_z_jogador){
        if (movimentando) {
            pos_x = novo_x_jogador;
            pos_y += y;
            pos_z = novo_z_jogador;
        }
        if (colidiu || (pos_y >= limite)){
            movimentando = 0;
            atirou = 0;
            colidiu = 0;
            pos_x = novo_x_jogador;
            pos_y = novo_y_jogador + 15.0;
            pos_z = novo_z_jogador;
        }

        atualizar_desenho();
        glutPostRedisplay();
    }

    //Cálculo da colisão
    bool colidir(float x_inimigo, float y_inimigo, float l_inimigo, float a_inimigo){

        if(atirou){
            int teste = pos_y - y_inimigo;

    		if(teste < 0)
    			teste *= -1;

    		if(teste <= a_inimigo){
    			teste = pos_x - x_inimigo;

    			if(teste < 0)
    				teste *=-1;

    			if(teste < l_inimigo){
    				colidiu = 1;
    				return true;
    			}
    		}
        }

		return false;


    }

    void desenhar_tiro(){
        
        glScalef(escala, escala, escala);

        glRotatef(90, 1, 0, 0);
        glPushMatrix();
        glPushMatrix();
        glColor3ub(255, 69, 0);
        gluCylinder(gluNewQuadric(), 0.5, 0.5, 3, 20, 20);
        glPopMatrix();

        glPushMatrix();
        gluDisk(gluNewQuadric(), 0.0, 0.5, 30, 1);
        glPopMatrix();

        glPushMatrix();
        glColor3ub(255, 255, 0);
        glTranslatef(0.0,0.0,3.0);
        gluDisk(gluNewQuadric(), 0.0, 0.5, 30, 1);
        glPopMatrix();
        glPopMatrix();

    }
    
};
