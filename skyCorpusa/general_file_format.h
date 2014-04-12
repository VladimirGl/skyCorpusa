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

  QList<int> datas();

private:
  QList<int> mDatas;
};

}  // namespace skyCorpusa

#endif // GENERAL_FILE_FORMAT_H
