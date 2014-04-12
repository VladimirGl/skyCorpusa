#-------------------------------------------------
#
# Project created by QtCreator 2014-04-12T02:19:43
#
#-------------------------------------------------

QT       += core gui sql

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
    image_collection.cpp \
    sky_data_read_write.cpp \
    aero_data_read_write.cpp \
    collection.cpp \
    aeronet_data_type.cpp

HEADERS  += widget.h \
    image_processing.h \
    image_reader.h \
    translator.h \
    server_processing.h \
    image_collection.h \
    im_processing_data.h \
    sky_data_read_write.h \
    aero_data_read_write.h \
    aeronet_data_type.h \
    collection.h

FORMS    += widget.ui
