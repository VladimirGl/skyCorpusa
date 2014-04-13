// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "aero_data_read_write.h"

#include <QFile>
#include <QTextStream>

namespace skyCorpusa {
namespace dataIO {

AERODataReadWrite::AERODataReadWrite(const QString &name)
{
}

AERONETDataType AERODataReadWrite::data(int x, int y)
{
  QFile file("/home/rayman/Downloads/sky_corpusa/moscow.csv");
  file.open(QIODevice::ReadOnly);
  QTextStream in(&file);

  QString line = in.readLine();
  line = in.readLine();

  file.close();

  QString med = line.mid(11, 8);
  double aot = med.toDouble() * 100;
  int aoot = (int)aot + 1;

  AERONETDataType t;
  t.set(x, y, "Moscow", aoot);
  return t;
}

}  // namespace dataIO
}  // namespace skyCorpusa
