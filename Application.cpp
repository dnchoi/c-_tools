/**
 * @file main.cpp
 * @author dongnyeok choi (luke.dn.choi@funzin.co.kr)
 * @brief Vision controller test code 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief It is main loop
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

#include <obj.h>
#include <gst_capture_reader.h>
#include <ThreadPool.h>

auto sum_num(auto a, auto b)
{
    return a + b;
}

void work(int t, int id) 
{
    cout << id << " start" << endl;
    this_thread::sleep_for(chrono::seconds(t));
    cout << id << " end after " << t << "s\n" << endl;
}

int main(int argc, char *argv[])
{
    Object_D *OD;
    OD = new Object_D();

    gst_capture_reader *capture;
    std::string cmd = "v4l2src device=/dev/video0 ! video/x-raw,format=YUY2,width=640,height=480,framerate=30/1 ! videoconvert ! appsink";
    capture = new gst_capture_reader(cmd, false);
    if(capture->is_opened()){
        Fz_ThreadPool::ThreadPool *pool = new Fz_ThreadPool::ThreadPool(1000);
        cv::Mat img;
        for(;;)
        {
            pool->EnqueueJob([&](){ capture->_read_frame("thread-1", img);} );
            if(cv::waitKey(1) == 'q')
                break;
            if(img.rows != 0){
                cv::imshow("", img);
            }
            else{
                std::cout << "frame is not loaded\n";
            }
        }
    }
    // if(capture->is_opened())
    // {
        // cv::Mat img;
    //     for(;;)
    //     {
    //         // capture->_read_frame(img);
    //         pool->EnqueueJob([&](){ capture->_read_frame(img);} );
    //         if(cv::waitKey(1) == 'q')
    //             break;
    //         // cv::imshow("", img);
    //         // for(int i = 0; i < 100; i++)
    //         // {
    //         //     OD->say_hello(sum_num(i, i+10));
    //         // }

    //     }
    // }
    // Fz_ThreadPool::ThreadPool pool(3);

    // for (int i = 0; i < 10; i++) 
    // {
    //     pool->EnqueueJob([i]() { work(i % 3 + 1, i); });
    // }
    return 0;
}