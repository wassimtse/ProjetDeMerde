#include "Ship.h"
#include <iostream>
#include <math.h>



Ship::Ship()
{
}

Ship::~Ship()
{
}


void Ship::Display()
{

    if  (!this->Stop )
    {
        z = z + 5.f ;
    }


 //  std::cout<<"x: "<<x<<"y: " <<y<<"z:"<<z<<"    "<<Stop<<std::endl;


    GLfloat colorAmbiante0_tab[]= {0.5, 0.1, 0.1, 1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante0_tab);

        GLfloat colorDiffuse0_tab[] = {0.2, 0.5, 0.3, 1.0};
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse0_tab);
        // Ship

        glPushMatrix();
        glRotatef(angleX,1.,0.,0.);
        glRotatef(angleY,0.,1.,0.);

        /*    // First Cylinder
            glPushMatrix();
            glTranslatef(x+0., y+0., z-5);
            GLUquadric* cylinder1=gluNewQuadric();
            gluQuadricDrawStyle(cylinder1, GLU_FILL);
            gluCylinder(cylinder1, 6, 6, 20, 20, 30);
            gluDeleteQuadric(cylinder1);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(x+0., y+0., z-5);
            GLUquadric* disk1_1=gluNewQuadric();
            gluQuadricDrawStyle(disk1_1, GLU_FILL);
            gluDisk(disk1_1, 0, 6, 20, 20);
            gluDeleteQuadric(disk1_1);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(x+0., y+0., z+10);
            GLUquadric* disk1_2=gluNewQuadric();
            gluQuadricDrawStyle(disk1_2, GLU_FILL);
            gluDisk(disk1_2, 0, 6, 20, 20);
            gluDeleteQuadric(disk1_2);
            glPopMatrix();

            // Cubes
            glPushMatrix();
            glRotatef(45., 0., 0., 1.);
            glBegin(GL_QUADS);

            glVertex3f(x-1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-5.0f);
            glVertex3f(x-1.f,y-20.f,z-5.0f);

            glVertex3f(x-1.f,y-20.f,z-5.0f);
            glVertex3f(x+1.f,y-20.f,z-5.0f);
            glVertex3f(x+1.f,y+20.f,z-5.0f);
            glVertex3f(x-1.f,y+20.f,z-5.0f);

            glVertex3f(x-1.f,y+20.f,z-5.0f);
            glVertex3f(x-1.f,y+20.f,z-13.0f);
            glVertex3f(x-1.f,y-20.f,z-13.0f);
            glVertex3f(x-1.f,y-20.f,z-5.0f);

            glVertex3f(x+1.f,y+20.f,z-5.0f);
            glVertex3f(x+1.f,y+20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-5.0f);

            glVertex3f(x-1.f,y+20.f,z-13.0f);
            glVertex3f(x+1.f,y+20.f,z-13.0f);
            glVertex3f(x+1.f,y+20.f,z-5.0f);
            glVertex3f(x-1.f,y+20.f,z-5.0f);

            glVertex3f(x-1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y+20.f,z-13.0f);
            glVertex3f(x-1.f,y+20.f,z-13.0f);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glRotatef(-45., 0., 0., 1.);
            glBegin(GL_QUADS);

            glVertex3f(x-1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-5.0f);
            glVertex3f(x-1.f,y-20.f,z-5.0f);

            glVertex3f(x-1.f,y-20.f,z-5.0f);
            glVertex3f(x+1.f,y-20.f,z-5.0f);
            glVertex3f(x+1.f,y+20.f,z-5.0f);
            glVertex3f(x-1.f,y+20.f,z-5.0f);

            glVertex3f(x-1.f,y+20.f,z-5.0f);
            glVertex3f(x-1.f,y+20.f,z-13.0f);
            glVertex3f(x-1.f,y-20.f,z-13.0f);
            glVertex3f(x-1.f,y-20.f,z-5.0f);

            glVertex3f(x+1.f,y+20.f,z-5.0f);
            glVertex3f(x+1.f,y+20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-5.0f);

            glVertex3f(x-1.f,y+20.f,z-13.0f);
            glVertex3f(x+1.f,y+20.f,z-13.0f);
            glVertex3f(x+1.f,y+20.f,z-5.0f);
            glVertex3f(x-1.f,y+20.f,z-5.0f);

            glVertex3f(x-1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y-20.f,z-13.0f);
            glVertex3f(x+1.f,y+20.f,z-13.0f);
            glVertex3f(x-1.f,y+20.f,z-13.0f);

            glEnd();
            glPopMatrix();

            // Second Cylinder
            glPushMatrix();
            glTranslatef(x-0.,y- 0., z-15);
            GLUquadric* cylinder2=gluNewQuadric();
            gluQuadricDrawStyle(cylinder2, GLU_FILL);
            gluCylinder(cylinder2, 3, 3, 10, 20, 20);
            gluDeleteQuadric(cylinder2);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(x-0., y-0., z-5);
            GLUquadric* disk2_1=gluNewQuadric();
            gluQuadricDrawStyle(disk2_1, GLU_FILL);
            gluDisk(disk2_1, 0, 3, 20, 20);
            gluDeleteQuadric(disk2_1);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(x-0., y-0., z-15);
            GLUquadric* disk2_2=gluNewQuadric();
            gluQuadricDrawStyle(disk2_2, GLU_FILL);
            gluDisk(disk2_2, 0, 3, 20, 20);
            gluDeleteQuadric(disk2_2);
            glPopMatrix();
            glPopMatrix();
           */
            GLUquadric* ship_sphere = gluNewQuadric();
            gluQuadricDrawStyle(ship_sphere,GLU_FILL);
            gluQuadricTexture(ship_sphere,GLU_TRUE);
            //
            glTranslatef(x,y,z); // On lui applique une translation
            glColor3f(0.f,0.f,1.f); // On définit la couleur courante comme étant bleue
            glRotatef(110,0,1,0);
            //gluCylinder(ship_sphere,1,1,20,20,20);
            gluSphere(ship_sphere, 5,20,20); // On dessine une sphère
            gluDisk(ship_sphere, 6, 8, 20, 20);
            glRotatef(90,1,1,0);
            gluDisk(ship_sphere, 9, 11, 20, 20);
            glRotatef(90,1,1,0);
            gluDisk(ship_sphere, 12, 14, 20, 20);
            glRotatef(90,1,1,0);
            gluDisk(ship_sphere, 15, 17, 20, 20);
            glRotatef(90,1,1,0);
            gluDisk(ship_sphere, 18, 20, 20, 20);
            glColor3f(1.f,1.f,1.f);



           /* GLUquadric* quadrique = gluNewQuadric();
            gluQuadricDrawStyle(quadrique,GLU_FILL);
            gluQuadricTexture(quadrique,GLU_TRUE);
            //
          //  glPushMatrix(); // On stocke le repère d'origine
            glTranslatef(x+0.f,y+0.f,z+0.f); // On lui applique une translation
           // glColor3f(0.f,0.f,1.f); // On définit la couleur courante comme étant bleue
            gluSphere(quadrique, 5.,20,20); // On dessine une sphère
          //  glPopMatrix(); // On retourne au repère d'origine
            glTranslatef(x-5.f,y+0.f,z+0.f);
            glBegin(GL_QUADS);
            glVertex3f(x-5.f,y,z-5.f);
            glVertex3f(x-10.f,y,z-5.f);
            glVertex3f(x-10.f,y,z+10.0f);
            glVertex3f(x-5.f,y,z+10.f);



            gluDeleteQuadric(quadrique); */

}
