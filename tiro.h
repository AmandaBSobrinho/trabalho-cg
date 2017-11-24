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
    int atirou;

    Tiro(int s, float pos_x_jogador, float pos_y_jogador, float pos_z_jogador){

        //Posição inicial do tiro (dentro do avião)
        pos_x = pos_x_jogador;
        pos_y = pos_y_jogador + 15.0;
        pos_z = pos_z_jogador;

        //Definição da velocidade inicial do tiro em Y
        velocidade = 40.0f;

        //Definição do limite da tela
        limite = s;

        //Definição da escala do tiro
        escala = 5.0f;

        //Estado inicial de movimentação = 0-parado
        movimentando = 0;
        atirou = 0;
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
        if(pos_y >= limite){
            movimentando = 0;
            atirou = 0;
            pos_x = novo_x_jogador;
            pos_y = novo_y_jogador + 15.0;
            pos_z = novo_z_jogador;
        }

        atualizar_desenho();
        glutPostRedisplay();
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
