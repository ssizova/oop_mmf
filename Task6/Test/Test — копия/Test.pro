CONFIG += console c++14

INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest/"
INCLUDEPATH += "../../"

SOURCES += \
    ../../functionmaker.cpp \
    main.cpp

HEADERS += \
    ../../functionmaker.h
DEFINES += GTEST_LINKED_AS_SHARED_LIBRARY=1
LIBS += -L../gtest/gtest.lib
