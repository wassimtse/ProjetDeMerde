#include "Space.h"

Space::Space()
{
    glColor3ub(255,255,255);
    glEnable(GL_TEXTURE_2D);

    QImage space_load = QImage(":/background.jpg");
    QImage space = space_load.convertToFormat(QImage::Format_RGBA8888);
    QImage asteroid_load = QImage(":/asteroid.jpg");
    QImage asteroid = asteroid_load.convertToFormat(QImage::Format_RGBA8888);

    m_TextureID_=new GLuint[2];
    glGenTextures(2,m_TextureID_);

    glBindTexture(GL_TEXTURE_2D,m_TextureID_[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,space.width(),space.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,space.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindTexture(GL_TEXTURE_2D,m_TextureID_[1]);
    glTexImage2D(GL_TEXTURE_2D,0,4,asteroid.width(),asteroid.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,asteroid.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

Space::~Space()
{
     delete [] m_TextureID_;
}

void Space::Display() const
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,m_TextureID_[0]);

    GLUquadric * sphere = gluNewQuadric();
    gluQuadricTexture(sphere,GLU_TRUE);
    gluQuadricOrientation(sphere, GLU_INSIDE);
    gluSphere(sphere,1000,200,200);

    gluDeleteQuadric(sphere);

    glBindTexture(GL_TEXTURE_2D,m_TextureID_[1]);
    glPushMatrix();
    glTranslatef(40.,12.,7.);
    GLUquadric * sphere2 = gluNewQuadric();
    gluQuadricTexture(sphere2,GLU_TRUE);
    gluQuadricOrientation(sphere2, GLU_INSIDE);
    gluSphere(sphere2,10,100,100);

    gluDeleteQuadric(sphere2);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}
