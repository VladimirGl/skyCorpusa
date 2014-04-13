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
  w.show();
  
  return a.exec();
}
