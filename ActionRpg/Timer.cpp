#include "Timer.h"

Timer::Timer()
{
	QueryPerformanceFrequency(&_frequency);
}

void Timer::start()
{
	_timestamps.emplace();
	QueryPerformanceCounter(&_timestamps.top()._s);
}

float Timer::stop()
{
	try {
		QueryPerformanceCounter(&_timestamps.top()._e);
		auto timespan = _timestamps.top()._e.QuadPart - _timestamps.top()._s.QuadPart;
		_timestamps.pop();
		return timespan * 1000.f / _frequency.QuadPart;
	}
	catch (...) {
		throw;
	}
}

void Timer::start(const std::string& name)
{
	_mTimestamps[name] = Timestamp();
	QueryPerformanceCounter(&_mTimestamps[name]._s);
}

float Timer::stop(const std::string& name)
{
	try {
		QueryPerformanceCounter(&_mTimestamps[name]._e);
		auto timespan = _mTimestamps[name]._e.QuadPart - _mTimestamps[name]._s.QuadPart;
		_mTimestamps.erase(name);
		return timespan * 1000.f / _frequency.QuadPart;
	}
	catch (...) {
		throw;
	}
}
