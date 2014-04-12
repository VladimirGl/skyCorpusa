// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef SKY_DATA_READ_WRITE_H
#define SKY_DATA_READ_WRITE_H

#include <QtSql>
#include <QString>

#include "im_processing_data.h"

namespace skyCorpusa {
namespace server {

class SkyDataReadWrite
{
public:
  SkyDataReadWrite(const QString& name);

  void pushData(imProcess::ImProcessingData data);


private:
  QSqlDatabase mBase;
};

}  // namespace server
}  // namespace skyCorpusa

#endif // SKY_DATA_READ_WRITE_H
