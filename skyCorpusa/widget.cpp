// Copyright (c) 2014 The Caroline authors. All rights reserved.
// Use of this source file is governed by a MIT license that can be found in the
// LICENSE file.
// Author: Glazachev Vladimir <glazachev.vladimir@gmail.com>

#include "widget.h"
#include "ui_widget.h"

#include "image_reader.h"

#include <QPixmap>

Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  QTime now = QTime::currentTime();
  qsrand(now.msec());

  colors.prepend("#8095ff");
  colors.prepend("#a5b5ff");
  colors.prepend("#c0d0ff");
  colors.prepend("#dbe6ff");
  colors.prepend("#f4fcff");

  QList<QString> cloudLevel;
  QList<QString> skyType;

  cloudLevel.prepend("Unusually clear");
  cloudLevel.prepend("Clear");
  cloudLevel.prepend("Somewhat Haze");
  cloudLevel.prepend("Very Hazy");
  cloudLevel.prepend("Extremaly Hazy");

  skyType.prepend("Deep blue");
  skyType.prepend("Blue");
  skyType.prepend("Light blue");
  skyType.prepend("Pale blue");
  skyType.prepend("Milky");

  ui->setupUi(this);

  translator.init();
  QString path;
  path = "/home/rayman/Downloads/sky_corpusa/images/sky_" + QString::number(qrand() % 7 + 1) + ".jpg";
  qDebug() << path;

  skyCorpusa::ImageReader reader;
  reader.setPath(path);
  reader.image();

  translator.loadImage(reader.image(), 15, 13);

  QPixmap im;
  im.convertFromImage(reader.image());
  im.scaledToHeight(280);
  im.scaledToWidth(300);
  ui->label->setScaledContents(true);
  ui->label->setPixmap(im);

  QColor sky = translator.sky();  
  QColor cloud = translator.cloud();

  QString style = "background: rgb(%1, %2, %3);";
  ui->label_4->setStyleSheet(style.arg(sky.red()).arg(sky.green()).arg(sky.blue()));

  ui->label_6->setStyleSheet(style.arg(cloud.red()).arg(cloud.green()).arg(cloud.blue()));

  qDebug() << translator.lastData().cl1();
  ui->text1->setText("Cloud level : " + cloudLevel.at( 5 - translator.lastData().cl1()));
  ui->text2->setText("Sky type : " + skyType.at( 5 - translator.lastData().sky()));
  ui->text3->setText("Nearest city : " + translator.lastData().city());
  ui->text4->setText("AOT Level : " + QString::number(translator.lastData().aot()));

}

Widget::~Widget()
{
  delete ui;
}
