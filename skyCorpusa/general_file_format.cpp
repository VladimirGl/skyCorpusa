// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "general_file_format.h"

namespace skyCorpusa {

GeneralFileFormat::GeneralFileFormat() :
  mCity("no"),
  mAOT(0),
  mSky(0),
  mCl1(0),
  mCl2(0),
  mSun(0)
{
}

void GeneralFileFormat::fillImageData(ImProcessingData data) {
  mSky = data.skyColor();
  mCl1 = data.cloudLevel();
  mCl2 = data.cloudType();
  mSun = data.sunLevel();
}

void GeneralFileFormat::fillAeroData(AERONETDataType data) {
  mCity = data.nearestCity();
  mAOT = data.aot1020();
}


}  // namespace skyCorpusa
