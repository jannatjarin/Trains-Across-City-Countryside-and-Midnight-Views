#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#include <iostream>
using namespace std;

int currentScenario = 1; // Global

// Scenario 1 variables
float train1_y = 1.4f;
bool trainMoving = true;

float bus1_x = 0.2f;
bool bus1Moving = false;


float bus_x= -0.1f;
bool busMoving=false;

float truck_x = -0.2f;
bool truckMoving = false;

float car1_x = 0.9f;
bool car1Moving = false;

bool barVisible = true;


float ship_x = -0.1f;
bool shipMoving = false;

// Scenario 2 variables
GLfloat cloudOffset = 0.0f;
GLfloat cloudSpeed = 0.001f;
float boat2_x = 0.0f;
float boat1_x = 0.6f;
float train2_y = 0.0f;
float rain_offset = 0.0f;
bool isRaining = false;
GLfloat bird_x = -0.43f;
bool birdsMoving = true;


// Scenario 3 variables
GLboolean isNightMode = GL_FALSE;
float boat3_x = -0.6f;
int boat3_visible = 1;
float bird1_x = -0.2f;
float bird2_x = -0.225f;
float bird3_x = 3.0f;
int birds_visible = 1;

// circle
GLvoid drawCircle(GLdouble xc, GLdouble yc, GLdouble radius)
{
    glBegin(GL_POLYGON);
    for (float i = 0; i <= 2 * 3.1416; i += 0.01f)
    {
        glVertex2f(xc + radius * cos(i), yc + radius * sin(i));
    }
    glEnd();
}


// text rendering
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

// Sound
void play_sound(const char* soundFile)
{
    PlaySound(NULL, NULL, 0);
    if (!PlaySound(soundFile, NULL, SND_FILENAME | SND_ASYNC))
    {
        cerr << "Error playing sound!" << endl;
    }
}

// Mouse click
void mouse(int button, int state, int x, int y)
{
    if (currentScenario == 1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        shipMoving = !shipMoving;
    }
    glutPostRedisplay();
}


void update(int value)
{
    // Scenario 1 animations
    if (currentScenario == 1) {
        if (barVisible && trainMoving) {
            train1_y -= 0.002f;
            if (train1_y < -1.0f - (6 * 0.45f))
            {
                train1_y = 1.4f; // Reset
            }
        }
        if (busMoving)
        {
            bus_x -= 0.0018f;
            if (bus_x < -1.0f)
            {
                bus_x = 1.0f;     // Reset
            }
        }

        if (!barVisible)
        {
            if (bus1Moving)
            {
                bus1_x += 0.0018f;
                if (bus1_x > 1.0f)
                {
                    bus1_x = -1.0f;
                }
            }

            if (truckMoving) {
                truck_x += 0.0018f;
                if (truck_x > 1.0f)
                {
                    truck_x = -1.0f;
                }
            }

            if (car1Moving) {
                car1_x -= 0.0018f;
                if (car1_x < -1.0f)
                {
                    car1_x = 1.0f;
                }
            }
        }

    // Ship movement
    if (shipMoving)
    {
        ship_x += 0.001f;
        if (ship_x > 1.5f)
        {
            ship_x = 0.4f;
        }
    }
    }

    // Scenario 2 animations
    else if (currentScenario == 2)
    {
        cloudOffset += cloudSpeed;

        if (boat2_x > -1.2f)
        {
            boat2_x -= 0.001f;
        }

        if (boat1_x > 0.1f)
        {
            boat1_x -= 0.0001f;
        }

        train2_y -= 0.002f;
        if (train2_y < -1.0f - 2.1f)
        {
            train2_y = 1.0f + 0.3f;
        }

        rain_offset -= 0.03f;
        if (rain_offset < -0.1f)
        {
            rain_offset = 0.8f;
        }

        if (birdsMoving)
        {
            bird_x += 0.001f;
            if (bird_x > 1.0f + 0.43f)
            {
                birdsMoving = false; // Stop
            }
        }
    }

    // Scenario 3 animations
    else if(currentScenario == 3)
    {
        if (boat3_x < 0.37f)
        {
            boat3_x += 0.002f;
        } else {
            boat3_visible = 0;
        }
    }

    if (bird1_x < 0.9f) {
        bird1_x += 0.0003f;
        bird2_x += 0.0003f;
        bird3_x += 0.0003f;
    } else {
        birds_visible = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}


// SCENARIO 1 FUNCTIONS


void line()
{
             // line
for (int i = 0; i <= 42; i++)

  {
      glLineWidth(7);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0f, 0.1f);
        glVertex2f(-0.97f, 0.1f);

    glEnd();

  glTranslatef(0.05f, 0.0f, 0.0f);
}
glEnd();
glLoadIdentity();
}
 // 2
void line1()
          {
             // line
for (int i = 0; i <= 42; i++)

  {
      glLineWidth(7);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0f, -0.1f);
        glVertex2f(-0.97, -0.1f);

    glEnd();

  glTranslatef(0.05f, 0.0f, 0.0f);
}
glEnd();
glLoadIdentity();
          }



void windowUnit()
{
    glBegin(GL_QUADS);
        glColor3f(0.83f, 0.83f, 0.83f); // light gray
        glVertex2f(-0.98f, 0.58f);
        glVertex2f(-0.92f, 0.58f);
        glVertex2f(-0.92f, 0.50f);
        glVertex2f(-0.98f, 0.50f);
    glEnd();

    // Vertical bar
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // white
        glVertex2f(-0.955f, 0.58f);
        glVertex2f(-0.945f, 0.58f);
        glVertex2f(-0.945f, 0.50f);
        glVertex2f(-0.955f, 0.50f);
    glEnd();

    // Horizontal bar
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // white
        glVertex2f(-0.98f, 0.545f);
        glVertex2f(-0.92f, 0.545f);
        glVertex2f(-0.92f, 0.535f);
        glVertex2f(-0.98f, 0.535f);
    glEnd();
}




void buildings()
{
    // left 1
    glBegin(GL_QUADS);
        glColor3f(0.81f, 0.07f, 0.15f);
        glVertex2f(-1.0f, 0.6f);
        glVertex2f(-0.8f, 0.6f);
        glVertex2f(-0.8f, 0.26f);
        glVertex2f(-1.0f, 0.26f);
    glEnd();

    glPushMatrix();
    for (int i = 0; i < 3; i++)
    {
        // left window
        windowUnit();

        // right window
        glTranslatef(0.1f, 0.0f, 0.0f);
        windowUnit();

        glTranslatef(-0.1f, -0.1f, 0.0f);
    }
    glPopMatrix();


    // left 2
    glBegin(GL_QUADS);
        glColor3f(0.61f, 0.97f, 0.45f);
        glVertex2f(-0.9f, 0.7f);
        glVertex2f(-0.8f, 0.7f);
        glVertex2f(-0.8f, 0.6f);
        glVertex2f(-0.9f, 0.6f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.1f, 0.1f, 0.0f);
    for (int i = 0; i < 1; i++)
    {
        windowUnit();
        glTranslatef(0.1f, 0.0f, 0.0f);
        windowUnit();
    }
    glPopMatrix();


    //left 3
    glBegin(GL_QUADS);
        glColor3f(0.61f, 0.07f, 0.45f);
        glVertex2f(-0.8f, 0.8f);
        glVertex2f(-0.6f, 0.8f);
        glVertex2f(-0.6f, 0.26f);
        glVertex2f(-0.8f, 0.26f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.2f, 0.2f, 0.0f);
    for (int i = 0; i < 4; i++)
    {
        windowUnit();
        glTranslatef(0.1f, 0.0f, 0.0f);
        windowUnit();
        glTranslatef(-0.1f, -0.1f, 0.0f);
    }
    glPopMatrix();


    // left 4
    glBegin(GL_QUADS);
        glColor3f(0.81f, 0.5f, 0.45f);
        glVertex2f(-0.6f, 0.65f);
        glVertex2f(-0.5f, 0.65f);
        glVertex2f(-0.5f, 0.26f);
        glVertex2f(-0.6f, 0.26f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.4f, 0.0f, 0.0f);
    for (int i = 0; i < 3; i++)
    {
        windowUnit();
        glTranslatef(0.1f, 0.0f, 0.0f);
        windowUnit();
        glTranslatef(-0.1f, -0.1f, 0.0f);
    }
    glPopMatrix();


    // left 5
    glBegin(GL_QUADS);
        glColor3f(0.31f, 0.4f, 0.45f);
        glVertex2f(-0.54f, 0.58f);
        glVertex2f(-0.32f, 0.58f);
        glVertex2f(-0.32f, 0.26f);
        glVertex2f(-0.54f, 0.26f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.45f, -0.05f, 0.0f);
    for (int i = 0; i < 2; i++)
    {
        windowUnit();
        glTranslatef(0.1f, 0.0f, 0.0f);
        windowUnit();
        glTranslatef(-0.1f, -0.1f, 0.0f);
    }
    glPopMatrix();


    // left 6
    glBegin(GL_QUADS);
        glColor3f(0.9f, 0.4f, 0.45f);
        glVertex2f(-0.4f, 0.72f);
        glVertex2f(-0.3f, 0.72f);
        glVertex2f(-0.3f, 0.26f);
        glVertex2f(-0.4f, 0.26f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.6f, 0.1f, 0.0f);
    for (int i = 0; i < 3; i++)
    {
        windowUnit();
        glTranslatef(0.1f, 0.0f, 0.0f);
        windowUnit();
        glTranslatef(-0.1f, -0.1f, 0.0f);
    }
    glPopMatrix();


    // left 7
        glBegin(GL_QUADS);
        glColor3f(0.51f, 0.4f, 0.75f);
        glVertex2f(-0.3f, 0.8f);
        glVertex2f(-0.1f, 0.8f);
        glVertex2f(-0.1f, 0.26f);
        glVertex2f(-0.3f, 0.26f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.70f, 0.2f, 0.0f);
    for (int i = 0; i < 4; i++)
    {
        windowUnit();
        glTranslatef(0.1f, 0.0f, 0.0f);
        windowUnit();
        glTranslatef(-0.1f, -0.1f, 0.0f);
    }
    glPopMatrix();





// right side

// shop 1
glBegin(GL_POLYGON); // body
    glColor3f(1.0f, 0.71f, 0.76f);
    glVertex2f(0.50f, 0.26f);
    glVertex2f(0.50f, 0.47f);
    glVertex2f(0.67f, 0.47f);
    glVertex2f(0.67f, 0.26f);
glEnd();

glBegin(GL_POLYGON); // roof
    glColor3f(0.50f, 0.0f, 0.0f);
    glVertex2f(0.50f, 0.47f);
    glVertex2f(0.50f, 0.55f);
    glVertex2f(0.67f, 0.55f);
    glVertex2f(0.67f, 0.47f);
glEnd();

glBegin(GL_POLYGON); // shelter
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.48f, 0.40f);
    glVertex2f(0.69f, 0.40f);
    glVertex2f(0.69f, 0.45f);
    glVertex2f(0.67f, 0.47f);
    glVertex2f(0.50f, 0.47f);
    glVertex2f(0.48f, 0.45f);
glEnd();

glBegin(GL_POLYGON); // door
    glColor3f(0.0f, 0.90f, 0.90f);
    glVertex2f(0.53f, 0.26f);
    glVertex2f(0.53f, 0.36f);
    glVertex2f(0.59f, 0.36f);
    glVertex2f(0.59f, 0.26f);
glEnd();

glBegin(GL_POLYGON); // window
    glColor3f(0.0f, 0.90f, 0.90f);
    glVertex2f(0.61f, 0.31f);
    glVertex2f(0.61f, 0.36f);
    glVertex2f(0.65f, 0.36f);
    glVertex2f(0.65f, 0.31f);
glEnd();

//shop 2
glBegin(GL_POLYGON); // body
    glColor3f(1.0f, 7.80f, 0.40f);
    glVertex2f(0.73f, 0.26f);
    glVertex2f(0.73f, 0.50f);
    glVertex2f(0.95f, 0.50f);
    glVertex2f(0.95f, 0.26f);
glEnd();

glBegin(GL_POLYGON); // roof
    glColor3f(0.70f, 0.35f, 0.0f);
    glVertex2f(0.73f, 0.55f);
    glVertex2f(0.95f, 0.55f);
    glVertex2f(0.95f, 0.50f);
    glVertex2f(0.73f, 0.50f);
glEnd();
glBegin(GL_POLYGON); // roof top
    glColor3f(0.70f, 0.35f, 0.0f);
    glVertex2f(0.78f, 0.55f);
    glVertex2f(0.90f, 0.55f);
    glVertex2f(0.87f, 0.60f);
    glVertex2f(0.81f, 0.60f);

glEnd();

glBegin(GL_POLYGON); // inside
    glColor3f(.30f, 0.15f, 0.0f);
    glVertex2f(0.75f, 0.35f);
    glVertex2f(0.75f, 0.48f);
    glVertex2f(0.93f, 0.48f);
    glVertex2f(0.93f, 0.35f);
glEnd();

glBegin(GL_POLYGON); // table
    glColor3f(0.50f, 0.25f, 0.0f);
    glVertex2f(0.75f, 0.26f);
    glVertex2f(0.75f, 0.35f);
    glVertex2f(0.93f, 0.35f);
    glVertex2f(0.93f, 0.26f);
glEnd();

glBegin(GL_POLYGON); // shelter
    glColor3f(0.90f, 0.45f, 0.0f);
    glVertex2f(0.71f, 0.43f);
    glVertex2f(0.97f, 0.43f);
    glVertex2f(0.97f, 0.47f);
    glVertex2f(0.95f, 0.50f);
    glVertex2f(0.73f, 0.50f);
    glVertex2f(0.71f, 0.47f);
glEnd();


}


void railLine1()
{
   //for rail line 1

    glLineWidth(10); // line 1
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);

        glVertex2f(-0.0f, 0.8f);
        glVertex2f(-0.0f, -0.8f);

    glEnd();

    glLineWidth(10); //line 2
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);

        glVertex2f(0.1f, 0.8f);
        glVertex2f(0.1f, -0.8f);

    glEnd();

    glLineWidth(20);//vertical line midddle
      /*glBegin(GL_LINES);
          glColor3f(0.0f, 0.0f, 0.0f); // black axes

          glVertex2f(-0.05f, 0.0f);
          glVertex2f(0.15f, 0.0f);

      glEnd(); */


for (int i = 0; i <= 5; i++)
{
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.05f, 0.0f);
        glVertex2f( 0.15f, 0.0f);
    glEnd();

    glTranslatef(0.0f, 0.14f, 0.0f);
}


glEnd();
glLoadIdentity();


for (int i = 0; i <= 5; i++)
{
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.05f, 0.0f);
        glVertex2f( 0.15f, 0.0f);
    glEnd();

    glTranslatef(0.0f, -0.14f, 0.0f);
}

glEnd();
glLoadIdentity();


      //for rail line 2


       glLineWidth(10); // line 3
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // black axes

        glVertex2f(0.25f, 0.8f);
        glVertex2f(0.25f, -0.8f);

    glEnd();

    glLineWidth(10); //line 4
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // black axes

        glVertex2f(0.35f, 0.8f);
        glVertex2f(0.35f, -0.8f);

    glEnd();

 glLineWidth(20);

for (int i = 0; i <= 5; i++)
{
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.4f, 0.0f);
    glEnd();

    glTranslatef(0.0f, 0.14f, 0.0f);
}

glEnd();
glLoadIdentity();


for (int i = 0; i <= 5; i++)
{
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.4f, 0.0f);
    glEnd();

    glTranslatef(0.0f, -0.14f, 0.0f);
}

glEnd();
glLoadIdentity();

}

// train1

void train1()
{
    glPushMatrix();
    glTranslatef(0.0f, train1_y - 0.8f, 0.0f);

    // 2nd body
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(0.3f, -0.01f, 0.05f);

    glColor3f(0.0f, 0.90f, 0.90f);
    drawCircle(0.3f, -0.01f, 0.04f);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.25f, 0.37f);
        glVertex2f(0.25f, -0.03f);
        glVertex2f(0.35f, -0.03f);
        glVertex2f(0.35f, 0.37f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.27f, 0.37f);
        glVertex2f(0.27f, 0.1f);
        glVertex2f(0.33f, 0.1f);
        glVertex2f(0.33f, 0.37f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.32f, 0.37f);
        glVertex2f(0.32f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.26f, 0.1f);
        glVertex2f(0.26f, 0.08f);
        glVertex2f(0.34f, 0.08f);
        glVertex2f(0.34f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex2f(0.25f, -0.01f);
        glVertex2f(0.25f, -0.02f);
        glVertex2f(0.35f, -0.02f);
        glVertex2f(0.35f, -0.01f);
    glEnd();

    // extra bodies
    for(int i = 1; i <= 6; i++) {
        glPushMatrix();
        glTranslatef(0.0f, 0.45f * i, 0.0f);

        // Front circle
        glColor3f(1.0f, 0.0f, 0.0f);
        glColor3f(0.0f, 0.90f, 0.90f);

       // Connecting bar
        glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.29f, -0.03f);
            glVertex2f(0.31f, -0.03f);
            glVertex2f(0.31f, -0.08f);
            glVertex2f(0.29f, -0.08f);
        glEnd();

        // 1st body
        glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(0.25f, 0.37f);
            glVertex2f(0.25f, -0.03f);
            glVertex2f(0.35f, -0.03f);
            glVertex2f(0.35f, 0.37f);
        glEnd();

        // Window
        glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(0.27f, 0.37f);
            glVertex2f(0.27f, 0.1f);
            glVertex2f(0.33f, 0.1f);
            glVertex2f(0.33f, 0.37f);
        glEnd();

        // Window divider
        glLineWidth(2);
        glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.32f, 0.37f);
            glVertex2f(0.32f, 0.1f);
        glEnd();

        // Green stripe
        glBegin(GL_QUADS);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(0.26f, 0.1f);
            glVertex2f(0.26f, 0.08f);
            glVertex2f(0.34f, 0.08f);
            glVertex2f(0.34f, 0.1f);
        glEnd();

        // Bottom stripe
        glBegin(GL_QUADS);
            glColor3f(0.5f, 0.5f, 0.5f);
            glVertex2f(0.25f, -0.01f);
            glVertex2f(0.25f, -0.02f);
            glVertex2f(0.35f, -0.02f);
            glVertex2f(0.35f, -0.01f);
        glEnd();

        glPopMatrix();
    }

    glPopMatrix();
}
void park()
{
    glBegin(GL_QUADS); glColor3f(0.3f, 0.8f, 0.3f); // green color
    glVertex2f(-1.0f, -0.25f);
    glVertex2f(-0.1f, -0.25f);
    glVertex2f(-0.1f, -0.8f);
    glVertex2f(-1.0f, -0.8f);
    glEnd();
// grass
glColor3f(0.0f, 0.6f, 0.0f);

glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-0.94f, -0.8f);
    glVertex2f(-0.94f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.94f, -0.8f);
    glVertex2f(-0.86f, -0.8f);
    glVertex2f(-0.8f, -0.66f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.74f, -0.8f);
    glVertex2f(-0.7f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.84f, -0.8f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.86f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.72f, -0.8f);
    glVertex2f(-0.68f, -0.8f);
    glVertex2f(-0.8f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.68f, -0.8f);
    glVertex2f(-0.64f, -0.8f);
    glVertex2f(-0.6f, -0.58f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.64f, -0.8f);
    glVertex2f(-0.6f, -0.8f);
    glVertex2f(-0.6f, -0.64f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.56f, -0.8f);
    glVertex2f(-0.5f, -0.8f);
    glVertex2f(-0.499f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.54f, -0.8f);
    glVertex2f(-0.47f, -0.8f);
    glVertex2f(-0.56f, -0.6f);
glEnd();


glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, -0.8f);
    glVertex2f(-0.58f, -0.8f);
    glVertex2f(-0.58f, -0.74f);
glEnd();


glBegin(GL_TRIANGLES);
    glVertex2f(-0.44f, -0.8f);
    glVertex2f(-0.4f, -0.8f);
    glVertex2f(-0.4f, -0.74f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.38f, -0.8f);
    glVertex2f(-0.32f, -0.8f);
    glVertex2f(-0.35f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.32f, -0.8f);
    glVertex2f(-0.26f, -0.8f);
    glVertex2f(-0.24f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.52f, -0.8f);
    glVertex2f(-0.44f, -0.8f);
    glVertex2f(-0.36f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.3f, -0.8f);
    glVertex2f(-0.26f, -0.8f);
    glVertex2f(-0.3f, -0.62f);
glEnd();


glBegin(GL_TRIANGLES);
    glVertex2f(-0.28f, -0.8f);
    glVertex2f(-0.22f, -0.8f);
    glVertex2f(-0.2f, -0.72f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.18f, -0.8f);
    glVertex2f(-0.12f, -0.8f);
    glVertex2f(-0.22f, -0.6f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-0.2f, -0.8f);
    glVertex2f(-0.16f, -0.8f);
    glVertex2f(-0.14f, -0.6f);
glEnd();

//Flower1
glColor3f(0.0f, 0.5f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.788f, -0.8f);
    glVertex2f(-0.788f, -0.699f);
    glVertex2f(-0.8f, -0.699f);
glEnd();
 //flower 2
glColor3f(0.0f, 0.5f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(-0.50f, -0.80f);
    glVertex2f(-0.49f, -0.80f);
    glVertex2f(-0.49f, -0.70f);
    glVertex2f(-0.50f, -0.70f);
glEnd();

//flower 3
glColor3f(0.0f, 0.5f, 0.0f);
glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.8f);
    glVertex2f(-0.39f, -0.8f);
    glVertex2f(-0.39f, -0.7f);
    glVertex2f(-0.40f, -0.7f);
glEnd();


// flower pata
glColor3f(1.0f, 0.0f, 0.0f);
drawCircle(-0.8f, -0.68f, 0.02f);
drawCircle(-0.817f, -0.7f, 0.02f);
drawCircle(-0.78f, -0.7f, 0.02f);
drawCircle(-0.8f, -0.72f, 0.02f);
//flower 2 pata
glColor3f(1.0f, 0.4f, 0.7f);
drawCircle(-0.49f, -0.68f, 0.02f);
drawCircle(-0.515f, -0.70f, 0.02f);
drawCircle(-0.47f, -0.70f, 0.02f);
drawCircle(-0.495f, -0.72f, 0.02f);

//flower 3 pata
glColor3f(0.2f, 0.4f, 1.0f); // blue petals
drawCircle(-0.395f, -0.68f, 0.02f);
drawCircle(-0.415f, -0.7f, 0.02f);
drawCircle(-0.375f, -0.7f, 0.02f);
drawCircle(-0.395f, -0.72f, 0.02f);
// Flower center
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.8f, -0.70f, 0.015f);
glColor3f(1.0f, 1.0f, 1.0f);
drawCircle(-0.495f, -0.70f, 0.015f);
glColor3f(1.0f, 1.0f, 0.0f); // yellow center
drawCircle(-0.395f, -0.70f, 0.015f);

