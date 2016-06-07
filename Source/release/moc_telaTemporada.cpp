/****************************************************************************
** Meta object code from reading C++ file 'telaTemporada.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../telaTemporada.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telaTemporada.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_telaTemporada_t {
    QByteArrayData data[10];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_telaTemporada_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_telaTemporada_t qt_meta_stringdata_telaTemporada = {
    {
QT_MOC_LITERAL(0, 0, 13), // "telaTemporada"
QT_MOC_LITERAL(1, 14, 14), // "mostrar_grupos"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "mostrar_rodadas"
QT_MOC_LITERAL(4, 46, 13), // "mostrar_jogos"
QT_MOC_LITERAL(5, 60, 18), // "on_Incluir_clicked"
QT_MOC_LITERAL(6, 79, 23), // "alterar_excluir_buttons"
QT_MOC_LITERAL(7, 103, 24), // "on_MostrarTabela_clicked"
QT_MOC_LITERAL(8, 128, 18), // "on_Excluir_clicked"
QT_MOC_LITERAL(9, 147, 17) // "on_Fechar_clicked"

    },
    "telaTemporada\0mostrar_grupos\0\0"
    "mostrar_rodadas\0mostrar_jogos\0"
    "on_Incluir_clicked\0alterar_excluir_buttons\0"
    "on_MostrarTabela_clicked\0on_Excluir_clicked\0"
    "on_Fechar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_telaTemporada[] = {

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
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void telaTemporada::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        telaTemporada *_t = static_cast<telaTemporada *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mostrar_grupos(); break;
        case 1: _t->mostrar_rodadas(); break;
        case 2: _t->mostrar_jogos(); break;
        case 3: _t->on_Incluir_clicked(); break;
        case 4: _t->alterar_excluir_buttons(); break;
        case 5: _t->on_MostrarTabela_clicked(); break;
        case 6: _t->on_Excluir_clicked(); break;
        case 7: _t->on_Fechar_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject telaTemporada::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_telaTemporada.data,
      qt_meta_data_telaTemporada,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *telaTemporada::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *telaTemporada::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_telaTemporada.stringdata0))
        return static_cast<void*>(const_cast< telaTemporada*>(this));
    return QWidget::qt_metacast(_clname);
}

int telaTemporada::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
