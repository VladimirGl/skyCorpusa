// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QImage>

#include "aeronet_data_type.h"
#include "im_processing_data.h"
#include "data_IO.h"
#include "collection_processing.h"
#include "image_collection.h"

namespace skyCorpusa {

class translator
{
public:
  translator();

  void loadImage(const QImage& image);
  AERONETDataType lastImageData() const;

  imProcess::ImageCollection collection() const;


private:
  dataIO::DataIO mData;
  CollectionProcessing mCollection;
};

}  // namespace skyCorpusa

#endif // TRANSLATOR_H
