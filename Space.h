#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <QtOpenGLWidgets>

#include "asteroid.h"
// Classe dediee pour la gestion du sol
class Space
{
public:
    // Constructeur avec parametres
    Space();

    // Destructeur
    ~Space();

    // Methode d'affichage
    void Display() const;

private:
    GLuint* m_TextureID_=nullptr;   // Tableau de textures
    QImage space;   // Texture de l'espace
    Asteroid * asteroids= nullptr; // Tableau d'asteroids
};
