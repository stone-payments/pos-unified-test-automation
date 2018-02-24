#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include <QKeyEvent>
#include <QObject>

#include "posobject.h"
#include "printercontroller.h"

class KeyboardController : public QObject {
  Q_OBJECT
 public:
  explicit KeyboardController(QObject *parent = nullptr);

  void write(QString phrase);

  void keyPress(QString key);

  void setDevice(PosObject *device);

 private:
  PrinterController *m_printerControllerInstance;
  PosObject *m_device;

  const int m_safeZPosition = 5;
};

#endif  // KEYBOARDCONTROLLER_H
