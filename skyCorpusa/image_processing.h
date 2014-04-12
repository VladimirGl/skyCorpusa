// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QImage>

#include "im_processing_data.h"

namespace imProcess {

class ImageProcessing
{
public:
  ImageProcessing();

  void loadImage(const QImage& image) { mImage = image; }
  ImProcessingData processed() const { return mData; }

  // Main method of the class. Here are made all the callculation.
  // Look ImProcessingData class and inside this method for more information.
  void compute();

private:
  QImage mImage;

  ImProcessingData mData;
};

}  // namespace imProcess

#endif // IMAGE_PROCESSING_H
