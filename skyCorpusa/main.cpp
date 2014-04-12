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

  QString test = "/home/rayman/Downloads/sky_10.jpg";

  skyCorpusa::ImageReader reader;
  reader.setPath(test);
  QImage im  = reader.image();
  im.save("/home/rayman/Downloads/sky_2_2.jpg");

  skyCorpusa::imProcess::ImageProcessing process;
  process.loadImage(im);
  process.compute();
  skyCorpusa::ImProcessingData data = process.processed();
  qDebug() << "data : " << data.skyColor() << " " << data.cloudLevel() << " " << data.cloudType() << " " << data.sunLevel();

  w.show();
  
  return a.exec();
}