for (int i = 0; i <= 2; i++)
{
    //bench body
    glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.07f);
        glVertex2f(-0.92f, -0.6f);
        glVertex2f(-0.72f, -0.6f);
        glVertex2f(-0.72f, -0.62f);
        glVertex2f(-0.92f, -0.62f);
    glEnd();

    //bench leg
    glBegin(GL_QUADS);
        glColor3f(0.36f, 0.18f, 0.05f);
        glVertex2f(-0.90f, -0.62f);
        glVertex2f(-0.87f, -0.62f);
        glVertex2f(-0.87f, -0.65f);
        glVertex2f(-0.90f, -0.65f);

        glVertex2f(-0.77f, -0.62f);
        glVertex2f(-0.74f, -0.62f);
        glVertex2f(-0.74f, -0.65f);
        glVertex2f(-0.77f, -0.65f);
    glEnd();

    glTranslatef(0.25f, 0.0f, 0.0f);
}


glEnd();
glLoadIdentity();
}

void buildingBack()
{
    glBegin(GL_QUADS);
        glColor3f(0.8f, 1.0f, 0.7f);
        glVertex2f(-1.0f, 0.8f);
        glVertex2f(-1.0f, 0.2f);
        glVertex2f(1.0f, 0.2f);
        glVertex2f(1.0f, 0.8f);
    glEnd();
}
void road()
{
    glBegin(GL_QUADS);
        glColor3f(0.4f, 0.4f, 0.4f);
        glVertex2f(-1.0f, 0.2f);
        glVertex2f(1.0f, 0.2f);
        glVertex2f(1.0f, -0.2f);
        glVertex2f(-1.0f, -0.2f);
    glEnd();
}
void bar ()
{
    //rail line bar 1
glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.0f);
glVertex2f(-0.12f, 0.23f);
glVertex2f(-0.09f, 0.23f);
glVertex2f(-0.09f, -0.23f);
glVertex2f(-0.12f, -0.23f);
glEnd();


//rail line bar 2
glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.0f);
glVertex2f(0.42f, -0.23f);
glVertex2f(0.45f, -0.23f);
glVertex2f(0.45f, 0.23f);
glVertex2f(0.42f, 0.23f);
glEnd();

// bottom small bar 2
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.46f, -0.3f);
glVertex2f(0.49f, -0.3f);
glVertex2f(0.45f, -0.23f);
glVertex2f(0.42f, -0.23f);
glEnd();

// bottom small bar 1
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.085f, -0.3f);
glVertex2f(-0.06f, -0.3f);
glVertex2f(-0.09f, -0.23f);
glVertex2f(-0.12f, -0.23f);
glEnd();

}

void river1()
{
    glBegin(GL_QUADS);
glColor3f(0.55f, 0.82f, 0.88f);
glVertex2f(0.4f, -0.8f);
glVertex2f(1.0f, -0.8f);
glVertex2f(1.0f, -0.3f);
glVertex2f(0.4f, -0.3f);
glEnd();



//stone

glColor3f(0.5f, 0.5f, 0.5f); // gray
drawCircle(0.95f, -0.78f, 0.012f);
glColor3f(0.55f, 0.55f, 0.55f); // lighter gray
drawCircle(0.97f, -0.77f, 0.013f);
glColor3f(0.45f, 0.45f, 0.45f); // darker gray
drawCircle(0.99f, -0.76f, 0.015f);
glColor3f(0.45f, 0.45f, 0.45f); // darker gray
drawCircle(0.87f, -0.74f, 0.015f);
glColor3f(0.45f, 0.45f, 0.45f); // darker gray
drawCircle(0.89f, -0.76f, 0.015f);
glColor3f(0.55f, 0.55f, 0.55f); // lighter gray
drawCircle(0.9f, -0.74f, 0.013f);
glColor3f(0.45f, 0.45f, 0.45f); // darker gray
drawCircle(0.9f, -0.76f, 0.015f);
glColor3f(0.45f, 0.45f, 0.45f); // darker gray
drawCircle(0.92f, -0.78f, 0.015f);
glColor3f(0.55f, 0.55f, 0.55f);
drawCircle(0.91f, -0.79f, 0.015f);
glColor3f(0.55f, 0.55f, 0.55f); // lighter gray
drawCircle(0.88f, -0.78f, 0.013f);


}


void ship()
{
glBegin(GL_QUADS);
glColor3f(0.45f, 0.456f, 0.45f);
glVertex2f(0.6f, -0.7f);
glVertex2f(0.8f, -0.7f);
glVertex2f(0.9f, -0.6f);
glVertex2f(0.5f, -0.6f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.4f, 0.6f, 0.8f);
glVertex2f(0.6f, -0.6f);
glVertex2f(0.8f, -0.6f);
glVertex2f(0.8f, -0.54f);
glVertex2f(0.6f, -0.54f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.1f, 0.345f);
glVertex2f(0.62f, -0.54f);
glVertex2f(0.66f, -0.54f);
glVertex2f(0.66f, -0.48f);
glVertex2f(0.62f, -0.48f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(0.72f, -0.54f);
glVertex2f(0.78f, -0.54f);
glVertex2f(0.78f, -0.42f);
glVertex2f(0.72f, -0.42f);
glEnd();

 glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.62f, -0.48f);
        glVertex2f(0.66f, -0.48f);
        glVertex2f(0.72f, -0.44f);
        glVertex2f(0.78f, -0.44f);
        glVertex2f(0.72f, -0.52f);
        glVertex2f(0.78f, -0.52f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
drawCircle(0.64f, -0.57f, 0.015f);

glColor3f(1.0f, 1.0f, 1.0f); //
drawCircle(0.7f, -0.57f, 0.015f);
glColor3f(1.0f, 1.0f, 1.0f); //
drawCircle(0.76f, -0.57f, 0.015f);



glEnd();
}


void soil()
{
    glBegin(GL_POLYGON);
    glColor3f(0.39f, 0.25f, 0.15f);
    glVertex2f(0.4f, -0.8f);
    glVertex2f(0.58f, -0.8f);
    glVertex2f(0.5, -0.72f);
    glVertex2f(0.42f, -0.72f);
    glVertex2f(0.4f,-0.76f);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(0.39f, 0.25f, 0.15f);
    glVertex2f(0.56f, -0.8f);
    glVertex2f(0.7f, -0.8f);
    glVertex2f(0.7, -0.76f);
    glVertex2f(0.66f, -0.74f);
    glVertex2f(0.58f,-0.74f);
    glVertex2f(0.54f,-0.76f);
glEnd();


glBegin(GL_POLYGON);
    glColor3f(0.39f, 0.25f, 0.15f);
    glVertex2f(0.7f, -0.8f);
    glVertex2f(0.88, -0.8f);
    glVertex2f(0.84f, -0.74f);
    glVertex2f(0.7f,-0.74f);
    glVertex2f(0.69f, -0.75f);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.39f, 0.25f, 0.15f);
    glVertex2f(0.88f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -0.78f);
    glVertex2f(0.86f, -0.78f);
glEnd();



glEnd();

}



void baseTree1()
{
    // leaves
    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(-0.04f, -0.08f, 0.12f);
    drawCircle(-0.12f, -0.012f, 0.12f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(-0.16f, 0.06f, 0.12f);

    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(-0.124f, 0.14f, 0.12f);
    drawCircle(-0.072f, 0.26f, 0.136f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.044f, 0.364f, 0.12f);

    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(0.16f, 0.32f, 0.12f);
    drawCircle(0.12f, 0.12f, 0.16f);
    drawCircle(0.248f, 0.14f, 0.12f);
    drawCircle(0.284f, 0.044f, 0.12f);
    drawCircle(0.26f, -0.04f, 0.12f);
    drawCircle(0.20f, -0.06f, 0.12f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.128f, -0.152f, 0.096f);
    drawCircle(0.088f, -0.152f, 0.096f);

    glColor3f(0.439f, 0.631f, 0.211f);
    drawCircle(0.16f, 0.18f, 0.152f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.112f, 0.22f, 0.152f);
    drawCircle(0.06f, 0.20f, 0.08f);

    glColor3f(0.647f, 0.776f, 0.223f);
    drawCircle(0.04f, 0.212f, 0.112f);
    drawCircle(0.036f, 0.196f, 0.072f);

    // main tree
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.06f, 0.08f);
        glVertex2f(0.10f, 0.08f);
        glVertex2f(0.12f, -0.48f);
        glVertex2f(0.04f, -0.48f);
    glEnd();

    // branch 1
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(0.232f, 0.04f);
        glVertex2f(0.232f, 0.04f);
    glEnd();

    // branch 2
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, 0.0f);
        glVertex2f(0.10f, -0.032f);
        glVertex2f(0.14f, 0.04f);
        glVertex2f(0.16f, 0.04f);
    glEnd();

    // branch 3
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.056f, 0.0f);
        glVertex2f(0.06f, -0.04f);
        glVertex2f(0.02f, 0.02f);
        glVertex2f(0.008f, -0.004f);
    glEnd();

    // branch 4
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(-0.008f, -0.008f);
        glVertex2f(-0.012f, -0.032f);
    glEnd();
}

void shop()
{

// right side

// shop 1
glBegin(GL_POLYGON); // body
    glColor3f(1.0f, 0.71f, 0.76f);
    glVertex2f(0.50f, 0.26f);
    glVertex2f(0.50f, 0.47f);
    glVertex2f(0.67f, 0.47f);
    glVertex2f(0.67f, 0.26f);
glEnd();

glBegin(GL_POLYGON); // roof
    glColor3f(0.50f, 0.0f, 0.0f);
    glVertex2f(0.50f, 0.47f);
    glVertex2f(0.50f, 0.55f);
    glVertex2f(0.67f, 0.55f);
    glVertex2f(0.67f, 0.47f);
glEnd();

glBegin(GL_POLYGON); // shelter
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.48f, 0.40f);
    glVertex2f(0.69f, 0.40f);
    glVertex2f(0.69f, 0.45f);
    glVertex2f(0.67f, 0.47f);
    glVertex2f(0.50f, 0.47f);
    glVertex2f(0.48f, 0.45f);
glEnd();

glBegin(GL_POLYGON); // door
    glColor3f(0.0f, 0.90f, 0.90f);
    glVertex2f(0.53f, 0.26f);
    glVertex2f(0.53f, 0.36f);
    glVertex2f(0.59f, 0.36f);
    glVertex2f(0.59f, 0.26f);
glEnd();

glBegin(GL_POLYGON); // window
    glColor3f(0.0f, 0.90f, 0.90f);
    glVertex2f(0.61f, 0.31f);
    glVertex2f(0.61f, 0.36f);
    glVertex2f(0.65f, 0.36f);
    glVertex2f(0.65f, 0.31f);
glEnd();

//shop 2
glBegin(GL_POLYGON); // body
    glColor3f(1.0f, 7.80f, 0.40f);
    glVertex2f(0.73f, 0.26f);
    glVertex2f(0.73f, 0.50f);
    glVertex2f(0.95f, 0.50f);
    glVertex2f(0.95f, 0.26f);
glEnd();

glBegin(GL_POLYGON); // roof
    glColor3f(0.70f, 0.35f, 0.0f);
    glVertex2f(0.73f, 0.55f);
    glVertex2f(0.95f, 0.55f);
    glVertex2f(0.95f, 0.50f);
    glVertex2f(0.73f, 0.50f);
glEnd();
glBegin(GL_POLYGON); // roof top
    glColor3f(0.70f, 0.35f, 0.0f);
    glVertex2f(0.78f, 0.55f);
    glVertex2f(0.90f, 0.55f);
    glVertex2f(0.87f, 0.60f);
    glVertex2f(0.81f, 0.60f);

glEnd();

glBegin(GL_POLYGON); // inside
    glColor3f(.30f, 0.15f, 0.0f);
    glVertex2f(0.75f, 0.35f);
    glVertex2f(0.75f, 0.48f);
    glVertex2f(0.93f, 0.48f);
    glVertex2f(0.93f, 0.35f);
glEnd();

glBegin(GL_POLYGON); // table
    glColor3f(0.50f, 0.25f, 0.0f);
    glVertex2f(0.75f, 0.26f);
    glVertex2f(0.75f, 0.35f);
    glVertex2f(0.93f, 0.35f);
    glVertex2f(0.93f, 0.26f);
glEnd();

glBegin(GL_POLYGON); // shelter
    glColor3f(0.90f, 0.45f, 0.0f);
    glVertex2f(0.71f, 0.43f);
    glVertex2f(0.97f, 0.43f);
    glVertex2f(0.97f, 0.47f);
    glVertex2f(0.95f, 0.50f);
    glVertex2f(0.73f, 0.50f);
    glVertex2f(0.71f, 0.47f);
glEnd();

}


void car1()
{
    // Wheel 1
    glColor3f(0.2f, 0.2f, 0.2f);
    drawCircle(-0.32f, -0.16f, 0.025f);
    // Wheel 2
    glColor3f(0.2f, 0.2f, 0.2f);
    drawCircle(-0.22f, -0.16f, 0.025f);

    // Wheel rims
    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle(-0.32f, -0.16f, 0.015f);
    drawCircle(-0.22f, -0.16f, 0.015f);

    // Main body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.27f, 0.0f); // Orange
    glVertex2f(-0.38f, -0.135f);
    glVertex2f(-0.16f, -0.135f);
    glVertex2f(-0.16f, -0.18f);
    glVertex2f(-0.38f, -0.18f);
    glEnd();

    // Upper body/cabin
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.27f, 0.0f);
    glVertex2f(-0.35f, -0.135f);
    glVertex2f(-0.19f, -0.135f);
    glVertex2f(-0.22f, -0.08f);
    glVertex2f(-0.32f, -0.08f);
    glEnd();

    // Front windshield
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.9f, 1.0f); // Light blue
    glVertex2f(-0.35f, -0.13f);
    glVertex2f(-0.32f, -0.13f);
    glVertex2f(-0.31f, -0.09f);
    glVertex2f(-0.33f, -0.09f);
    glEnd();

    // Rear windshield
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.9f, 1.0f);
    glVertex2f(-0.22f, -0.13f);
    glVertex2f(-0.19f, -0.13f);
    glVertex2f(-0.21f, -0.09f);
    glVertex2f(-0.23f, -0.09f);
    glEnd();

    // Front grille
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); // Dark gray
    glVertex2f(-0.38f, -0.14f);
    glVertex2f(-0.36f, -0.14f);
    glVertex2f(-0.36f, -0.17f);
    glVertex2f(-0.38f, -0.17f);
    glEnd();

    // Headlights
    glColor3f(1.0f, 1.0f, 0.9f); // Light yellow
    drawCircle(-0.375f, -0.15f, 0.01f);

    // Bumper
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.38f, -0.175f);
    glVertex2f(-0.16f, -0.175f);
    glVertex2f(-0.16f, -0.18f);
    glVertex2f(-0.38f, -0.18f);
    glEnd();
}

void bus()
{
    // main body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.27f, 0.0f);
    glVertex2f(-0.52f, -0.16f);
    glVertex2f(-0.27f, -0.16f);
    glVertex2f(-0.20f, -0.14f);
    glVertex2f(-0.20f, 0.00f);
    glVertex2f(-0.52f, 0.00f);
    glEnd();

    // door
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.49f, -0.02f);
    glVertex2f(-0.49f, -0.14f);
    glVertex2f(-0.46f, -0.14f);
    glVertex2f(-0.46f, -0.02f);
    glEnd();

    // windows
    glPushMatrix();
    for (int i = 0; i <= 3; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.44f, -0.02f);
        glVertex2f(-0.44f, -0.06f);
        glVertex2f(-0.41f, -0.06f);
        glVertex2f(-0.41f, -0.02f);
        glEnd();
        glTranslatef(0.06f, 0.0f, 0.0f);
    }
    glPopMatrix();

    // wheels
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(-0.49f, -0.16f, 0.021f);
    drawCircle(-0.24f, -0.16f, 0.021f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.49f, -0.16f, 0.012f);
    drawCircle(-0.24f, -0.16f, 0.012f);


}



void bus1()
{
    // main body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.59f, 0.04f);
    glVertex2f(0.59f, 0.20f);
    glVertex2f(0.88f, 0.20f);
    glVertex2f(0.91f, 0.19f);
    glVertex2f(0.91f, 0.04f);
    glEnd();

    // door (bigger)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.88f, 0.17f);
    glVertex2f(0.88f, 0.06f);
    glVertex2f(0.84f, 0.06f);
    glVertex2f(0.84f, 0.17f);
    glEnd();

    // windows (bigger)
    glPushMatrix();
    for (int i = 0; i <= 3; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.63f, 0.17f);
        glVertex2f(0.63f, 0.13f);
        glVertex2f(0.67f, 0.13f);
        glVertex2f(0.67f, 0.17f);
        glEnd();
        glTranslatef(0.054f, 0.0f, 0.0f);
    }
    glPopMatrix();

    // wheels (bigger)
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(0.63f, 0.04f, 0.021f);
    drawCircle(0.87f, 0.04f, 0.021f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.63f, 0.04f, 0.012f);
    drawCircle(0.87f, 0.04f, 0.012f);
}

// truck
void truck()
{
    // back
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.31f, 0.05f);
    glVertex2f(-0.31f, 0.23f);
    glVertex2f(-0.52f, 0.23f);
    glVertex2f(-0.52f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.52f, 0.04f);
    glVertex2f(-0.52f, 0.10f);
    glVertex2f(-0.20f, 0.10f);
    glVertex2f(-0.20f, 0.04f);
    glEnd();

    // front
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.31f, 0.18f);
    glVertex2f(-0.31f, 0.04f);
    glVertex2f(-0.20f, 0.04f);
    glVertex2f(-0.20f, 0.12f);
    glVertex2f(-0.25f, 0.18f);
    glEnd();

    // window
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.29f, 0.14f);
    glVertex2f(-0.29f, 0.11f);
    glVertex2f(-0.24f, 0.11f);
    glVertex2f(-0.24f, 0.12f);
    glVertex2f(-0.25f, 0.14f);
    glEnd();

    // vertical lines
    glPushMatrix();
    for (int i = 0; i <= 4; i++)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(-0.52f, 0.23f);
            glVertex2f(-0.52f, 0.05f);
        glEnd();
        glTranslatef(0.048f, 0.0f, 0.0f);
    }
    glPopMatrix();

    // wheels
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(-0.48f, 0.05f, 0.021f);
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(-0.24f, 0.05f, 0.021f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.48f, 0.05f, 0.012f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.24f, 0.05f, 0.012f);
}

void human()
{
    //head
    glColor3f(1.0f, 0.87f, 0.77f);
    drawCircle(-0.5f, -0.35f, 0.035f);

    //chokh
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.5f);
    glBegin(GL_POINTS);
        glVertex2f(-0.515f, -0.345f);
        glVertex2f(-0.485f, -0.345f);
    glEnd();

    //face
    glColor3f(0.8f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.507f, -0.362f);
        glVertex2f(-0.493f, -0.362f);
    glEnd();


    // dress upper part
    glColor3f(1.0f, 0.4f, 0.6f); // pink top
    glBegin(GL_QUADS);
        glVertex2f(-0.52f, -0.38f);
        glVertex2f(-0.48f, -0.38f);
        glVertex2f(-0.477f, -0.42f);
        glVertex2f(-0.523f, -0.42f);
    glEnd();

    // girl Dress bottom part
    glColor3f(0.9f, 0.2f, 0.5f); //pink
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.523f, -0.42f);
        glVertex2f(-0.477f, -0.42f);
        glVertex2f(-0.535f, -0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.523f, -0.42f);
        glVertex2f(-0.477f, -0.42f);
        glVertex2f(-0.499f, -0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.523f, -0.42f);
        glVertex2f(-0.477f, -0.42f);
        glVertex2f(-0.468f, -0.5f);
    glEnd();

    //hand
    glColor3f(1.0f, 0.87f, 0.77f);
    glBegin(GL_QUADS);
        glVertex2f(-0.528f, -0.43f);
        glVertex2f(-0.522f, -0.43f);
        glVertex2f(-0.522f, -0.39f);
        glVertex2f(-0.528f, -0.39f);

    glEnd();

        glBegin(GL_QUADS);
        glVertex2f(-0.474f, -0.43f);
        glVertex2f(-0.48f, -0.43f);
        glVertex2f(-0.48f, -0.39f);
        glVertex2f(-0.474f, -0.39f);

    glEnd();

    // paa1
    glColor3f(0.3f, 0.3f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.507f, -0.515f);
        glVertex2f(-0.515f, -0.515f);
        glVertex2f(-0.515f, -0.475f);
        glVertex2f(-0.507f, -0.475f);

    glEnd();
//pa2
    glBegin(GL_QUADS);
        glVertex2f(-0.485f, -0.515f);
        glVertex2f(-0.493f, -0.515f);
        glVertex2f(-0.493f, -0.475f);
        glVertex2f(-0.485f, -0.475f);

    glEnd();

    // for juta
    glColor3f(0.1f, 0.1f, 0.1f);
    drawCircle(-0.511f, -0.518f, 0.007f);
    drawCircle(-0.487f, -0.518f, 0.007f);

    glEnd();

}


// SCENARIO 2 FUNCTIONS


void sky2()
{
    glBegin(GL_QUADS);
        glColor3f(0.68f, 0.85f, 0.90f);
        glVertex2f(-1.0f, 0.8f);
        glVertex2f(1.0f, 0.8f);
        glVertex2f(1.0f, 0.3f);
        glVertex2f(-1.0f, 0.3f);
    glEnd();
}

void cloud2()
{
    glColor3f(0.95f, 0.96f, 0.96f);
    drawCircle(0.00f, 0.00f, 0.08f);
    drawCircle(-0.10f, 0.00f, 0.07f);
    drawCircle(0.10f, 0.00f, 0.07f);
    drawCircle(-0.05f, 0.08f, 0.06f);
    drawCircle(0.05f, 0.08f, 0.06f);
}

