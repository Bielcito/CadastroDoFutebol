/****************************************************************************
** Meta object code from reading C++ file 'tipocampeonato.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tipocampeonato.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tipocampeonato.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tipoCampeonato_t {
    QByteArrayData data[11];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tipoCampeonato_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tipoCampeonato_t qt_meta_stringdata_tipoCampeonato = {
    {
QT_MOC_LITERAL(0, 0, 14), // "tipoCampeonato"
QT_MOC_LITERAL(1, 15, 30), // "on_tabela_itemSelectionChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 17), // "on_editar_clicked"
QT_MOC_LITERAL(4, 65, 15), // "on_novo_clicked"
QT_MOC_LITERAL(5, 81, 15), // "atualizarTabela"
QT_MOC_LITERAL(6, 97, 18), // "on_excluir_clicked"
QT_MOC_LITERAL(7, 116, 13), // "keyPressEvent"
QT_MOC_LITERAL(8, 130, 10), // "QKeyEvent*"
QT_MOC_LITERAL(9, 141, 1), // "e"
QT_MOC_LITERAL(10, 143, 17) // "on_novo_2_clicked"

    },
    "tipoCampeonato\0on_tabela_itemSelectionChanged\0"
    "\0on_editar_clicked\0on_novo_clicked\0"
    "atualizarTabela\0on_excluir_clicked\0"
    "keyPressEvent\0QKeyEvent*\0e\0on_novo_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tipoCampeonato[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void tipoCampeonato::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tipoCampeonato *_t = static_cast<tipoCampeonato *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tabela_itemSelectionChanged(); break;
        case 1: _t->on_editar_clicked(); break;
        case 2: _t->on_novo_clicked(); break;
        case 3: _t->atualizarTabela(); break;
        case 4: _t->on_excluir_clicked(); break;
        case 5: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->on_novo_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject tipoCampeonato::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tipoCampeonato.data,
      qt_meta_data_tipoCampeonato,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tipoCampeonato::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tipoCampeonato::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tipoCampeonato.stringdata0))
        return static_cast<void*>(const_cast< tipoCampeonato*>(this));
    return QWidget::qt_metacast(_clname);
}

int tipoCampeonato::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
