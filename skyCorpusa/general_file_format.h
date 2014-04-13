// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef GENERAL_FILE_FORMAT_H
#define GENERAL_FILE_FORMAT_H

#include "im_processing_data.h"
#include "aeronet_data_type.h"

#include <QList>

namespace skyCorpusa {

class GeneralFileFormat
{
public:
  GeneralFileFormat();

  void fillImageData(ImProcessingData data);
  void fillAeroData(AERONETDataType data);

  QString city() const { return mCity; }
  int aot() const { return mAOT; }
  int sky() const { return mSky; }
  int cl1() const { return mCl1; }
  int cl2() const { return mCl2; }
  int sun() const { return mSun; }

private:
  QString mCity;
  int mAOT;
  int mSky;
  int mCl1;
  int mCl2;
  int mSun;
};

}  // namespace skyCorpusa

#endif // GENERAL_FILE_FORMAT_H
