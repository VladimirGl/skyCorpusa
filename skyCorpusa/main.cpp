// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "widget.h"
#include <QApplication>

#include <QImage>
#include <QString>
#include <QDebug>

#include "image_reader.h"
#include "image_processing.h"
#include "data_IO.h"
#include "translator.h"
#include "general_file_format.h"

#include "data_IO.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Widget w;

  QString test = "/home/rayman/Downloads/sky_2.jpg";

  skyCorpusa::ImageReader reader;
  reader.setPath(test);
  QImage im  = reader.image();
  im.save("/home/rayman/Downloads/sky_2_2.jpg");

  skyCorpusa::Translator translator;
  translator.init();
  translator.loadImage(im, 250, 12);
  skyCorpusa::GeneralFileFormat form;
  form = translator.lastData();
  qDebug() << form.city() << " " << form.aot();
  qDebug() << form.sky() << " " << form.cl1() << " " << form.cl2() << " " << form.sun();

  w.show();
  
  return a.exec();
}
