#-------------------------------------------------
#
# Project created by QtCreator 2014-04-12T02:19:43
#
#-------------------------------------------------

OPENCV_BINDIR =

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = skyCorpusa
TEMPLATE = app


SOURCES +=\
    image_processing.cpp \
    image_reader.cpp \
    main.cpp \
    widget.cpp \
    translator.cpp \
    server_processing.cpp \
    aero_data.cpp \
    sky_data.cpp \
    image_collection.cpp

HEADERS  += widget.h \
    image_processing.h \
    image_reader.h \
    translator.h \
    server_processing.h \
    aero_data.h \
    sky_data.h \
    image_collection.h

FORMS    += widget.ui
