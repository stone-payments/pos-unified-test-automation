#include <QImage>
#include "visionworker.h"
#include "printercontroller.h"

//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdlib.h>

#include <chrono>
#include <thread>

#include <iostream>

QPointF VisionWorker::getKeyPosition(QString)
{
    return QPointF(0,0);
}

VisionWorker::VisionWorker() :
    m_timer(new QTimer(this))
{
    // Default webcam
//    capture.open(0);
//    m_timer->start(100); // 60fps

    connect(m_timer, &QTimer::timeout, this, &VisionWorker::updateFrame);
}

void VisionWorker::calibrate()
{
//    PrinterController::instance().moveZ(10);
//    PrinterController::instance().setXYPosition(printerVisionPosition);
//    updateFrame();
//    getBaseOrigin();
//    getPosOrigin();
}

void VisionWorker::getBaseOrigin()
{
//    cv::Mat frame;
//    cv::cvtColor( m_lastFrame, m_lastFrame, CV_BGR2HSV);
//    cv::Rect coin_roi(m_lastFrame.cols*.80, m_lastFrame.rows*.5, m_lastFrame.cols*.15, m_lastFrame.rows*.25);

//    cv::Mat frame_threshold;
//    cv::Mat frame_roi = m_lastFrame(coin_roi);
//    cv::GaussianBlur(frame_roi, frame_roi, cv::Size(9, 9), 0);

//    // Detect the object based on RGB Range Values
//    cv::inRange(frame_roi,cv::Scalar(0,150,0), cv::Scalar(255,255,255),frame_threshold);

//    std::vector<std::vector<cv::Point>> contours;
//    std::vector<cv::Vec4i> hierarchy;
//    cv::findContours(frame_threshold, contours, hierarchy,  CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );

//    cv::Point center_of_rect;
//    if(contours.size() > 0)
//    {
//        cv::Rect r = cv::boundingRect(contours[0]);
//        cv::rectangle(frame_roi, r, cv::Scalar(0,0,255), 2);

//        center_of_rect = (r.br() + r.tl())*0.5;



//        m_baseOrigin = QPoint(center_of_rect.x, center_of_rect.y);
//        m_pixelMmRatio = r.width/19.;

//        center_of_rect.x += coin_roi.x - 26*m_pixelMmRatio - (m_device->m_width*m_pixelMmRatio);
//        center_of_rect.y += coin_roi.y + 150;
//        cv::circle(m_lastFrame,center_of_rect,1,cv::Scalar(0,0,255),5);

//    foreach (KeyMap key, m_device->m_keyboardMap) {
//        cv::Point keyPosition(center_of_rect.x + key.position.x()*m_pixelMmRatio, center_of_rect.y - key.position.y()*m_pixelMmRatio);
//        cv::circle(m_lastFrame,keyPosition,1,cv::Scalar(0,255,0), 5);
//    }

//    cv::imshow("asdasd", m_lastFrame);
//    cv::imshow("thresholf", frame_threshold);
//    }
}

void VisionWorker::getPosOrigin()
{

}

void VisionWorker::setDevice(PosObject *device)
{
    m_device = device;
}

void VisionWorker::updateFrame()
{
//    capture >> m_lastFrame;
//    getBaseOrigin();

//    cv::Mat frameRgb;
//    // Convert cv::Mat to QImage so we can display it in graphics view
//    cv::cvtColor(m_lastFrame, frameRgb,CV_BGR2RGB);
//    QImage image((const uchar *) frameRgb.data, frameRgb.cols, frameRgb.rows, frameRgb.step, QImage::Format_RGB888);

//    //getBaseOrigin();
//    emit imageChanged(image);
}

