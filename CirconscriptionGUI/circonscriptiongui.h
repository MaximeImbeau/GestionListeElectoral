#ifndef CIRCONSCRIPTIONGUI_H
#define CIRCONSCRIPTIONGUI_H

#include <QtGui/QMainWindow>
#include "ui_circonscriptiongui.h"
#include "Circonscription.h"
#include "Adresse.h"
#include "Date.h"
#include <vector>

class CirconscriptionGUI : public QMainWindow
{
    Q_OBJECT

public:
    CirconscriptionGUI(QWidget *parent = 0);
    ~CirconscriptionGUI();

private slots:
	void dialogueInscriptionCandidat();
	void dialogueInscriptionElecteur();
	void dialogueDesinscriptionPersonne();
private:
    elections::Circonscription *m_circonscription;
    Ui::CirconscriptionGUIClass ui;
};

#endif // CIRCONSCRIPTIONGUI_H
