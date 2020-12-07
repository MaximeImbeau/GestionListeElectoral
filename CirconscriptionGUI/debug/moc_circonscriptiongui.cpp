/****************************************************************************
** Meta object code from reading C++ file 'circonscriptiongui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../circonscriptiongui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'circonscriptiongui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CirconscriptionGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      50,   19,   19,   19, 0x08,
      80,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CirconscriptionGUI[] = {
    "CirconscriptionGUI\0\0dialogueInscriptionCandidat()\0"
    "dialogueInscriptionElecteur()\0"
    "dialogueDesinscriptionPersonne()\0"
};

void CirconscriptionGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CirconscriptionGUI *_t = static_cast<CirconscriptionGUI *>(_o);
        switch (_id) {
        case 0: _t->dialogueInscriptionCandidat(); break;
        case 1: _t->dialogueInscriptionElecteur(); break;
        case 2: _t->dialogueDesinscriptionPersonne(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CirconscriptionGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CirconscriptionGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CirconscriptionGUI,
      qt_meta_data_CirconscriptionGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CirconscriptionGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CirconscriptionGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CirconscriptionGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CirconscriptionGUI))
        return static_cast<void*>(const_cast< CirconscriptionGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CirconscriptionGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