void clouds2() {

    float patternWidth = 2.0f;

    int repetitions = 3;

    for (int rep = 0; rep < repetitions; rep++) {
        glPushMatrix();
            float currentOffset = cloudOffset + (rep - 1) * patternWidth;

            while (currentOffset > patternWidth) currentOffset -= patternWidth;
            while (currentOffset < -patternWidth) currentOffset += patternWidth;

            glTranslatef(currentOffset, 0.0f, 0.0f);

            // Cloud 1
            glPushMatrix();
                glTranslatef(-0.85f, 0.75f, 0.0f);
                glScalef(0.6f, 0.6f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 2
            glPushMatrix();
                glTranslatef(-0.55f, 0.65f, 0.0f);
                glScalef(0.7f, 0.6f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 3
            glPushMatrix();
                glTranslatef(-0.25f, 0.55f, 0.0f);
                glScalef(0.6f, 0.7f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 4
            glPushMatrix();
                glTranslatef(0.05f, 0.72f, 0.0f);
                glScalef(0.5f, 0.5f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 5
            glPushMatrix();
                glTranslatef(0.35f, 0.60f, 0.0f);
                glScalef(0.8f, 0.6f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 6
            glPushMatrix();
                glTranslatef(0.65f, 0.68f, 0.0f);
                glScalef(0.6f, 0.5f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 7
            glPushMatrix();
                glTranslatef(-0.90f, 0.50f, 0.0f);
                glScalef(0.5f, 0.5f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 8
            glPushMatrix();
                glTranslatef(-0.35f, 0.75f, 0.0f);
                glScalef(0.6f, 0.6f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 9
            glPushMatrix();
                glTranslatef(0.40f, 0.78f, 0.0f);
                glScalef(0.5f, 0.7f, 1.0f);
                cloud2();
            glPopMatrix();

            // Cloud 10
            glPushMatrix();
                glTranslatef(0.85f, 0.58f, 0.0f);
                glScalef(0.6f, 0.6f, 1.0f);
                cloud2();
            glPopMatrix();

        glPopMatrix();
    }
}

void drawCloudPattern() {
    // Cloud 1
    glPushMatrix();
        glTranslatef(-0.85f, 0.75f, 0.0f);
        glScalef(0.6f, 0.6f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 2
    glPushMatrix();
        glTranslatef(-0.55f, 0.65f, 0.0f);
        glScalef(0.7f, 0.6f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 3
    glPushMatrix();
        glTranslatef(-0.25f, 0.55f, 0.0f);
        glScalef(0.6f, 0.7f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 4
    glPushMatrix();
        glTranslatef(0.05f, 0.72f, 0.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 5
    glPushMatrix();
        glTranslatef(0.35f, 0.60f, 0.0f);
        glScalef(0.8f, 0.6f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 6
    glPushMatrix();
        glTranslatef(0.65f, 0.68f, 0.0f);
        glScalef(0.6f, 0.5f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 7
    glPushMatrix();
        glTranslatef(-0.90f, 0.50f, 0.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 8
    glPushMatrix();
        glTranslatef(-0.35f, 0.75f, 0.0f);
        glScalef(0.6f, 0.6f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 9
    glPushMatrix();
        glTranslatef(0.40f, 0.78f, 0.0f);
        glScalef(0.5f, 0.7f, 1.0f);
        cloud2();
    glPopMatrix();

    // Cloud 10
    glPushMatrix();
        glTranslatef(0.85f, 0.58f, 0.0f);
        glScalef(0.6f, 0.6f, 1.0f);
        cloud2();
    glPopMatrix();
}

void clouds2_simple() {
    float patternWidth = 1.8f;

    glPushMatrix();
        glTranslatef(fmod(cloudOffset, patternWidth), 0.0f, 0.0f);
        drawCloudPattern();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(fmod(cloudOffset, patternWidth) - patternWidth, 0.0f, 0.0f);
        drawCloudPattern();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(fmod(cloudOffset, patternWidth) + patternWidth, 0.0f, 0.0f);
        drawCloudPattern();
    glPopMatrix();
}


     void tree2()
 {
     for (int i = 0; i <= 9; i++)
     {
        glColor3f(0.0f, 0.6f, 0.0f);
        drawCircle(-0.98f, 0.33f, 0.03f);
        drawCircle(-0.93f, 0.34f, 0.045f);
        drawCircle(-0.87f, 0.35f, 0.06f);
        drawCircle(-0.81f, 0.34f, 0.045f);
        drawCircle(-0.76f, 0.33f, 0.03f);
        glEnd();

    glTranslatef(0.25f, 0.0f, 0.0f);
     }

glEnd();
glLoadIdentity();

 }
void railLine2()
{
    //background

    glBegin(GL_QUADS);
        glColor3f(0.78f, 0.79f, 0.77f);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f( 1.0f, 0.3f);
        glVertex2f( 1.0f, 0.2f);
        glVertex2f(-1.0f, 0.2f);
    glEnd();

    //line 1
    glLineWidth(8);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f(1.0f, 0.3f);
    glEnd();

    //line 2
    glLineWidth(8);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f, 0.2f);
        glVertex2f(1.0f, 0.2f);
    glEnd();


    //middle line
    for (int i = 0; i <= 25; i++)
{

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f, 0.32f);
        glVertex2f(-0.98f, 0.32f);
        glVertex2f(-0.95f, 0.18f);
        glVertex2f(-0.97f, 0.18f);
    glEnd();

    glTranslatef(0.1f, 0.0f, 0.0f);
}


glEnd();
glLoadIdentity();
}



    void water2()
{
     glBegin(GL_QUADS);
        glColor3f(0.69f, 0.89f, 1.0f); //light sky blue
        glVertex2f(-1.0f, 0.2f);
        glVertex2f( 1.0f, 0.2f);
        glVertex2f( 1.0f,-0.8f);
        glVertex2f(-1.0f,-0.8f);
    glEnd();

}

void ground2()
{
    glBegin(GL_POLYGON);
        glColor3f(0.6f, 0.9f, 0.6f);
        glVertex2f(-1.0f, -0.06f);
        glVertex2f(0.4f, -0.06f);
        glVertex2f(0.2f, -0.16f);
        glVertex2f(0.5f, -0.21f);
        glVertex2f(0.20f, -0.34f);
        glVertex2f(0.43f, -0.42f);
        glVertex2f(0.34f, -0.48f);
        glVertex2f(0.6f, -0.56f);
        glVertex2f(0.325f, -0.64f);
        glVertex2f(0.7f, -0.8f);

        glVertex2f(-1.0f, -0.8f);


    glEnd();

    //corner of ground
     glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.007f);
        glVertex2f(0.2f,-0.16f);
        glVertex2f(0.26f,-0.17f);
        glVertex2f(0.4f,-0.1f);
        glVertex2f(0.4f,-0.06f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.007f);
        glVertex2f(0.2f,-0.34f);
        glVertex2f(0.24f,-0.36f);
        glVertex2f(0.5f,-0.24f);
        glVertex2f(0.5f,-0.21f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.007f);
        glVertex2f(0.34f,-0.48f);
        glVertex2f(0.38f,-0.5f);
        glVertex2f(0.426f,-0.47f);
        glVertex2f(0.43f,-0.42f);

    glEnd();
     glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.007f);
        glVertex2f(0.324f,-0.64f);
        glVertex2f(0.38f,-0.66f);
        glVertex2f(0.6f,-0.6f);
        glVertex2f(0.6f,-0.56f);

    glEnd();

    // edges
    glLineWidth(2.0f);
    glColor3f(0.2f, 0.4f, 0.2f);
    glBegin(GL_LINES);
        glVertex2f(0.4f, -0.06f);
        glVertex2f(0.2f, -0.16f);
        glVertex2f(0.5f, -0.21f);
        glVertex2f(0.20f, -0.34f);
        glVertex2f(0.43f, -0.42f);
        glVertex2f(0.34f, -0.48f);
        glVertex2f(0.6f, -0.56f);
        glVertex2f(0.325f, -0.64f);
    glEnd();


}

void house2()
{
    //black base
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.27f, -0.204f);
        glVertex2f( 0.27f, -0.204f);
        glVertex2f( 0.27f, -0.234f);
        glVertex2f(-0.27f, -0.234f);
    glEnd();

    //wall
    glColor3f(0.9f, 0.7f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.21f, -0.06f);
        glVertex2f( 0.21f, -0.06f);
        glVertex2f( 0.21f, -0.204f);
        glVertex2f(-0.21f, -0.204f);
    glEnd();

    // back house

    // back wall
    glColor3f(0.88f, 0.72f, 0.55f);
    glBegin(GL_QUADS);
        glVertex2f(-0.23f, 0.08f);
        glVertex2f( 0.23f, 0.08f);
        glVertex2f( 0.23f, -0.06f);
        glVertex2f(-0.23f, -0.06f);
    glEnd();

    //back roof
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.17f, 0.18f);
        glVertex2f( 0.17f, 0.18f);
        glVertex2f( 0.29f, 0.08f);
        glVertex2f(-0.29f, 0.08f);
    glEnd();

    //roof design
    glColor3f(0.55f, 0.0f, 0.0f); //maroon
    glBegin(GL_TRIANGLES);
        glVertex2f( 0.0f,   0.18f);
        glVertex2f(-0.1f, 0.08f);
        glVertex2f( 0.1f, 0.08f);
    glEnd();

    //tally lines

    glLineWidth(2.0f);
    glColor3f(0.6f, 0.0f, 0.0f); // dark red


    // left line
    glBegin(GL_LINES);
        glVertex2f(-0.17f, 0.18f);
        glVertex2f(-0.29f, 0.08f);
    glEnd();

    // right line
    glBegin(GL_LINES);
        glVertex2f(0.17f, 0.18f);
        glVertex2f(0.29f, 0.08f);
    glEnd();

    // left lines
    glPushMatrix();
    for(int i = 1; i <= 11; i++)
    {
        glTranslatef(0.015f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.17f, 0.18f);
            glVertex2f(-0.29f, 0.08f);
        glEnd();
    }
    glPopMatrix();

    // right lines
    glPushMatrix();
    for(int i = 1; i <= 11; i++)
    {
        glTranslatef(-0.015f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.17f, 0.18f);
            glVertex2f(0.29f, 0.08f);
        glEnd();
    }
    glPopMatrix();


    // back roof edge
    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.29f, 0.08f);
        glVertex2f( 0.29f, 0.08f);
        glVertex2f( 0.29f, 0.07f);
        glVertex2f(-0.29f, 0.07f);
    glEnd();


        //roof 1
        glColor3f(0.8f, 0.1f, 0.1f);
        glBegin(GL_QUADS);
            glVertex2f(-0.185f, 0.03f);
            glVertex2f( 0.185f, 0.03f);
            glVertex2f( 0.285f, -0.06f);
            glVertex2f(-0.285f, -0.06f);

        glEnd();

    //tally lines
    glLineWidth(2.0f);
    glColor3f(0.6f, 0.0f, 0.0f); // dark red

    // center line
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.029f);
        glVertex2f(0.0f, -0.06f);
    glEnd();

    // left line
    glBegin(GL_LINES);
        glVertex2f(-0.185f, 0.029f);
        glVertex2f(-0.285f, -0.06f);
    glEnd();

    // right line
    glBegin(GL_LINES);
        glVertex2f(0.185f, 0.029f);
        glVertex2f(0.285f, -0.06f);
    glEnd();

    //left lines
    glPushMatrix();
    for(int i = 1; i <= 10; i++)
    {
        glTranslatef(0.018f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.185f, 0.029f);
            glVertex2f(-0.285f, -0.06f);
        glEnd();
    }
    glPopMatrix();

    // right lines
    glPushMatrix();
    for(int i = 1; i <= 10; i++)
    {
        glTranslatef(-0.018f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.185f, 0.03f);
            glVertex2f(0.285f, -0.06f);
        glEnd();
    }
    glPopMatrix();


    // roof edge
    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.285f, -0.06f);
        glVertex2f( 0.285f, -0.06f);
        glVertex2f( 0.285f, -0.069f);
        glVertex2f(-0.285f, -0.069f);
    glEnd();

    //roof design
    glColor3f(0.55f, 0.0f, 0.0f); //maroon
    glBegin(GL_TRIANGLES);
        glVertex2f( 0.0f,    0.016f);
        glVertex2f(-0.09f, -0.06f);
        glVertex2f( 0.09f, -0.06f);
    glEnd();

    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.138f, -0.06f);
        glVertex2f( 0.138f, -0.06f);
        glVertex2f( 0.138f, -0.069f);
        glVertex2f(-0.138f, -0.069f);
    glEnd();

    // white line
    glLineWidth(2);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f( 0.0f,    0.014f);
        glVertex2f( 0.05f, -0.054f);
        glVertex2f(-0.05f, -0.054f);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-0.015f, -0.054f);
        glVertex2f( 0.0f,    0.014f);

        glVertex2f( 0.015f, -0.054f);
        glVertex2f( 0.0f,    0.014f);
    glEnd();


    //pillars
    glColor3f(0.95f, 0.9f, 0.75f);

    //pillar 1
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.07f);
        glVertex2f(-0.235f, -0.07f);
        glVertex2f(-0.235f, -0.204f);
        glVertex2f(-0.25f, -0.204f);
    glEnd();

    //pillar 2
    glBegin(GL_QUADS);
        glVertex2f(-0.048f, -0.06f);
        glVertex2f(-0.036f, -0.06f);
        glVertex2f(-0.036f, -0.204f);
        glVertex2f(-0.048f, -0.204f);
    glEnd();

    //pillar 3
    glBegin(GL_QUADS);
        glVertex2f(0.036f, -0.06f);
        glVertex2f(0.048f, -0.06f);
        glVertex2f(0.048f, -0.204f);
        glVertex2f(0.036f, -0.204f);
    glEnd();

    //pillar 4
    glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.07f);
        glVertex2f(0.235f, -0.07f);
        glVertex2f(0.235f, -0.204f);
        glVertex2f(0.25f, -0.204f);
    glEnd();


    //door
    glColor3f(0.32f, 0.2f, 0.12f);
    glBegin(GL_QUADS);
        glVertex2f(-0.03f, -0.105f);
        glVertex2f( 0.03f, -0.105f);
        glVertex2f( 0.03f, -0.204f);
        glVertex2f(-0.03f, -0.204f);
    glEnd();

    // window 1
    glColor3f(0.32f, 0.2f, 0.12f);
    glBegin(GL_QUADS);
        glVertex2f(-0.16f, -0.084f);
        glVertex2f(-0.10f, -0.084f);
        glVertex2f(-0.10f, -0.165f);
        glVertex2f(-0.16f, -0.165f);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
        glVertex2f(0.16f, -0.084f);
        glVertex2f(0.1f, -0.084f);
        glVertex2f(0.1f, -0.165f);
        glVertex2f(0.16f, -0.165f);
    glEnd();



    //right railing
    glColor3f(0.95f, 0.95f, 0.95f);
    glLineWidth(2.5f);

    glBegin(GL_LINES);
        glVertex2f(0.205f, -0.15f);
        glVertex2f(0.205f, -0.204f);
    glEnd();

    glPushMatrix();
    for(int i = 1; i <= 5; i++)
    {
        glTranslatef(-0.029f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.205f, -0.15f);
        glVertex2f(0.205f, -0.204f);
        glEnd();
    }
    glPopMatrix();

     // right horizontal
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(0.206f, -0.15f);
        glVertex2f(0.058f, -0.15f);
    glEnd();



    //left railing
    glColor3f(0.95f, 0.95f, 0.95f);
    glLineWidth(2.5f);

    glBegin(GL_LINES);
        glVertex2f(-0.208f, -0.15f);
        glVertex2f(-0.208f, -0.204f);
    glEnd();

    glPushMatrix();
    for(int i = 1; i <= 5; i++)
    {
        glTranslatef(0.029f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.208f, -0.15f);
        glVertex2f(-0.208f, -0.204f);
        glEnd();
    }
    glPopMatrix();


    //left horizontal
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(-0.211f, -0.15f);
        glVertex2f(-0.061f, -0.15f);
    glEnd();


    //stairs
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(-0.054f, -0.204f);
        glVertex2f( 0.054f, -0.204f);
        glVertex2f( 0.066f, -0.225f);
        glVertex2f(-0.066f, -0.225f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.066f, -0.225f);
        glVertex2f( 0.066f, -0.225f);
        glVertex2f( 0.084f, -0.24f);
        glVertex2f(-0.084f, -0.24f);
    glEnd();
}

    void boat1()
{
    // main boat
 glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.64f, -0.5f);
        glVertex2f(0.9f, -0.5f);
        glVertex2f(0.96f, -0.4f);
        glVertex2f(0.86f, -0.44f);
        glVertex2f(0.66f, -0.44f);
        glVertex2f(0.54f, -0.4f);
//middle khamba
    glEnd();
     glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(0.74f, -0.44f);
        glVertex2f(0.76f, -0.44f);
        glVertex2f(0.76f, -0.12f);
        glVertex2f(0.74f, -0.12f);
    glEnd();
//right pal
glBegin(GL_TRIANGLES);

    glColor3f(0.8f, 0.33f, 0.0f);

    glVertex2f(0.78f, -0.44f);
    glVertex2f(0.84f, -0.44f);
    glVertex2f(0.76f, -0.2f);

glEnd();
//left pal
glBegin(GL_TRIANGLES);

    glColor3f(0.8f, 0.33f, 0.0f);

    glVertex2f(0.68f, -0.44f);
    glVertex2f(0.73f, -0.44f);
    glVertex2f(0.74f, -0.2f);
glEnd();

//small flag
glBegin(GL_TRIANGLES);

    glColor3f(0.1f, 0.5f, 0.0f);

    glVertex2f(0.74f, -0.16f);
    glVertex2f(0.74f, -0.14f);
    glVertex2f(0.66f, -0.145f);

glEnd();
}

    void baseTree2()
{
    // leaves
    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(-0.04f, -0.08f, 0.12f);
    drawCircle(-0.12f, -0.012f, 0.12f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(-0.16f, 0.06f, 0.12f);

    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(-0.124f, 0.14f, 0.12f);
    drawCircle(-0.072f, 0.26f, 0.136f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.044f, 0.364f, 0.12f);

    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(0.16f, 0.32f, 0.12f);
    drawCircle(0.12f, 0.12f, 0.16f);
    drawCircle(0.248f, 0.14f, 0.12f);
    drawCircle(0.284f, 0.044f, 0.12f);
    drawCircle(0.26f, -0.04f, 0.12f);
    drawCircle(0.20f, -0.06f, 0.12f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.128f, -0.152f, 0.096f);
    drawCircle(0.088f, -0.152f, 0.096f);

    glColor3f(0.439f, 0.631f, 0.211f);
    drawCircle(0.16f, 0.18f, 0.152f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.112f, 0.22f, 0.152f);
    drawCircle(0.06f, 0.20f, 0.08f);

    glColor3f(0.647f, 0.776f, 0.223f);
    drawCircle(0.04f, 0.212f, 0.112f);
    drawCircle(0.036f, 0.196f, 0.072f);

    // main tree
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.06f, 0.08f);
        glVertex2f(0.10f, 0.08f);
        glVertex2f(0.12f, -0.48f);
        glVertex2f(0.04f, -0.48f);
    glEnd();


    // branch 1
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, 0.0f);
        glVertex2f(0.10f, -0.032f);
        glVertex2f(0.14f, 0.04f);
        glVertex2f(0.16f, 0.04f);
    glEnd();

    // branch 2
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(0.232f, 0.04f);
        glVertex2f(0.232f, 0.04f);
    glEnd();

    // branch 3
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.056f, 0.0f);
        glVertex2f(0.06f, -0.04f);
        glVertex2f(0.02f, 0.02f);
        glVertex2f(0.008f, -0.004f);
    glEnd();

    // branch 4
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(-0.008f, -0.008f);
        glVertex2f(-0.012f, -0.032f);
    glEnd();
}

    void dress()
{
    //dress picking khamba 1

     glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(0.12f, -0.74f);
        glVertex2f(0.14f, -0.74f);
        glVertex2f(0.14f, -0.42f);
        glVertex2f(0.12f, -0.42f);
    glEnd();
//dress picking khamba 2

     glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.74f);
        glVertex2f(-0.18f, -0.74f);
        glVertex2f(- 0.18f, -0.42f);
        glVertex2f(-0.2f, -0.42f);
    glEnd();
    //
     glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.22f, -0.46f);
        glVertex2f(0.16f, -0.46f);
        glVertex2f(0.16f, -0.44f);
        glVertex2f(-0.22f, -0.44f);
    glEnd();

//  Dress 1 (left)
glColor3f(0.0f, 0.0f, 0.5f);
glBegin(GL_POLYGON);
    glVertex2f(-0.14f, -0.46f);
    glVertex2f(-0.10f, -0.46f);
    glVertex2f(-0.10f, -0.52f);
    glVertex2f(-0.14f, -0.52f);
glEnd();
// Sleeves
glBegin(GL_POLYGON);
    glVertex2f(-0.14f, -0.46f);
    glVertex2f(-0.16f, -0.46f);
    glVertex2f(-0.16f, -0.49f);
    glVertex2f(-0.14f, -0.49f);
glEnd();
glBegin(GL_POLYGON);
    glVertex2f(-0.10f, -0.46f);
    glVertex2f(-0.08f, -0.46f);
    glVertex2f(-0.08f, -0.49f);
    glVertex2f(-0.10f, -0.49f);
glEnd();


// Dress 2 middle
glColor3f(0.8f, 0.2f, 0.2f);
glBegin(GL_POLYGON);
    glVertex2f(-0.04f, -0.46f);
    glVertex2f( 0.00f, -0.46f);
    glVertex2f( 0.00f, -0.52f);
    glVertex2f(-0.04f, -0.52f);
glEnd();
// Sleeves
glBegin(GL_POLYGON);
    glVertex2f(-0.04f, -0.46f);
    glVertex2f(-0.06f, -0.46f);
    glVertex2f(-0.06f, -0.49f);
    glVertex2f(-0.04f, -0.49f);
glEnd();
glBegin(GL_POLYGON);
    glVertex2f(0.00f, -0.46f);
    glVertex2f(0.02f, -0.46f);
    glVertex2f(0.02f, -0.49f);
    glVertex2f(0.00f, -0.49f);
glEnd();


// Baby Dress 3 right
glColor3f(0.2f, 0.6f, 0.3f);
glBegin(GL_POLYGON);
    glVertex2f(0.06f, -0.46f);
    glVertex2f(0.10f, -0.46f);
    glVertex2f(0.10f, -0.52f);
    glVertex2f(0.06f, -0.52f);
glEnd();
// Sleeves
glBegin(GL_POLYGON);
    glVertex2f(0.06f, -0.46f);
    glVertex2f(0.04f, -0.46f);
    glVertex2f(0.04f, -0.49f);
    glVertex2f(0.06f, -0.49f);
glEnd();
glBegin(GL_POLYGON);
    glVertex2f(0.10f, -0.46f);
    glVertex2f(0.12f, -0.46f);
    glVertex2f(0.12f, -0.49f);
    glVertex2f(0.10f, -0.49f);
glEnd();

