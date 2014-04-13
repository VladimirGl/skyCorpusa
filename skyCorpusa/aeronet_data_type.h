// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef AERONET_DATA_TYPE_H
#define AERONET_DATA_TYPE_H

#include <QImage>
#include <QString>

namespace skyCorpusa {

class AERONETDataType
{
public:
  AERONETDataType();
  void set(int x, int y, const QString& city, int aot) { mX = x; mY = y; mCity = city; mAOT = aot; }
  QString nearestCity() const;
  int aot1020() const { return mAOT; }

private:
  int mAOT;
  QString mCity;
  int mX;
  int mY;
};

}  // namespace skyCorpusa

#endif // AERONET_DATA_TYPE_H
