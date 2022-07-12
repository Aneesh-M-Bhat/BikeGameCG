#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <ctime>

#define COLUMNS 100
#define ROWS 100
#define FPS 20
struct point
{
    int x;
    int y;
};
short bDirectionHorizontal = 1;
short bDirectionVertical = 0;
bool obstacleSpawn = false;
point bikePos = {(int)(COLUMNS * 0.1), (int)(ROWS * 0.5)};
point obstaclePos;
bool gameOver = false;

void drawRect(point *arr, int startX, int startY, int size)
{
    for (int i = 0; i < size; i++)
    {
        glRecti(arr[i].x + startX, arr[i].y + startY, arr[i].x + 1 + startX, arr[i].y + 1 + startY);
    }
}

void drawUsn1(int startX, int startY)
{
    point coor4[7] = {{0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 1}, {1, 2}, {2, 1}};
    point coorJ[8] = {{4, 0}, {4, 1}, {5, 0}, {5, 3}, {6, 0}, {6, 1}, {6, 2}, {6, 3}};
    point coorK[8] = {{8, 0}, {8, 1}, {8, 2}, {8, 3}, {9, 1}, {9, 2}, {10, 0}, {10, 3}};
    point coor1[7] = {{12, 0}, {12, 2}, {13, 0}, {13, 1}, {13, 2}, {13, 3}, {14, 0}};
    point coor9a[9] = {{16, 1}, {16, 2}, {16, 3}, {17, 1}, {17, 3}, {18, 0}, {18, 1}, {18, 2}, {18, 3}};
    point coorC[8] = {{20, 0}, {20, 1}, {20, 2}, {20, 3}, {21, 0}, {21, 3}, {22, 0}, {22, 3}};
    point coorS[10] = {{24, 0}, {24, 2}, {24, 3}, {25, 0}, {25, 1}, {25, 2}, {25, 3}, {26, 0}, {26, 1}, {26, 3}};
    point coor0a[10] = {{28, 0}, {28, 1}, {28, 2}, {28, 3}, {29, 0}, {29, 3}, {30, 0}, {30, 1}, {30, 2}, {30, 3}};
    point coor0b[10] = {{32, 0}, {32, 1}, {32, 2}, {32, 3}, {33, 0}, {33, 3}, {34, 0}, {34, 1}, {34, 2}, {34, 3}};
    point coor9b[9] = {{36, 1}, {36, 2}, {36, 3}, {37, 1}, {37, 3}, {38, 0}, {38, 1}, {38, 2}, {38, 3}};
    glColor3f(0.784, 0.635, 0.784);
    drawRect(coor4, startX, startY, 7);
    drawRect(coorJ, startX, startY, 8);
    drawRect(coorK, startX, startY, 8);
    drawRect(coor1, startX, startY, 7);
    drawRect(coor9a, startX, startY, 9);
    drawRect(coorC, startX, startY, 8);
    drawRect(coorS, startX, startY, 10);
    drawRect(coor0a, startX, startY, 10);
    drawRect(coor0b, startX, startY, 10);
    drawRect(coor9b, startX, startY, 9);
}

void drawUsn2(int startX, int startY)
{
    point coor4a[7] = {{0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 1}, {1, 2}, {2, 1}};
    point coorJ[8] = {{4, 0}, {4, 1}, {5, 0}, {5, 3}, {6, 0}, {6, 1}, {6, 2}, {6, 3}};
    point coorK[8] = {{8, 0}, {8, 1}, {8, 2}, {8, 3}, {9, 1}, {9, 2}, {10, 0}, {10, 3}};
    point coor1a[7] = {{12, 0}, {12, 2}, {13, 0}, {13, 1}, {13, 2}, {13, 3}, {14, 0}};
    point coor9a[9] = {{16, 1}, {16, 2}, {16, 3}, {17, 1}, {17, 3}, {18, 0}, {18, 1}, {18, 2}, {18, 3}};
    point coorC[8] = {{20, 0}, {20, 1}, {20, 2}, {20, 3}, {21, 0}, {21, 3}, {22, 0}, {22, 3}};
    point coorS[10] = {{24, 0}, {24, 2}, {24, 3}, {25, 0}, {25, 1}, {25, 2}, {25, 3}, {26, 0}, {26, 1}, {26, 3}};
    point coor0[10] = {{28, 0}, {28, 1}, {28, 2}, {28, 3}, {29, 0}, {29, 3}, {30, 0}, {30, 1}, {30, 2}, {30, 3}};
    point coor4b[7] = {{32, 1}, {32, 2}, {32, 3}, {33, 0}, {33, 1}, {33, 2}, {34, 1}};
    point coor1b[7] = {{36, 0}, {36, 2}, {37, 0}, {37, 1}, {37, 2}, {37, 3}, {38, 0}};
    glColor3f(0.784, 0.635, 0.784);
    drawRect(coor4a, startX, startY, 7);
    drawRect(coorJ, startX, startY, 8);
    drawRect(coorK, startX, startY, 8);
    drawRect(coor1a, startX, startY, 7);
    drawRect(coor9a, startX, startY, 9);
    drawRect(coorC, startX, startY, 8);
    drawRect(coorS, startX, startY, 10);
    drawRect(coor0, startX, startY, 10);
    drawRect(coor4b, startX, startY, 7);
    drawRect(coor1b, startX, startY, 7);
}

