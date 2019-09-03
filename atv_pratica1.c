/*
*
*   Diretivas de Compilação:
*
*   gcc atv_pratica1.c -o main -lGL -lglut -lGLU
*
*/

#include <stdio.h>
#include <GL/glut.h>

int ROTACAO = 0;
int ESCALA = 0;
int TRANSLACAO = 1;

int VALOR_TRANLACAO_X = 0;
int VALOR_TRANLACAO_Y = 0;

int VALOR_ROTACAO = 0;

float VALOR_ESCALA = 0;

#define COMECO_X 0 //10
#define FIM_X 10 //20

#define COMECO_Y 0 //20
#define FIM_Y 10 //30

int init(void){
    //define a cor de fundo
    glClearColor(1.0,1.0,1.0,0.0);
    //carrega a matriz de projeção
    glMatrixMode(GL_PROJECTION);
    //define projeção ortogonal 2D
    gluOrtho2D(0.0,100.0,0.0,100.0);
}

void desenhaQuadrado (void){


    /*Escala*/
//    glTranslatef((COMECO_X+FIM_X)/2,(COMECO_Y+FIM_Y)/2,0); 
//    glScalef(VALOR_ESCALA,VALOR_ESCALA,0.0); // faza escala
//    glTranslatef(-(COMECO_X+FIM_X)/2,-(COMECO_Y+FIM_Y)/2,0); 
    

    glColor3f(1.0,0.0,0.0); // Altera o atributo de cor
    glBegin(GL_POLYGON);// desenha um quadrado

        glVertex2f(COMECO_X,COMECO_Y);
        glVertex2f(COMECO_X,FIM_Y);
        glVertex2f(FIM_X,FIM_Y);
        glVertex2f(FIM_X,COMECO_Y);

    glEnd();
    glutPostRedisplay();
}


void catchKey(int key){

        switch(key){
        case 116:
            printf("Ativado o modo = [Translação]\n");
            ROTACAO = 0;
            ESCALA = 0;
            TRANSLACAO = 1;
        break;	
        case 114:
            printf("Ativado o modo = [Rotação]\n");
            ROTACAO = 1;
            ESCALA = 0;
            TRANSLACAO = 0;
        break;
        case 101:
            printf("Ativado o modo = [Escala]\n");
            ROTACAO = 0;
            ESCALA = 1;
            TRANSLACAO = 0;
        break;
    }
    glutPostRedisplay();
}

void SpecialInput(int key, int x, int y){

    if (TRANSLACAO == 1){

        switch(key){
            case GLUT_KEY_UP:
                VALOR_TRANLACAO_Y+=1;
            break;
            case GLUT_KEY_DOWN:
                VALOR_TRANLACAO_Y-=1;
            break;
            case GLUT_KEY_LEFT:
                VALOR_TRANLACAO_X-=1;

            break;
            case GLUT_KEY_RIGHT:
                VALOR_TRANLACAO_X+=1;
            break;
        }
        
    }else if(ROTACAO == 1){

        switch(key){
            case GLUT_KEY_LEFT:
                VALOR_ROTACAO += 10;

            break;
            case GLUT_KEY_RIGHT:
                VALOR_ROTACAO -= 10;
            break;
        }
    }else if(ESCALA == 1){

        switch(key){
            case GLUT_KEY_UP:
                VALOR_ESCALA += 2.0;

            break;
            case GLUT_KEY_DOWN:
                VALOR_ESCALA -= 0.5;
            break;
        }
    }
    glutPostRedisplay();
}

void drawBitmapText(float x,float y) {

    glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(x, y);
    
    if(ESCALA == 1){
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, "E");
        
    }else if(TRANSLACAO == 1){
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, "T");
    }else if (ROTACAO == 1){

        glutBitmapString(GLUT_BITMAP_HELVETICA_18, "R");
    }

}

int display(void){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutKeyboardFunc(catchKey);
    glutSpecialFunc(SpecialInput);

    /*Translação */
    glTranslatef(VALOR_TRANLACAO_X,VALOR_TRANLACAO_Y,0);

    /*Rotação */
    glTranslatef((COMECO_X+FIM_X)/2,(COMECO_Y+FIM_Y)/2,0);
    glRotatef(VALOR_ROTACAO,0,0,1);
    glTranslatef(-(COMECO_X+FIM_X)/2,-(COMECO_Y+FIM_Y)/2,0);

    if(VALOR_ESCALA != 0){
        /*Escala*/
        glTranslatef((COMECO_X+FIM_X)/2,(COMECO_Y+FIM_Y)/2,0); 
        glScalef(VALOR_ESCALA,VALOR_ESCALA,0.0); // faza escala
        glTranslatef(-(COMECO_X+FIM_X)/2,-(COMECO_Y+FIM_Y)/2,0);
    }

    desenhaQuadrado();

    drawBitmapText((COMECO_X+FIM_X)/2,(COMECO_Y+FIM_Y)/2);
    glFlush(); //desenha os comandos não executados
}

int main(int argc, char** argv){

    glutInit(&argc, argv);//inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);//modo de display
    glutInitWindowPosition(200,0);//posição inicial da janela
    glutInitWindowSize(500,500);//largura e altura da janela
    glutCreateWindow("Atividade Pratica 1");//cria a janela de exibição

    init();//função de inicialização

    //estabelece a função display como a função callback de exibição
    glutDisplayFunc(display);
    
    glutMainLoop();// mostra tudo e espere

}
