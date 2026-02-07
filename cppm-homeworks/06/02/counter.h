#pragma once
class Counter {
private:
	int num;

public:
	Counter() : num(1) {};
	Counter(int num);

	void increment();
	void decrement();
	void print() const;
};