/****************************************************************************
** Meta object code from reading C++ file 'lines.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../5patternf/lines.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_lines_t {
    QByteArrayData data[14];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lines_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lines_t qt_meta_stringdata_lines = {
    {
QT_MOC_LITERAL(0, 0, 5), // "lines"
QT_MOC_LITERAL(1, 6, 8), // "pattern_"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "pattern"
QT_MOC_LITERAL(4, 24, 7), // "display"
QT_MOC_LITERAL(5, 32, 2), // "x2"
QT_MOC_LITERAL(6, 35, 2), // "y2"
QT_MOC_LITERAL(7, 38, 2), // "x1"
QT_MOC_LITERAL(8, 41, 2), // "y1"
QT_MOC_LITERAL(9, 44, 7), // "QImage*"
QT_MOC_LITERAL(10, 52, 1), // "q"
QT_MOC_LITERAL(11, 54, 4), // "QRgb"
QT_MOC_LITERAL(12, 59, 5), // "value"
QT_MOC_LITERAL(13, 65, 5) // "clear"

    },
    "lines\0pattern_\0\0pattern\0display\0x2\0"
    "y2\0x1\0y1\0QImage*\0q\0QRgb\0value\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lines[] = {

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
       4,    6,   36,    2, 0x08 /* Private */,
      13,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 9, 0x80000000 | 11,    5,    6,    7,    8,   10,   12,
    QMetaType::Void,

       0        // eod
};

void lines::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lines *_t = static_cast<lines *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pattern_(); break;
        case 1: _t->pattern(); break;
        case 2: _t->display((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QImage*(*)>(_a[5])),(*reinterpret_cast< QRgb(*)>(_a[6]))); break;
        case 3: _t->clear(); break;
        default: ;
        }
    }
}

const QMetaObject lines::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_lines.data,
      qt_meta_data_lines,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *lines::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lines::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_lines.stringdata0))
        return static_cast<void*>(const_cast< lines*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int lines::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