glColor3f(0.6f, 0.9f, 0.6f);
    drawCircle(-0.12f, -0.46f, 0.01f);

    glColor3f(0.6f, 0.9f, 0.6f);
    drawCircle(-0.02f, -0.46f, 0.01f);
            glEnd();




    glColor3f(0.6f, 0.9f, 0.6f);
    drawCircle(0.08f, -0.46f, 0.01f);
            glEnd();
}


 void boat2()
{
    glPushMatrix();
    glTranslatef(boat2_x, 0.18f, 0.0f);
    glScalef(0.2f, 0.2f, 1.0f);

    // main boat
    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.64f, -0.5f);
        glVertex2f(0.9f, -0.5f);
        glVertex2f(0.96f, -0.4f);
        glVertex2f(0.86f, -0.44f);
        glVertex2f(0.66f, -0.44f);
        glVertex2f(0.54f, -0.4f);
    glEnd();

    // middle khamba
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(0.74f, -0.44f);
        glVertex2f(0.76f, -0.44f);
        glVertex2f(0.76f, -0.12f);
        glVertex2f(0.74f, -0.12f);
    glEnd();

    // right pal
    glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.33f, 0.0f);
        glVertex2f(0.78f, -0.44f);
        glVertex2f(0.84f, -0.44f);
        glVertex2f(0.76f, -0.2f);
    glEnd();

    // left pal
    glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.33f, 0.0f);
        glVertex2f(0.68f, -0.44f);
        glVertex2f(0.73f, -0.44f);
        glVertex2f(0.74f, -0.2f);
    glEnd();

    // small flag
    glBegin(GL_TRIANGLES);
        glColor3f(0.1f, 0.5f, 0.0f);
        glVertex2f(0.74f, -0.16f);
        glVertex2f(0.74f, -0.14f);
        glVertex2f(0.66f, -0.145f);
    glEnd();

    glPopMatrix();
}
void humanbody()
{
    // Head
    glColor3f(1.0f, 0.8f, 0.6f); // skin color
    drawCircle(-0.28f, -0.55f, 0.030f);

    // Eyes
    glPointSize(4.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
        glVertex2f(-0.29f, -0.54f);
        glVertex2f(-0.27f, -0.54f);
    glEnd();

    // body
    glColor3f(1.0f, 0.27f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.30f, -0.58f);
        glVertex2f(-0.26f, -0.58f);
        glVertex2f(-0.26f, -0.68f);
        glVertex2f(-0.30f, -0.68f);
    glEnd();

    // Left Arm
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.32f, -0.58f);
        glVertex2f(-0.30f, -0.58f);
        glVertex2f(-0.30f, -0.67f);
        glVertex2f(-0.32f, -0.67f);
    glEnd();

    // Right Arm
    glBegin(GL_QUADS);
        glVertex2f(-0.26f, -0.58f);
        glVertex2f(-0.24f, -0.58f);
        glVertex2f(-0.24f, -0.67f);
        glVertex2f(-0.26f, -0.67f);
    glEnd();

    // finger
    glColor3f(1.0f, 0.8f, 0.6f);
    drawCircle(-0.31f, -0.68f, 0.013f);
    drawCircle(-0.25f, -0.68f, 0.013f);

    // pant
    glColor3f(0.53f, 0.82f, 0.92f);
    glBegin(GL_QUADS);
        glVertex2f(-0.30f, -0.68f);
        glVertex2f(-0.28f, -0.68f);
        glVertex2f(-0.28f, -0.78f);
        glVertex2f(-0.30f, -0.78f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-0.28f, -0.68f);
        glVertex2f(-0.26f, -0.68f);
        glVertex2f(-0.26f, -0.78f);
        glVertex2f(-0.28f, -0.78f);
    glEnd();

    // Feet
    glColor3f(0.1f, 0.1f, 0.1f);
    drawCircle(-0.295f, -0.79f, 0.012f);
    drawCircle(-0.265f, -0.79f, 0.012f);
}

void train2()
{
    // chaka back train2
   glPushMatrix();
    for (int i = 1; i <= 2; i++)
    {
        glTranslatef(0.2f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.5f, 0.5f, 0.5f); // Gray
            drawCircle(0.55f, 0.21f, 0.016f);
            glColor3f(0.0f, 0.0f, 0.0f); // Black
            drawCircle(0.55f, 0.21f, 0.01f);
        glEnd();
    }
    glPopMatrix();

    // Back train2 body
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex2f(0.7f, 0.32f);
        glVertex2f(0.7f, 0.21f);
        glVertex2f(1.0f, 0.21f);
        glVertex2f(1.0f, 0.32f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(0.7f, 0.265f);
        glVertex2f(0.7f, 0.21f);
        glVertex2f(1.0f, 0.21f);
        glVertex2f(1.0f, 0.265f);
    glEnd();

    // Back train2 windows (janala)
    glPushMatrix();
    for (int i = 1; i <= 6; i++)
    {
        glTranslatef(0.05f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
           glColor3f(0.5f, 0.6f, 0.4f); //deep grren
            glVertex2f(0.66f, 0.3f);
            glVertex2f(0.66f, 0.27f);
            glVertex2f(0.69f, 0.27f);
            glVertex2f(0.69f, 0.3f);
        glEnd();
    }
    glPopMatrix();

    // Back train2 lines
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glVertex2f(0.7f, 0.265f);
        glVertex2f(1.0f, 0.265f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.8f, 0.31f);
        glVertex2f(0.9f, 0.31f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.8f, 0.31f);
        glVertex2f(0.8f, 0.21f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.9f, 0.31f);
        glVertex2f(0.9f, 0.21f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.85f, 0.31f);
        glVertex2f(0.85f, 0.21f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.7f, 0.32f);
        glVertex2f(0.7f, 0.21f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.7f, 0.32f);
        glVertex2f(1.0f, 0.32f);
    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2f(0.7f, 0.22f);
        glVertex2f(0.68f, 0.22f);
    glEnd();

    // chaka front train2
    glPushMatrix();
    for (int i = 1; i <= 2; i++)
    {
        glTranslatef(0.2f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.5f, 0.5f, 0.5f); // Gray
            drawCircle(0.24f, 0.21f, 0.016f);
            glColor3f(0.0f, 0.0f, 0.0f); // Black
            drawCircle(0.24f, 0.21f, 0.01f);
        glEnd();
    }
    glPopMatrix();

    // Front train2 body
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex2f(0.68f, 0.32f);
        glVertex2f(0.68f, 0.21f);
        glVertex2f(0.4f, 0.21f);
        glVertex2f(0.37f, 0.27f);
        glVertex2f(0.4f, 0.32f);
    glEnd();

    // Front curve
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    drawCircle(0.39f, 0.24f, 0.03f);
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(0.68f, 0.265f);
        glVertex2f(0.68f, 0.21f);
        glVertex2f(0.4f, 0.21f);
        glVertex2f(0.4f, 0.265f);
    glEnd();

    // Front train2 janala
    glPushMatrix();
    for (int i = 1; i <= 5; i++)
    {
        glTranslatef(0.047f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glColor3f(0.5f, 0.6f, 0.4f); //deep green
            glVertex2f(0.383f, 0.3f);
            glVertex2f(0.383f, 0.27f);
            glVertex2f(0.413f, 0.27f);
            glVertex2f(0.413f, 0.3f);
        glEnd();
    }
    glPopMatrix();

    // Front window
    glBegin(GL_QUADS);
        glColor3f(0.9f, 0.8f, 0.0f); //light brown
        glVertex2f(0.41f, 0.3f);
        glVertex2f(0.41f, 0.27f);
        glVertex2f(0.37f, 0.27f);
        glVertex2f(0.39f, 0.3f);
    glEnd();

    // Front train2 lines
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glVertex2f(0.68f, 0.265f);
        glVertex2f(0.37f, 0.265f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.68f, 0.32f);
        glVertex2f(0.4f, 0.32f);
    glEnd();


    glPushMatrix();
    for (int bogey = 1; bogey <= 5; bogey++)
    {


        glTranslatef(0.32f, 0.0f, 0.0f);


        glPushMatrix();
        for (int i = 1; i <= 2; i++)
        {
            glTranslatef(0.2f, 0.0f, 0.0f);
            glBegin(GL_POLYGON);
                glColor3f(0.5f, 0.5f, 0.5f); // Gray
                drawCircle(0.55f, 0.21f, 0.016f);
                glColor3f(0.0f, 0.0f, 0.0f); // Black
                drawCircle(0.55f, 0.21f, 0.01f);
            glEnd();
        }
        glPopMatrix();

        // Bogey body
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f); // White
            glVertex2f(0.7f, 0.32f);
            glVertex2f(0.7f, 0.21f);
            glVertex2f(1.0f, 0.21f);
            glVertex2f(1.0f, 0.32f);
        glEnd();
        glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 0.0f); // Red
            glVertex2f(0.7f, 0.265f);
            glVertex2f(0.7f, 0.21f);
            glVertex2f(1.0f, 0.21f);
            glVertex2f(1.0f, 0.265f);
        glEnd();

        // Windows
        glPushMatrix();
        for (int i = 1; i <= 6; i++)
        {
            glTranslatef(0.05f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
                glColor3f(0.5f, 0.6f, 0.4f); //deep green
                glVertex2f(0.66f, 0.3f);
                glVertex2f(0.66f, 0.27f);
                glVertex2f(0.69f, 0.27f);
                glVertex2f(0.69f, 0.3f);
            glEnd();
        }
        glPopMatrix();

        // Lines
        glLineWidth(2);
        glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.7f, 0.265f);
            glVertex2f(1.0f, 0.265f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.8f, 0.31f);
            glVertex2f(0.9f, 0.31f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.8f, 0.31f);
            glVertex2f(0.8f, 0.21f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.9f, 0.31f);
            glVertex2f(0.9f, 0.21f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.85f, 0.31f);
            glVertex2f(0.85f, 0.21f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.7f, 0.32f);
            glVertex2f(0.7f, 0.21f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.7f, 0.32f);
            glVertex2f(1.0f, 0.32f);
        glEnd();


        glLineWidth(4);
        glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f); // Black
            glVertex2f(0.7f, 0.22f);
            glVertex2f(0.68f, 0.22f);
        glEnd();
    }
    glPopMatrix();
}

void bird2()
{
    glPushMatrix();
    glTranslatef(bird_x, 0.0f, 0.0f);

    // Bird 1
    glPushMatrix();
    glTranslatef(0.04f, 0.58f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.03f, 0.01f);
    glEnd();
    glPopMatrix();

    // Bird 2
    glPushMatrix();
    glTranslatef(0.08f, 0.59f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.03f, 0.01f);
    glEnd();
    glPopMatrix();

    // Bird 3
    glPushMatrix();
    glTranslatef(0.0f, 0.57f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.03f, 0.01f);
    glEnd();
    glPopMatrix();

    // Bird 4
    glPushMatrix();
    glTranslatef(0.05f, 0.56f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.03f, 0.01f);
    glEnd();
    glPopMatrix();

    // Bird 5
    glPushMatrix();
    glTranslatef(0.03f, 0.60f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.01f, -0.01f);
        glVertex2f(0.03f, 0.01f);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}



void rain()
{


    for (int i = 0; i <= 30; i++)
{
    glBegin(GL_LINES);
        glColor3f(0.7f, 0.7f, 1.0f);

        for (float j = 0.0f; j < 2.4f; j += 0.4f) {
            glVertex2f(-0.99f, 0.77f + rain_offset - j);
            glVertex2f(-0.99f, 0.73f + rain_offset - j);
        }
    glEnd();
    glTranslatef(0.09f, 0.0f, 0.0f);
}
glLoadIdentity();
}



void skyRain()
{
    glBegin(GL_QUADS);
        glColor3f(0.4f, 0.4f, 0.4f);  // grey
        glVertex2f(-1.0f, 0.3f);
        glVertex2f( 1.0f, 0.3f);
        glVertex2f( 1.0f, 0.8f);
        glVertex2f(-1.0f, 0.8f);
    glEnd();
}

void cloudRain()
{
    glColor3f(0.6f, 0.6f, 0.6f); //light grey
    drawCircle(0.00f, 0.00f, 0.08f);
    drawCircle(-0.10f, 0.00f, 0.07f);
    drawCircle(0.10f, 0.00f, 0.07f);
    drawCircle(-0.05f, 0.08f, 0.06f);
    drawCircle(0.05f, 0.08f, 0.06f);
}

void drawRainCloudPattern() {
    // Cloud 1
    glPushMatrix();
        glTranslatef(-0.85f, 0.75f, 0.0f);
        glScalef(0.6f, 0.6f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 2
    glPushMatrix();
        glTranslatef(-0.55f, 0.65f, 0.0f);
        glScalef(0.7f, 0.6f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 3
    glPushMatrix();
        glTranslatef(-0.25f, 0.55f, 0.0f);
        glScalef(0.6f, 0.7f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 4
    glPushMatrix();
        glTranslatef(0.05f, 0.72f, 0.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 5
    glPushMatrix();
        glTranslatef(0.35f, 0.60f, 0.0f);
        glScalef(0.8f, 0.6f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 6
    glPushMatrix();
        glTranslatef(0.65f, 0.68f, 0.0f);
        glScalef(0.6f, 0.5f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 7
    glPushMatrix();
        glTranslatef(-0.90f, 0.50f, 0.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 8
    glPushMatrix();
        glTranslatef(-0.35f, 0.75f, 0.0f);
        glScalef(0.6f, 0.6f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 9
    glPushMatrix();
        glTranslatef(0.40f, 0.78f, 0.0f);
        glScalef(0.5f, 0.7f, 1.0f);
        cloudRain();
    glPopMatrix();

    // Cloud 10
    glPushMatrix();
        glTranslatef(0.85f, 0.58f, 0.0f);
        glScalef(0.6f, 0.6f, 1.0f);
        cloudRain();
    glPopMatrix();
}


void cloudsRain_simple() {
    float patternWidth = 1.8f;

    glPushMatrix();
        glTranslatef(fmod(cloudOffset, patternWidth), 0.0f, 0.0f);
        drawRainCloudPattern();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(fmod(cloudOffset, patternWidth) - patternWidth, 0.0f, 0.0f);
        drawRainCloudPattern();
    glPopMatrix();


    glPushMatrix();
        glTranslatef(fmod(cloudOffset, patternWidth) + patternWidth, 0.0f, 0.0f);
        drawRainCloudPattern();
    glPopMatrix();
}

void cloudsRain()
{
    float patternWidth = 2.0f;

    int repetitions = 3;

    for (int rep = 0; rep < repetitions; rep++) {
        glPushMatrix();

            float currentOffset = cloudOffset + (rep - 1) * patternWidth;

            while (currentOffset > patternWidth) currentOffset -= patternWidth;
            while (currentOffset < -patternWidth) currentOffset += patternWidth;

            glTranslatef(currentOffset, 0.0f, 0.0f);

            // Cloud 1
            glPushMatrix();
                glTranslatef(-0.85f, 0.75f, 0.0f);
                glScalef(0.6f, 0.6f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 2
            glPushMatrix();
                glTranslatef(-0.55f, 0.65f, 0.0f);
                glScalef(0.7f, 0.6f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 3
            glPushMatrix();
                glTranslatef(-0.25f, 0.55f, 0.0f);
                glScalef(0.6f, 0.7f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 4
            glPushMatrix();
                glTranslatef(0.05f, 0.72f, 0.0f);
                glScalef(0.5f, 0.5f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 5
            glPushMatrix();
                glTranslatef(0.35f, 0.60f, 0.0f);
                glScalef(0.8f, 0.6f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 6
            glPushMatrix();
                glTranslatef(0.65f, 0.68f, 0.0f);
                glScalef(0.6f, 0.5f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 7
            glPushMatrix();
                glTranslatef(-0.90f, 0.50f, 0.0f);
                glScalef(0.5f, 0.5f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 8
            glPushMatrix();
                glTranslatef(-0.35f, 0.75f, 0.0f);
                glScalef(0.6f, 0.6f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 9
            glPushMatrix();
                glTranslatef(0.40f, 0.78f, 0.0f);
                glScalef(0.5f, 0.7f, 1.0f);
                cloudRain();
            glPopMatrix();

            // Cloud 10
            glPushMatrix();
                glTranslatef(0.85f, 0.58f, 0.0f);
                glScalef(0.6f, 0.6f, 1.0f);
                cloudRain();
            glPopMatrix();

        glPopMatrix();
    }
}


     void treeRain()
 {
     for (int i = 0; i <= 9; i++)
     {
        glColor3f(0.0f, 0.4f, 0.0f);
        drawCircle(-0.98f, 0.33f, 0.03f);
        drawCircle(-0.93f, 0.34f, 0.045f);
        drawCircle(-0.87f, 0.35f, 0.06f);
        drawCircle(-0.81f, 0.34f, 0.045f);
        drawCircle(-0.76f, 0.33f, 0.03f);
        glEnd();

    glTranslatef(0.25f, 0.0f, 0.0f);
     }

glEnd();
glLoadIdentity();

 }
void railLine2Rain()
{
    //background

    glBegin(GL_QUADS);
        glColor3f(0.78f, 0.79f, 0.77f);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f( 1.0f, 0.3f);
        glVertex2f( 1.0f, 0.2f);
        glVertex2f(-1.0f, 0.2f);
    glEnd();

    //line 1
    glLineWidth(8);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f(1.0f, 0.3f);
    glEnd();

    //line 2
    glLineWidth(8);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f, 0.2f);
        glVertex2f(1.0f, 0.2f);
    glEnd();


    //middle line
    for (int i = 0; i <= 25; i++)
{

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f, 0.32f);
        glVertex2f(-0.98f, 0.32f);
        glVertex2f(-0.95f, 0.18f);
        glVertex2f(-0.97f, 0.18f);
    glEnd();

    glTranslatef(0.1f, 0.0f, 0.0f);
}


glEnd();
glLoadIdentity();
}



    void waterRain()
{
     glBegin(GL_QUADS);
        glColor3f(0.65f, 0.65f, 0.65f); //light grey
        glVertex2f(-1.0f, 0.2f);
        glVertex2f( 1.0f, 0.2f);
        glVertex2f( 1.0f,-0.8f);
        glVertex2f(-1.0f,-0.8f);
    glEnd();

}

void groundRain()
{
    glBegin(GL_POLYGON);
        glColor3f(0.4f, 0.7f, 0.4f);
        glVertex2f(-1.0f, -0.06f);
        glVertex2f(0.4f, -0.06f);
        glVertex2f(0.2f, -0.16f);
        glVertex2f(0.5f, -0.21f);
        glVertex2f(0.20f, -0.34f);
        glVertex2f(0.43f, -0.42f);
        glVertex2f(0.34f, -0.48f);
        glVertex2f(0.6f, -0.56f);
        glVertex2f(0.325f, -0.64f);
        glVertex2f(0.7f, -0.8f);

        glVertex2f(-1.0f, -0.8f);


    glEnd();

    //corner of ground
     glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.007f);
        glVertex2f(0.2f,-0.16f);
        glVertex2f(0.26f,-0.17f);
        glVertex2f(0.4f,-0.1f);
        glVertex2f(0.4f,-0.06f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.007f);
        glVertex2f(0.2f,-0.34f);
        glVertex2f(0.24f,-0.36f);
        glVertex2f(0.5f,-0.24f);
        glVertex2f(0.5f,-0.21f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.007f);
        glVertex2f(0.34f,-0.48f);
        glVertex2f(0.38f,-0.5f);
        glVertex2f(0.426f,-0.47f);
        glVertex2f(0.43f,-0.42f);

    glEnd();
     glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.007f);
        glVertex2f(0.324f,-0.64f);
        glVertex2f(0.38f,-0.66f);
        glVertex2f(0.6f,-0.6f);
        glVertex2f(0.6f,-0.56f);
glEnd();

    // edges
    glLineWidth(2.0f);
    glColor3f(0.2f, 0.4f, 0.2f);
    glBegin(GL_LINES);
        glVertex2f(0.4f, -0.06f);
        glVertex2f(0.2f, -0.16f);
        glVertex2f(0.5f, -0.21f);
        glVertex2f(0.20f, -0.34f);
        glVertex2f(0.43f, -0.42f);
        glVertex2f(0.34f, -0.48f);
        glVertex2f(0.6f, -0.56f);
        glVertex2f(0.325f, -0.64f);
    glEnd();


}

void houseRain()
{
    //black base
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.27f, -0.204f);
        glVertex2f( 0.27f, -0.204f);
        glVertex2f( 0.27f, -0.234f);
        glVertex2f(-0.27f, -0.234f);
    glEnd();

    //wall
    glColor3f(0.9f, 0.7f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.21f, -0.06f);
        glVertex2f( 0.21f, -0.06f);
        glVertex2f( 0.21f, -0.204f);
        glVertex2f(-0.21f, -0.204f);
    glEnd();

    // back house

    // back wall
    glColor3f(0.88f, 0.72f, 0.55f);
    glBegin(GL_QUADS);
        glVertex2f(-0.23f, 0.08f);
        glVertex2f( 0.23f, 0.08f);
        glVertex2f( 0.23f, -0.06f);
        glVertex2f(-0.23f, -0.06f);
    glEnd();

    //back roof
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.17f, 0.18f);
        glVertex2f( 0.17f, 0.18f);
        glVertex2f( 0.29f, 0.08f);
        glVertex2f(-0.29f, 0.08f);
    glEnd();

    //roof design
    glColor3f(0.55f, 0.0f, 0.0f); //maroon
    glBegin(GL_TRIANGLES);
        glVertex2f( 0.0f,   0.18f);
        glVertex2f(-0.1f, 0.08f);
        glVertex2f( 0.1f, 0.08f);
    glEnd();

    //tally lines

    glLineWidth(2.0f);
    glColor3f(0.6f, 0.0f, 0.0f); // dark red


    // left line
    glBegin(GL_LINES);
        glVertex2f(-0.17f, 0.18f);
        glVertex2f(-0.29f, 0.08f);
    glEnd();

    // right line
    glBegin(GL_LINES);
        glVertex2f(0.17f, 0.18f);
        glVertex2f(0.29f, 0.08f);
    glEnd();

    // left lines
    glPushMatrix();
    for(int i = 1; i <= 11; i++)
    {
        glTranslatef(0.015f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.17f, 0.18f);
            glVertex2f(-0.29f, 0.08f);
        glEnd();
    }
    glPopMatrix();

    // right lines
    glPushMatrix();
    for(int i = 1; i <= 11; i++)
    {
        glTranslatef(-0.015f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.17f, 0.18f);
            glVertex2f(0.29f, 0.08f);
        glEnd();
    }
    glPopMatrix();


    // back roof edge
    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.29f, 0.08f);
        glVertex2f( 0.29f, 0.08f);
        glVertex2f( 0.29f, 0.07f);
        glVertex2f(-0.29f, 0.07f);
    glEnd();


        //roof 1
        glColor3f(0.8f, 0.1f, 0.1f);
        glBegin(GL_QUADS);
            glVertex2f(-0.185f, 0.03f);
            glVertex2f( 0.185f, 0.03f);
            glVertex2f( 0.285f, -0.06f);
            glVertex2f(-0.285f, -0.06f);

        glEnd();

    //tally lines
    glLineWidth(2.0f);
    glColor3f(0.6f, 0.0f, 0.0f); // dark red

    // center line
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.029f);
        glVertex2f(0.0f, -0.06f);
    glEnd();

    // left line
    glBegin(GL_LINES);
        glVertex2f(-0.185f, 0.029f);
        glVertex2f(-0.285f, -0.06f);
    glEnd();

    // right line
    glBegin(GL_LINES);
        glVertex2f(0.185f, 0.029f);
        glVertex2f(0.285f, -0.06f);
    glEnd();

    //left lines
    glPushMatrix();
    for(int i = 1; i <= 10; i++)
    {
        glTranslatef(0.018f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.185f, 0.029f);
            glVertex2f(-0.285f, -0.06f);
        glEnd();
    }
    glPopMatrix();

    // right lines
    glPushMatrix();
    for(int i = 1; i <= 10; i++)
    {
        glTranslatef(-0.018f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.185f, 0.03f);
            glVertex2f(0.285f, -0.06f);
        glEnd();
    }
    glPopMatrix();


    // roof edge
    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.285f, -0.06f);
        glVertex2f( 0.285f, -0.06f);
        glVertex2f( 0.285f, -0.069f);
        glVertex2f(-0.285f, -0.069f);
    glEnd();

    //roof design
    glColor3f(0.55f, 0.0f, 0.0f); //maroon
    glBegin(GL_TRIANGLES);
        glVertex2f( 0.0f,    0.016f);
        glVertex2f(-0.09f, -0.06f);
        glVertex2f( 0.09f, -0.06f);
    glEnd();

    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.138f, -0.06f);
        glVertex2f( 0.138f, -0.06f);
        glVertex2f( 0.138f, -0.069f);
        glVertex2f(-0.138f, -0.069f);
    glEnd();

    // white line
    glLineWidth(2);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f( 0.0f,    0.014f);
        glVertex2f( 0.05f, -0.054f);
        glVertex2f(-0.05f, -0.054f);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-0.015f, -0.054f);
        glVertex2f( 0.0f,    0.014f);

        glVertex2f( 0.015f, -0.054f);
        glVertex2f( 0.0f,    0.014f);
    glEnd();


    //pillars
    glColor3f(0.95f, 0.9f, 0.75f);

    //pillar 1
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.07f);
        glVertex2f(-0.235f, -0.07f);
        glVertex2f(-0.235f, -0.204f);
        glVertex2f(-0.25f, -0.204f);
    glEnd();

    //pillar 2
    glBegin(GL_QUADS);
        glVertex2f(-0.048f, -0.06f);
        glVertex2f(-0.036f, -0.06f);
        glVertex2f(-0.036f, -0.204f);
        glVertex2f(-0.048f, -0.204f);
    glEnd();

    //pillar 3
    glBegin(GL_QUADS);
        glVertex2f(0.036f, -0.06f);
        glVertex2f(0.048f, -0.06f);
        glVertex2f(0.048f, -0.204f);
        glVertex2f(0.036f, -0.204f);
    glEnd();

    //pillar 4
    glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.07f);
        glVertex2f(0.235f, -0.07f);
        glVertex2f(0.235f, -0.204f);
        glVertex2f(0.25f, -0.204f);
    glEnd();


    //door
    glColor3f(0.32f, 0.2f, 0.12f);
    glBegin(GL_QUADS);
        glVertex2f(-0.03f, -0.105f);
        glVertex2f( 0.03f, -0.105f);
        glVertex2f( 0.03f, -0.204f);
        glVertex2f(-0.03f, -0.204f);
    glEnd();

    // window 1
    glColor3f(1.0f, 1.0f, 0.8f);
    glBegin(GL_QUADS);
        glVertex2f(-0.16f, -0.084f);
        glVertex2f(-0.10f, -0.084f);
        glVertex2f(-0.10f, -0.165f);
        glVertex2f(-0.16f, -0.165f);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
        glVertex2f(0.16f, -0.084f);
        glVertex2f(0.1f, -0.084f);
        glVertex2f(0.1f, -0.165f);
        glVertex2f(0.16f, -0.165f);
    glEnd();



    //right railing
    glColor3f(0.95f, 0.95f, 0.95f);
    glLineWidth(2.5f);

    glBegin(GL_LINES);
        glVertex2f(0.205f, -0.15f);
        glVertex2f(0.205f, -0.204f);
    glEnd();

    glPushMatrix();
    for(int i = 1; i <= 5; i++)
    {
        glTranslatef(-0.029f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.205f, -0.15f);
        glVertex2f(0.205f, -0.204f);
        glEnd();
    }
    glPopMatrix();

     // right horizontal
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(0.206f, -0.15f);
        glVertex2f(0.058f, -0.15f);
    glEnd();



    //left railing
    glColor3f(0.95f, 0.95f, 0.95f);
    glLineWidth(2.5f);

    glBegin(GL_LINES);
        glVertex2f(-0.208f, -0.15f);
        glVertex2f(-0.208f, -0.204f);
    glEnd();

    glPushMatrix();
    for(int i = 1; i <= 5; i++)
    {
        glTranslatef(0.029f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.208f, -0.15f);
        glVertex2f(-0.208f, -0.204f);
        glEnd();
    }
    glPopMatrix();


    //left horizontal
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(-0.211f, -0.15f);
        glVertex2f(-0.061f, -0.15f);
    glEnd();


    //stairs
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(-0.054f, -0.204f);
        glVertex2f( 0.054f, -0.204f);
        glVertex2f( 0.066f, -0.225f);
        glVertex2f(-0.066f, -0.225f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.066f, -0.225f);
        glVertex2f( 0.066f, -0.225f);
        glVertex2f( 0.084f, -0.24f);
        glVertex2f(-0.084f, -0.24f);
    glEnd();
}

    void boatRain()
{
    // main boat
 glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.64f, -0.5f);
        glVertex2f(0.9f, -0.5f);
        glVertex2f(0.96f, -0.4f);
        glVertex2f(0.86f, -0.44f);
        glVertex2f(0.66f, -0.44f);
        glVertex2f(0.54f, -0.4f);
//middle khamba
    glEnd();
     glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(0.74f, -0.44f);
        glVertex2f(0.76f, -0.44f);
        glVertex2f(0.76f, -0.12f);
        glVertex2f(0.74f, -0.12f);
    glEnd();
//right pal
glBegin(GL_TRIANGLES);

    glColor3f(0.8f, 0.33f, 0.0f);

    glVertex2f(0.78f, -0.44f);
    glVertex2f(0.84f, -0.44f);
    glVertex2f(0.76f, -0.2f);

glEnd();
//left pal
glBegin(GL_TRIANGLES);

    glColor3f(0.8f, 0.33f, 0.0f);

    glVertex2f(0.68f, -0.44f);
    glVertex2f(0.73f, -0.44f);
    glVertex2f(0.74f, -0.2f);
glEnd();

//small flag
glBegin(GL_TRIANGLES);

    glColor3f(0.1f, 0.5f, 0.0f);

    glVertex2f(0.74f, -0.16f);
    glVertex2f(0.74f, -0.14f);
    glVertex2f(0.66f, -0.145f);

glEnd();
}

    void baseTree2Rain()
{
    // leaves
    glColor3f(0.484f, 0.452f, 0.029f);
    drawCircle(-0.04f, -0.08f, 0.12f);
    drawCircle(-0.12f, -0.012f, 0.12f);

    glColor3f(0.625f, 0.758f, 0.068f);
    drawCircle(-0.16f, 0.06f, 0.12f);

    glColor3f(0.484f, 0.652f, 0.029f);
    drawCircle(-0.124f, 0.14f, 0.12f);
    drawCircle(-0.072f, 0.26f, 0.136f);

    glColor3f(0.625f, 0.758f, 0.068f);
    drawCircle(0.044f, 0.364f, 0.12f);

    glColor3f(0.484f, 0.652f, 0.029f);
    drawCircle(0.16f, 0.32f, 0.12f);
    drawCircle(0.12f, 0.12f, 0.16f);
    drawCircle(0.248f, 0.14f, 0.12f);
    drawCircle(0.284f, 0.044f, 0.12f);
    drawCircle(0.26f, -0.04f, 0.12f);
    drawCircle(0.20f, -0.06f, 0.12f);

    glColor3f(0.625f, 0.558f, 0.068f);
    drawCircle(0.128f, -0.152f, 0.096f);
    drawCircle(0.088f, -0.152f, 0.096f);

    glColor3f(0.339f, 0.531f, 0.111f);
    drawCircle(0.16f, 0.18f, 0.152f);

    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.112f, 0.22f, 0.152f);
    drawCircle(0.06f, 0.20f, 0.08f);

    glColor3f(0.547f, 0.676f, 0.123f);
    drawCircle(0.04f, 0.212f, 0.112f);
    drawCircle(0.036f, 0.196f, 0.072f);

    // main tree
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.06f, 0.08f);
        glVertex2f(0.10f, 0.08f);
        glVertex2f(0.12f, -0.48f);
        glVertex2f(0.04f, -0.48f);
    glEnd();

    // branch 1
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(0.232f, 0.04f);
        glVertex2f(0.232f, 0.04f);
    glEnd();

    // branch 2
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, 0.0f);
        glVertex2f(0.10f, -0.032f);
        glVertex2f(0.14f, 0.04f);
        glVertex2f(0.16f, 0.04f);
    glEnd();

    // branch 3
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.056f, 0.0f);
        glVertex2f(0.06f, -0.04f);
        glVertex2f(0.02f, 0.02f);
        glVertex2f(0.008f, -0.004f);
    glEnd();

    // branch 4
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(-0.008f, -0.008f);
        glVertex2f(-0.012f, -0.032f);
    glEnd();
}


