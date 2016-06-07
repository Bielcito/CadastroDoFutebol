/****************************************************************************
** Meta object code from reading C++ file 'cadastroJogo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cadastroJogo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cadastroJogo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cadastroJogo_t {
    QByteArrayData data[12];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cadastroJogo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cadastroJogo_t qt_meta_stringdata_cadastroJogo = {
    {
QT_MOC_LITERAL(0, 0, 12), // "cadastroJogo"
QT_MOC_LITERAL(1, 13, 27), // "atualizarComboBoxEquipeCasa"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 27), // "atualizarComboBoxEquipeFora"
QT_MOC_LITERAL(4, 70, 24), // "on_isTempoNormal_clicked"
QT_MOC_LITERAL(5, 95, 1), // "x"
QT_MOC_LITERAL(6, 97, 24), // "on_isProrrogacao_clicked"
QT_MOC_LITERAL(7, 122, 21), // "on_isPenaltis_clicked"
QT_MOC_LITERAL(8, 144, 7), // "checked"
QT_MOC_LITERAL(9, 152, 15), // "somarPontosCasa"
QT_MOC_LITERAL(10, 168, 15), // "somarPontosFora"
QT_MOC_LITERAL(11, 184, 20) // "on_Confirmar_clicked"

    },
    "cadastroJogo\0atualizarComboBoxEquipeCasa\0"
    "\0atualizarComboBoxEquipeFora\0"
    "on_isTempoNormal_clicked\0x\0"
    "on_isProrrogacao_clicked\0on_isPenaltis_clicked\0"
    "checked\0somarPontosCasa\0somarPontosFora\0"
    "on_Confirmar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cadastroJogo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    1,   56,    2, 0x08 /* Private */,
       6,    1,   59,    2, 0x08 /* Private */,
       7,    1,   62,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cadastroJogo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cadastroJogo *_t = static_cast<cadastroJogo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->atualizarComboBoxEquipeCasa(); break;
        case 1: _t->atualizarComboBoxEquipeFora(); break;
        case 2: _t->on_isTempoNormal_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_isProrrogacao_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_isPenaltis_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->somarPontosCasa(); break;
        case 6: _t->somarPontosFora(); break;
        case 7: _t->on_Confirmar_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject cadastroJogo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cadastroJogo.data,
      qt_meta_data_cadastroJogo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cadastroJogo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cadastroJogo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cadastroJogo.stringdata0))
        return static_cast<void*>(const_cast< cadastroJogo*>(this));
    return QWidget::qt_metacast(_clname);
}

int cadastroJogo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
