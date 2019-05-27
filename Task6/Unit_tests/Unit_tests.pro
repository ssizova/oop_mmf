CONFIG += c++14

SOURCES += \
        main.cpp

HEADERS +=\
"../functionmaker.h"

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
INCLUDEPATH+="gtest/include"
INCLUDEPATH+="gtest/"
INCLUDEPATH+="../"
