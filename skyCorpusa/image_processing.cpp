// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include <QDebug>

#include "image_processing.h"

#include <QRgb>
#include <QColor>
#include <qmath.h>

namespace skyCorpusa {
namespace imProcess {

ImageProcessing::ImageProcessing()
{
}

ImageProcessing::~ImageProcessing() {
  if (mImage.isNull()) return;

  int w = mImage.width();
  int h = mImage.height();

  for (int i = 0; i < h; i++) {
    delete [] mIsSky[i];
  }

  delete [] mIsSky;

  for (int i = 0; i < h; i++) {
    delete [] mIsCloud[i];
  }

  delete [] mIsCloud;
}

void ImageProcessing::loadImage(const QImage &image) {
  int w = image.width();
  int h = image.height();

  mImage = image;

  mIsSky = new bool*[h];
  for (int i = 0; i < h; i++) {
    mIsSky[i] = new bool[w];
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      mIsSky[i][j] = false;
    }
  }

  mIsCloud = new bool*[h];
  for (int i = 0; i < h; i++) {
    mIsCloud[i] = new bool[w];
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      mIsCloud[i][j] = false;
    }
  }
}

void ImageProcessing::compute() {
  if (mImage.isNull()) return;

  skyProcessing();

}

void ImageProcessing::skyProcessing() {
  int w = mImage.width();
  int h = mImage.height();

  int hFrom = (h / 3) * 2;

  int sRed = 0;
  int sGreen = 0;
  int sBlue = 0;

  for (int i = hFrom; i < h; i++) {
    for (int j = 0; j < w; j++) {
      QRgb pix = mImage.pixel(j, i);
      int red = qRed(pix);
      int green = qGreen(pix);
      int blue = qBlue(pix);

      mIsSky[i][j] = isSky(red, green, blue);
      if (mIsSky[i][j]) {
        mSkyCount++;

        QRgb pix = mImage.pixel(j, i);
        int red = qRed(pix);
        int green = qGreen(pix);
        int blue = qBlue(pix);

        sRed += red;
        sGreen += green;
        sBlue += blue;

        mBrightness += brightness(red, green, blue);
      }
    }
  }

  if (mSkyCount) {
    sRed   /= mSkyCount;
    sGreen /= mSkyCount;
    sBlue  /= mSkyCount;

    skyR = sRed;
    skyG = sGreen;
    skyB = sBlue;
  }
}

void ImageProcessing::cloudProcessing() {
  int w = mImage.width();
  int h = mImage.height();

  int hFrom = (h / 3) * 2;

  int cRed = 0;
  int cGreen = 0;
  int cBlue = 0;

  for (int i = hFrom; i < h; i++) {
    for (int j = 0; j < w; j++) {
      QRgb pix = mImage.pixel(j, i);
      int red = qRed(pix);
      int green = qGreen(pix);
      int blue = qBlue(pix);

      mIsCloud[i][j] = isCloud(red, green, blue);
      if (mIsCloud[i][j]) {
        mIsSky[i][j] = false;
        mCloudCount++;

        QRgb pix = mImage.pixel(j, i);
        int red = qRed(pix);
        int green = qGreen(pix);
        int blue = qBlue(pix);

        cRed += red;
        cGreen += green;
        cBlue += blue;

        mBrightness += brightness(red, green, blue);
      }
    }
  }

  if (mCloudCount) {

    cRed   /= mCloudCount;
    cGreen /= mCloudCount;
    cBlue  /= mCloudCount;

    mData.setCloudLevel( toCloudLevel(cRed, cGreen, cBlue) );
  }
}

int ImageProcessing::brightness(int R, int G, int B) const {
  return ( 0.299 * R + 0.587 * G + 0.113 * B );
}

bool ImageProcessing::isSky(int R, int G, int B) const {
  return ( (B > R)
           && (B > G)
           && qAbs(B - G) > 25
           && qAbs(B - R) > 25
           && (B > 50) )
      || ( (B > R)
           && (B > G)
           && qAbs(B - G) > 10
           && qAbs(B - G) > 10
           && (B > 200)
           && (B < 230) );
}

bool ImageProcessing::isCloud(int R, int G, int B) const {
  bool isSkyHere = isSky(R, G, B);
  bool isCloudHere = false;

  if (isSkyHere) {
    int dist = qSqrt(  (R - skyR) * (R - skyR)
                     + (G - skyG) * (G - skyG)
                     + (R - skyB) * (R - skyB)
                     );

    if (dist > 25) {
      isCloudHere = true;
    }
  } else {
    isCloudHere = (    qAbs(R - G) < 10
                    && qAbs(R - B) < 10
                    && qAbs(G - B) < 10);
  }

  return isCloudHere;
}

int ImageProcessing::toSkyLevel() const {

}

int ImageProcessing::toCloudLevel(int R, int G, int B) const {

}

int ImageProcessing::toCloudType(int R, int G, int B) const {

}

int ImageProcessing::toBrighness() const {
}

}  // namespace imProcess
}  // namespace skyCorpusa
