/****************************************************************************
** Meta object code from reading C++ file 'tools.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../C_lib/Qt_lib/tools.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Console_t {
    const uint offsetsAndSize[10];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Console_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Console_t qt_meta_stringdata_Console = {
    {
QT_MOC_LITERAL(0, 7), // "Console"
QT_MOC_LITERAL(8, 7), // "sendCMD"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 7), // "command"
QT_MOC_LITERAL(25, 8) // "onChange"

    },
    "Console\0sendCMD\0\0command\0onChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Console[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    0 /* Public */,
       4,    1,   29,    2, 0x06,    2 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Console::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Console *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendCMD((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Console::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::sendCMD)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Console::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::onChange)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Console::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlainTextEdit::staticMetaObject>(),
    qt_meta_stringdata_Console.offsetsAndSize,
    qt_meta_data_Console,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Console_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>



>,
    nullptr
} };


const QMetaObject *Console::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Console::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Console.stringdata0))
        return static_cast<void*>(this);
    return QPlainTextEdit::qt_metacast(_clname);
}

int Console::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Console::sendCMD(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Console::onChange(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CommandList_t {
    const uint offsetsAndSize[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CommandList_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CommandList_t qt_meta_stringdata_CommandList = {
    {
QT_MOC_LITERAL(0, 11) // "CommandList"

    },
    "CommandList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandList[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CommandList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject CommandList::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableWidget::staticMetaObject>(),
    qt_meta_stringdata_CommandList.offsetsAndSize,
    qt_meta_data_CommandList,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *CommandList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommandList.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int CommandList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RW_Widget_t {
    const uint offsetsAndSize[8];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RW_Widget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RW_Widget_t qt_meta_stringdata_RW_Widget = {
    {
QT_MOC_LITERAL(0, 9), // "RW_Widget"
QT_MOC_LITERAL(10, 16), // "write_pb_clicked"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 15) // "read_pb_clicked"

    },
    "RW_Widget\0write_pb_clicked\0\0read_pb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RW_Widget[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    0 /* Public */,
       3,    0,   27,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RW_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RW_Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->write_pb_clicked(); break;
        case 1: _t->read_pb_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RW_Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RW_Widget::write_pb_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RW_Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RW_Widget::read_pb_clicked)) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject RW_Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RW_Widget.offsetsAndSize,
    qt_meta_data_RW_Widget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RW_Widget_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *RW_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RW_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RW_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RW_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RW_Widget::write_pb_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RW_Widget::read_pb_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_ConnectionSetup_t {
    const uint offsetsAndSize[12];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ConnectionSetup_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ConnectionSetup_t qt_meta_stringdata_ConnectionSetup = {
    {
QT_MOC_LITERAL(0, 15), // "ConnectionSetup"
QT_MOC_LITERAL(16, 22), // "on_ApplyButton_clicked"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 10), // "closeEvent"
QT_MOC_LITERAL(51, 12), // "QCloseEvent*"
QT_MOC_LITERAL(64, 5) // "event"

    },
    "ConnectionSetup\0on_ApplyButton_clicked\0"
    "\0closeEvent\0QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionSetup[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x08,    0 /* Private */,
       3,    1,   27,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void ConnectionSetup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnectionSetup *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ApplyButton_clicked(); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ConnectionSetup::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ConnectionSetup.offsetsAndSize,
    qt_meta_data_ConnectionSetup,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ConnectionSetup_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *ConnectionSetup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionSetup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionSetup.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ConnectionSetup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_ConnectionsBar_t {
    const uint offsetsAndSize[12];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ConnectionsBar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ConnectionsBar_t qt_meta_stringdata_ConnectionsBar = {
    {
QT_MOC_LITERAL(0, 14), // "ConnectionsBar"
QT_MOC_LITERAL(15, 15), // "SettingsChanged"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 15), // "Connection_Info"
QT_MOC_LITERAL(48, 2), // "CI"
QT_MOC_LITERAL(51, 10) // "OpenDevice"

    },
    "ConnectionsBar\0SettingsChanged\0\0"
    "Connection_Info\0CI\0OpenDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionsBar[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    0 /* Public */,
       5,    0,   29,    2, 0x06,    2 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void ConnectionsBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnectionsBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SettingsChanged((*reinterpret_cast< Connection_Info(*)>(_a[1]))); break;
        case 1: _t->OpenDevice(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConnectionsBar::*)(Connection_Info );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionsBar::SettingsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConnectionsBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConnectionsBar::OpenDevice)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ConnectionsBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ConnectionsBar.offsetsAndSize,
    qt_meta_data_ConnectionsBar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ConnectionsBar_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Connection_Info, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *ConnectionsBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionsBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionsBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ConnectionsBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ConnectionsBar::SettingsChanged(Connection_Info _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConnectionsBar::OpenDevice()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
