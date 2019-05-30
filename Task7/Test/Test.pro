
CONFIG += console c++14

INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest/"
INCLUDEPATH += "../"

SOURCES += \
../gas_dynamics.cpp\
    gtest/src/gtest-all.cc \
    gtest/src/gtest-death-test.cc \
    gtest/src/gtest-filepath.cc \
    gtest/src/gtest-matchers.cc \
    gtest/src/gtest-port.cc \
    gtest/src/gtest-printers.cc \
    gtest/src/gtest-test-part.cc \
    gtest/src/gtest-typed-test.cc \
    gtest/src/gtest.cc \
    main.cpp

HEADERS += \
    ../gas_dynamics.h \
    ../initial_parameters.h \
#    ../mainwindow.h \
    gtest/include/gtest/gtest-death-test.h \
    gtest/include/gtest/gtest-matchers.h \
    gtest/include/gtest/gtest-message.h \
    gtest/include/gtest/gtest-param-test.h \
    gtest/include/gtest/gtest-printers.h \
    gtest/include/gtest/gtest-spi.h \
    gtest/include/gtest/gtest-test-part.h \
    gtest/include/gtest/gtest-typed-test.h \
    gtest/include/gtest/gtest.h \
    gtest/include/gtest/gtest_pred_impl.h \
    gtest/include/gtest/gtest_prod.h \
    gtest/include/gtest/internal/custom/gtest-port.h \
    gtest/include/gtest/internal/custom/gtest-printers.h \
    gtest/include/gtest/internal/custom/gtest.h \
    gtest/include/gtest/internal/gtest-filepath.h \
    gtest/include/gtest/internal/gtest-internal.h \
    gtest/include/gtest/internal/gtest-param-util.h \
    gtest/include/gtest/internal/gtest-port-arch.h \
    gtest/include/gtest/internal/gtest-port.h \
    gtest/include/gtest/internal/gtest-string.h \
    gtest/include/gtest/internal/gtest-type-util.h \
    gtest/src/gtest-internal-inl.h


#QT -= gui

#CONFIG += c++11 console
#CONFIG -= app_bundle

## The following define makes your compiler emit warnings if you use
## any Qt feature that has been marked deprecated (the exact warnings
## depend on your compiler). Please consult the documentation of the
## deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

## You can also make your code fail to compile if it uses deprecated APIs.
## In order to do so, uncomment the following line.
## You can also select to disable deprecated APIs only up to a certain version of Qt.
##DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#SOURCES += \
#        main.cpp

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../left_side.dat \
    ../right_side.dat \
    gtest/gtest.lib \
    gtest/gtest_main.lib \
    gtest/include/gtest/internal/custom/README.md \
    gtest/include/gtest/internal/gtest-type-util.h.pump \
    left_side.dat \
    right_side.dat

RESOURCES += \
    left_side.dat \
    right_side.dat
