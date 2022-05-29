#include "asteroid.h"
#include <iostream>
#include <math.h>


Asteroid::Asteroid()
{
    int negative;
    position[0][0]= rand() % 100;
    negative = rand() % 1;
    if (negative == 1) position[0][0] *= -1;
    position[0][1]= rand() % 300;
    negative = rand() % 1;
    if (negative == 1) position[0][1] *= -1;
    position[0][2]= rand() % 800;
   // glTranslatef(position[0][0], position[0][1], position[0][2]); // On lui applique une translation
   // glColor3f(0.f,0.f,1.f); // On définit la couleur courante comme étant bleue
    //gluSphere(quadrique, 5.,20,20); // On dessine une sphère
    for (int i=1; i<20; i++)
    {
      //  std::cout<<"Im here"<<std::endl;
        int j=0;
        while (j<i)
        {
            float distance = 0;
            while (distance <20)
            {
                position[i][0]= rand() % 300;
                negative = rand() % 1;
                if (negative == 1) position[i][0] *= -1;
                position[i][1]= rand() % 100;
                negative = rand() % 1;
                if (negative == 1) position[i][1] *= -1;
                position[i][2]= rand() % 800 + 50;
                distance= sqrt((position[i][0]-position[j][0])*(position[i][0]-position[j][0])
                        +(position[i][1]-position[j][1])*(position[i][1]-position[j][1])
                        +(position[i][2]-position[j][2])*(position[i][2]-position[j][2]));
              //  std::cout<<"distance= "<<distance<<std::endl;
            }
            j++;

        }
      //  glTranslatef(position[i][0], position[i][1], position[i][2]); // On lui applique une translation
       // glColor3f(0.f,0.f,1.f); // On définit la couleur courante comme étant bleue
     //   gluSphere(quadrique, 5.,20,20); // On dessine une sphère

    }
}

Asteroid::~Asteroid()
{
}


void Asteroid::Display()
{

            glEnable(GL_TEXTURE_2D);
            QImage qim_Texture1 (":/asteroide.jpg");
            qim_Texture1 = qim_Texture1.convertToFormat(QImage::Format_RGBA8888);
            GLuint texture;
            glGenTextures(1, &texture); // Crée un objet texture et lui associe un numéro qu'on stocke
            glBindTexture(GL_TEXTURE_2D, texture); // Définit la texture courante
            //Transmet à OpenGL toutes les caractéristiques de la rexture courante : largeur, hauteur,
            // format, etc... et bien sûr l'image
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D, 0, 4, qim_Texture1.width(), qim_Texture1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, qim_Texture1.bits());
            GLUquadric* quadrique1 = gluNewQuadric();
            gluQuadricDrawStyle(quadrique1,GLU_FILL);
            gluQuadricTexture(quadrique1,GLU_TRUE);
            QImage qim_Texture2 (":/asteroid.jpg");
            qim_Texture2 = qim_Texture2.convertToFormat(QImage::Format_RGBA8888);
            GLuint texture1;
            glGenTextures(2, &texture1); // Crée un objet texture et lui associe un numéro qu'on stocke
            glBindTexture(GL_TEXTURE_2D, texture1); // Définit la texture courante
            //Transmet à OpenGL toutes les caractéristiques de la rexture courante : largeur, hauteur,
            // format, etc... et bien sûr l'image
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D, 0, 4, qim_Texture2.width(), qim_Texture2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, qim_Texture2.bits());
            GLUquadric* quadrique2 = gluNewQuadric();
            gluQuadricDrawStyle(quadrique2,GLU_FILL);
            gluQuadricTexture(quadrique2,GLU_TRUE);
            for (int i=0 ; i<=10; i++)
            {
                glPushMatrix();
                glTranslatef(position[i][0], position[i][1], position[i][2]); // On lui applique une translation
               // glColor3f(0.f,0.f,1.f); // On définit la couleur courante comme étant bleue
                if (rand() % 1 == 1) {
                    gluSphere(quadrique1, 50.,20,20); // On dessine une sphère
                }
                else {
                    gluSphere(quadrique2, 50.,20,20);
                }
                glPopMatrix();
            }

            gluDeleteQuadric(quadrique1);
            gluDeleteQuadric(quadrique2);

            glDisable(GL_TEXTURE_2D);
}
