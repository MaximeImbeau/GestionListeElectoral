TEMPLATE = app
TARGET = CirconscriptionGUI
QT += core \
    gui
HEADERS += desinscriptionpersonne.h \
    inscriptionelecteur.h \
    inscriptioncandidat.h \
    circonscriptiongui.h
SOURCES += desinscriptionpersonne.cpp \
    inscriptionelecteur.cpp \
    inscriptioncandidat.cpp \
    main.cpp \
    circonscriptiongui.cpp
FORMS += desinscriptionpersonne.ui \
    inscriptionelecteur.ui \
    inscriptioncandidat.ui \
    circonscriptiongui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
