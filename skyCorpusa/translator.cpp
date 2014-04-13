// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "translator.h"

#include "image_processing.h"

#include <QString>

const QString path = "/home/rayman/Downloads/sky_corpusa/image_base";

namespace skyCorpusa {

Translator::Translator()
{
}

void Translator::init() {
  mCounter = 1;
}

void Translator::loadImage(const QImage &image, int x, int y) {
  imProcess::ImageProcessing process;
  process.loadImage(image);
  process.compute();

  mSky = process.sky();
  mCloud = process.cloud();

  image.save(path + "/" + QString::number(mCounter) + ".jpg");
  mCounter++;

  mLastData = mData.data(process.processed(), x, y);
}

GeneralFileFormat Translator::lastData() const {
  return mLastData;
}

imProcess::ImageCollection Translator::collection() const {

}


}  // namespace skyCorpusa
