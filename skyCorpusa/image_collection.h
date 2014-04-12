// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef IMAGE_COLLECTION_H
#define IMAGE_COLLECTION_H

#include <QList>
#include <QImage>

#include "im_processing_data.h"

namespace skyCorpusa {
namespace imProcess {

class ImageCollection
{
public:
  ImageCollection();

  void addImage(const QImage& im, const ImProcessingData& proc, int aData);

  int length() const { return mCollection.length(); }

  QImage image(int num) const;
  ImProcessingData data(int num) const;
  int aeroData(int num) const;

private:
  QList<QImage> mCollection;

  QList<ImProcessingData> mProcesssingData;
  QList<int> mAeroData;
};

}  // namespace imProcess
}  // namespace skyCorpusa

#endif // IMAGE_COLLECTION_H
