// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef IMAGE_READER_H
#define IMAGE_READER_H

#include <QImage>
#include <QString>

namespace skyCorpusa {

class ImageReader
{
public:
  enum FromType {
    File = 0,
    Camera
  };

  ImageReader();

  void setHeight(int height) { mH = height; }
  void setWidth(int width) { mW = width; }

  void setType(FromType type) { mFrom = type; }
  void setPath(const QString& path) { mPath = path; }

  int w() const { return mW; }
  int h() const { return mH; }

  QString path() const { return mPath; }
  FromType fromType() const { return mFrom; }

  QImage image() const;

private:
  int mH;
  int mW;

  QString mPath;
  FromType mFrom;
};

}  // namespace skyCorpusa

#endif // IMAGE_READER_H
