std::mutex mtx1, mtx2;

void threadA(){
    std::lock_guard<std::mutex> lock(mtx1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock(mtx2);
}


void threadB(){
    std::lock_guard<std::mutex> lock(mtx2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock(mtx1);
}