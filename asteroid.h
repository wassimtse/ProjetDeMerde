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
    Asteroid(float x ,float y,float z, float speed);
    ~Asteroid();

    void Display();
private:
    GLuint* m_TextureID_=nullptr;   // Tableau de textures
    QImage space;                   // Texture de l'espace
};

#endif // ASTEROID_H
