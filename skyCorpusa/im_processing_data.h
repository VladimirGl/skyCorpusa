// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef IM_PROCESSING_DATA_H
#define IM_PROCESSING_DATA_H

namespace skyCorpusa {
namespace imProcess {

class ImProcessingData
{
public:
  ImProcessingData() :
    mSkyColor(0),
    mCloudLevel(0),
    mCloudType(0),
    mSunLevel(0)
  {}

  void setSkyColor(int color) { mSkyColor = color; }
  void setCloudLevel(int level) { mCloudLevel = level; }
  void setCloudType(int type) { mCloudType = type; }
  void setSunLevel(int level) { mSunLevel = level; }

  int skyColor() const { return mSkyColor; }
  int cloudLevel() const { return mCloudLevel; }
  int cloudType() const { return mCloudType; }
  int sunLevel() const { return mSunLevel; }

private:
  int mSkyColor;
  int mCloudLevel;
  int mCloudType;
  int mSunLevel;
};

}  // namespace imProcess
}  // namespace skyCorpusa

#endif // IM_PROCESSING_DATA_H
