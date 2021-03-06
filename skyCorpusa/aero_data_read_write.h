// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef AERO_DATA_READ_WRITE_H
#define AERO_DATA_READ_WRITE_H

#include "aeronet_data_type.h"

#include <QtSql>
#include <QString>

namespace skyCorpusa {
namespace dataIO {

class AERODataReadWrite
{
public:
  AERODataReadWrite(const QString& name);

  AERONETDataType data(int x, int y);

private:
  QSqlDatabase mBase;
};

}  // namespace dataIO
}  // namespace skyCorpusa


#endif // AERO_DATA_READ_WRITE_H
