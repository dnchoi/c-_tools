#ifndef __GST_CAPTURE_READER_H__
#define __GST_CAPTURE_READER_H__

// #include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <pthread.h>
#include <unistd.h>
#include <syscall.h>

class gst_capture_reader
{
private:
    void _read_image_thread(void *arg);
    pthread_mutex_t frameLocker;
    pthread_t UpdThread;    
    bool using_th = false;
    bool thread_exit = false;
    void get_thread();
    bool safe_memcpy(void* data, void* source, int size);

public:
    gst_capture_reader(std::string cmd, bool use_thread);
    ~gst_capture_reader();

    cv::VideoCapture *cap;
    cv::Mat send_mat;    
    cv::Size2d resize_mat;

    void cap_setting(int w, int h);
    bool is_opened();
    void exit_cap();
    void _read_frame(std::string name, cv::Mat &img);

};

#endif // __GST_CAPTURE_READER_H__