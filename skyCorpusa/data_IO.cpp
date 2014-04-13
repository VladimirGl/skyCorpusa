// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "data_IO.h"

namespace skyCorpusa {
namespace dataIO {

const QString pathBase = "/home/rayman/Downloads/sky_corpusa";
const QString aBase = "blabla";
const QString sBase = "sky_data";

DataIO::DataIO() :
  mAeroReader(AERODataReadWrite(pathBase + "/" + aBase)),
  mSkyWriter(SkyDataReadWrite(pathBase + "/" + sBase))
{}

GeneralFileFormat DataIO::data(ImProcessingData imData, int x, int y)
{
  GeneralFileFormat f;
  f.fillImageData(imData);
  AERONETDataType a = mAeroReader.data(x, y);
  f.fillAeroData(a);

  mSkyWriter.pushData(imData, a);
  return f;
}

}  // namespace dataIO
}  // namespace skyCorpusa
