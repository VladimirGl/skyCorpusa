// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT
  
public:
  explicit Widget(QWidget *parent = 0);
  ~Widget();
  
private:
  Ui::Widget *ui;
};

#endif // WIDGET_H