void drawName1(int startX, int startY)
{
    point coorA[14] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 1}, {1, 4}, {2, 1}, {2, 4}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}};
    point coorN[14] = {{5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {6, 2}, {6, 3}, {7, 1}, {7, 2}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}};
    point coorEa[13] = {{10, 0}, {10, 1}, {10, 2}, {10, 3}, {10, 4}, {11, 0}, {11, 2}, {11, 4}, {12, 0}, {12, 2}, {12, 4}, {13, 0}, {13, 4}};
    point coorEb[13] = {{15, 0}, {15, 1}, {15, 2}, {15, 3}, {15, 4}, {16, 0}, {16, 2}, {16, 4}, {17, 0}, {17, 2}, {17, 4}, {18, 0}, {18, 4}};
    point coorS[14] = {{20, 0}, {20, 3}, {20, 4}, {21, 0}, {21, 2}, {21, 3}, {21, 4}, {22, 0}, {22, 1}, {22, 2}, {22, 4}, {23, 0}, {23, 1}, {23, 4}};
    point coorH[12] = {{25, 0}, {25, 1}, {25, 2}, {25, 3}, {25, 4}, {26, 2}, {27, 2}, {28, 0}, {28, 1}, {28, 2}, {28, 3}, {28, 4}};
    glColor3f(0.784, 0.635, 0.784);
    drawRect(coorA, startX, startY, 14);
    drawRect(coorN, startX, startY, 14);
    drawRect(coorEa, startX, startY, 13);
    drawRect(coorEb, startX, startY, 13);
    drawRect(coorS, startX, startY, 14);
    drawRect(coorH, startX, startY, 12);
}

void drawName2(int startX, int startY)
{
    point coorS[14] = {{0, 0}, {0, 3}, {0, 4}, {1, 0}, {1, 2}, {1, 3}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 4}, {3, 0}, {3, 1}, {3, 4}};
    point coorH[12] = {{5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {6, 2}, {7, 2}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}};
    point coorIa[14] = {{10, 0}, {10, 4}, {11, 0}, {11, 1}, {11, 2}, {11, 3}, {11, 4}, {12, 0}, {12, 1}, {12, 2}, {12, 3}, {12, 4}, {13, 0}, {13, 4}};
    point coorV[14] = {{15, 1}, {15, 2}, {15, 3}, {15, 4}, {16, 0}, {16, 1}, {16, 2}, {17, 0}, {17, 1}, {17, 2}, {18, 1}, {18, 2}, {18, 3}, {18, 4}};
    point coorA[14] = {{20, 0}, {20, 1}, {20, 2}, {20, 3}, {20, 4}, {21, 1}, {21, 4}, {22, 1}, {22, 4}, {23, 0}, {23, 1}, {23, 2}, {23, 3}, {23, 4}};
    point coorN[14] = {{25, 0}, {25, 1}, {25, 2}, {25, 3}, {25, 4}, {26, 2}, {26, 3}, {27, 1}, {27, 2}, {28, 0}, {28, 1}, {28, 2}, {28, 3}, {28, 4}};
    point coorIb[14] = {{30, 0}, {30, 4}, {31, 0}, {31, 1}, {31, 2}, {31, 3}, {31, 4}, {32, 0}, {32, 1}, {32, 2}, {32, 3}, {32, 4}, {33, 0}, {33, 4}};
    glColor3f(0.784, 0.635, 0.784);
    drawRect(coorS, startX, startY, 14);
    drawRect(coorH, startX, startY, 12);
    drawRect(coorIa, startX, startY, 14);
    drawRect(coorV, startX, startY, 14);
    drawRect(coorA, startX, startY, 14);
    drawRect(coorN, startX, startY, 14);
    drawRect(coorIb, startX, startY, 14);
}

