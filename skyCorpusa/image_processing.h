// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QImage>
#include <QMatrix>

#include "im_processing_data.h"

namespace skyCorpusa {
namespace imProcess {

class ImageProcessing
{
public:
  ImageProcessing();
  ~ImageProcessing();

  void loadImage(const QImage& image);
  ImProcessingData processed() const { return mData; }

  // Main method of the class. Here are made all the callculation.
  // Look ImProcessingData class and inside this method for more information.
  void compute();

protected:
  int brightness(int R, int G, int B) const;

  void skyProcessing();
  void cloudProcessing();

  bool isSky(int R, int G, int B) const;
  bool isCloud(int R, int G, int B) const;

  int toSkyLevel() const;
  int toCloudLevel(int R, int G, int B) const;
  int toCloudType(int R, int G, int B) const;
  int toBrighness() const;

private:
  QImage mImage;
  bool **mIsSky;
  bool **mIsCloud;

  int skyR;
  int skyG;
  int skyB;
  int mSkyCount;
  int mCloudCount;

  int mBrightness;

  ImProcessingData mData;
};

}  // namespace imProcess
}  // namespace skyCorpusa

#endif // IMAGE_PROCESSING_H
