/*
 * main.cpp
 *
 *  Created on: Sep 29, 2024
 *      Author: Megan - School
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx; //protecting the shared data (ready flag)
std::condition_variable cv; //condition variable for thread synchronization
bool ready = false; //flag to indication when counting up is complete

//Function for counting up
void countUp() {
	for (int i = 0; i <= 20; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << "Counting Up: " << i << std::endl; //print current count
	}

	//notify when counting is finished
	{
		std::lock_guard<std::mutex> lock(mtx); //lock the mutex to safely modify the shared flag
		ready = true; //setting the ready flag to true
	}

	//Notifying the condition variable to wake up the waiting thread
	cv.notify_one();
}

//Function for counting down
void countDown() {
	std::unique_lock<std::mutex> lock(mtx); //mutex locked until notified
	cv.wait(lock, [] { return ready; }); //waiting until ready flag is true

	for (int i = 20; i >= 0; --i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << "Counting Down: " << i << std::endl; //print current count
	}
}

int main() {
	//Two threads, one for counting up, the other for counting down
	std::thread thread1(countUp);
	std::thread thread2(countDown);

	thread1.join(); //wait for thread 1 to complete
	thread2.join(); //wait for thread 2 to complete

	return 0;
}


