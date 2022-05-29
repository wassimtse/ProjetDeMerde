# configuration Qt
QT       += core gui opengl widgets openglwidgets
TEMPLATE  = app
CONFIG += c++17

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}


# fichiers sources/headers/ressources
SOURCES += main.cpp myglwidget.cpp \
    Ship.cpp \
    Space.cpp \
    asteroid.cpp \
    station.cpp
HEADERS += myglwidget.h \
    Ship.h \
    Space.h \
    asteroid.h \
    station.h

# nom de l'exe genere
TARGET 	  = StarterTD2

RESOURCES += \
    Textures/textures.qrc

DISTFILES += \
    Textures/spaceImg.jpg \
    Textures/asteroid.jpg
