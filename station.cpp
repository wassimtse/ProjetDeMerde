#include "station.h"

Station::Station()
{

    QImage station_load = QImage(":/station.jpg");
    QImage stationIMG = station_load.convertToFormat(QImage::Format_RGBA8888);

    m_TextureID_=new GLuint[1];
    glGenTextures(1,m_TextureID_);

    glBindTexture(GL_TEXTURE_2D,m_TextureID_[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,stationIMG.width(),stationIMG.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,stationIMG.bits());
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


}
Station::~Station()
{
}


void Station::Display()
{
  //  std::cout<<"x: "<<x<<"y: " <<y<<"z:"<<z<<"    "<<std::endl;

        glEnable(GL_TEXTURE_2D);
        glPushMatrix();

        glPushMatrix();
        glTranslatef(x+0., y+0., z-5);
        GLUquadric* cylinderS1=gluNewQuadric();
        gluQuadricTexture(cylinderS1, GLU_TRUE);
        glBindTexture(GL_TEXTURE_2D, m_TextureID_[0]);
        gluQuadricDrawStyle(cylinderS1, GLU_FILL);
        gluCylinder(cylinderS1, 30, 30, 20, 20, 30);
        gluDeleteQuadric(cylinderS1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(x+0., y+0., z-5);
        GLUquadric* diskS1_1=gluNewQuadric();
        gluQuadricTexture(diskS1_1, GLU_TRUE);
        glBindTexture(GL_TEXTURE_2D, m_TextureID_[0]);
        gluQuadricDrawStyle(diskS1_1, GLU_FILL);
        gluDisk(diskS1_1, 0, 30, 20, 20);
        gluDeleteQuadric(diskS1_1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(x+0., y+0., z+10);
        GLUquadric* diskS1_2=gluNewQuadric();
        gluQuadricTexture(diskS1_2, GLU_TRUE);
        glBindTexture(GL_TEXTURE_2D, m_TextureID_[0]);
        gluQuadricDrawStyle(diskS1_2, GLU_FILL);
        gluDisk(diskS1_2, 0, 30, 20, 20);
        gluDeleteQuadric(diskS1_2);
        glPopMatrix();


        glDisable(GL_TEXTURE_2D);

}


