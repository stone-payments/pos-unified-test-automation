#ifndef VISIONWORKER_H
#define VISIONWORKER_H

#include <QObject>
#include <QTimer>
#include <QImage>

//#include <opencv2/opencv.hpp>
#include "printercontroller.h"
#include "posobject.h"

class VisionWorker : public QObject
{
    Q_OBJECT
public:

    /** Singleton implementation **/
    static VisionWorker& instance()
    {
        static VisionWorker instance;
        return instance;
    }
    /******************************/

    QPointF getKeyPosition(QString key);

    void calibrate();
    void getBaseOrigin();
    void getPosOrigin();

    QImage frame_1;
    void setDevice(PosObject *device);
private:
    /** Singleton implementation **/
    VisionWorker();
    VisionWorker (VisionWorker const&);
    VisionWorker& operator=(VisionWorker const&);

    QTimer* m_timer;
//    cv::VideoCapture capture;
//    cv::Mat m_lastFrame;

    const QPoint printerVisionPosition = QPoint(50, 210);
    QPoint m_baseOrigin;
    PosObject* m_device;
    qreal m_pixelMmRatio;
signals:
    void imageChanged(QImage);

private slots:
    void updateFrame();
};

#endif // VISIONWORKER_H