void dressBar()
{
    //dress picking khamba 1

     glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(0.12f, -0.74f);
        glVertex2f(0.14f, -0.74f);
        glVertex2f(0.14f, -0.42f);
        glVertex2f(0.12f, -0.42f);
    glEnd();
//dress picking khamba 2

     glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.74f);
        glVertex2f(-0.18f, -0.74f);
        glVertex2f(- 0.18f, -0.42f);
        glVertex2f(-0.2f, -0.42f);
    glEnd();
    //
     glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.22f, -0.46f);
        glVertex2f(0.16f, -0.46f);
        glVertex2f(0.16f, -0.44f);
        glVertex2f(-0.22f, -0.44f);
    glEnd();
}


 void boat2Rain()
{
    glPushMatrix();
    glTranslatef(boat2_x, 0.18f, 0.0f);
    glScalef(0.2f, 0.2f, 1.0f);

    // main boat
    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.64f, -0.5f);
        glVertex2f(0.9f, -0.5f);
        glVertex2f(0.96f, -0.4f);
        glVertex2f(0.86f, -0.44f);
        glVertex2f(0.66f, -0.44f);
        glVertex2f(0.54f, -0.4f);
    glEnd();

    // middle khamba
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(0.74f, -0.44f);
        glVertex2f(0.76f, -0.44f);
        glVertex2f(0.76f, -0.12f);
        glVertex2f(0.74f, -0.12f);
    glEnd();

    // right pal
    glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.33f, 0.0f);
        glVertex2f(0.78f, -0.44f);
        glVertex2f(0.84f, -0.44f);
        glVertex2f(0.76f, -0.2f);
    glEnd();

    // left pal
    glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.33f, 0.0f);
        glVertex2f(0.68f, -0.44f);
        glVertex2f(0.73f, -0.44f);
        glVertex2f(0.74f, -0.2f);
    glEnd();

    // small flag
    glBegin(GL_TRIANGLES);
        glColor3f(0.1f, 0.5f, 0.0f);
        glVertex2f(0.74f, -0.16f);
        glVertex2f(0.74f, -0.14f);
        glVertex2f(0.66f, -0.145f);
    glEnd();

    glPopMatrix();
}

void trainRain()
{
    // chaka back train2
   glPushMatrix();
    for (int i = 1; i <= 2; i++)
    {
        glTranslatef(0.2f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.5f, 0.5f, 0.5f); // Gray
            drawCircle(0.55f, 0.21f, 0.016f);
            glColor3f(0.0f, 0.0f, 0.0f); // Black
            drawCircle(0.55f, 0.21f, 0.01f);
        glEnd();
    }
    glPopMatrix();

    // Back train2 body
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex2f(0.7f, 0.32f);
        glVertex2f(0.7f, 0.21f);
        glVertex2f(1.0f, 0.21f);
        glVertex2f(1.0f, 0.32f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(0.7f, 0.265f);
        glVertex2f(0.7f, 0.21f);
        glVertex2f(1.0f, 0.21f);
        glVertex2f(1.0f, 0.265f);
    glEnd();

    // Back train2 windows (janala)
    glPushMatrix();
    for (int i = 1; i <= 6; i++)
    {
        glTranslatef(0.05f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
           glColor3f(0.5f, 0.6f, 0.4f); //deep grren
            glVertex2f(0.66f, 0.3f);
            glVertex2f(0.66f, 0.27f);
            glVertex2f(0.69f, 0.27f);
            glVertex2f(0.69f, 0.3f);
        glEnd();
    }
    glPopMatrix();

    // Back train2 lines
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glVertex2f(0.7f, 0.265f);
        glVertex2f(1.0f, 0.265f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.8f, 0.31f);
        glVertex2f(0.9f, 0.31f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.8f, 0.31f);
        glVertex2f(0.8f, 0.21f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.9f, 0.31f);
        glVertex2f(0.9f, 0.21f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.85f, 0.31f);
        glVertex2f(0.85f, 0.21f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.7f, 0.32f);
        glVertex2f(0.7f, 0.21f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.7f, 0.32f);
        glVertex2f(1.0f, 0.32f);
    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2f(0.7f, 0.22f);
        glVertex2f(0.68f, 0.22f);
    glEnd();

    // chaka front train2
    glPushMatrix();
    for (int i = 1; i <= 2; i++)
    {
        glTranslatef(0.2f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.5f, 0.5f, 0.5f); // Gray
            drawCircle(0.24f, 0.21f, 0.016f);
            glColor3f(0.0f, 0.0f, 0.0f); // Black
            drawCircle(0.24f, 0.21f, 0.01f);
        glEnd();
    }
    glPopMatrix();

    // Front train2 body
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex2f(0.68f, 0.32f);
        glVertex2f(0.68f, 0.21f);
        glVertex2f(0.4f, 0.21f);
        glVertex2f(0.37f, 0.27f);
        glVertex2f(0.4f, 0.32f);
    glEnd();

    // Front curve
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    drawCircle(0.39f, 0.24f, 0.03f);
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(0.68f, 0.265f);
        glVertex2f(0.68f, 0.21f);
        glVertex2f(0.4f, 0.21f);
        glVertex2f(0.4f, 0.265f);
    glEnd();

    // Front train2 janala
    glPushMatrix();
    for (int i = 1; i <= 5; i++)
    {
        glTranslatef(0.047f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glColor3f(0.5f, 0.6f, 0.4f); //deep green
            glVertex2f(0.383f, 0.3f);
            glVertex2f(0.383f, 0.27f);
            glVertex2f(0.413f, 0.27f);
            glVertex2f(0.413f, 0.3f);
        glEnd();
    }
    glPopMatrix();

    // Front window
    glBegin(GL_QUADS);
        glColor3f(0.9f, 0.8f, 0.0f); //light brown
        glVertex2f(0.41f, 0.3f);
        glVertex2f(0.41f, 0.27f);
        glVertex2f(0.37f, 0.27f);
        glVertex2f(0.39f, 0.3f);
    glEnd();

    // Front train2 lines
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glVertex2f(0.68f, 0.265f);
        glVertex2f(0.37f, 0.265f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0.68f, 0.32f);
        glVertex2f(0.4f, 0.32f);
    glEnd();


    glPushMatrix();
    for (int bogey = 1; bogey <= 5; bogey++)
    {


        glTranslatef(0.32f, 0.0f, 0.0f);


        glPushMatrix();
        for (int i = 1; i <= 2; i++)
        {
            glTranslatef(0.2f, 0.0f, 0.0f);
            glBegin(GL_POLYGON);
                glColor3f(0.5f, 0.5f, 0.5f); // Gray
                drawCircle(0.55f, 0.21f, 0.016f);
                glColor3f(0.0f, 0.0f, 0.0f); // Black
                drawCircle(0.55f, 0.21f, 0.01f);
            glEnd();
        }
        glPopMatrix();

        // Bogey body
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f); // White
            glVertex2f(0.7f, 0.32f);
            glVertex2f(0.7f, 0.21f);
            glVertex2f(1.0f, 0.21f);
            glVertex2f(1.0f, 0.32f);
        glEnd();
        glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 0.0f); // Red
            glVertex2f(0.7f, 0.265f);
            glVertex2f(0.7f, 0.21f);
            glVertex2f(1.0f, 0.21f);
            glVertex2f(1.0f, 0.265f);
        glEnd();

        // Windows
        glPushMatrix();
        for (int i = 1; i <= 6; i++)
        {
            glTranslatef(0.05f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
                glColor3f(0.5f, 0.6f, 0.4f); //deep green
                glVertex2f(0.66f, 0.3f);
                glVertex2f(0.66f, 0.27f);
                glVertex2f(0.69f, 0.27f);
                glVertex2f(0.69f, 0.3f);
            glEnd();
        }
        glPopMatrix();

        // Lines
        glLineWidth(2);
        glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(0.7f, 0.265f);
            glVertex2f(1.0f, 0.265f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.8f, 0.31f);
            glVertex2f(0.9f, 0.31f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.8f, 0.31f);
            glVertex2f(0.8f, 0.21f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.9f, 0.31f);
            glVertex2f(0.9f, 0.21f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.85f, 0.31f);
            glVertex2f(0.85f, 0.21f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.7f, 0.32f);
            glVertex2f(0.7f, 0.21f);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex2f(0.7f, 0.32f);
            glVertex2f(1.0f, 0.32f);
        glEnd();


        glLineWidth(4);
        glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f); // Black
            glVertex2f(0.7f, 0.22f);
            glVertex2f(0.68f, 0.22f);
        glEnd();
    }
    glPopMatrix();
}


//.........................................................scenario 3

    void drawSemiCircle_s1(float cx, float cy, float radiusX, float radiusY) {
        int triangleAmount = 50;
        float twicePi = 2.0f * 3.1416f;
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                cx + (radiusX * cos(i * twicePi / (triangleAmount * 2))),
                cy + (radiusY * sin(i * twicePi / (triangleAmount * 2)))
            );
        }
        glEnd();
    }

void chairs()
{


// matha
    glBegin((GL_QUADS));
        glColor3f(0.12f, 0.23f, 0.37f);// dark blue
        glVertex2f(0.9f, 0.1f);
        glVertex2f(0.69f, 0.1f);
        glVertex2f(0.69f, -0.02f);
        glVertex2f(0.81f, -0.1f);
    glEnd();


// red curve
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(0.93f, -0.04f, 0.14f);

    // chair dan side
    glBegin((GL_QUADS));
        glColor3f(1.0f, 0.0f, 0.0f); // red
        glVertex2f(1.0f, 0.1f);
        glVertex2f(0.9f, 0.1f);
        glVertex2f(0.9f, -0.1f);
        glVertex2f(1.0f, -0.1f);
        glEnd();
    // seat
        glBegin((GL_POLYGON));
        glColor3f(0.12f, 0.23f, 0.37f); // dark blue
        glVertex2f(0.81f, -0.1f);
        glVertex2f(0.7f, -0.61f);
        glVertex2f(0.85f, -0.61f);
        glVertex2f(1.0f, -0.41f);
        glVertex2f(1.0f, -0.1f);
        glEnd();

        glPushMatrix();

    glTranslatef(0.78f, -0.4, 0.0f);
    glScalef(1.3f, 1.3f, 0.0f);
    glRotatef(80.0f, 0.0f, 0.0f, 1.0f);


    glColor3f(0.12f, 0.23f, 0.37f);
    drawSemiCircle_s1(0.0f, 0.0f, 0.23f, 0.10f);

glPopMatrix();

    // black uporer line
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.58f, -0.61f);
        glVertex2f(0.51f, -0.8f);
        glVertex2f(1.0f, -0.8f);
        glVertex2f(1.0f, -0.61f);
    glEnd();
    // red nicher line
    glBegin((GL_QUADS));
        glColor3f(0.86f, 0.80f, 0.59f);// yellowish
        glVertex2f(0.6f, -0.64f);
        glVertex2f(0.54f, -0.8f);
        glVertex2f(1.0f, -0.8f);
        glVertex2f(1.0f, -0.64f);
    glEnd();
    // blue
    glBegin((GL_POLYGON));
        glColor3f(0.86f, 0.80f, 0.59f);// yellowish
        glVertex2f(0.4f, -0.49f);
        glVertex2f(0.62f, -0.49f);
        glVertex2f(0.7f, -0.61f);
        glVertex2f(0.58f, -0.61f);
        glVertex2f(0.35f, -0.62f);
    glEnd();
    // seat hatol
    glBegin((GL_QUADS));
        glColor3f(0.10f, 0.10f, 0.10f);
        glVertex2f(0.4f, -0.49f);
        glVertex2f(0.62f, -0.49f);
        glVertex2f(0.62f, -0.4f);
        glVertex2f(0.4f, -0.4f);
    glEnd();


    // boshar seat
    glBegin((GL_QUADS));
        glColor3f(0.12f, 0.23f, 0.37f); // dark blue
        glVertex2f(0.28f, -0.54f);
        glVertex2f(0.28f, -0.8f);
        glVertex2f(0.51f, -0.8f);
        glVertex2f(0.58f, -0.61f);
    glEnd();

    glPushMatrix();

    glTranslatef(0.28f, -0.68f, 0.0f);
    glScalef(0.7f, 0.7f, 0.0f);


    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);


    glColor3f(0.12f, 0.23f, 0.37f);
    drawSemiCircle_s1(0.0f, 0.0f, 0.2f, 0.1f);

glPopMatrix();




     // cornar triangle
    glBegin((GL_TRIANGLES));
        glColor3f(1.0f, 0.88f, 0.89f); // black
        glVertex2f(0.85f, -0.61f);
        glVertex2f(1.0f, -0.61f);
        glVertex2f(1.0f, -0.41f);
        glEnd();


    // matha
    glBegin((GL_QUADS));
        glColor3f(0.12f, 0.23f, 0.37f);// dark blue
        glVertex2f(-0.9f, 0.1f);
        glVertex2f(-0.69f, 0.1f);
        glVertex2f(-0.69f, -0.02f);
        glVertex2f(-0.81f, -0.1f);
    glEnd();

     // red curve
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(-0.93f, -0.04f, 0.14f);

    // Bam side er chair
    glBegin((GL_QUADS));
        glColor3f(1.0f, 0.0f, 0.0f); // red
        glVertex2f(-1.0f, 0.1f);
        glVertex2f(-0.9f, 0.1f);
        glVertex2f(-0.81f, -0.1f);
        glVertex2f(-1.0f, -0.1f);
    glEnd();
    // seat
    glBegin((GL_POLYGON));
        glColor3f(0.12f, 0.23f, 0.37f); // dark blue
        glVertex2f(-0.81f, -0.1f);
        glVertex2f(-0.7f, -0.61f);
        glVertex2f(-0.85f, -0.61f);
        glVertex2f(-1.0f, -0.41f);
        glVertex2f(-1.0f, -0.1f);
    glEnd();

            glPushMatrix();
    glTranslatef(-0.80f, -0.395, 0.0f);
    glScalef(1.3f, 1.3f, 0.0f);

    glRotatef(280.0f, 0.0f, 0.0f, 1.0f);


    glColor3f(0.12f, 0.23f, 0.37f);
    drawSemiCircle_s1(0.0f, 0.0f, 0.23f, 0.10f);

