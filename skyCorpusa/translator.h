// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QImage>

#include "general_file_format.h"
#include "data_IO.h"
#include "collection_processing.h"
#include "image_collection.h"

namespace skyCorpusa {

class Translator
{
public:
  Translator();

  void init();

  void loadImage(const QImage& image, int x, int y);
  GeneralFileFormat lastData() const;

  imProcess::ImageCollection collection() const;


private:
  dataIO::DataIO mData;
  CollectionProcessing mCollection;

  GeneralFileFormat mLastData;

  int mCounter;
};

}  // namespace skyCorpusa

#endif // TRANSLATOR_H
