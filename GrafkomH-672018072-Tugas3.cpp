#include <gl/glut.h>

void Inisialisasi(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(4.0f);
    gluOrtho2D(0.0,640.0,0.0,480.0);
}

void Display(void)
{
    float
        xA1 = 50, yA1 = 50,
        xB1 = 150, yB1 = 200,

        xA2 = 50, yA2 = 200,
        xB2 = 150, yB2 = 50,

        xA3 = 100, yA3 = 50,
        xB3 = 200, yB3 = 200,

        xA4 = 100, yA4 = 200,
        xB4 = 200, yB4 = 50;

    float
        MA1B1, MA2B2, MA3B3, MA4B4,
        CA1B1, CA2B2, CA3B3, CA4B4,
        PA1B1x, PA2B2x, PA3B3x, PA4B4x,
        PA1B1y, PA2B2y, PA3B3y, PA4B4y;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(xA1, yA1);
    glVertex2f(xB1, yB1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(xA2, yA2);
    glVertex2f(xB2, yB2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(xA3, yA3);
    glVertex2f(xB3, yB3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(xA4, yA4);
    glVertex2f(xB4, yB4);
    glEnd();

    //rumus perpotongan
    MA1B1 = (yB1 - yA1) / (xB1 - xA1);
    MA2B2 = (yB2 - yA2) / (xB2 - xA2);
    MA3B3 = (yB3 - yA3) / (xB3 - xA3);
    MA4B4 = (yB4 - yA4) / (xB4 - xA4);

    CA1B1 = yA1 - (xA1 * MA1B1);
    CA2B2 = yA2 - (xA2 * MA2B2);
    CA3B3 = yA3 - (xA3 * MA3B3);
    CA4B4 = yA4 - (xA4 * MA4B4);

    //titik potong
    PA1B1x = (CA2B2 - CA1B1) / (MA1B1 - MA2B2);
    PA1B1y = (MA1B1 * PA1B1x) + CA1B1;

    PA2B2x = (CA3B3 - CA2B2) / (MA2B2 - MA3B3);
    PA2B2y = (MA2B2 * PA2B2x) + CA2B2;

    PA3B3x = (CA4B4 - CA3B3) / (MA3B3 - MA4B4);
    PA3B3y = (MA3B3 * PA3B3x) + CA3B3;

    PA4B4x = (CA4B4 - CA1B1) / (MA1B1 - MA4B4);
    PA4B4y = (MA4B4 * PA4B4x) + CA4B4;

    //hasil
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(PA1B1x, PA1B1y);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(PA2B2x, PA2B2y);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(PA3B3x, PA3B3y);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(PA4B4x, PA4B4y);
    glEnd();

    glFlush();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,460);
    glutInitWindowPosition(100,100);
    glutCreateWindow("GrafkomH-672018072-Tugas3");
    glutDisplayFunc(Display);
    Inisialisasi();
    glutMainLoop();
}
