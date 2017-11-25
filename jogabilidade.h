class Jogabilidade{
    
    public:
    int pontos;
    float combustivel;
    int tanque_combustivel;
    char escreve_pontos[20];

    Jogabilidade(){
        // Variável que conta a pontuação
        pontos = 0;
        
        // Variável que mede o nível de combustível (cheio = 0)
        combustivel = 0;

        // Flag que indica que um tanque de combustível foi encontrado
        tanque_combustivel = 0;
    };
    
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

    void atualizar_combustivel (){
        if (!tanque_combustivel)
            if (combustivel > -1550)
                combustivel--;
        
        if (tanque_combustivel){
            tanque_combustivel = 0;
            if (combustivel <= -40)
                combustivel += 40;
        }
        desenhar_medidor(0.1*combustivel);
        desenhar_display();
        glutPostRedisplay();
    }

    void desenhar_texto (const char *string, float x, float y, float z) {
        glTranslatef (x,y,z);
        glScalef (0.2,0.2,0.2);
        glLineWidth(2);
        while (*string)
            glutStrokeCharacter (GLUT_STROKE_ROMAN, *string++);
    }

    // Desenha o display cinza onde a pontuação e o combustível devem ficar
    void desenhar_display(){
        glColor3ub(128,128,128);
        glBegin(GL_POLYGON); 
        glVertex3f(-300,-300,50);
        glVertex3f(300,-300,50);
        glVertex3f(300,-200,50);
        glVertex3f(-300,-200,50);
        //glVertex3f(-300,0,-350);
        //glVertex3f(300,0,-350);
        //glVertex3f(300,0,-250);
        //glVertex3f(-300,0,-250);
        glEnd();

        // Desenho da pontuação
        glPushMatrix();
        glColor3ub(255, 255, 0);
        sprintf(escreve_pontos, "%d", pontos);
        desenhar_texto (escreve_pontos, -20, -225, 60);
        glPopMatrix();

        // Desenho do combustível
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP); 
        glVertex3f(-100,-280,60);
        glVertex3f(100,-280,60);
        glVertex3f(100,-235,60);
        glVertex3f(-100,-235,60);
        glEnd();

        glPushMatrix();
        desenhar_texto ("F", 65, -260, 60);
        glPopMatrix();

        glPushMatrix();
        desenhar_texto ("1/2", -25, -260, 60);
        glPopMatrix();

        glPushMatrix();
        desenhar_texto ("E", -85, -260, 60);
        glPopMatrix();
    }

    void desenhar_medidor (float x){
        glPushMatrix();
        glTranslatef(x,0,0);
        glColor3ub(255, 255, 0);
        glBegin(GL_POLYGON); 
        glVertex3f(80,-280,55);
        glVertex3f(70,-280,55);
        glVertex3f(70,-245,55);
        glVertex3f(80,-245,55);
        glEnd();
        glPopMatrix();
    }
    
};
