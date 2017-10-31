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
    explicit VisionWorker(QObject *parent = nullptr);
    cv::VideoCapture capture;
private:
    QTimer* m_timer;

signals:
    void imageChanged(QImage);

private slots:
    void updateFrame();
};

#endif // VISIONWORKER_H
