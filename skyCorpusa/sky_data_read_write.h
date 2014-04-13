// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef SKY_DATA_READ_WRITE_H
#define SKY_DATA_READ_WRITE_H

#include <QtSql>
#include <QString>

#include "im_processing_data.h"
#include "aeronet_data_type.h"

namespace skyCorpusa {
namespace dataIO {

class SkyDataReadWrite
{
public:
  SkyDataReadWrite(const QString& name);

  // Write data to SQL database in SkyData table
  // sky_color from 1 to 5, there 1 - dark blue, 5 - milky sky color
  // cloud_color from 1 to 5, there 1 - white, 5 - dark cloud color
  // cloud_type from 1 to 5, there 1 - no cloud, 5 - only cloud
  // sun - brightness from 1 to 255
  void pushData(const ImProcessingData& data, const AERONETDataType& aero);


private:
  QSqlDatabase mBase;
};

}  // namespace dataIO
}  // namespace skyCorpusa

#endif // SKY_DATA_READ_WRITE_H
