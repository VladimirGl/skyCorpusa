// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include "general_file_format.h"

#include "aero_data_read_write.h"
#include "sky_data_read_write.h"

namespace skyCorpusa {
namespace dataIO {

class DataIO
{
public:
  DataIO();

  GeneralFileFormat data(ImProcessingData imData, int x, int y);

private:
  AERODataReadWrite mAeroReader;
  SkyDataReadWrite  mSkyWriter;
};

}  // namespace dataIO
}  // namespace skyCorpusa


#endif // DATA_PROCESSING_H
