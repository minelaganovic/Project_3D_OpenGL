#include <fstream>
#include <iostream>
#include<windows.h>
#include<GL/freeglut.h>
#include<GL/freeglut_ext.h>
#include<GL/freeglut_std.h>
#include<math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include<vector>
#include<string>

int i;

GLfloat moveX = 0.0f;
GLfloat moveY = 0.0f;
GLfloat moveZ = 0.0f;

GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;
GLfloat rotZ = 0.0f;

GLfloat camY = 0.0f;
GLfloat camX = 0.0f;
GLfloat camZ = 0.0f;

GLfloat vNormal[3]= {};
GLfloat x,y,z;
GLuint texture;
GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint text_2d;

void initLighting(){

    GLfloat L0_Ambient[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat L0_Diffuse[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat L0_postion[] = {0, 100, 0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, L0_Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, L0_Diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, L0_postion);
}

void drawGate() {

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(-45.0f ,2.0f, 23.0f);
        glRotatef(90,0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,38,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,38,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,38,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,38,20,20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(5.0f ,2.0f, 23.0f);
        glRotatef(90,0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,40,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,40,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,40,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,18,20,20);
    glPopMatrix();

    glPushMatrix();
         glColor3f(0.52f, 0.32f, 0.02f);
         glTranslatef(5.0f, 0.0f, 23.0f);
         glRotatef(90,-1.0f,0.0f,0.0f);
         glutSolidCylinder(0.4,7,50,50);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.52f, 0.32f, 0.02f);
        glTranslatef(-7.0f, 0.0f, 23.0f);
        glRotatef(90,-1.0f,0.0f,0.0f);
        glutSolidCylinder(0.4,7,50,50);
    glPopMatrix();
}
//
void drawBoundary(){
    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(-45.0f ,2.0f, 23.0f);
        glRotatef(-180,0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,68,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,68,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,68,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,68,20,20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(45.0f ,2.0f, 23.0f);
        glRotatef(180,0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,68,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,68,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,68,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,68,20,20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(-45.0f ,2.0f, -45.0f);
        glRotatef(90,0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,90,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,90,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,90,20,20);
        glTranslatef(0.0f ,1.0f, 0.0f);
        glutSolidCylinder(0.3,90,20,20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(-45.0f ,0.0f, -45.0f);
        glRotatef(90,-1.0f,0.0f,0.0f);
        glutSolidCylinder(0.3,7,20,20);
        for(int i=0; i<17; i++){
            glTranslatef(5.0f ,0.0f, 0.0f);
            glutSolidCylinder(0.3,7,20,20);
        }
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        // Draw vertical parts of gate (right)
        glTranslatef(45.0f ,0.0f, -45.0f);
        glRotatef(90,-1.0f,0.0f,0.0f);
        glutSolidCylinder(0.3,7,20,20);
        for(int i=0; i<13; i++){
            glTranslatef(0.0f ,-5.0f, 0.0f);
            glutSolidCylinder(0.3,7,20,20);
        }
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(45.0f ,0.0f, 23.0f);
        glRotatef(90,-1.0f,0.0f,0.0f);
        glutSolidCylinder(0.3,7,20,20);
        glTranslatef(-7.0f ,0.0f, 0.0f);
        glutSolidCylinder(0.3,7,20,20);
        glTranslatef(-7.0f ,0.0f, 0.0f);
        glutSolidCylinder(0.3,7,20,20);
        glTranslatef(-7.0f ,0.0f, 0.0f);
        glutSolidCylinder(0.3,7,20,20);
        glTranslatef(-7.0f ,0.0f, 0.0f);
        glutSolidCylinder(0.3,7,20,20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(-38.0f ,0.0f, 23.0f);
        glRotatef(90,-1.0f,0.0f,0.0f);
        glutSolidCylinder(0.3,7,20,20);
        glTranslatef(7.0f ,0.0f, 0.0f);
        glutSolidCylinder(0.3,7,20,20);
        glTranslatef(7.0f ,0.0f, 0.0f);
        glutSolidCylinder(0.3,7,20,20);
        glTranslatef(7.0f ,0.0f, 0.0f);
        glutSolidCylinder(0.3,7,20,20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.39f, 0.24f, 0.02f);
        glTranslatef(-45.0f ,0.0f, 23.0f);
        glRotatef(90,-1.0f,0.0f,0.0f);
        glutSolidCylinder(0.3,7,20,20);
        for(int i=0; i<13; i++){
            glTranslatef(0.0f ,5.0f, 0.0f);
        glutSolidCylinder(0.3,7,20,20);
        }
    glPopMatrix();

}
void drawRoad(){

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.12f, 0.11f);
    glVertex3f(-4.0f, 0.1f, -10.0f);
    glVertex3f(2.0f, 0.1f, -10.0f);
    glVertex3f(2.0f, 0.1f, 25.0f);
    glVertex3f(-4.0f, 0.1f, 25.0f);
    glEnd();
    glPopMatrix();

}
void drawFloor(){
    glBegin(GL_QUADS);
    glColor4f(0, 1, 0, 1);
    glNormal3d(0, 0, 1);
    glTexCoord2f(0,1);
    glVertex3f(50,0, 50);
    glTexCoord2f(1,1 );
    glVertex3f(-50,0, 50);
    glTexCoord2f(1,0 );
    glVertex3f(-50,0, -50);
    glTexCoord2f(0,0);
    glVertex3f(50,0, -50);
    glEnd();
}
void drawChair(){

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(0,3,0.0);
    glVertex3f(0,3,1.0);
    glVertex3f(1.5,3,1.0);
    glVertex3f(1.5,3,0);

    glColor3f(1,0,0);
    glVertex3f(0,3,0.0);
    glVertex3f(-0.5,6,0.0);
    glVertex3f(-0.5,6,1.0);
    glVertex3f(0,3,1.0);
    //legs
    glColor3f(0,0,0);
    glVertex3f(0,3,1.0);
    glVertex3f(0,0.2,1.0);
    glVertex3f(0.1,0.2,1.0);
    glVertex3f(0.1,3,1.0);

    glVertex3f(0.9,3,1.0);
    glVertex3f(0.9,0.2,1.0);
    glVertex3f(1,0.2,1.0);
    glVertex3f(1,3,1.0);

    glVertex3f(0.9,3,0.0);
    glVertex3f(0.9,0.2,0.0);
    glVertex3f(1,0.2,0.0);
    glVertex3f(1,3,0.0);

    glVertex3f(0,3,0.0);
    glVertex3f(0,0.2,0.0);
    glVertex3f(0.1,0.2,0.0);
    glVertex3f(0.1,3,0.0);
    glEnd();

    glPopMatrix();
}
void drawCanteen(){
    glPushMatrix();
    glTranslatef(-15,0,-20 );
    glBegin(GL_QUADS);
    //back
    glColor3f(0.24f, 0.14f, 0.05f);
    glVertex3f(0.0f, 19.8f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(30.0f, 0.0f, 0.0f);
    glVertex3f(30.0f, 19.8f, 0.0f);

    // front
    glColor3f(0.8f, 0.65f, 0.44f);
    glVertex3f(0.0f, 13.0f, 10.0f);
    glVertex3f(0.0f, 8.0f, 10.0f);
    glVertex3f(30.0f, 8.0f, 10.0f);
    glVertex3f(30.0f, 13.0f, 10.0f);
    glVertex3f(0.0f, 8.0f, 10.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, 10.0f);
    glVertex3f(10.0f,8.0f, 10.0f);
    glVertex3f(17.0f, 8.0f, 10.0f);
    glVertex3f(17.0f, 0.0f, 10.0f);
    glVertex3f(30.0f, 0.0f, 10.0f);
    glVertex3f(30.0f,8.0f, 10.0f);

    //left
    glVertex3f(0.0f, 20.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    glVertex3f(0.0f,13.0f, 10.0f);

    //right
    glVertex3f(30.0f, 20.0f, 0.0f);
    glVertex3f(30.0f, 13.0f, 10.0f);
    glVertex3f(30.0f, 0.0f, 10.0f);
    glVertex3f(30.0f,0.0f, 0.0f);
    //floor
    glColor3f(0.51f, 0.46f, 0.38f);
    glVertex3f(0.0f, 0.01f, 0.0f);
    glVertex3f(0.0f, 0.01f, 10.0f);
    glVertex3f(30.0f, 0.01f, 10.0f);
    glVertex3f(30.0f,0.01f, 0.0f);
    //table left
    glColor3f(0.51f, 0.15f, 0.57f);
    glVertex3f(6.0f, 5.9f, 0.01f);
    glVertex3f(6.0f, 5.9f, 3.0f);
    glVertex3f(6.0f, 0.4f,3.0f);
    glVertex3f(6.0f,0.40f, 0.01f);

    glColor3f(0.51f, 0.15f, 0.57f);
    glVertex3f(20.0f, 5.9f, 0.01f);
    glVertex3f(20.0f, 5.9f, 3.0f);
    glVertex3f(20.0f, 0.4f,3.0f);
    glVertex3f(20.0f,0.40f, 0.01f);

    glColor3f(0.48f, 0.17f, 0.54f);
    glVertex3f(6.0f, 5.9f, 3.0f);
    glVertex3f(6.0f, 0.4f,3.0f);
    glVertex3f(20.0f, 0.4f,3.0f);
    glVertex3f(20.0f, 5.9f, 3.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(23.0f, 10.7f, 10.03f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14.8f, 8.8f, 10.03f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17,6.8,1.7);
    glColor3f(0.33f, 0.15f, 0.11f);
    glutSolidTeapot(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.0,4.25,6.0);
    glColor3f(0.6f, 0.76f, 0.7f);
    glRotatef(90,1.0,0.0,0.0);
    glutSolidCylinder(0.97,0.2,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.0,4.41,5.5);
    glColor3f(0.43f, 0.09f, 0.14f);
    glutSolidTeapot(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.5,4.41,6.3);
    glColor3f(0.43f, 0.09f, 0.14f);
    glutSolidTeacup(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.4,4.41,6.3);
    glColor3f(0.43f, 0.09f, 0.14f);
    glutSolidTeacup(0.5);
    glPopMatrix();

    glPopMatrix();

}
void drawTable(){
    glPushMatrix();
    glColor3f(0.54f, 0.35f, 0.05f);
    glBegin(GL_POLYGON);
    glVertex3f(4.0f, 4.00f, 6.0f);
    glVertex3f(6.0f, 4.0f, 8.0f);
    glVertex3f(8.0f, 4.0f, 8.0f);
    glVertex3f(10.0f,4.00f, 6.0f);
    glVertex3f(8.0f, 4.00f, 4.0f);
    glVertex3f(6.0f,4.00f, 4.0f);
    glEnd();
    glPopMatrix();
    //legs
    glColor3f(0.6f, 0.28f, 0.11f);
    glPushMatrix();
    glTranslatef(6,0.2,5);
    glRotatef(-90,1,0,0);
    glutSolidCylinder(0.1,3.79,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8,0.2,5);
    glRotatef(-90,1,0,0);
    glutSolidCylinder(0.1,3.79,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6,0.2,7);
    glRotatef(-90,1,0,0);
    glutSolidCylinder(0.1,3.79,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8,0.2,7);
    glRotatef(-90,1,0,0);
    glutSolidCylinder(0.1,3.79,50,50);
    glPopMatrix();
}
void drawBarTableTop(){

    glPushMatrix();
    glTranslatef(-15,0,-20 );
    glBegin(GL_QUADS);
    glTexCoord2f(0,1);
    glVertex3f(6.0f, 6.0f, 1.0f);
    glTexCoord2f(1,1);
    glVertex3f(6.0f, 6.0f, 3.0f);
    glTexCoord2f(1,0);
    glVertex3f(20.0f, 6.0f,3.0f);
    glTexCoord2f(0,0);
    glVertex3f(20.0f,6.00f, 1.01f);
    glEnd();
    glPopMatrix();
}
void drawRoof(){
   
    glPushMatrix();
    glTranslatef(-15,0,-20 );
    glColor3f(1,0,0);
    glBegin(GL_QUADS);

    glTexCoord2f(0,1);
    glVertex3f(-1.0f, 21.1f, -1.0f);
    glTexCoord2f(1,1);
    glVertex3f(-1.0f, 12.6f, 11.0f);
    glTexCoord2f(1,0);
    glVertex3f(31.0f, 12.6f, 11.0f);
    glTexCoord2f(0,0);
    glVertex3f(31.0f,21.1f, -1.0f);
    glEnd();
    glPopMatrix();
}
void init(){

    glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
    GLfloat globalAmbient[] = {0.8, 0.8, 0.8, 1.0};
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    initLighting();
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
}
void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        gluLookAt(1.0 + camX, 7.0 + camY, 38.0 + camZ, 0, 0, 0, 0, 2.0, 0);
        glTranslatef(moveX, moveY, moveZ );
        glRotatef( rotX, 1.0f, 0.0f, 0.0f );
        glRotatef( rotY, 0.0f, 1.0f, 0.0f );
        glRotatef( rotZ, 0.0f, 0.0f, 1.0f );

        glPushMatrix();
        drawFloor();
        glPopMatrix();
        drawGate();
        drawRoad();

        drawBoundary();
        drawRoof();
        drawBarTableTop();
        drawCanteen();

        glPushMatrix();
        glTranslatef(-15,-0.1,-20 );
        drawTable();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-11,-0.1,-14 );
        drawChair();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-4,-0.1,-12 );
        glRotatef(170,0,1,0);
        drawChair();
        glPopMatrix();

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture2);
        glBegin(GL_POLYGON);
        //text1
        glColor3f(0.7,0.7,0.6);
          glTexCoord2f(0.0, 0.0); glVertex3f(-4.0f, 0.1f, -10.0f);
          glTexCoord2f(0.0, 2.0); glVertex3f(2.0f, 0.1f, -10.0f);
          glTexCoord2f(2.0, 2.0); glVertex3f(2.0f, 0.1f, 25.0f);
          glTexCoord2f(2.0, 0.0); glVertex3f(-4.0f, 0.1f, 25.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-16, 0, 0);
        glTranslatef(16,0,0);
        glColor3f(0.31f, 0.05f, 0.33f);
        glPushMatrix();
        glTranslatef(-16,3,0 );
        glPopMatrix();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-35,0.1,2);
        glRotatef(-35,0,1,0);
        glPopMatrix();

        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
void keyboardSpecial(int key, int x, int y){

    if(key == GLUT_KEY_UP)
        moveZ += 1;

    if(key == GLUT_KEY_DOWN)

        moveZ -= 1;

    if(key == GLUT_KEY_LEFT)

        rotY += 5.0;

    if(key == GLUT_KEY_RIGHT)

        rotY -= 5.0;
    glutPostRedisplay();

}
void keyboard(unsigned char key , int x , int y){

    if(key == 'k')

        glDisable(GL_LIGHT0);

    if(key == 'K')

        glEnable(GL_LIGHT0);

}
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}
void changeSize(GLsizei w, GLsizei h){
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w/1 : (GLfloat)w/(GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, aspect_ratio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_DEPTH | GLUT_RGBA);

    glutCreateWindow("Project 3D");
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(100, 100);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);

    //pozivanje texture
    texture=LoadTexture("./textures/texture.raw",256, 256);
    texture1=LoadTexture("./textures/texture1.raw",256, 256);
    texture2=LoadTexture("./textures/texture2.raw",256, 256);
    texture3=LoadTexture("./textures/texture3.raw",256, 256);
    glutMainLoop();
    return 0;
}
