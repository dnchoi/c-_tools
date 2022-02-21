#include <gst_capture_reader.h>
int j = 0;
gst_capture_reader::gst_capture_reader(std::string cmd, bool use_thread)
{
    cap = new cv::VideoCapture();

    try
    {
        cap->open(cmd);

        using_th = use_thread;

        // this->_read_frame(send_mat);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

gst_capture_reader::~gst_capture_reader()
{
    
}

bool gst_capture_reader::safe_memcpy(void* data, void* source, int size)
{
    if(size < 0) return false;

    memcpy(data, source, (size_t)size);
}

void gst_capture_reader::_read_frame(std::string name, cv::Mat &img)
{
    try
    {
        cv::Mat frame;

        cap->read(frame);
        unsigned dataArraySize = frame.cols * frame.rows * 3;
        // memcpy(img.data, frame.data, dataArraySize);
        // safe_memcpy(frame.data, img.data, dataArraySize);

        img = frame;
        std::cout << name << "\t" << j << std::endl;
        j++;
    }
    catch(const std::exception& e)
    {
        std::cerr << "OpenCV error : " << e.what() << '\n';
    }
    
    
}

void gst_capture_reader::_read_image_thread(void *arg)
{
    // for(;;)
    // {
    //     cv::Mat tempFrame;
    //     cap->read(tempFrame);
 
    //     pthread_mutex_lock(&frameLocker);
    //     frame = tempFrame;
    //     pthread_mutex_unlock(&frameLocker);
    //     if(thread_exit == true)
    //     {
    //         break;
    //     }
    // }
    // printf("[New] value of getpid = %d, syscall(__NR_gettid) = %ld\n", getpid(), syscall(__NR_gettid));
    // exit_cap();
    // pthread_exit( (void *)0 );
}

void gst_capture_reader::get_thread()
{
    // if(using_th)
    // {
    //     std::cout << "Using thread" << std::endl;
    //     pthread_mutex_init(&frameLocker,NULL);  
    //     pthread_create(&UpdThread, NULL, _read_image_thread, NULL);
    // }
}

void gst_capture_reader::cap_setting(int w, int h)
{
    cap->set(cv::CAP_PROP_FRAME_WIDTH, w);
    cap->set(cv::CAP_PROP_FRAME_HEIGHT, h);
}

bool gst_capture_reader::is_opened()
{
    return cap->isOpened();
}

void gst_capture_reader::exit_cap()
{
    cap->release();
}