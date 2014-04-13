// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "image_processing.h"

#include <QRgb>
#include <QColor>
#include <qmath.h>
#include <QDebug>

namespace skyCorpusa {
namespace imProcess {

ImageProcessing::ImageProcessing()
{
  mSkyCount = 0;
  mCloudCount = 0;
  mSkyR = 0;
  mSkyG = 0;
  mSkyB = 0;
  mBrightness = 0;
  mCloudR = 0;
  mCloudG = 0;
  mCloudB = 0;
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
  cloudProcessing();

}

QColor ImageProcessing::sky() const
{
  return QColor(mSkyR, mSkyG, mSkyB);
}

QColor ImageProcessing::cloud() const
{
  return QColor(mCloudR, mCloudG, mCloudB);
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
      }
    }
  }

  if (mSkyCount) {
    sRed   /= mSkyCount;
    sGreen /= mSkyCount;
    sBlue  /= mSkyCount;

    mSkyR = sRed;
    mSkyG = sGreen;
    mSkyB = sBlue;

    mData.setSkyColor( toSkyLevel() );
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
        if (mIsSky[i][j]) {
          mIsSky[i][j] = false;
          mSkyCount--;
        }

        mCloudCount++;

        QRgb pix = mImage.pixel(j, i);
        int red = qRed(pix);
        int green = qGreen(pix);
        int blue = qBlue(pix);

        cRed += red;
        cGreen += green;
        cBlue += blue;
      }
    }
  }

  if (mCloudCount) {

    cRed   /= mCloudCount;
    cGreen /= mCloudCount;
    cBlue  /= mCloudCount;

    mCloudR = cRed;
    mCloudG = cGreen;
    mCloudB = cBlue;

    mData.setCloudLevel( toCloudLevel() );
    mData.setCloudType( toCloudType(cRed, cGreen, cBlue) );
    mData.setSunLevel( toBrighness() );
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
           && (B > 50)
           && (B < 200) )
      || ( (B > R)
           && (B > G)
           && qAbs(B - G) > 7
           && qAbs(B - G) > 7
           && (B > 200)
           && (B < 250) );
}

bool ImageProcessing::isCloud(int R, int G, int B) const {
  bool isSkyHere = isSky(R, G, B);
  bool isCloudHere = false;

  if (isSkyHere) {
    int dist = qSqrt(  (R - mSkyR) * (R - mSkyR)
                     + (G - mSkyG) * (G - mSkyG)
                     + (R - mSkyB) * (R - mSkyB)
                     );

    if (dist > 400) {
      isCloudHere = true;
    }
  } else {
    isCloudHere = (    qAbs(R - G) < 15
                    && qAbs(R - B) < 15
                    && qAbs(G - B) < 15);
  }


  return isCloudHere;
}

int ImageProcessing::toSkyLevel() const {
  int l = (mSkyR + mSkyG + mSkyB) / 3;
  int type[5];
  type[0] = (128 - mSkyR) * (128 - mSkyR) + (149 - mSkyG) * (149 - mSkyG);
  type[1] = (165 - mSkyR) * (165 - mSkyR) + (181 - mSkyG) * (181 - mSkyG);
  type[2] = (192 - mSkyR) * (192 - mSkyR) + (208 - mSkyG) * (208 - mSkyG);
  type[3] = (219 - mSkyR) * (219 - mSkyR) + (230 - mSkyG) * (230 - mSkyG);
  type[4] = (244 - mSkyR) * (244 - mSkyR) + (252 - mSkyG) * (252 - mSkyG);

  int min = type[0];
  int count = 0;
  for (int i = 1; i < 5; i++) {
    if (type[i] < min) {
      min = type[i];
      count = i;
    }
  }

  return (count + 1);
}

int ImageProcessing::toCloudLevel() const {
  double d = (double)mCloudCount / (mCloudCount + mSkyCount);
  qDebug() << d;

  if (d < 0.05) {
    return UnusuallyClear;
  } else if (d < 0.4) {
    return Clear;
  } else if (d < 0.6) {
    return SomewhatHazy;
  } else if (d < 0.95) {
    return VeryHazy;
  }
  return ExtremelyHazy;
}

int ImageProcessing::toCloudType(int R, int G, int B) const {
  int l = (R + G + B) / 3;

  l = 255 - l;
  if (l < 50) {
    return 1;
  } else if (l < 100) {
    return 2;
  } else if (l < 150) {
    return 3;
  } else if (l < 200) {
    return 4;
  }

  return 5;
}

int ImageProcessing::toBrighness() {
  int w = mImage.width();
  int h = mImage.height();

  int hFrom = (h / 3) * 2;

  mBrightness = 0;
  int counter = 0;

  for (int i = hFrom; i < h; i++) {
    for (int j = 0; j < w; j++) {
      QRgb pix = mImage.pixel(j, i);
      int red = qRed(pix);
      int green = qGreen(pix);
      int blue = qBlue(pix);

      if (mIsCloud[i][j] || mIsSky[i][j]) {
        mBrightness += brightness(red, green, blue);
        counter++;
      }
    }
  }

  if (counter) {
    mBrightness /= counter;
  }

  return mBrightness;
}

}  // namespace imProcess
}  // namespace skyCorpusa
