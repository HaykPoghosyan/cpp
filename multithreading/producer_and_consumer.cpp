
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

bool canSale = false;

bool canProduce = false;

condition_variable cv;

mutex mtx;

class Buffer {
	int arr[5] = { 0,0,0,0,0 };
public:
	void put() {
		for (int i = 0; i < 5; i++) {
			if (arr[i] == 1) {
				continue;
			}
			else {
				arr[i] = 1;
				break;
			}
		}
	}
	void take() {
		for (int i = 0; i < 5; i++) {
			if (arr[i] == 0) {
				continue;
			}
			else {
				arr[i] = 0;
				break;
			}
		}
	}
	void show() {
		for (int i = 0; i < 5; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
	int size() {
		int size = 0;
		for (int i = 0; i < 5; i++) {
			size = size + arr[5];
		}
		return size;
	}
} buf;


void produce(){
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(5000));
		if (buf.size() < 5) {
			canProduce = true;
		}
		else {
			canProduce = false;
		}
		{
			unique_lock <mutex> lck(mtx);
			cv.wait(lck, []() {return canProduce; });
		}
		{
			mtx.lock();
			buf.put();
			buf.show();
			cout << "produce " << endl;
			canSale = true;
			mtx.unlock();
		}
		cv.notify_all();
	}
}

void consume() {
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(5000));
		if (buf.size() > 0 ) {
			canSale = true;
		}
		else {
			canSale= false;
		}
		{
			unique_lock <mutex> lck(mtx);
			cv.wait(lck, []() {return canSale; });
		}
		{
			mtx.lock();
			buf.take();
			buf.show();
			cout << "consume " << endl;
			canProduce = true;
			mtx.unlock();
		}
		cv.notify_all();
	}
}

int main()
{
	thread td(produce);

	thread td2(consume);

	buf.show();

	td.join();
	td2.join();

    return 0;
}

