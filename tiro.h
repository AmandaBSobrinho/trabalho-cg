class Tiro{
    
    public:
    //Posições atuais
    float pos_x;
    float pos_y;
    float pos_z;

    //Limite da tela utilizada
    float limite;
    
    //Escala do tamanho do tiro
    float escala;

    Tiro(int s){

        //Posição inicial do tiro (dentro do avião)
        pos_x = 1.0f;
        pos_y = -280.0f;
        pos_z = 1.0f;

        //Definição do limite da tela
        limite = s;

        //Definição da escala do tiro
        escala = 30.0f;
        
    };
    
    //Atualiza o desenho
    void atualizar_desenho(){

        glPushMatrix();
        //Translada o desenho para a posição atual
        glTranslatef(pos_x, pos_y, pos_z);

        //Desenha o tiro
        desenhar_tiro();
        glPopMatrix();

    }
    
    //Movimenta o tiro até o limite da câmera
    void movimentar(float y){
        
        while (pos_y <= limite) {
            pos_y += y;
        }
        reset();
    
        
        atualizar_desenho();
        glutPostRedisplay();
    }
    
    //Reinicializa a posição do tiro, reutilizando o objeto já criado
    void reset(){
        
        pos_x = 1.0f;
        pos_y = -280.0f;
        pos_z = 1.0f;
        
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
