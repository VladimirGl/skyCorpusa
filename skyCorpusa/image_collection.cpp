// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "image_collection.h"

namespace skyCorpusa {
namespace imProcess {

const int querySize = 10;

ImageCollection::ImageCollection()
{
}

void ImageCollection::addImage(const QImage &im, const ImProcessingData &proc, int aData) {
  mCollection.prepend(im);
  mProcesssingData.prepend(proc);
  mAeroData.prepend(aData);

  int size = mCollection.length();

  if (size > querySize) {
    mCollection.removeLast();
    mProcesssingData.removeLast();
    mAeroData.removeLast();
  }
}

QImage ImageCollection::image(int num) const {
  if (num >= length()) {
    return QImage();
  }

  return mCollection.at(num);
}

ImProcessingData ImageCollection::data(int num) const {
  if (num >= length()) {
    return ImProcessingData();
  }

  return mProcesssingData.at(num);
}

int ImageCollection::aeroData(int num) const {
  if (num >= length()) {
    return -1;
  }

  return mAeroData.at(num);
}

}  // namespace imProcessing
}  // namespace skyCorpusa
