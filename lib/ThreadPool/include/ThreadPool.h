#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using namespace std;

namespace Fz_ThreadPool{
class ThreadPool 
{
public:
    ThreadPool(size_t num_threads);
    ~ThreadPool();

    void EnqueueJob(function<void()> job);      // job 을 추가한다.

private:
    size_t num_threads_;                        // 총 Worker 쓰레드의 개수.
    vector<thread> worker_threads_;             // Worker 쓰레드를 보관하는 벡터.
    queue<function<void()>> jobs_;              // 할일들을 보관하는 job 큐.
    condition_variable cv_job_q_;               // 위의 job 큐를 위한 cv 와 m.
    mutex m_job_q_;

    bool stop_all;                              // 위의 job 큐를 위한 cv 와 m.

    void WorkerThread();                        // Worker 쓰레드
};
}
#endif // __THREAD_POOL_H__

