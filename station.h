#ifndef STATION_H
#define STATION_H
#include <cstdlib>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <QtOpenGLWidgets>
#include <qopengl.h>

#include <iostream>



class Station
{
public:
    Station();


    // Destructeur
    ~Station();

    // Methode d'affichage
    void Display();

    //position
    float z= 800 + rand() % 200;
    float x= rand() % 100;
    float y= rand() % 100;
private:
    GLuint* m_TextureID_=nullptr;   // Tableau de textures
    QImage station;   // Texture de l'espace
};

#endif // STATION_H
