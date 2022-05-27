#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>

// Classe dediee pour la gestion de la voiture
class Ship
{
public:
    // Constructeur avec parametres
    Ship();

    // Destructeur
    ~Ship();

    // Methode d'affichage
    void Display();



    //position
    bool Stop = false;
    float z=0;
    float x=0;
    float y=0;
    float angleX = 0;
    float angleY= 0;
    float radius = 20;
};
