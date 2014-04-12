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

  // Returns true, if point can be the sky. The rule follows the empirical observation.
  bool isSky(int R, int G, int B) const;
  // Returns true, if point can be the cloud. If point can be as sky as cloud, then sets point as cloud.
  bool isCloud(int R, int G, int B) const;

  int toSkyLevel() const;
  int toCloudLevel() const;
  int toCloudType(int R, int G, int B) const;
  int toBrighness();

private:
  QImage mImage;
  bool **mIsSky;
  bool **mIsCloud;

  int mSkyR;
  int mSkyG;
  int mSkyB;
  int mSkyCount;
  int mCloudCount;

  int mBrightness;

  ImProcessingData mData;
};

}  // namespace imProcess
}  // namespace skyCorpusa

#endif // IMAGE_PROCESSING_H
