// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "image_reader.h"

namespace skyCorpusa {
namespace imProcess {

ImageReader::ImageReader() :
  mH(480),
  mW(640),
  mPath(""),
  mFrom(File)
{}

QImage ImageReader::image() const {

  if (mFrom == File) {
    QImage im(mPath);
    return im.scaled(mW, mH);
  }

  // DO IMAGE CAPTURE
}

}  // namespace imProcess
}  // namespace skyCorpusa
