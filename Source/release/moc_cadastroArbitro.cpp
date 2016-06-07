/****************************************************************************
** Meta object code from reading C++ file 'cadastroArbitro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cadastroArbitro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cadastroArbitro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cadastroArbitro_t {
    QByteArrayData data[9];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cadastroArbitro_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cadastroArbitro_t qt_meta_stringdata_cadastroArbitro = {
    {
QT_MOC_LITERAL(0, 0, 15), // "cadastroArbitro"
QT_MOC_LITERAL(1, 16, 20), // "on_Confirmar_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 19), // "on_Cancelar_clicked"
QT_MOC_LITERAL(4, 58, 24), // "on_SelecionarImg_clicked"
QT_MOC_LITERAL(5, 83, 21), // "on_RemoverImg_clicked"
QT_MOC_LITERAL(6, 105, 11), // "resizeEvent"
QT_MOC_LITERAL(7, 117, 13), // "QResizeEvent*"
QT_MOC_LITERAL(8, 131, 1) // "e"

    },
    "cadastroArbitro\0on_Confirmar_clicked\0"
    "\0on_Cancelar_clicked\0on_SelecionarImg_clicked\0"
    "on_RemoverImg_clicked\0resizeEvent\0"
    "QResizeEvent*\0e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cadastroArbitro[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void cadastroArbitro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cadastroArbitro *_t = static_cast<cadastroArbitro *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Confirmar_clicked(); break;
        case 1: _t->on_Cancelar_clicked(); break;
        case 2: _t->on_SelecionarImg_clicked(); break;
        case 3: _t->on_RemoverImg_clicked(); break;
        case 4: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject cadastroArbitro::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cadastroArbitro.data,
      qt_meta_data_cadastroArbitro,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cadastroArbitro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cadastroArbitro::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cadastroArbitro.stringdata0))
        return static_cast<void*>(const_cast< cadastroArbitro*>(this));
    return QWidget::qt_metacast(_clname);
}

int cadastroArbitro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
