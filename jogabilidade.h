class Jogabilidade{
    
    public:
    int pontos;
    float combustivel;
    int tanque_combustivel;
    char escreve_pontos[20];
    int vista;

    int vidas;

    Jogabilidade(){
        // Variável que conta a pontuação
        pontos = 0;
        
        // Variável que mede o nível de combustível (cheio = 0)
        combustivel = 0;

        // Flag que indica que um tanque de combustível foi encontrado
        tanque_combustivel = 0;

        // Flag que define a vista (superior ou atrás do avião) para desenhar o display no plano certo
        vista = 1;

        vidas = 3;
    };

    void reiniciar(){
        // Variável que conta a pontuação
        pontos = 0;
        
        // Variável que mede o nível de combustível (cheio = 0)
        combustivel = 0;

        // Flag que indica que um tanque de combustível foi encontrado
        tanque_combustivel = 0;

        // Flag que define a vista (superior ou atrás do avião) para desenhar o display no plano certo
        //vista = 1;

        vidas = 3;
    }

    void reset(){

        vidas--;
        combustivel = 0;

    }
    
    // Faz a contagem de pontos em relação aos objetos destruídos
    void atualizar_pontuacao (int tipo_objeto_destruido){
        // Tipo 0 - Helicóptero, Tipo 1 - Navio, Tipo 2 - tanque de combustível, Tipo 3 - Ponte
        int tipo = tipo_objeto_destruido;

        switch (tipo) {
            case 0:
                pontos += 60;
                break;
            case 1:
                pontos += 30;
                break;
            case 2:
                pontos += 80;
                break;
            case 3:
                pontos += 500;
                break;
        }

        desenhar_display();
        glutPostRedisplay();
    }

    void desenhar_texto (const char *string, float x, float y, float z, int line) {

        glPushMatrix();

        glTranslatef (x,y,z);
        glScalef (0.2,0.2,0.2);
        glLineWidth(line);
        while (*string)
            glutStrokeCharacter (GLUT_STROKE_ROMAN, *string++);

        glPopMatrix();
    }

    void atualizar_combustivel (){
        if (!tanque_combustivel)
            if (combustivel > -1550)
                combustivel--;
        
        if (tanque_combustivel){
            tanque_combustivel = 0;
            if (combustivel <= -200)
                combustivel += 200;
            else
                combustivel += (0 - combustivel);
        }

        desenhar_display();
        glutPostRedisplay();
    }

    // Desenha o display cinza onde a pontuação e o combustível devem ficar
    void desenhar_display(){

        glPushMatrix();

        if(vista == 0){

            glScalef(0.15f, 0.15f, 0.15f);
            glTranslatef(0, -2050, 0);
            glRotatef(90, 1, 0, 0);
            glTranslatef(0, 400, 0);

        }

        desenhar_medidor(0.1*combustivel);
        
        // Quadro cinza
        glColor3ub(128,128,128);
        glBegin(GL_POLYGON);
            glVertex3f(-400,-400,100);
            glVertex3f(400,-400,100);
            glVertex3f(400,-300,100);
            glVertex3f(-400,-300,100);
        glEnd();

        // Desenho da pontuação
        glColor3ub(255, 255, 0);
        sprintf(escreve_pontos, "%d", pontos);
        desenhar_texto (escreve_pontos, -10, -325, 120, 2);

        // Desenho do combustível
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
            glVertex3f(-100,-380,120);
            glVertex3f(100,-380,120);
            glVertex3f(100,-335,120);
            glVertex3f(-100,-335,120);
        glEnd();

        desenhar_texto ("F", 65, -360, 120, 2);

        desenhar_texto ("1/2", -25, -360, 120, 2);

        desenhar_texto ("E", -85, -360, 120, 2);
        glPopMatrix();
    }

    void Mensagem_Game_Over(){

        glPushMatrix();
        glColor3ub(255, 0, 0);
        glScalef (2,2,2);
        desenhar_texto ("GAME OVER", -80, 0, 0, 3);
        sprintf(escreve_pontos, "%d", pontos);

        glColor3ub(255, 255, 0);
        glScalef (1,1,1);
        desenhar_texto ("Pontos:", -50, -40, 0, 3);
        desenhar_texto (escreve_pontos, -50, -80, 0, 3);
        glPopMatrix();

    }

    void desenhar_medidor (float x){
        glPushMatrix();

        glTranslatef(x,0,0);
        glColor3ub(255, 255, 0);

        glBegin(GL_POLYGON);
            glVertex3f(80,-380,110);
            glVertex3f(70,-380,110);
            glVertex3f(70,-345,110);
            glVertex3f(80,-345,110);
        glEnd();

        glPopMatrix();
    }
    
};
