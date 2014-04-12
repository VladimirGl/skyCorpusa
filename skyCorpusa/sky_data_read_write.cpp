#include "sky_data_read_write.h"

#include <QDebug>

namespace skyCorpusa {
namespace server {

SkyDataReadWrite::SkyDataReadWrite(const QString& name)
{
  mBase = QSqlDatabase::addDatabase("QSQLITE");
  mBase.setDatabaseName(name);

  QFileInfo checkFile(name);

  if (checkFile.isFile()) {
    if (mBase.open()) {
        qDebug() << "[!] Connected to database - " << name;
    } else {
        qDebug() << "[!] Database not opened";
    }
  } else {
      qDebug() << "[!] Database File does not exist";
  }
}

void SkyDataReadWrite::pushData(imProcess::ImProcessingData data) {
  if (!mBase.isOpen()) {
    qDebug() << "[!] Base not opened";

    bool isOk = false;

    QString str;
    str = "INSERT INTO SkyData VALUES("
          + QString::number(data.skyColor())
          + ", "
          + QString::number(data.cloudLevel())
          + ", "
          + QString::number(data.cloudType())
          + ", "
          + QString::number(data.sunLevel())
          + ")";

    QSqlQuery query;
    isOk = query.exec(str);
  }
}



}  // namespace skyCorpusa
}  // namespace server
