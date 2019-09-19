#include <iostream>
#include <chrono>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() : duration()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "took:" << ms << " ms\n";
	}

};

int Fib(int val)
{
	if (val == 0)
		return 0;
	else if (val == 1)
		return 1;
	else
		return (Fib(val - 1) + Fib(val - 2));
}

void Fibonacci(int val)
{
	Timer t;
	std::cout << "Fib(" << val << "):" << Fib(val) << " ";
}

int main()
{
	std::cout << "Hello Fibonacci!\n\n";

	for (int i = 0; i < 40; i++)
	{
		Fibonacci(i);
		std::cout << std::endl;
	}

	std::cin.get();
}

