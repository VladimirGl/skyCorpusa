// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "translator.h"

#include "image_processing.h"

#include <QString>

const QString path = "/home/rayman/Downloads/sky_corpusa/images";

namespace skyCorpusa {

Translator::Translator()
{
}

void Translator::init() {

}

void Translator::loadImage(const QImage &image, int x, int y) {
  imProcess::ImageProcessing process;
  process.loadImage(image);
  process.compute();

  image.save(path + "/" + QString::number(mCounter) + ".jpg");
  mCounter++;

  mLastData = mData.data(process.processed(), x, y);


}

GeneralFileFormat Translator::lastData() const {

}

imProcess::ImageCollection Translator::collection() const {

}


}  // namespace skyCorpusa
