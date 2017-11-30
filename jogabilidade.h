class Jogabilidade{
    
    public:
    int pontos;
    float combustivel;
    int tanque_combustivel;
    char escreve_pontos[20];
    int vista;

    Jogabilidade(){
        // Variável que conta a pontuação
        pontos = 0;
        
        // Variável que mede o nível de combustível (cheio = 0)
        combustivel = 0;

        // Flag que indica que um tanque de combustível foi encontrado
        tanque_combustivel = 0;

        // Flag que define a vista (superior ou atrás do avião) para desenhar o display no plano certo
        vista = 1;
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
        if (vista == 0)
            glRotatef (90.0f, 1.0f, 0.0f, 0.0f);
        while (*string)
            glutStrokeCharacter (GLUT_STROKE_ROMAN, *string++);
    }

    // Desenha o display cinza onde a pontuação e o combustível devem ficar
    void desenhar_display(){
        // Quadro cinza
        glColor3ub(128,128,128);
        glBegin(GL_POLYGON);
        if (vista) { // se vista = 1, temos a vista superior, e o display fica no plano xy
            glVertex3f(-400,-400,50);
            glVertex3f(400,-400,50);
            glVertex3f(400,-300,50);
            glVertex3f(-400,-300,50);
        }
        else { // se vista = 0, a visão é atrás do avião, e o display fica no plano xz
            glVertex3f(-400,0,-472);
            glVertex3f(400,0,-472);
            glVertex3f(400,0,-368);
            glVertex3f(-400,0,-368);
        }
        glEnd();

        // Desenho da pontuação
        glPushMatrix();
        glColor3ub(255, 255, 0);
        sprintf(escreve_pontos, "%d", pontos);
        if (vista)
            desenhar_texto (escreve_pontos, -10, -325, 60);
        else
            desenhar_texto (escreve_pontos, -10, -10, -393);
        glPopMatrix();

        // Desenho do combustível
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        if (vista){
            glVertex3f(-100,-380,60);
            glVertex3f(100,-380,60);
            glVertex3f(100,-335,60);
            glVertex3f(-100,-335,60);
        }
        else {
            glVertex3f(-100,-10,-447);
            glVertex3f(100,-10,-447);
            glVertex3f(100,-10,-402);
            glVertex3f(-100,-10,-402);
        }
        glEnd();

        glPushMatrix();
        if (vista)
            desenhar_texto ("F", 65, -360, 60);
        else
            desenhar_texto ("F", 65, -10, -427);
        glPopMatrix();

        glPushMatrix();
        if (vista)
            desenhar_texto ("1/2", -25, -360, 60);
        else
            desenhar_texto ("1/2", -25, -10, -427);
        glPopMatrix();

        glPushMatrix();
        if (vista)
            desenhar_texto ("E", -85, -360, 60);
        else
            desenhar_texto ("E", -85, -10, -427);
        glPopMatrix();
    }

    void desenhar_medidor (float x){
        glPushMatrix();
        glTranslatef(x,0,0);
        glColor3ub(255, 255, 0);
        glBegin(GL_POLYGON);
        if (vista) {
            glVertex3f(80,-380,55);
            glVertex3f(70,-380,55);
            glVertex3f(70,-345,55);
            glVertex3f(80,-345,55);
        }
        else {
            glVertex3f(80,-5,-447);
            glVertex3f(70,-5,-447);
            glVertex3f(70,-5,-412);
            glVertex3f(80,-5,-412);
        }
        glEnd();
        glPopMatrix();
    }
    
};
