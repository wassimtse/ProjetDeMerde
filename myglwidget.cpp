#include "myglwidget.h"
#include <QApplication>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <gtx/normalize_dot.hpp>


#include <math.h>

// Declarations des constantes
const unsigned int WIN = 900;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 1.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
const float cameraSpeed = 5.f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN, WIN);

    // Connexion du timer
        connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
            m_TimeElapsed += 1.0f;
            update();
        });

        m_AnimationTimer.setInterval(20);
        m_AnimationTimer.start();

}


// Fonction d'initialisation

//Fonction d'initialisation
void MyGLWidget::initializeGL() {
    space_ = new Space();
    ship_ = new Ship();
    asteroid_ = new Asteroid();



    glEnable(GL_DEPTH_TEST);

}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        glFrustum(-2, 2, -2, 2, 2, 2000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // ...
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    glm::mat4 view;

   /* gluLookAt(0.0f, 0.0f, 3.0f,
              0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f);
    */
    gluLookAt(cameraPos[0], cameraPos[1], ship_->z-50.f,
            cameraPos[0]+cameraFront[0], cameraPos[1]+cameraFront[1], ship_->z+cameraFront[2],
            cameraUp[0], cameraUp[1], cameraUp[2]);
    ship_->x = cameraPos[0];
    ship_->y = cameraPos[1];
    //ship_->z = cameraPos[2];

/*
    gluLookAt(0. +ship_->x , 35.+ship_->y, 80. + ship_->z,
              ship_->x, ship_->y, ship_->z,
              0., 1., 0.);
*/
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(70.,1.,2,2000.);
    // Lumiere ambiante
    glLightfv(GL_LIGHT0,GL_AMBIENT,new GLfloat[4]{.8, .8, .8, 1});
    glLightfv(GL_LIGHT0,GL_DIFFUSE,new GLfloat[4]{.8, .8, .8, 1});
    glLightfv(GL_LIGHT0,GL_SPECULAR,new GLfloat[4]{.8, .8, .8, 1});
    glLightfv(GL_LIGHT0,GL_POSITION,new GLfloat[4]{0, 0, 1, 0});
     glDisable(GL_LIGHTING);
    glPushMatrix();
    space_->Display();

    asteroid_->Display();
    ship_->Display();

    glPopMatrix();



    // Affichage de la route
    // Affichage de la voiture
}


// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent* keyEvent)
{
    switch (keyEvent->key())
    {
        case Qt::Key_Right:
        /*if (ship_->x>=-1400)
        {
            ship_->x-=2;
             ship_->angleY+=0.3;
        }*/
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
            this->update();
        break;
        case Qt::Key_Left:
        /*if (ship_->x<=1400)
        {
            ship_->x+=2;
            ship_->angleY-=0.3;
        }*/
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
            this->update();
        break;
        case Qt::Key_Up:
        /*if (ship_->y<=1400)
        {
           ship_->y+=2;
            ship_->angleX-=0.3;
        }*/
        cameraPos += cameraSpeed * cameraFront;
            this->update();
        break;
        case Qt::Key_Down:
        /*if (ship_->y>=-1400)
        {
            ship_->y-=2;
             ship_->angleX+=0.3;
        }*/
        cameraPos -= cameraSpeed * cameraFront;
            this->update();
        break;
    case Qt::Key_Space:
        ship_->Stop = !(ship_->Stop);
        this->update();
        break;
    }
}
