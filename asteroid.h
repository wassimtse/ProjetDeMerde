#ifndef ASTEROID_H
#define ASTEROID_H
#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <QtOpenGLWidgets>

class Asteroid
{
public:
    Asteroid();
    ~Asteroid();

    void Display();

private :
       int position[20][3];
};

#endif // ASTEROID_H