glPopMatrix();
    // black uporer line
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.58f, -0.61f);
        glVertex2f(-0.51f, -0.8f);
        glVertex2f(-1.0f, -0.8f);
        glVertex2f(-1.0f, -0.61f);
    glEnd();
    // red nicher line
    glBegin((GL_QUADS));
        glColor3f(0.86f, 0.80f, 0.59f);//yellowish
        glVertex2f(-0.6f, -0.64f);
        glVertex2f(-0.54f, -0.8f);
        glVertex2f(-1.0f, -0.8f);
        glVertex2f(-1.0f, -0.64f);
    glEnd();
    // armrest er niche
    glBegin((GL_POLYGON));
        glColor3f(0.86f, 0.80f, 0.59f);
        glVertex2f(-0.4f, -0.49f);
        glVertex2f(-0.62f, -0.49f);
        glVertex2f(-0.7f, -0.61f);
        glVertex2f(-0.58f, -0.61f);
        glVertex2f(-0.35f, -0.62f);
    glEnd();
    // seat hatol
    glBegin((GL_QUADS));
        glColor3f(0.10f, 0.10f, 0.10f);//black
        glVertex2f(-0.4f, -0.49f);
        glVertex2f(-0.62f, -0.49f);
        glVertex2f(-0.62f, -0.4f);
        glVertex2f(-0.4f, -0.4f);
    glEnd();
    // boshar seat
    glBegin((GL_QUADS));
        glColor3f(0.12f, 0.23f, 0.37f); // dark blue
        glVertex2f(-0.2f, -0.54f);
        glVertex2f(-0.2f, -0.8f);
        glVertex2f(-0.51f, -0.8f);
        glVertex2f(-0.58f, -0.61f);
    glEnd();


    glPushMatrix();

    glTranslatef(-0.2f, -0.68f, 0.0f);
    glScalef(0.7f, 0.7f, 0.0f);

    glRotatef(270.0f, 0.0f, 0.0f, 1.0f);


    glColor3f(0.12f, 0.23f, 0.37f);
    drawSemiCircle_s1(0.0f, 0.0f, 0.2f, 0.1f);

glPopMatrix();




}

void table()
{
    // window er nicher khamba 1
    glBegin((GL_QUADS));
        glColor3f(0.24f, 0.25f, 0.27f); // dark gray
        glVertex2f(-0.12f, -0.3f);
        glVertex2f(-0.15f, -0.4f);
        glVertex2f(0.15f, -0.4f);
        glVertex2f(0.12f,- 0.3f);
    glEnd();
    // window er nicher khamba 2
    glBegin((GL_QUADS));
        glColor3f(0.69f, 0.71f, 0.76f); // light grayish
        glVertex2f(-0.1f, -0.3f);
        glVertex2f(-0.12f, -0.38f);
        glVertex2f(0.12f, -0.38f);
        glVertex2f(0.1f,- 0.3f);
    glEnd();
    // bordar table
    glBegin((GL_QUADS));
        glColor3f(0.24f, 0.25f, 0.27f); // dark ass
        glVertex2f(-0.13f, -0.4f);
        glVertex2f(-0.13f, -0.56f);
        glVertex2f(0.13f, -0.56f);
        glVertex2f(0.13f,- 0.4f);
    glEnd();
    // window er nicher khamba 3 dan side
    glBegin((GL_QUADS));
        glColor3f(0.69f, 0.71f, 0.76f); // light ash
        glVertex2f(-0.12f, -0.4f);
        glVertex2f(-0.12f, -0.55f);
        glVertex2f(0.0f, -0.55f);
        glVertex2f(0.0f,- 0.4f);
    glEnd();
    // window er nicher khamba 3 bam side side
    glBegin((GL_QUADS));
        glColor3f(0.69f, 0.71f, 0.76f); //  light ash
        glVertex2f(0.0f, -0.55f);
        glVertex2f(0.0f, -0.4f);
        glVertex2f(0.12f, -0.4f);
        glVertex2f(0.12f,- 0.55f);
    glEnd();
    // table er majhe border
    glBegin((GL_QUADS));
        glColor3f(0.24f, 0.25f, 0.27f); //  dark ash
        glVertex2f(0.0f, -0.4f);
        glVertex2f(0.0f, -0.55f);
        glVertex2f(0.01f, -0.55f);
        glVertex2f(0.01f,- 0.4f);
    glEnd();


}

void lamp()
{
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 1
        glVertex2f(-1.0f, 0.35f);
        glVertex2f(-1.0f, 0.24f);
        glVertex2f(-0.99f, 0.24f);
        glVertex2f(-0.99f, 0.35f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 2
        glVertex2f(-1.0f, 0.33f);
        glVertex2f(-1.0f, 0.25f);
        glVertex2f(-0.98f, 0.25f);
        glVertex2f(-0.98f, 0.33f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 3
        glVertex2f(-1.0f, 0.295f);
        glVertex2f(-1.0f, 0.28f);
        glVertex2f(-0.84f, 0.28f);
        glVertex2f(-0.84f, 0.295f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 4
        glVertex2f(-0.87f, 0.35f);
        glVertex2f(-0.87f, 0.24f);
        glVertex2f(-0.84f, 0.24f);
        glVertex2f(-0.84f, 0.35f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 5
        glVertex2f(-0.85f, 0.4f);
        glVertex2f(-0.85f, 0.35f);
        glVertex2f(-0.858f, 0.35f);
        glVertex2f(-0.858f, 0.4f);
    glEnd();
    // lamp er niche golla
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(-0.854f, 0.228f, 0.013f);
    //circle er niche quad
    glBegin((GL_QUADS));
        glColor3f(0.5f, 0.5f, 0.5f); // black 6
        glVertex2f(-0.85f, 0.228f);
        glVertex2f(-0.85f, 0.19f);
        glVertex2f(-0.86f, 0.19f);
        glVertex2f(-0.86f, 0.228f);
    glEnd();
    // lamp er niche golla 2
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(-0.853f, 0.19f, 0.013f);
    // main lamp
    glBegin((GL_QUADS));
        glColor3f(0.69f, 0.71f, 0.76f); // black 5
        glVertex2f(-0.89f, 0.53f);
        glVertex2f(-0.93f, 0.4f);
        glVertex2f(-0.78f, 0.4f);
        glVertex2f(-0.82f, 0.53f);
    glEnd();
    // dan lamp
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 1
        glVertex2f(1.0f, 0.35f);
        glVertex2f(1.0f, 0.24f);
        glVertex2f(0.99f, 0.24f);
        glVertex2f(0.99f, 0.35f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 2
        glVertex2f(1.0f, 0.33f);
        glVertex2f(1.0f, 0.25f);
        glVertex2f(0.98f, 0.25f);
        glVertex2f(0.98f, 0.33f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 3
        glVertex2f(1.0f, 0.295f);
        glVertex2f(1.0f, 0.28f);
        glVertex2f(0.84f, 0.28f);
        glVertex2f(0.84f, 0.295f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 4
        glVertex2f(0.87f, 0.35f);
        glVertex2f(0.87f, 0.24f);
        glVertex2f(0.84f, 0.24f);
        glVertex2f(0.84f, 0.35f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black 5
        glVertex2f(0.85f, 0.4f);
        glVertex2f(0.85f, 0.35f);
        glVertex2f(0.858f, 0.35f);
        glVertex2f(0.858f, 0.4f);
    glEnd();
    // lamp er niche golla 1
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(0.853f, 0.228f, 0.013f);
    //circle er niche quad
    glBegin((GL_QUADS));
        glColor3f(0.5f, 0.5f, 0.5f); // black 6
        glVertex2f(0.85f, 0.228f);
        glVertex2f(0.85f, 0.19f);
        glVertex2f(0.86f, 0.19f);
        glVertex2f(0.86f, 0.228f);
    glEnd();
    // lamp er niche golla 2
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(0.853f, 0.19f, 0.013f);
    // main lamp
    glBegin((GL_QUADS));
        glColor3f(0.69f, 0.71f, 0.76f); // black 7
        glVertex2f(0.89f, 0.53f);
        glVertex2f(0.93f, 0.4f);
        glVertex2f(0.78f, 0.4f);
        glVertex2f(0.82f, 0.53f);
    glEnd();
}

void chain()
{
    glBegin((GL_QUADS));
        glColor3f(2.0f, 0.0f, 0.0f);
        glVertex2f(-0.77f, 0.35f);
        glVertex2f(-0.77f, 0.24f);
        glVertex2f(-0.68f, 0.24f);
        glVertex2f(-0.68f, 0.35f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(1.0f, 0.6f, 0.6f); // black 7
        glVertex2f(-0.75f, 0.34f);
        glVertex2f(-0.76f, 0.25f);
        glVertex2f(-0.69f, 0.25f);
        glVertex2f(-0.7f, 0.34f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 1.0f); // yellow
        glVertex2f(-0.749f, 0.3f);
        glVertex2f(-0.76f, 0.25f);
        glVertex2f(-0.69f, 0.25f);
        glVertex2f(-0.7f, 0.3f);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // black axes
        glVertex2f(-0.728f, 0.3f);
        glVertex2f(-0.728f, 0.2f);
    glEnd();
    glBegin((GL_QUADS));
        glColor3f(0.81f, 0.0f, 0.0f); // red
        glVertex2f(-0.71f, 0.2f);
        glVertex2f(-0.71f, 0.12f);
        glVertex2f(-0.74f, 0.12f);
        glVertex2f(-0.74f, 0.2f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // blue
    renderBitmapString(-0.78f, 0.36f, 0.0f, GLUT_BITMAP_HELVETICA_10, "EMERGENCY");

}

void window()
{
    // window line 1
    glBegin((GL_QUADS));
        glColor3f(0.86f, 0.80f, 0.59f); // yellowish
        glVertex2f(-0.65f, -0.3f);
        glVertex2f(0.65f, -0.3f);
        glVertex2f(0.65f, 0.59f);
        glVertex2f(-0.65f, 0.59f);
    glEnd();
    // window er bhitorer red coloer line
    glBegin((GL_QUADS));
        glColor3f(0.69f, 0.71f, 0.76f); // light grayish
        glVertex2f(-0.62f, -0.26f);
        glVertex2f(0.62f, -0.26f);
        glVertex2f(0.62f, 0.55f);
        glVertex2f(-0.62f, 0.55f);
    glEnd();
    // kalo line er uporer line
    glBegin((GL_QUADS));
        glColor3f(0.24f, 0.25f, 0.27f); //  dark ash
        glVertex2f(-0.6f, 0.44f);
        glVertex2f(0.6f, 0.44f);
        glVertex2f(0.6f, 0.55f);
        glVertex2f(-0.6f, 0.55f);
    glEnd();
    // shutter
    glBegin((GL_POLYGON));
        glColor3f(0.86f, 0.80f, 0.59f); // yellowish
        glVertex2f(-0.62f, 0.42f);
        glVertex2f(-0.6f, 0.4f);
        glVertex2f(0.6f, 0.4f);
        glVertex2f(0.62f, 0.42f);
        glVertex2f(0.6f, 0.44f);
        glVertex2f(-0.6f, 0.44f);
    glEnd();
    // black inner line
    glBegin((GL_QUADS));
        glColor3f(0.10f, 0.10f, 0.10f); // black
        glVertex2f(-0.6f, 0.4f);
        glVertex2f(-0.6f, -0.22f);
        glVertex2f(0.6f, -0.22f);
        glVertex2f(0.6f, 0.4f);
    glEnd();
}

void sky3()
{
    glBegin(GL_QUADS);
        glColor3f(0.784f, 0.902f, 1.0f); //off white
        glVertex2f(-0.58f, 0.38f);
        glVertex2f(0.58f, 0.38f);
        glVertex2f(0.58f, 0.17f);
        glVertex2f(-0.58f, 0.17f);
    glEnd();
}


void cloud3() //main cloud
{
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.00f, 0.00f, 0.08f);
    drawCircle(-0.10f, 0.00f, 0.07f);
    drawCircle(0.10f, 0.00f, 0.07f);
    drawCircle(-0.05f, 0.08f, 0.06f);
    drawCircle(0.05f, 0.08f, 0.06f);
}

void clouds3()
{
    //1
    glPushMatrix();
        glTranslatef(-0.50f, 0.24f, 0.0f);
        glScalef(0.25f, 0.20f, 1.0f);
        cloud3();
    glPopMatrix();
    //2
    glPushMatrix();
        glTranslatef(-0.25f, 0.25f, 0.0f);
        glScalef(0.22f, 0.18f, 1.0f);
        cloud3();
    glPopMatrix();
    //3
    glPushMatrix();
        glTranslatef(0.00f, 0.22f, 0.0f);
        glScalef(0.28f, 0.20f, 1.0f);
        cloud3();
    glPopMatrix();
    //4
    glPushMatrix();
        glTranslatef(0.28f, 0.25f, 0.0f);
        glScalef(0.22f, 0.18f, 1.0f);
        cloud3();
    glPopMatrix();
    //5
    glPushMatrix();
        glTranslatef(0.50f, 0.23f, 0.0f);
        glScalef(0.25f, 0.20f, 1.0f);
        cloud3();
    glPopMatrix();
    //6
    glPushMatrix();
        glTranslatef(-0.40f, 0.32f, 0.0f);
        glScalef(0.20f, 0.16f, 1.0f);
        cloud3();
    glPopMatrix();
    //7
    glPushMatrix();
        glTranslatef(-0.10f, 0.34f, 0.0f);
        glScalef(0.24f, 0.18f, 1.0f);
        cloud3();
    glPopMatrix();
    //8
    glPushMatrix();
        glTranslatef(0.17f, 0.33f, 0.0f);
        glScalef(0.20f, 0.16f, 1.0f);
        cloud3();
    glPopMatrix();
    //9
    glPushMatrix();
        glTranslatef(0.48f, 0.31f, 0.0f);
        glScalef(0.22f, 0.17f, 1.0f);
        cloud3();
    glPopMatrix();
}

void sun()
{
    glColor3f(1.0f, 0.84f, 0.0f); // golden yellow
    drawCircle(-0.30f, 0.3f, 0.07f);
}



void outside()
{
    glBegin((GL_QUADS));
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.58f, 0.38f);
        glVertex2f(-0.58f, -0.19f);
        glVertex2f(0.58f, -0.19f);
        glVertex2f(0.58f, 0.38f);
    glEnd();

    //water
    glBegin((GL_QUADS));
        glColor3f(0.69f, 0.89f, 1.0f);
        glVertex2f(-0.58f, 0.17f);
        glVertex2f(0.58f, 0.17f);
        glVertex2f(0.58f, 0.02f);
        glVertex2f(-0.58f, 0.02f);
    glEnd();
    //ground
    glBegin((GL_QUADS));
        glColor3f(0.6f, 0.9f, 0.6f);
        glVertex2f(-0.58f, 0.02f);
        glVertex2f(0.58f, 0.02f);
        glVertex2f(0.58f, -0.19f);
        glVertex2f(-0.58f, -0.19f);
    glEnd();
}

void tree3()
{
    for (int i = 0; i <= 10; i++)
    {
        glPushMatrix();
            glColor3f(0.0f, 0.6f, 0.0f);
            drawCircle(-0.98f, 0.33f, 0.03f);
            drawCircle(-0.93f, 0.34f, 0.045f);
            drawCircle(-0.87f, 0.35f, 0.06f);
            drawCircle(-0.81f, 0.34f, 0.045f);
            drawCircle(-0.76f, 0.33f, 0.03f);
        glPopMatrix();
        glTranslatef(0.25f, 0.0f, 0.0f);
    }
}

void house3()
{
    //ek tala
    glColor3f(0.9f, 0.7f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.55f, -0.48f);
        glVertex2f(-0.15f, -0.48f);
        glVertex2f(-0.15f, -0.70f);
        glVertex2f(-0.55f, -0.70f);
    glEnd();
    //ek tala chal
    glColor3f(0.7f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.50f, -0.42f);
        glVertex2f(-0.18f, -0.42f);
        glVertex2f(-0.10f, -0.50f);
        glVertex2f(-0.60f, -0.50f);
    glEnd();
    //dui tala
    glColor3f(0.9f, 0.7f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.50f, -0.30f);
        glVertex2f(-0.35f, -0.30f);
        glVertex2f(-0.35f, -0.42f);
        glVertex2f(-0.50f, -0.42f);
    glEnd();
    // dui tala chal
    glColor3f(0.7f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-0.50f, -0.24f);
        glVertex2f(-0.35f, -0.24f);
        glVertex2f(-0.30f, -0.30f);
        glVertex2f(-0.55f, -0.30f);
    glEnd();
    //door
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.38f, -0.55f);
        glVertex2f(-0.31f, -0.55f);
        glVertex2f(-0.31f, -0.70f);
        glVertex2f(-0.38f, -0.70f);
    glEnd();
    //ek tala windows
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON); //left
        glVertex2f(-0.50f, -0.54f);
        glVertex2f(-0.44f, -0.54f);
        glVertex2f(-0.44f, -0.62f);
        glVertex2f(-0.50f, -0.62f);
    glEnd();
    glBegin(GL_POLYGON); //right
        glVertex2f(-0.26f, -0.54f);
        glVertex2f(-0.20f, -0.54f);
        glVertex2f(-0.20f, -0.62f);
        glVertex2f(-0.26f, -0.62f);
    glEnd();
    //dui tala window
    glBegin(GL_POLYGON); // left
        glVertex2f(-0.48f, -0.32f);
        glVertex2f(-0.44f, -0.32f);
        glVertex2f(-0.44f, -0.38f);
        glVertex2f(-0.48f, -0.38f);
    glEnd();
    glBegin(GL_POLYGON); // right
        glVertex2f(-0.42f, -0.32f);
        glVertex2f(-0.38f, -0.32f);
        glVertex2f(-0.38f, -0.38f);
        glVertex2f(-0.42f, -0.38f);
    glEnd();
    //rails
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.35f, -0.34f);
        glVertex2f(-0.2f, -0.34f);
    glEnd();
    // middle rails
    for (int i = 0; i < 6; i++)
    {
        glBegin(GL_LINES);
            glVertex2f(-0.35f, -0.42f);
            glVertex2f(-0.35f, -0.34f);
        glEnd();
        glTranslatef(0.03f, 0.0f, 0.0f);
    }
}

void house32()
{
    //black base
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.27f, -0.204f);
        glVertex2f(0.27f, -0.204f);
        glVertex2f(0.27f, -0.234f);
        glVertex2f(-0.27f, -0.234f);
    glEnd();
    //wall
    glColor3f(0.9f, 0.7f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.21f, -0.06f);
        glVertex2f(0.21f, -0.06f);
        glVertex2f(0.21f, -0.204f);
        glVertex2f(-0.21f, -0.204f);
    glEnd();
    // back house
    // back wall
    glColor3f(0.88f, 0.72f, 0.55f);
    glBegin(GL_QUADS);
        glVertex2f(-0.23f, 0.08f);
        glVertex2f(0.23f, 0.08f);
        glVertex2f(0.23f, -0.06f);
        glVertex2f(-0.23f, -0.06f);
    glEnd();
    //back roof
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.17f, 0.18f);
        glVertex2f(0.17f, 0.18f);
        glVertex2f(0.29f, 0.08f);
        glVertex2f(-0.29f, 0.08f);
    glEnd();
    //roof design
    glColor3f(0.55f, 0.0f, 0.0f); //maroon
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.18f);
        glVertex2f(-0.1f, 0.08f);
        glVertex2f(0.1f, 0.08f);
    glEnd();
    //tally lines
    glLineWidth(2.0f);
    glColor3f(0.6f, 0.0f, 0.0f); // dark red
    // left line
    glBegin(GL_LINES);
        glVertex2f(-0.17f, 0.18f);
        glVertex2f(-0.29f, 0.08f);
    glEnd();
    // right line
    glBegin(GL_LINES);
        glVertex2f(0.17f, 0.18f);
        glVertex2f(0.29f, 0.08f);
    glEnd();
    // left lines
    glPushMatrix();
    for(int i = 1; i <= 11; i++)
    {
        glTranslatef(0.015f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.17f, 0.18f);
            glVertex2f(-0.29f, 0.08f);
        glEnd();
    }
    glPopMatrix();
    // right lines
    glPushMatrix();
    for(int i = 1; i <= 11; i++)
    {
        glTranslatef(-0.015f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.17f, 0.18f);
            glVertex2f(0.29f, 0.08f);
        glEnd();
    }
    glPopMatrix();
    // back roof edge
    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.29f, 0.08f);
        glVertex2f(0.29f, 0.08f);
        glVertex2f(0.29f, 0.07f);
        glVertex2f(-0.29f, 0.07f);
    glEnd();
    //roof 1
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.185f, 0.03f);
        glVertex2f(0.185f, 0.03f);
        glVertex2f(0.285f, -0.06f);
        glVertex2f(-0.285f, -0.06f);
    glEnd();
    //tally lines
    glLineWidth(2.0f);
    glColor3f(0.6f, 0.0f, 0.0f); // dark red
    // center line
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.029f);
        glVertex2f(0.0f, -0.06f);
    glEnd();
    // left line
    glBegin(GL_LINES);
        glVertex2f(-0.185f, 0.029f);
        glVertex2f(-0.285f, -0.06f);
    glEnd();
    // right line
    glBegin(GL_LINES);
        glVertex2f(0.185f, 0.029f);
        glVertex2f(0.285f, -0.06f);
    glEnd();
    //left lines
    glPushMatrix();
    for(int i = 1; i <= 10; i++)
    {
        glTranslatef(0.018f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.185f, 0.029f);
            glVertex2f(-0.285f, -0.06f);
        glEnd();
    }
    glPopMatrix();
    // right lines
    glPushMatrix();
    for(int i = 1; i <= 10; i++)
    {
        glTranslatef(-0.018f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.185f, 0.03f);
            glVertex2f(0.285f, -0.06f);
        glEnd();
    }
    glPopMatrix();
    // roof edge
    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.285f, -0.06f);
        glVertex2f(0.285f, -0.06f);
        glVertex2f(0.285f, -0.069f);
        glVertex2f(-0.285f, -0.069f);
    glEnd();
    //roof design
    glColor3f(0.55f, 0.0f, 0.0f); //maroon
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.016f);
        glVertex2f(-0.09f, -0.06f);
        glVertex2f(0.09f, -0.06f);
    glEnd();
    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.138f, -0.06f);
        glVertex2f(0.138f, -0.06f);
        glVertex2f(0.138f, -0.069f);
        glVertex2f(-0.138f, -0.069f);
    glEnd();
    // white line
    glLineWidth(2);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 0.014f);
        glVertex2f(0.05f, -0.054f);
        glVertex2f(-0.05f, -0.054f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-0.015f, -0.054f);
        glVertex2f(0.0f, 0.014f);
        glVertex2f(0.015f, -0.054f);
        glVertex2f(0.0f, 0.014f);
    glEnd();
    //pillars
    glColor3f(0.95f, 0.9f, 0.75f);
    //pillar 1
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.07f);
        glVertex2f(-0.235f, -0.07f);
        glVertex2f(-0.235f, -0.204f);
        glVertex2f(-0.25f, -0.204f);
    glEnd();
    //pillar 2
    glBegin(GL_QUADS);
        glVertex2f(-0.048f, -0.06f);
        glVertex2f(-0.036f, -0.06f);
        glVertex2f(-0.036f, -0.204f);
        glVertex2f(-0.048f, -0.204f);
    glEnd();
    //pillar 3
    glBegin(GL_QUADS);
        glVertex2f(0.036f, -0.06f);
        glVertex2f(0.048f, -0.06f);
        glVertex2f(0.048f, -0.204f);
        glVertex2f(0.036f, -0.204f);
    glEnd();
    //pillar 4
    glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.07f);
        glVertex2f(0.235f, -0.07f);
        glVertex2f(0.235f, -0.204f);
        glVertex2f(0.25f, -0.204f);
    glEnd();
    //door
    glColor3f(0.32f, 0.2f, 0.12f);
    glBegin(GL_QUADS);
        glVertex2f(-0.03f, -0.105f);
        glVertex2f(0.03f, -0.105f);
        glVertex2f(0.03f, -0.204f);
        glVertex2f(-0.03f, -0.204f);
    glEnd();
    // window 1
    glColor3f(0.2f, 0.5f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-0.16f, -0.084f);
        glVertex2f(-0.10f, -0.084f);
        glVertex2f(-0.10f, -0.165f);
        glVertex2f(-0.16f, -0.165f);
    glEnd();
    //window 2
    glBegin(GL_QUADS);
        glVertex2f(0.16f, -0.084f);
        glVertex2f(0.1f, -0.084f);
        glVertex2f(0.1f, -0.165f);
        glVertex2f(0.16f, -0.165f);
    glEnd();
    //right railing
    glColor3f(0.95f, 0.95f, 0.95f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(0.205f, -0.15f);
        glVertex2f(0.205f, -0.204f);
    glEnd();
    glPushMatrix();
    for(int i = 1; i <= 5; i++)
    {
        glTranslatef(-0.029f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.205f, -0.15f);
        glVertex2f(0.205f, -0.204f);
        glEnd();
    }
    glPopMatrix();
    // right horizontal
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(0.206f, -0.15f);
        glVertex2f(0.058f, -0.15f);
    glEnd();
    //left railing
    glColor3f(0.95f, 0.95f, 0.95f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(-0.208f, -0.15f);
        glVertex2f(-0.208f, -0.204f);
    glEnd();
    glPushMatrix();
    for(int i = 1; i <= 5; i++)
    {
        glTranslatef(0.029f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.208f, -0.15f);
        glVertex2f(-0.208f, -0.204f);
        glEnd();
    }
    glPopMatrix();
    //left horizontal
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(-0.211f, -0.15f);
        glVertex2f(-0.061f, -0.15f);
    glEnd();

    //stairs
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(-0.054f, -0.204f);
        glVertex2f(0.054f, -0.204f);
        glVertex2f(0.066f, -0.225f);
        glVertex2f(-0.066f, -0.225f);
    glEnd();
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.066f, -0.225f);
        glVertex2f(0.066f, -0.225f);
        glVertex2f(0.084f, -0.24f);
        glVertex2f(-0.084f, -0.24f);
    glEnd();
}

