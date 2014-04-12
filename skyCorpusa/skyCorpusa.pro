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
    image_collection.cpp \
    sky_data_read_write.cpp \
    aero_data_read_write.cpp \
    aeronet_data_type.cpp \
    data_IO.cpp \
    collection_processing.cpp \
    general_file_format.cpp

HEADERS  += widget.h \
    image_processing.h \
    image_reader.h \
    translator.h \
    image_collection.h \
    im_processing_data.h \
    sky_data_read_write.h \
    aero_data_read_write.h \
    aeronet_data_type.h \
    data_IO.h \
    collection_processing.h \
    general_file_format.h

FORMS    += widget.ui

PRPATH = $$PWD
