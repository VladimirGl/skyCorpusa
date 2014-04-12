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

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Widget w;

  QString test = "/home/rayman/Downloads/sky-09.jpg";

  skyCorpusa::imProcess::ImageReader reader;
  reader.setPath(test);
  QImage im  = reader.image();

  qDebug() << im.height();

  w.show();
  
  return a.exec();
}
