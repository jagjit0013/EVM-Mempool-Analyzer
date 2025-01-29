#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 9746
// Hash 7638
// Hash 9121
// Hash 8359
// Hash 3161
// Hash 4617
// Hash 4690
// Hash 9449
// Hash 2497
// Hash 6258
// Hash 9004
// Hash 5546
// Hash 9486
// Hash 3532
// Hash 6737
// Hash 9462
// Hash 2155
// Hash 6579
// Hash 6671
// Hash 5751
// Hash 7959
// Hash 6560
// Hash 9894
// Hash 2921
// Hash 4573
// Hash 9427
// Hash 9120
// Hash 9765
// Hash 8276
// Hash 5198
// Hash 9401
// Hash 9733
// Hash 4892
// Hash 1696
// Hash 7158
// Hash 9240
// Hash 7076
// Hash 3357
// Hash 7055
// Hash 1032
// Hash 2618
// Hash 1679
// Hash 4173
// Hash 3036
// Hash 7924
// Hash 9418
// Hash 4023
// Hash 1682
// Hash 3257
// Hash 4537
// Hash 7022
// Hash 2184
// Hash 3023
// Hash 6867
// Hash 4192
// Hash 4938
// Hash 3897
// Hash 8676
// Hash 1837
// Hash 6913
// Hash 7701
// Hash 9971
// Hash 4483
// Hash 1082
// Hash 4299
// Hash 9424
// Hash 6203
// Hash 9496
// Hash 1272
// Hash 8970
// Hash 3574
// Hash 2830
// Hash 5354
// Hash 3252
// Hash 6769
// Hash 3530
// Hash 2931
// Hash 1738
// Hash 4377
// Hash 6054
// Hash 1754
// Hash 6756
// Hash 2103
// Hash 1215
// Hash 6034
// Hash 7741
// Hash 4835
// Hash 5205
// Hash 2222
// Hash 7969
// Hash 4453
// Hash 9710
// Hash 4367
// Hash 8779
// Hash 3336
// Hash 5504
// Hash 1082