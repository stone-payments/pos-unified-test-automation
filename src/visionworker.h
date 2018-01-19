#ifndef VISIONWORKER_H
#define VISIONWORKER_H

#include <QObject>
#include <QTimer>
#include <QImage>

#include <opencv2/opencv.hpp>

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
private:
    /** Singleton implementation **/
    VisionWorker();
    VisionWorker (VisionWorker const&);
    VisionWorker& operator=(VisionWorker const&);
    /******************************/
    QTimer* m_timer;

    cv::VideoCapture capture;
signals:
    void imageChanged(QImage);

private slots:
    void updateFrame();
};

#endif // VISIONWORKER_H
