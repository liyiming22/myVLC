/****************************************************************************
** Meta object code from reading C++ file 'SimplePlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SimplePlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimplePlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimplePlayer_t {
    QByteArrayData data[25];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimplePlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimplePlayer_t qt_meta_stringdata_SimplePlayer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SimplePlayer"
QT_MOC_LITERAL(1, 13, 16), // "open_local_files"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "toggle_play_state"
QT_MOC_LITERAL(4, 49, 18), // "seekSlider_clicked"
QT_MOC_LITERAL(5, 68, 16), // "seekSlider_moved"
QT_MOC_LITERAL(6, 85, 19), // "seekSlider_released"
QT_MOC_LITERAL(7, 105, 20), // "volumeSlider_changed"
QT_MOC_LITERAL(8, 126, 22), // "signal_set_full_screen"
QT_MOC_LITERAL(9, 149, 8), // "showList"
QT_MOC_LITERAL(10, 158, 12), // "takeSnapShot"
QT_MOC_LITERAL(11, 171, 10), // "toggleMute"
QT_MOC_LITERAL(12, 182, 9), // "recordPos"
QT_MOC_LITERAL(13, 192, 7), // "moveDif"
QT_MOC_LITERAL(14, 200, 9), // "debugTest"
QT_MOC_LITERAL(15, 210, 9), // "leftClick"
QT_MOC_LITERAL(16, 220, 10), // "rightClick"
QT_MOC_LITERAL(17, 231, 10), // "modeChange"
QT_MOC_LITERAL(18, 242, 19), // "updateDurationLabel"
QT_MOC_LITERAL(19, 262, 4), // "type"
QT_MOC_LITERAL(20, 267, 4), // "time"
QT_MOC_LITERAL(21, 272, 12), // "activeSlider"
QT_MOC_LITERAL(22, 285, 21), // "mouseDoubleClickEvent"
QT_MOC_LITERAL(23, 307, 12), // "QMouseEvent*"
QT_MOC_LITERAL(24, 320, 5) // "event"

    },
    "SimplePlayer\0open_local_files\0\0"
    "toggle_play_state\0seekSlider_clicked\0"
    "seekSlider_moved\0seekSlider_released\0"
    "volumeSlider_changed\0signal_set_full_screen\0"
    "showList\0takeSnapShot\0toggleMute\0"
    "recordPos\0moveDif\0debugTest\0leftClick\0"
    "rightClick\0modeChange\0updateDurationLabel\0"
    "type\0time\0activeSlider\0mouseDoubleClickEvent\0"
    "QMouseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimplePlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    0,  110,    2, 0x06 /* Public */,
       4,    1,  111,    2, 0x06 /* Public */,
       5,    1,  114,    2, 0x06 /* Public */,
       6,    0,  117,    2, 0x06 /* Public */,
       7,    1,  118,    2, 0x06 /* Public */,
       8,    0,  121,    2, 0x06 /* Public */,
       9,    0,  122,    2, 0x06 /* Public */,
      10,    0,  123,    2, 0x06 /* Public */,
      11,    0,  124,    2, 0x06 /* Public */,
      12,    0,  125,    2, 0x06 /* Public */,
      13,    1,  126,    2, 0x06 /* Public */,
      14,    0,  129,    2, 0x06 /* Public */,
      15,    1,  130,    2, 0x06 /* Public */,
      16,    1,  133,    2, 0x06 /* Public */,
      17,    0,  136,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    2,  137,    2, 0x0a /* Public */,
      21,    0,  142,    2, 0x0a /* Public */,
      22,    1,  143,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QTime,   19,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,

       0        // eod
};

void SimplePlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimplePlayer *_t = static_cast<SimplePlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open_local_files(); break;
        case 1: _t->toggle_play_state(); break;
        case 2: _t->seekSlider_clicked((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->seekSlider_moved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->seekSlider_released(); break;
        case 5: _t->volumeSlider_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->signal_set_full_screen(); break;
        case 7: _t->showList(); break;
        case 8: _t->takeSnapShot(); break;
        case 9: _t->toggleMute(); break;
        case 10: _t->recordPos(); break;
        case 11: _t->moveDif((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 12: _t->debugTest(); break;
        case 13: _t->leftClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->rightClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->modeChange(); break;
        case 16: _t->updateDurationLabel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2]))); break;
        case 17: _t->activeSlider(); break;
        case 18: _t->mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::open_local_files)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::toggle_play_state)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::seekSlider_clicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::seekSlider_moved)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::seekSlider_released)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::volumeSlider_changed)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::signal_set_full_screen)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::showList)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::takeSnapShot)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::toggleMute)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::recordPos)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::moveDif)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::debugTest)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::leftClick)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::rightClick)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (SimplePlayer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimplePlayer::modeChange)) {
                *result = 15;
                return;
            }
        }
    }
}

const QMetaObject SimplePlayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SimplePlayer.data,
      qt_meta_data_SimplePlayer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SimplePlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimplePlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimplePlayer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SimplePlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void SimplePlayer::open_local_files()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SimplePlayer::toggle_play_state()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SimplePlayer::seekSlider_clicked(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SimplePlayer::seekSlider_moved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SimplePlayer::seekSlider_released()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SimplePlayer::volumeSlider_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SimplePlayer::signal_set_full_screen()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SimplePlayer::showList()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SimplePlayer::takeSnapShot()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void SimplePlayer::toggleMute()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void SimplePlayer::recordPos()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void SimplePlayer::moveDif(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void SimplePlayer::debugTest()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void SimplePlayer::leftClick(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void SimplePlayer::rightClick(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void SimplePlayer::modeChange()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