void baseTree3()
{
    // leaves
    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(-0.04f, -0.08f, 0.12f);
    drawCircle(-0.12f, -0.012f, 0.12f);
    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(-0.16f, 0.06f, 0.12f);
    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(-0.124f, 0.14f, 0.12f);
    drawCircle(-0.072f, 0.26f, 0.136f);
    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.044f, 0.364f, 0.12f);
    glColor3f(0.584f, 0.752f, 0.129f);
    drawCircle(0.16f, 0.32f, 0.12f);
    drawCircle(0.12f, 0.12f, 0.16f);
    drawCircle(0.248f, 0.14f, 0.12f);
    drawCircle(0.284f, 0.044f, 0.12f);
    drawCircle(0.26f, -0.04f, 0.12f);
    drawCircle(0.20f, -0.06f, 0.12f);
    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.128f, -0.152f, 0.096f);
    drawCircle(0.088f, -0.152f, 0.096f);
    glColor3f(0.439f, 0.631f, 0.211f);
    drawCircle(0.16f, 0.18f, 0.152f);
    glColor3f(0.725f, 0.858f, 0.078f);
    drawCircle(0.112f, 0.22f, 0.152f);
    drawCircle(0.06f, 0.20f, 0.08f);
    glColor3f(0.647f, 0.776f, 0.223f);
    drawCircle(0.04f, 0.212f, 0.112f);
    drawCircle(0.036f, 0.196f, 0.072f);
    // main tree
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.06f, 0.08f);
        glVertex2f(0.10f, 0.08f);
        glVertex2f(0.12f, -0.48f);
        glVertex2f(0.04f, -0.48f);
    glEnd();
    // branch 1
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(0.232f, 0.04f);
        glVertex2f(0.232f, 0.04f);
    glEnd();
    // branch 2
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, 0.0f);
        glVertex2f(0.10f, -0.032f);
        glVertex2f(0.14f, 0.04f);
        glVertex2f(0.16f, 0.04f);
    glEnd();
    // branch 3
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.056f, 0.0f);
        glVertex2f(0.06f, -0.04f);
        glVertex2f(0.02f, 0.02f);
        glVertex2f(0.008f, -0.004f);
    glEnd();
    // branch 4
    glBegin(GL_QUADS);
        glColor3f(0.662f, 0.298f, 0.078f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(-0.008f, -0.008f);
        glVertex2f(-0.012f, -0.032f);
    glEnd();
}

void khamba()
{
    // uporer lomba kalo line
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-1.0f, 0.65f);
        glVertex2f(1.0f, 0.65f);
        glVertex2f(1.0f, 0.68f);
        glVertex2f(-1.0f, 0.68f);
    glEnd();
    // khamba 1
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.8f, 0.55f);
        glVertex2f(-0.82f, 0.55f);
        glVertex2f(-0.86f, 0.65f);
        glVertex2f(-0.75f, 0.65f);
    glEnd();
    // khamba 2
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(0.8f, 0.55f);
        glVertex2f(0.82f, 0.55f);
        glVertex2f(0.86f, 0.65f);
        glVertex2f(0.75f, 0.65f);
    glEnd();
    // khambar uporer line 1
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.58f, 0.68f);
        glVertex2f(-0.58f, 0.8f);
        glVertex2f(-0.6f, 0.8f);
        glVertex2f(-0.6f, 0.68f);
    glEnd();
    // line 2
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(0.58f, 0.68f);
        glVertex2f(0.58f, 0.8f);
        glVertex2f(0.6f, 0.8f);
        glVertex2f(0.6f, 0.68f);
    glEnd();
    // line 3
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(0.0f, 0.68f);
        glVertex2f(0.0f, 0.8f);
        glVertex2f(-0.02f, 0.8f);
        glVertex2f(-0.02f, 0.68f);
    glEnd();
}

void boat32()
{
    // main boat
    glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(0.64f, -0.5f);
        glVertex2f(0.9f, -0.5f);
        glVertex2f(0.96f, -0.4f);
        glVertex2f(0.86f, -0.44f);
        glVertex2f(0.66f, -0.44f);
        glVertex2f(0.54f, -0.4f);
    glEnd();
    // middle khamba
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(0.74f, -0.44f);
        glVertex2f(0.76f, -0.44f);
        glVertex2f(0.76f, -0.12f);
        glVertex2f(0.74f, -0.12f);
    glEnd();
    // right pal
    glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.33f, 0.0f);
        glVertex2f(0.78f, -0.44f);
        glVertex2f(0.84f, -0.44f);
        glVertex2f(0.76f, -0.2f);
    glEnd();
    // left pal
    glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.33f, 0.0f);
        glVertex2f(0.68f, -0.44f);
        glVertex2f(0.73f, -0.44f);
        glVertex2f(0.74f, -0.2f);
    glEnd();
    // small flag
    glBegin(GL_TRIANGLES);
        glColor3f(0.1f, 0.5f, 0.0f);
        glVertex2f(0.74f, -0.16f);
        glVertex2f(0.74f, -0.14f);
        glVertex2f(0.66f, -0.145f);
    glEnd();
}

void bird3()
{
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.39f, 0.28f);
        glVertex2f( -0.38f, 0.27f);

        glVertex2f(-0.38f, 0.27f);
        glVertex2f( -0.36f, 0.29f);
        glEnd();
}

void skyNight()
{
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.2f);
        glVertex2f(-0.58f, 0.38f);
        glVertex2f(0.58f, 0.38f);
        glVertex2f(0.58f, 0.17f);
        glVertex2f(-0.58f, 0.17f);
    glEnd();
}

void moon()
{
    glColor3f(0.8f, 0.8f, 0.9f);
    drawCircle(0.35f, 0.28f, 0.06f);
}
void outsideNight()
{
    glBegin((GL_QUADS));
        glColor3f(0.2f, 0.2f, 0.3f);
        glVertex2f(-0.58f, 0.38f);
        glVertex2f(-0.58f, -0.19f);
        glVertex2f(0.58f, -0.19f);
        glVertex2f(0.58f, 0.38f);
    glEnd();
    // Water
    glBegin((GL_QUADS));
        glColor3f(0.1f, 0.3f, 0.5f);
        glVertex2f(-0.58f, 0.17f);
        glVertex2f(0.58f, 0.17f);
        glVertex2f(0.58f, 0.02f);
        glVertex2f(-0.58f, 0.02f);
    glEnd();
    // Ground
    glBegin((GL_QUADS));
        glColor3f(0.3f, 0.5f, 0.3f);
        glVertex2f(-0.58f, 0.02f);
        glVertex2f(0.58f, 0.02f);
        glVertex2f(0.58f, -0.19f);
        glVertex2f(-0.58f, -0.19f);
    glEnd();
}

void lampNight()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 1
        glVertex2f(-1.0f, 0.35f);
        glVertex2f(-1.0f, 0.24f);
        glVertex2f(-0.99f, 0.24f);
        glVertex2f(-0.99f, 0.35f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 2
        glVertex2f(-1.0f, 0.33f);
        glVertex2f(-1.0f, 0.25f);
        glVertex2f(-0.98f, 0.25f);
        glVertex2f(-0.98f, 0.33f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 3
        glVertex2f(-1.0f, 0.295f);
        glVertex2f(-1.0f, 0.28f);
        glVertex2f(-0.84f, 0.28f);
        glVertex2f(-0.84f, 0.295f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 4
        glVertex2f(-0.87f, 0.35f);
        glVertex2f(-0.87f, 0.24f);
        glVertex2f(-0.84f, 0.24f);
        glVertex2f(-0.84f, 0.35f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 5
        glVertex2f(-0.85f, 0.4f);
        glVertex2f(-0.85f, 0.35f);
        glVertex2f(-0.858f, 0.35f);
        glVertex2f(-0.858f, 0.4f);
    glEnd();
    // lamp er niche golla
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(-0.854f, 0.228f, 0.013f);
    // circle er niche quad
    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f); // black 6
        glVertex2f(-0.85f, 0.228f);
        glVertex2f(-0.85f, 0.19f);
        glVertex2f(-0.86f, 0.19f);
        glVertex2f(-0.86f, 0.228f);
    glEnd();
    // lamp er niche golla 2
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(-0.853f, 0.19f, 0.013f);
    // main lamp (left)
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.5f); // Glowing yellow
        glVertex2f(-0.89f, 0.53f);
        glVertex2f(-0.93f, 0.4f);
        glVertex2f(-0.78f, 0.4f);
        glVertex2f(-0.82f, 0.53f);
    glEnd();
    // ray
    glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 1.0f, 0.5f, 0.3f);
        glVertex2f(-0.854f, 0.53f);
        glVertex2f(-0.904f, 0.05f);
        glVertex2f(-0.804f, 0.05f);
    glEnd();
    // Right lamp
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 1
        glVertex2f(1.0f, 0.35f);
        glVertex2f(1.0f, 0.24f);
        glVertex2f(0.99f, 0.24f);
        glVertex2f(0.99f, 0.35f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 2
        glVertex2f(1.0f, 0.33f);
        glVertex2f(1.0f, 0.25f);
        glVertex2f(0.98f, 0.25f);
        glVertex2f(0.98f, 0.33f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 3
        glVertex2f(1.0f, 0.295f);
        glVertex2f(1.0f, 0.28f);
        glVertex2f(0.84f, 0.28f);
        glVertex2f(0.84f, 0.295f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 4
        glVertex2f(0.87f, 0.35f);
        glVertex2f(0.87f, 0.24f);
        glVertex2f(0.84f, 0.24f);
        glVertex2f(0.84f, 0.35f);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black 5
        glVertex2f(0.85f, 0.4f);
        glVertex2f(0.85f, 0.35f);
        glVertex2f(0.858f, 0.35f);
        glVertex2f(0.858f, 0.4f);
    glEnd();
    // lamp er niche golla 1
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(0.853f, 0.228f, 0.013f);
    // circle er niche quad
    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f); // black 6
        glVertex2f(0.85f, 0.228f);
        glVertex2f(0.85f, 0.19f);
        glVertex2f(0.86f, 0.19f);
        glVertex2f(0.86f, 0.228f);
    glEnd();
    // lamp er niche golla 2
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(0.853f, 0.19f, 0.013f);
    // main lamp (right)
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.5f); // Glowing yellow
        glVertex2f(0.89f, 0.53f);
        glVertex2f(0.93f, 0.4f);
        glVertex2f(0.78f, 0.4f);
        glVertex2f(0.82f, 0.53f);
    glEnd();
    // rays
    glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 1.0f, 0.5f, 0.3f); // Semi-transparent yellow
        glVertex2f(0.854f, 0.53f);
        glVertex2f(0.904f, 0.05f);
        glVertex2f(0.804f, 0.05f);
    glEnd();


}

//night
void houseNight()
{
    //ek tala
    glColor3f(0.5f, 0.4f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-0.55f, -0.48f);
        glVertex2f(-0.15f, -0.48f);
        glVertex2f(-0.15f, -0.70f);
        glVertex2f(-0.55f, -0.70f);
    glEnd();
    //ek tala chal
    glColor3f(0.4f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.50f, -0.42f);
        glVertex2f(-0.18f, -0.42f);
        glVertex2f(-0.10f, -0.50f);
        glVertex2f(-0.60f, -0.50f);
    glEnd();
    //dui tala
    glColor3f(0.5f, 0.4f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-0.50f, -0.30f);
        glVertex2f(-0.35f, -0.30f);
        glVertex2f(-0.35f, -0.42f);
        glVertex2f(-0.50f, -0.42f);
    glEnd();
    // dui tala chal
    glColor3f(0.4f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.50f, -0.24f);
        glVertex2f(-0.35f, -0.24f);
        glVertex2f(-0.30f, -0.30f);
        glVertex2f(-0.55f, -0.30f);
    glEnd();
    //door
    glColor3f(0.3f, 0.15f, 0.05f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.38f, -0.55f);
        glVertex2f(-0.31f, -0.55f);
        glVertex2f(-0.31f, -0.70f);
        glVertex2f(-0.38f, -0.70f);
    glEnd();
    //ek tala windows
    glColor3f(0.8f, 0.8f, 0.5f);
    glBegin(GL_POLYGON); //left
        glVertex2f(-0.50f, -0.54f);
        glVertex2f(-0.44f, -0.54f);
        glVertex2f(-0.44f, -0.62f);
        glVertex2f(-0.50f, -0.62f);
    glEnd();
    glBegin(GL_POLYGON); //right
        glVertex2f(-0.26f, -0.54f);
        glVertex2f(-0.20f, -0.54f);
        glVertex2f(-0.20f, -0.62f);
        glVertex2f(-0.26f, -0.62f);
    glEnd();
    //dui tala window
    glBegin(GL_POLYGON); // left
        glVertex2f(-0.48f, -0.32f);
        glVertex2f(-0.44f, -0.32f);
        glVertex2f(-0.44f, -0.38f);
        glVertex2f(-0.48f, -0.38f);
    glEnd();
    glBegin(GL_POLYGON); // right
        glVertex2f(-0.42f, -0.32f);
        glVertex2f(-0.38f, -0.32f);
        glVertex2f(-0.38f, -0.38f);
        glVertex2f(-0.42f, -0.38f);
    glEnd();
    //rails
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.35f, -0.34f);
        glVertex2f(-0.2f, -0.34f);
    glEnd();
    // middle rails
    for (int i = 0; i < 6; i++)
    {
        glBegin(GL_LINES);
            glVertex2f(-0.35f, -0.42f);
            glVertex2f(-0.35f, -0.34f);
        glEnd();
        glTranslatef(0.03f, 0.0f, 0.0f);
    }
}

void house2Night()
{
    //black base
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.27f, -0.204f);
        glVertex2f(0.27f, -0.204f);
        glVertex2f(0.27f, -0.234f);
        glVertex2f(-0.27f, -0.234f);
    glEnd();
    //wall
    glColor3f(0.5f, 0.4f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-0.21f, -0.06f);
        glVertex2f(0.21f, -0.06f);
        glVertex2f(0.21f, -0.204f);
        glVertex2f(-0.21f, -0.204f);
    glEnd();
    // back house
    // back wall
    glColor3f(0.5f, 0.4f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-0.23f, 0.08f);
        glVertex2f(0.23f, 0.08f);
        glVertex2f(0.23f, -0.06f);
        glVertex2f(-0.23f, -0.06f);
    glEnd();
    //back roof
    glColor3f(0.4f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.17f, 0.18f);
        glVertex2f(0.17f, 0.18f);
        glVertex2f(0.29f, 0.08f);
        glVertex2f(-0.29f, 0.08f);
    glEnd();
    //roof design
    glColor3f(0.3f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.18f);
        glVertex2f(-0.1f, 0.08f);
        glVertex2f(0.1f, 0.08f);
    glEnd();
    //tally lines
    glLineWidth(2.0f);
    glColor3f(0.3f, 0.0f, 0.0f);
    // left line
    glBegin(GL_LINES);
        glVertex2f(-0.17f, 0.18f);
        glVertex2f(-0.29f, 0.08f);
    glEnd();
    // right line
    glBegin(GL_LINES);
        glVertex2f(0.17f, 0.18f);
        glVertex2f(0.29f, 0.08f);
    glEnd();
    // left lines
    glPushMatrix();
    for(int i = 1; i <= 11; i++)
    {
        glTranslatef(0.015f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.17f, 0.18f);
            glVertex2f(-0.29f, 0.08f);
        glEnd();
    }
    glPopMatrix();
    // right lines
    glPushMatrix();
    for(int i = 1; i <= 11; i++)
    {
        glTranslatef(-0.015f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.17f, 0.18f);
            glVertex2f(0.29f, 0.08f);
        glEnd();
    }
    glPopMatrix();
    // back roof edge
    glColor3f(0.3f, 0.025f, 0.025f);
    glBegin(GL_QUADS);
        glVertex2f(-0.29f, 0.08f);
        glVertex2f(0.29f, 0.08f);
        glVertex2f(0.29f, 0.07f);
        glVertex2f(-0.29f, 0.07f);
    glEnd();
    //roof 1
    glColor3f(0.4f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.185f, 0.03f);
        glVertex2f(0.185f, 0.03f);
        glVertex2f(0.285f, -0.06f);
        glVertex2f(-0.285f, -0.06f);
    glEnd();
    //tally lines
    glLineWidth(2.0f);
    glColor3f(0.3f, 0.0f, 0.0f);
    // center line
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.029f);
        glVertex2f(0.0f, -0.06f);
    glEnd();
    // left line
    glBegin(GL_LINES);
        glVertex2f(-0.185f, 0.029f);
        glVertex2f(-0.285f, -0.06f);
    glEnd();
    // right line
    glBegin(GL_LINES);
        glVertex2f(0.185f, 0.029f);
        glVertex2f(0.285f, -0.06f);
    glEnd();
    //left lines
    glPushMatrix();
    for(int i = 1; i <= 10; i++)
    {
        glTranslatef(0.018f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.185f, 0.029f);
            glVertex2f(-0.285f, -0.06f);
        glEnd();
    }
    glPopMatrix();
    // right lines
    glPushMatrix();
    for(int i = 1; i <= 10; i++)
    {
        glTranslatef(-0.018f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.185f, 0.03f);
            glVertex2f(0.285f, -0.06f);
        glEnd();
    }
    glPopMatrix();
    // roof edge
    glColor3f(0.3f, 0.025f, 0.025f);
    glBegin(GL_QUADS);
        glVertex2f(-0.285f, -0.06f);
        glVertex2f(0.285f, -0.06f);
        glVertex2f(0.285f, -0.069f);
        glVertex2f(-0.285f, -0.069f);
    glEnd();
    //roof design
    glColor3f(0.3f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.016f);
        glVertex2f(-0.09f, -0.06f);
        glVertex2f(0.09f, -0.06f);
    glEnd();
    glColor3f(0.3f, 0.025f, 0.025f);
    glBegin(GL_QUADS);
        glVertex2f(-0.138f, -0.06f);
        glVertex2f(0.138f, -0.06f);
        glVertex2f(0.138f, -0.069f);
        glVertex2f(-0.138f, -0.069f);
    glEnd();
    // white line
    glLineWidth(2);
    glColor3f(0.8f, 0.8f, 0.5f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 0.014f);
        glVertex2f(0.05f, -0.054f);
        glVertex2f(-0.05f, -0.054f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-0.015f, -0.054f);
        glVertex2f(0.0f, 0.014f);
        glVertex2f(0.015f, -0.054f);
        glVertex2f(0.0f, 0.014f);
    glEnd();
    //pillars
    glColor3f(0.5f, 0.5f, 0.4f);
    //pillar 1
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.07f);
        glVertex2f(-0.235f, -0.07f);
        glVertex2f(-0.235f, -0.204f);
        glVertex2f(-0.25f, -0.204f);
    glEnd();
    //pillar 2
    glBegin(GL_QUADS);
        glVertex2f(-0.048f, -0.06f);
        glVertex2f(-0.036f, -0.06f);
        glVertex2f(-0.036f, -0.204f);
        glVertex2f(-0.048f, -0.204f);
    glEnd();
    //pillar 3
    glBegin(GL_QUADS);
        glVertex2f(0.036f, -0.06f);
        glVertex2f(0.048f, -0.06f);
        glVertex2f(0.048f, -0.204f);
        glVertex2f(0.036f, -0.204f);
    glEnd();
    //pillar 4
    glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.07f);
        glVertex2f(0.235f, -0.07f);
        glVertex2f(0.235f, -0.204f);
        glVertex2f(0.25f, -0.204f);
    glEnd();
    //door
    glColor3f(0.16f, 0.1f, 0.06f);
    glBegin(GL_QUADS);
        glVertex2f(-0.03f, -0.105f);
        glVertex2f(0.03f, -0.105f);
        glVertex2f(0.03f, -0.204f);
        glVertex2f(-0.03f, -0.204f);
    glEnd();
    // window 1
    glColor3f(0.8f, 0.8f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.16f, -0.084f);
        glVertex2f(-0.10f, -0.084f);
        glVertex2f(-0.10f, -0.165f);
        glVertex2f(-0.16f, -0.165f);
    glEnd();
    //window 2
    glBegin(GL_QUADS);
        glVertex2f(0.16f, -0.084f);
        glVertex2f(0.1f, -0.084f);
        glVertex2f(0.1f, -0.165f);
        glVertex2f(0.16f, -0.165f);
    glEnd();
    //right railing
    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(0.205f, -0.15f);
        glVertex2f(0.205f, -0.204f);
    glEnd();
    glPushMatrix();
    for(int i = 1; i <= 5; i++)
    {
        glTranslatef(-0.029f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.205f, -0.15f);
        glVertex2f(0.205f, -0.204f);
        glEnd();
    }
    glPopMatrix();
    // right horizontal
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(0.206f, -0.15f);
        glVertex2f(0.058f, -0.15f);
    glEnd();
    //left railing
    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(-0.208f, -0.15f);
        glVertex2f(-0.208f, -0.204f);
    glEnd();
    glPushMatrix();
    for(int i = 1; i <= 5; i++)
    {
        glTranslatef(0.029f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.208f, -0.15f);
        glVertex2f(-0.208f, -0.204f);
        glEnd();
    }
    glPopMatrix();
    //left horizontal
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(-0.211f, -0.15f);
        glVertex2f(-0.061f, -0.15f);
    glEnd();
    //shiri
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-0.054f, -0.204f);
        glVertex2f(0.054f, -0.204f);
        glVertex2f(0.066f, -0.225f);
        glVertex2f(-0.066f, -0.225f);
    glEnd();
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
        glVertex2f(-0.066f, -0.225f);
        glVertex2f(0.066f, -0.225f);
        glVertex2f(0.084f, -0.24f);
        glVertex2f(-0.084f, -0.24f);
    glEnd();
}

