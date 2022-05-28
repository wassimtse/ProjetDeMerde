#include "Ship.h"
#include "Space.h"
#include <QOpenGLWidget>
#include <QKeyEvent>

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QOpenGLWidget
{
public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent* event);

private:
    Space* space_ = nullptr;
    Ship* ship_ = nullptr;
    Asteroid* asteroid_ = nullptr;
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
};
