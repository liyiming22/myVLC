/****************************************************************************
** Meta object code from reading C++ file 'listdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "listdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_listDialog_t {
    QByteArrayData data[10];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_listDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_listDialog_t qt_meta_stringdata_listDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "listDialog"
QT_MOC_LITERAL(1, 11, 8), // "listPlay"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "ChannelGroup*"
QT_MOC_LITERAL(4, 35, 9), // "recordPos"
QT_MOC_LITERAL(5, 45, 7), // "moveDif"
QT_MOC_LITERAL(6, 53, 13), // "selectChannel"
QT_MOC_LITERAL(7, 67, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(8, 84, 17), // "addGroupOrChannel"
QT_MOC_LITERAL(9, 102, 17) // "delGroupOrChannel"

    },
    "listDialog\0listPlay\0\0ChannelGroup*\0"
    "recordPos\0moveDif\0selectChannel\0"
    "QTreeWidgetItem*\0addGroupOrChannel\0"
    "delGroupOrChannel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_listDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   49,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x0a /* Public */,
       6,    2,   53,    2, 0x0a /* Public */,
       8,    2,   58,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,

       0        // eod
};

void listDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        listDialog *_t = static_cast<listDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listPlay((*reinterpret_cast< ChannelGroup*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->recordPos(); break;
        case 2: _t->moveDif((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->selectChannel((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->addGroupOrChannel((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->delGroupOrChannel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (listDialog::*_t)(ChannelGroup * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&listDialog::listPlay)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject listDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_listDialog.data,
      qt_meta_data_listDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *listDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *listDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_listDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int listDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void listDialog::listPlay(ChannelGroup * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
