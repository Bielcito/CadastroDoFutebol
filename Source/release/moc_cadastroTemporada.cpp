/****************************************************************************
** Meta object code from reading C++ file 'cadastroTemporada.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cadastroTemporada.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cadastroTemporada.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cadastroTemporada_t {
    QByteArrayData data[6];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cadastroTemporada_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cadastroTemporada_t qt_meta_stringdata_cadastroTemporada = {
    {
QT_MOC_LITERAL(0, 0, 17), // "cadastroTemporada"
QT_MOC_LITERAL(1, 18, 20), // "on_confirmar_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 19), // "on_cancelar_clicked"
QT_MOC_LITERAL(4, 60, 19), // "on_tempCima_clicked"
QT_MOC_LITERAL(5, 80, 20) // "on_tempBaixo_clicked"

    },
    "cadastroTemporada\0on_confirmar_clicked\0"
    "\0on_cancelar_clicked\0on_tempCima_clicked\0"
    "on_tempBaixo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cadastroTemporada[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cadastroTemporada::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cadastroTemporada *_t = static_cast<cadastroTemporada *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_confirmar_clicked(); break;
        case 1: _t->on_cancelar_clicked(); break;
        case 2: _t->on_tempCima_clicked(); break;
        case 3: _t->on_tempBaixo_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject cadastroTemporada::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cadastroTemporada.data,
      qt_meta_data_cadastroTemporada,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cadastroTemporada::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cadastroTemporada::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cadastroTemporada.stringdata0))
        return static_cast<void*>(const_cast< cadastroTemporada*>(this));
    return QWidget::qt_metacast(_clname);
}

int cadastroTemporada::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
