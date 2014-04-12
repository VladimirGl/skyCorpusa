// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QImage>

namespace skyCorpusa {

class translator
{
public:
  translator();

  void loadImage(const QImage& image);

};

}  // namespace skyCorpusa

#endif // TRANSLATOR_H
