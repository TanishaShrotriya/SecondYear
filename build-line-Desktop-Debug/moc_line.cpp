/****************************************************************************
** Meta object code from reading C++ file 'line.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../line/line.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'line.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_line_t {
    QByteArrayData data[10];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_line_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_line_t qt_meta_stringdata_line = {
    {
QT_MOC_LITERAL(0, 0, 4), // "line"
QT_MOC_LITERAL(1, 5, 7), // "display"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 2), // "dx"
QT_MOC_LITERAL(4, 17, 2), // "dy"
QT_MOC_LITERAL(5, 20, 1), // "e"
QT_MOC_LITERAL(6, 22, 5), // "input"
QT_MOC_LITERAL(7, 28, 4), // "sign"
QT_MOC_LITERAL(8, 33, 3), // "val"
QT_MOC_LITERAL(9, 37, 5) // "clear"

    },
    "line\0display\0\0dx\0dy\0e\0input\0sign\0val\0"
    "clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_line[] = {

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
       1,    3,   40,    2, 0x08 /* Private */,
       6,    0,   47,    2, 0x08 /* Private */,
       7,    1,   48,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void line::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        line *_t = static_cast<line *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->display(); break;
        case 1: _t->display((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->input(); break;
        case 3: { int _r = _t->sign((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->clear(); break;
        default: ;
        }
    }
}

const QMetaObject line::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_line.data,
      qt_meta_data_line,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *line::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *line::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_line.stringdata0))
        return static_cast<void*>(const_cast< line*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int line::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