void unit(int x, int y, float r, float g, float b)
{

    glLineWidth(1.0);
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}
void drawRect(int x, int y, float r, float g, float b)
{
    glColor3f(r, g, b);
    glRecti(x, y, x + 1, y + 1);
}
void drawTrack()
{
    for (int i = 0; i <= COLUMNS; i++)
    {
        drawRect(i, ROWS*0.75, 1.0, 1.0, 1.0);
        drawRect(i, ROWS*0.75 + 1, 1.0, 1.0, 1.0);
        drawRect(i, ROWS*0.25, 1.0, 1.0, 1.0);
        drawRect(i, ROWS*0.25+1, 1.0, 1.0, 1.0);
    }
    // for (int x = 0; x < COLUMNS; x++)
    //     for (int y = ROWS / 4; y < ROWS * 3 / 4; y++)
    //         unit(x, y, 1.0, 1.0, 1.0);
}
void drawLine(int start, int stop, int yInc)
{
    for (int i = start; i <= stop; i++)
    {
        drawRect(bikePos.x + i, bikePos.y + yInc, 1.0, 0.0, 0.0);
    }
}
void drawBike()
{
    point bikeBottomCoors[42] = {{3, 0}, {4, 0}, {5, 0}, {10, 0}, {11, 0}, {12, 0}, {2, 1}, {4, 1}, {6, 1}, {9, 1}, {11, 1}, {13, 1}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {10, 2}, {11, 2}, {12, 2}, {13, 2}, {9, 2}, {2, 3}, {4, 3}, {6, 3}, {9, 3}, {11, 3}, {13, 3}, {3, 4}, {4, 4}, {5, 4}, {7, 4}, {8, 4}, {10, 4}, {11, 4}, {12, 4}, {4, 5}, {6, 5}, {7, 5}, {8, 5}, {9, 5}, {11, 5}};
    for (int i = 0; i < 42; i++)
    {
        drawRect(bikePos.x + bikeBottomCoors[i].x, bikePos.y + bikeBottomCoors[i].y, 1.0, 0.0, 0.0);
    }
    drawLine(2, 14, 6);
    drawLine(1, 15, 7);
    drawLine(0, 15, 8);
    drawLine(5, 9, 9);
    drawLine(11, 14, 9);
    drawLine(11, 13, 10);
    drawLine(10, 12, 11);
    for (int i = 2; i <= 14; i++)
    {
        unit(bikePos.x + i, bikePos.y + 6, 1.0, 0.0, 0.0);
    }
    // unit(bikePos.x, bikePos.y, 1.0, 0.0, 0.0);
    switch (bDirectionHorizontal)
    {
    case 1:
        obstaclePos.x--;
        break;
    case 0:
        break;
    case -1:
        obstaclePos.x++;
        break;
    }
    switch (bDirectionVertical)
    {
    case 1:
        bikePos.y++;
        break;
    case 0:
        break;
    case -1:
        bikePos.y--;
        break;
    }
    if (bikePos.y < ROWS * 0.25 || bikePos.y > ROWS * 0.75 - 12)
        gameOver = true;
    if (bikePos.x + 15 == obstaclePos.x)
        for (int i = obstaclePos.y; i >= obstaclePos.y - ROWS * 0.1; i--)
        {
            if (bikePos.y + 10 >= i && i >= bikePos.y)
                gameOver = true;
        }
    // if (bikePos.x+15 == obstaclePos.x && bikePos.y <= obstaclePos.y && bikePos.y >= obstaclePos.y - ROWS * 0.2)
    //     gameOver = true;
}

void randomPoint()
{
    srand(time(NULL));
    // foodX = 1 + rand() % (COLUMNS - 3);
    // foodY = 1 + rand() % (ROWS - 3);
    obstaclePos.x = (int)(COLUMNS * 0.7 + rand() % (int)(COLUMNS * 0.3));
    obstaclePos.y = (int)(ROWS * 0.45 + rand() % (int)(ROWS * 0.3));
}

void drawObstacle()
{
    if (!obstacleSpawn)
    {
        obstacleSpawn = true;
        randomPoint();
    }
    for (int i = 0; i < ROWS * 0.1; i++)
        unit(obstaclePos.x, obstaclePos.y - i, 0.0, 0.0, 1.0);
    if (obstaclePos.x == 0 || obstaclePos.x == COLUMNS)
        obstacleSpawn = false;
}

void displayCallback()
{
    if (gameOver)
        exit(0);
    glClear(GL_COLOR_BUFFER_BIT);
    // drawUsn1(COLUMNS*0.1,ROWS*0.8);
    // drawUsn2(COLUMNS*0.1,ROWS*0.8-5);
    // drawName1(COLUMNS*0.1,ROWS*0.4);
    // drawName2(COLUMNS*0.1,ROWS*0.4-6);
    drawTrack();
    drawObstacle();
    drawBike();
    glutSwapBuffers();
}

void reshapeCallback(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timerCallback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, timerCallback, 0);
}

void keyboardCallback(int key, int, int)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        if (bDirectionVertical < 1)
            bDirectionVertical++;

        break;
    case GLUT_KEY_DOWN:
        if (bDirectionVertical > -1)
            bDirectionVertical--;

        break;
    case GLUT_KEY_RIGHT:
        if (bDirectionHorizontal < 1)
            bDirectionHorizontal++;

        break;
    case GLUT_KEY_LEFT:
        if (bDirectionHorizontal > 0)
            bDirectionHorizontal--;

        break;
    }
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("BIKE");
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);
    glutTimerFunc(0, timerCallback, 0);
    glutSpecialFunc(keyboardCallback);
    init();
    glutMainLoop();
    return 0;
}
