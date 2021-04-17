#include "MyUtils.h"

#include <chrono>
#include <thread>

void myUtils::sleep(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}