void baseTreeNight()
{
    // leaves
    glColor3f(0.3f, 0.4f, 0.06f);
    drawCircle(-0.04f, -0.08f, 0.12f);
    drawCircle(-0.12f, -0.012f, 0.12f);
    glColor3f(0.4f, 0.5f, 0.04f);
    drawCircle(-0.16f, 0.06f, 0.12f);
    glColor3f(0.3f, 0.4f, 0.06f);
    drawCircle(-0.124f, 0.14f, 0.12f);
    drawCircle(-0.072f, 0.26f, 0.136f);
    glColor3f(0.4f, 0.5f, 0.04f);
    drawCircle(0.044f, 0.364f, 0.12f);
    glColor3f(0.3f, 0.4f, 0.06f);
    drawCircle(0.16f, 0.32f, 0.12f);
    drawCircle(0.12f, 0.12f, 0.16f);
    drawCircle(0.248f, 0.14f, 0.12f);
    drawCircle(0.284f, 0.044f, 0.12f);
    drawCircle(0.26f, -0.04f, 0.12f);
    drawCircle(0.20f, -0.06f, 0.12f);
    glColor3f(0.4f, 0.5f, 0.04f);
    drawCircle(0.128f, -0.152f, 0.096f);
    drawCircle(0.088f, -0.152f, 0.096f);
    glColor3f(0.2f, 0.3f, 0.1f);
    drawCircle(0.16f, 0.18f, 0.152f);
    glColor3f(0.4f, 0.5f, 0.04f);
    drawCircle(0.112f, 0.22f, 0.152f);
    drawCircle(0.06f, 0.20f, 0.08f);
    glColor3f(0.3f, 0.4f, 0.1f);
    drawCircle(0.04f, 0.212f, 0.112f);
    drawCircle(0.036f, 0.196f, 0.072f);
    // main tree
    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.15f, 0.04f);
        glVertex2f(0.06f, 0.08f);
        glVertex2f(0.10f, 0.08f);
        glVertex2f(0.12f, -0.48f);
        glVertex2f(0.04f, -0.48f);
    glEnd();
    // branch 1
    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.15f, 0.04f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(0.232f, 0.04f);
        glVertex2f(0.232f, 0.04f);
    glEnd();
    // branch 2
    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.15f, 0.04f);
        glVertex2f(0.10f, 0.0f);
        glVertex2f(0.10f, -0.032f);
        glVertex2f(0.14f, 0.04f);
        glVertex2f(0.16f, 0.04f);
    glEnd();
    // branch 3
    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.15f, 0.04f);
        glVertex2f(0.056f, 0.0f);
        glVertex2f(0.06f, -0.04f);
        glVertex2f(0.02f, 0.02f);
        glVertex2f(0.008f, -0.004f);
    glEnd();
    // branch 4
    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.15f, 0.04f);
        glVertex2f(0.10f, -0.08f);
        glVertex2f(0.10f, -0.12f);
        glVertex2f(-0.008f, -0.008f);
        glVertex2f(-0.012f, -0.032f);
    glEnd();
}

void khambaNight()
{
    // uporer lomba kalo line
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-1.0f, 0.65f);
        glVertex2f(1.0f, 0.65f);
        glVertex2f(1.0f, 0.68f);
        glVertex2f(-1.0f, 0.68f);
    glEnd();
    // khamba 1
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, 0.55f);
        glVertex2f(-0.82f, 0.55f);
        glVertex2f(-0.86f, 0.65f);
        glVertex2f(-0.75f, 0.65f);
    glEnd();
    // khamba 2
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.8f, 0.55f);
        glVertex2f(0.82f, 0.55f);
        glVertex2f(0.86f, 0.65f);
        glVertex2f(0.75f, 0.65f);
    glEnd();
    // khambar uporer line 1
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.58f, 0.68f);
        glVertex2f(-0.58f, 0.8f);
        glVertex2f(-0.6f, 0.8f);
        glVertex2f(-0.6f, 0.68f);
    glEnd();
    // line 2
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(0.58f, 0.68f);
        glVertex2f(0.58f, 0.8f);
        glVertex2f(0.6f, 0.8f);
        glVertex2f(0.6f, 0.68f);
    glEnd();
    // line 3
    glBegin((GL_QUADS));
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(0.0f, 0.68f);
        glVertex2f(0.0f, 0.8f);
        glVertex2f(-0.02f, 0.8f);
        glVertex2f(-0.02f, 0.68f);
    glEnd();
}

void boat2Night()
{
    // main boat
    glBegin(GL_POLYGON);
        glColor3f(0.05f, 0.05f, 0.05f);
        glVertex2f(0.64f, -0.5f);
        glVertex2f(0.9f, -0.5f);
        glVertex2f(0.96f, -0.4f);
        glVertex2f(0.86f, -0.44f);
        glVertex2f(0.66f, -0.44f);
        glVertex2f(0.54f, -0.4f);
    glEnd();
    // middle khamba
    glColor3f(0.05f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(0.74f, -0.44f);
        glVertex2f(0.76f, -0.44f);
        glVertex2f(0.76f, -0.12f);
        glVertex2f(0.74f, -0.12f);
    glEnd();
    // right pal
    glBegin(GL_TRIANGLES);
        glColor3f(0.4f, 0.15f, 0.0f);
        glVertex2f(0.78f, -0.44f);
        glVertex2f(0.84f, -0.44f);
        glVertex2f(0.76f, -0.2f);
    glEnd();
    // left pal
    glBegin(GL_TRIANGLES);
        glColor3f(0.4f, 0.15f, 0.0f);
        glVertex2f(0.68f, -0.44f);
        glVertex2f(0.73f, -0.44f);
        glVertex2f(0.74f, -0.2f);
    glEnd();
    // small flag
    glBegin(GL_TRIANGLES);
        glColor3f(0.05f, 0.25f, 0.0f);
        glVertex2f(0.74f, -0.16f);
        glVertex2f(0.74f, -0.14f);
        glVertex2f(0.66f, -0.145f);
    glEnd();
}

void stars()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
        glVertex2f(-0.56f, 0.18f);
        glVertex2f(-0.48f, 0.20f);
        glVertex2f(-0.40f, 0.23f);
        glVertex2f(-0.32f, 0.19f);
        glVertex2f(-0.24f, 0.22f);
        glVertex2f(-0.16f, 0.17f);
        glVertex2f(-0.08f, 0.21f);
        glVertex2f(0.00f, 0.24f);
        glVertex2f(0.08f, 0.18f);
        glVertex2f(0.16f, 0.20f);
        glVertex2f(0.24f, 0.23f);
        glVertex2f(0.32f, 0.19f);
        glVertex2f(0.40f, 0.22f);
        glVertex2f(0.48f, 0.17f);
        glVertex2f(0.56f, 0.21f);
        glVertex2f(-0.56f, 0.36f);
        glVertex2f(-0.50f, 0.31f);
        glVertex2f(-0.44f, 0.37f);
        glVertex2f(-0.38f, 0.29f);
        glVertex2f(-0.32f, 0.34f);
        glVertex2f(-0.26f, 0.30f);
        glVertex2f(-0.20f, 0.36f);
        glVertex2f(-0.14f, 0.32f);
        glVertex2f(-0.08f, 0.38f);
        glVertex2f(-0.02f, 0.33f);
        glVertex2f(0.02f, 0.37f);
        glVertex2f(0.08f, 0.31f);
        glVertex2f(0.14f, 0.35f);
        glVertex2f(0.20f, 0.29f);
        glVertex2f(0.26f, 0.36f);
        glVertex2f(0.32f, 0.32f);
        glVertex2f(0.38f, 0.38f);
        glVertex2f(0.44f, 0.30f);
        glVertex2f(0.50f, 0.34f);
        glVertex2f(0.56f, 0.37f);
    glEnd();
}


// SCENARIO 1 DISPLAY FUNCTION
void displayScenario1()
{
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Reset transformation matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw background first
    buildingBack();
    road();

    // Draw road lines
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // White lines
    for(float i = -0.9f; i < 0.9f; i += 0.2f) {
        glVertex2f(i, 0.0f);
        glVertex2f(i + 0.1f, 0.0f);
    }
    glEnd();


    glLoadIdentity();
    line();
    line1();
    glLoadIdentity();
    glTranslatef(-0.45f, 0.65f, 0.0f);
    glScalef(0.3f, 0.3f, 1.0f);
    baseTree1();

    glLoadIdentity();
    glTranslatef(-0.6f, 0.65f, 0.0f);
    glScalef(0.2f, 0.2f, 1.0f);
    baseTree1();

    glLoadIdentity();
    glTranslatef(-0.8f, 0.65f, 0.0f);
    glScalef(0.3f, 0.3f, 1.0f);
    baseTree1();

    glLoadIdentity();
    glTranslatef(-0.98f, 0.61f, 0.0f);
    glScalef(0.3f, 0.3f, 1.0f);
    baseTree1();

    glLoadIdentity();
    buildings();
    river1();
    railLine1();
    park();
    human();
    if (barVisible)
    {
        bar();
    }


    glPushMatrix();
    glTranslatef(ship_x, 0.0f, 0.0f);
    ship();
    glPopMatrix();

    soil();
        train1();

        glPushMatrix();
        glTranslatef(bus_x, 0.0f, 0.0f);
        bus();
        glPopMatrix();
        glPushMatrix();
    glTranslatef(truck_x, 0.0f, 0.0f);
    truck();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(car1_x, 0.0f, 0.0f);
    car1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(bus1_x, 0.0f, 0.0f);
    bus1();

    glLoadIdentity();
    glTranslatef(bus1_x, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(0.72f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_10, "SCHOOL BUS");

    glPopMatrix();

    // Shop
    glLoadIdentity();
    glTranslatef(0.66f, 0.48f, 0.0f);
    glScalef(0.47f, 0.47f, 1.0f);
    baseTree1();

    glLoadIdentity();
    shop();

    glLoadIdentity();
    glTranslatef(0.97f, 0.46f, 0.0f);
    glScalef(0.4f, 0.4f, 1.0f);
    baseTree1();



    human();


    glLoadIdentity();

    glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(0.55f, 0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "SHOP");
    glColor3f(1.0f, 0.0f, 0.0f);
    renderBitmapString(0.76f, 0.518f, 0.0f, GLUT_BITMAP_HELVETICA_18, "+");
    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(0.78f, 0.518f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "PHARMA");


    glutSwapBuffers();
    glFlush();
}

// SCENARIO 2 DISPLAY FUNCTION
void displayScenario2()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (isRaining) {
        skyRain();
        cloudsRain();

        treeRain();
        waterRain();
        groundRain();
        rain();

        glLoadIdentity();
        glTranslatef(boat1_x, -0.075f, 0.0f);
        glScalef(0.6f, 0.6f, 1.0f);
        boatRain();

        glLoadIdentity();
        boat2Rain();
        railLine2Rain();

        glLoadIdentity();
        glTranslatef(train2_y, -0.075f, 0.0f);
        glScalef(1.4f, 1.4f, 1.0f);
        trainRain();

        glLoadIdentity();
        dressBar();

        glLoadIdentity();
        glTranslatef(-1.0f, -0.2f, 0.0f);
        glScalef(0.8f, 0.8f, 1.0f);
        baseTree2Rain();

        glLoadIdentity();
        glTranslatef(-0.45f, -0.05f, 0.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        baseTree2Rain();

        glLoadIdentity();
        glTranslatef(-0.1f, -0.15f, 0.0f);
        glScalef(0.70f, 0.8f, 1.0f);
        houseRain();

        glLoadIdentity();
        glTranslatef(-0.6f, -0.3f, 0.0f);
        houseRain();

    } else
    {
        sky2();


        glLoadIdentity();
        glColor3f(1.0f, 1.0f, 0.0f);
        drawCircle(0.7f, 0.4f, 0.11f);


        glLoadIdentity();
        clouds2_simple();

        glLoadIdentity();
        tree2();
        water2();
        ground2();
        humanbody();

        glLoadIdentity();
        glTranslatef(boat1_x, -0.075f, 0.0f);
        glScalef(0.6f, 0.6f, 1.0f);
        boat1();

        glLoadIdentity();
        boat2();
        railLine2();

        glLoadIdentity();
        glTranslatef(train2_y, -0.075f, 0.0f);
        glScalef(1.4f, 1.4f, 1.0f);
        train2();

        glLoadIdentity();
        dress();
        glLoadIdentity();
        bird2();

        glLoadIdentity();
        glTranslatef(-1.0f, -0.2f, 0.0f);
        glScalef(0.8f, 0.8f, 1.0f);
        baseTree2();

        glLoadIdentity();
        glTranslatef(-0.45f, -0.05f, 0.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        baseTree2();

        glLoadIdentity();
        glTranslatef(-0.1f, -0.15f, 0.0f);
        glScalef(0.70f, 0.8f, 1.0f);
        house2();

        glLoadIdentity();
        glTranslatef(-0.6f, -0.3f, 0.0f);
        house2();


    }

    glutSwapBuffers();
    glFlush();
}

// SCENARIO 3 DISPLAY FUNCTION
void displayScenario3()
{
    if (isNightMode) {
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
    } else {
        glClearColor(1.0f, 0.89f, 0.88f, 1.0f);
    }
    glClear(GL_COLOR_BUFFER_BIT);

    chairs();
    table();
    chain();
    window();
    khamba();

    if (isNightMode)
        {
        lampNight();
        outsideNight();
        skyNight();
        stars();
        moon();



        glPushMatrix();
        glTranslatef(-0.16f, 0.03f, 0.0f);
        glScalef(0.418f, 0.418f, 1.0f);
        tree3();
        glPopMatrix();

        if (boat3_visible)
        {
        glPushMatrix();
        glTranslatef(boat3_x, 0.2f, 0.0f);
        glScalef(0.25f, 0.25f, 1.0f);
        boat2Night();
        glPopMatrix();
        }


        glLoadIdentity();
        glTranslatef(0.1f, 0.0f, 0.0f);
        glScalef(0.2f, 0.2f, 1.0f);
        baseTreeNight();

        glLoadIdentity();
        glTranslatef(0.35f, 0.05f, 0.0f);
        glScalef(0.25f, 0.25f, 1.0f);
        baseTreeNight();

        glLoadIdentity();
        // Houses
        glPushMatrix();
        glTranslatef(0.6f, 0.15f, 0.0f);
        glScalef(0.418f, 0.418f, 1.0f);
        houseNight();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.25f, -0.04f, 0.0f);
        glScalef(0.39f, 0.39f, 1.0f);
        house2Night();
        glPopMatrix();

        //birds
        if (birds_visible) {
        glPushMatrix();
        glTranslatef(bird1_x, 0.05f, 0.0f);
        glScalef(0.8f, 0.8f, 1.0f);
        bird3();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(bird2_x, 0.035f, 0.0f);
        glScalef(0.8f, 0.8f, 1.0f);
        bird3();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(bird3_x, 0.28f, 0.0f);
        bird3();
        glPopMatrix();
        }

    }
     else
    {
        lamp();
        outside();
        sky3();
        clouds3();
        sun();

         glPushMatrix();
        glTranslatef(-0.16f, 0.03f, 0.0f);
        glScalef(0.418f, 0.418f, 1.0f);
        tree3();
        glPopMatrix();


        if (boat3_visible)
        {
        glPushMatrix();
        glTranslatef(boat3_x, 0.2f, 0.0f);
        glScalef(0.25f, 0.25f, 1.0f);
        boat32();
        glPopMatrix();
        }


        glLoadIdentity();
        glTranslatef(0.1f, 0.0f, 0.0f);
        glScalef(0.2f, 0.2f, 1.0f);
        baseTree3();

        glLoadIdentity();
        glTranslatef(0.35f, 0.05f, 0.0f);
        glScalef(0.25f, 0.25f, 1.0f);
        baseTree3();

        glLoadIdentity();
        // Houses
        glPushMatrix();
        glTranslatef(0.6f, 0.15f, 0.0f);
        glScalef(0.418f, 0.418f, 1.0f);
        house3();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.25f, -0.04f, 0.0f);
        glScalef(0.39f, 0.39f, 1.0f);
        house32();
        glPopMatrix();

        //birds
        if (birds_visible) {
        glPushMatrix();
        glTranslatef(bird1_x, 0.05f, 0.0f);
        glScalef(0.8f, 0.8f, 1.0f);
        bird3();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(bird2_x, 0.035f, 0.0f);
        glScalef(0.8f, 0.8f, 1.0f);
        bird3();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(bird3_x, 0.28f, 0.0f);
        bird3();
        glPopMatrix();
        }
    }

    glFlush();
}
// MAIN DISPLAY FUNCTION
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    switch(currentScenario) {
        case 1:
            displayScenario1();
            break;
        case 2:
            displayScenario2();
            break;
        case 3:
            displayScenario3();
            break;
    }
}

// KEYBOARD FUNCTION
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case '1':

            PlaySound(NULL, NULL, 0);
            currentScenario = 1;
            glutPostRedisplay();
            break;
        case '2':

            PlaySound(NULL, NULL, 0);
            currentScenario = 2;
            isRaining = false;
            glutPostRedisplay();
            break;
        case '3':

    PlaySound(NULL, NULL, 0);
    currentScenario = 3;

    play_sound("day.wav");
    glutPostRedisplay();
    break;

        // Scenario 1 controls
        case 'c':
        case 'C':
            if (currentScenario == 1)
            {
                play_sound("car.wav");
                cout << "Car sound playing" << endl;
            }
            break;
        case 't':
        case 'T':
            if (currentScenario == 1)
            {
                play_sound("train.wav");
                cout << "Train sound playing" << endl;
            }
            break;

case 'b':
case 'B':
    if (currentScenario == 1)
    {
        barVisible = true; //bar
        trainMoving = true;

        busMoving = false;
        bus1Moving = false;
        truckMoving = false;
        car1Moving = false;
        bus_x = -0.1f;
        bus1_x = 0.2f;
        truck_x = -0.2f;
        car1_x = 0.9f;

        cout << "Railway crossing ACTIVE: Train moving, cars reset and waiting" << endl;
        glutPostRedisplay();
    }
    break;

case 'g':
case 'G':
    if (currentScenario == 1)
    {
        barVisible = false;
        trainMoving = false;

        train1_y = 1.4f; // Reset


        busMoving = true;
        bus1Moving = true;
        truckMoving = true;
        car1Moving = true;

        glutPostRedisplay();
    }
    break;


        // Scenario 2 controls
        case 'r':
        case 'R':
            if (currentScenario == 2)
            {
                isRaining = !isRaining;
                if (isRaining)
                {
                    play_sound("rain.wav");
                } else
                {
                    PlaySound(NULL, NULL, 0);
                }
                glutPostRedisplay();
            }
            break;
        case 's':
        case 'S':
            if (currentScenario == 2)
            {
                isRaining = false;
                PlaySound(NULL, NULL, 0);
                glutPostRedisplay();
            }
            break;

        // Scenario 3 controls
        case 'n':
case 'N':
    if (currentScenario == 3)
    {
        isNightMode = true;
        play_sound("night.wav");
        glutPostRedisplay();
    }
    break;

case 'd':
case 'D':
    if (currentScenario == 3)
    {
        isNightMode = !isNightMode;
        if (!isNightMode)
        {
            play_sound("day.wav");
        } else
        {
            PlaySound(NULL, NULL, 0);
        }
        glutPostRedisplay();
    }
    break;

        case 27:
            PlaySound(NULL, NULL, 0);
            exit(0);
            break;
    }
}

// INITIALIZATION
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -0.8, 0.8);
    glMatrixMode(GL_MODELVIEW);
}

// MAIN FUNCTION
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(80, 50);
    glutCreateWindow("OpenGL 3 Scenarios - Press 1, 2, or 3");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(0, update, 0);

    cout << "Controls:" << endl;
    cout << "Press 1 for Scenario 1" << endl;
    cout << "Press 2 for Scenario 2" << endl;
    cout << "Press 3 for Scenario 3" << endl;
    cout << "Press B to move train" <<endl;
    cout << "Press G to move vehicles" <<endl;
    cout << "Click left mouse to move the ship" <<endl;
    cout << "Press R for rain" <<endl;
    cout << "Press S for sunny day" <<endl;
    cout << "Press N for night" <<endl;
    cout << "Press D for day" <<endl;


    cout << "ESC to exit" << endl;


    glutMainLoop();
    PlaySound(NULL, NULL, 0);
    return 0;
}



