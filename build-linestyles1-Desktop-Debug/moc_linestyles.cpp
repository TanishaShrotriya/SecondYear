/****************************************************************************
** Meta object code from reading C++ file 'linestyles.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../6linestyles1 working/linestyles.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linestyles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_linestyles_t {
    QByteArrayData data[11];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_linestyles_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_linestyles_t qt_meta_stringdata_linestyles = {
    {
QT_MOC_LITERAL(0, 0, 10), // "linestyles"
QT_MOC_LITERAL(1, 11, 8), // "display1"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "display2"
QT_MOC_LITERAL(4, 30, 6), // "dashed"
QT_MOC_LITERAL(5, 37, 7), // "dashdot"
QT_MOC_LITERAL(6, 45, 5), // "thick"
QT_MOC_LITERAL(7, 51, 7), // "display"
QT_MOC_LITERAL(8, 59, 6), // "dotted"
QT_MOC_LITERAL(9, 66, 5), // "clear"
QT_MOC_LITERAL(10, 72, 4) // "sign"

    },
    "linestyles\0display1\0\0display2\0dashed\0"
    "dashdot\0thick\0display\0dotted\0clear\0"
    "sign"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_linestyles[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    2,   64,    2, 0x08 /* Private */,
       8,    2,   69,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    2,

       0        // eod
};

void linestyles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        linestyles *_t = static_cast<linestyles *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->display1(); break;
        case 1: _t->display2(); break;
        case 2: _t->dashed(); break;
        case 3: _t->dashdot(); break;
        case 4: _t->thick(); break;
        case 5: _t->display((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->dotted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->clear(); break;
        case 8: { int _r = _t->sign((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject linestyles::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_linestyles.data,
      qt_meta_data_linestyles,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *linestyles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *linestyles::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_linestyles.stringdata0))
        return static_cast<void*>(const_cast< linestyles*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int linestyles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
