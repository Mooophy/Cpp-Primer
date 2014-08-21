TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11


SOURCES += main.cpp \
    Sales_data.cc \
    strvec.cpp \
    string.cpp \
    date.cpp \
    wy_strblob.cpp \
    wy_strblobptr.cpp \
    wy_conststrblobptr.cpp \
    strblobptr_pointer.cpp

HEADERS += \
    Sales_data.h \
    StrBlob.h \
    strvec.h \
    string.h \
    date.h \
    wy_strblob.h \
    wy_strblobptr.h \
    wy_conststrblobptr.h \
    strblobptr_pointer.h

