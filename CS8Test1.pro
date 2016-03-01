TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    basenode.cpp \
    linkedlist.cpp \
    fraction.cpp \
    mixed.cpp \
    main.cpp \
    token.cpp \
    operand.cpp \
    myoperator.cpp \
    shuntingyard.cpp

HEADERS += \
    linkedlist.h \
    node.h \
    basenode.h \
    queue.h \
    fraction.h \
    mixed.h \
    stack.h \
    token.h \
    operand.h \
    myoperator.h \
    shuntingyard.h

