#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <exception>

template <class T>
class Queue
{
public:
	virtual ~Queue() = default;;
	virtual void enQueue(const T& e) = 0;
	virtual T& deQueue() = 0;
	virtual bool isEmpty() = 0;
};

class QueueOverflow : public std::exception
{
public:
	QueueOverflow() : reason("Queue Overflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

class QueueUnderflow : public std::exception
{
public:
	QueueUnderflow() : reason("Queue Underflow") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize() : reason("Wrong Queue Size") {}
	const char* what() const { return reason; }
private:
	const char* reason;
};

#endif // !QUEUE_QUEUE_H