// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include <QDebug>

#include "image_processing.h"

#include <QRgb>
#include <QColor>

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

  int w = mImage.width();
  int h = mImage.height();

  int hFrom = (h / 3) * 2;

  int skyCount = 0;
  int cloudCount = 0;
  for (int i = hFrom; i < h; i++) {
    for (int j = 0; j < w; j++) {
      QRgb pix = mImage.pixel(j, i);
      int red = qRed(pix);
      int green = qGreen(pix);
      int blue = qBlue(pix);

      mIsSky[i][j] = isSky(red, green, blue);
      mIsCloud[i][j] = isCloud(red, green, blue);
      if (mIsSky[i][j]) { skyCount++; }
      if (mIsCloud[i][j]) { cloudCount++; }
    }
  }

  int sRed = 0;
  int sGreen = 0;
  int sBlue = 0;

  int cRed = 0;
  int cGreen = 0;
  int cBlue = 0;

  int bright = 0;

  for (int i = hFrom; i < h; i++) {
    for (int j = 0; j < w; j++) {
      QRgb pix = mImage.pixel(j, i);
      int red = qRed(pix);
      int green = qGreen(pix);
      int blue = qBlue(pix);

      if (mIsSky[i][j]) {
        sRed += red;
        sGreen += green;
        sBlue += blue;
        bright += brightness(red, green, blue);
      }

      if (mIsCloud[i][j]) {
        cRed += red;
        cGreen += green;
        cBlue += blue;
        bright += brightness(red, green, blue);
      }
    }
  }

  if (skyCount && cloudCount) {
    bright /= (skyCount + cloudCount);

    sRed   /= skyCount;
    sGreen /= skyCount;
    sBlue  /= skyCount;

    cRed   /= cloudCount;
    cGreen /= cloudCount;
    cBlue  /= cloudCount;



    QColor color;
    color.setRed(sRed);
    color.setGreen(sGreen);
    color.setBlue(sBlue);
    QColor color2;
    color2.setRed(cRed);
    color2.setGreen(cGreen);
    color2.setBlue(cBlue);
    qDebug() << skyCount << " " << color.name();
    qDebug() << cloudCount << " " << color2.name();
    double quantee = (double)cloudCount / (cloudCount + skyCount);
    qDebug() << (double)quantee;
    qDebug() << bright;
  }

}

int ImageProcessing::brightness(int R, int G, int B) const {
  return ( 0.299 * R + 0.587 * G + 0.113 * B );
}

bool ImageProcessing::isSky(int R, int G, int B) const {
  return ( ((qAbs(R - (G / 2)) < 10) || (qAbs(R -G) < 10))
           && (B > R)
           && (B > G)
           && (B > 50) );
}

bool ImageProcessing::isCloud(int R, int G, int B) const{
  return ( (qAbs(R - G) < 10)
           && (qAbs(B - G) < 10)
           && (qAbs(R - B) < 10) );
}

}  // namespace imProcess
}  // namespace skyCorpusa
