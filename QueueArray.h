#ifndef QUEUE_QUEUEARRAY_H
#define QUEUE_QUEUEARRAY_H

#include "Queue.h"

template <class T>
class QueueArray final : public Queue<T>
{
public:
	QueueArray(int size = 100);
	QueueArray(const QueueArray<T>& src);
	virtual ~QueueArray() { delete[] array_; }
	void enQueue(const T& e) override;
	T& deQueue() override;
	bool isEmpty() override { return head_ == tail_; }
	void out();
private:
	T* array_;
	int head_ = 1;
	int tail_ = 1;
	int size_;
};

template<class T>
QueueArray<T>::QueueArray(int size)
{
	try
	{
		array_ = new T[size_ = size + 1];
	}
	catch (...)
	{
		throw WrongQueueSize();
	}
	head_ = 1;
	tail_ = 1;
}

template<class T>
QueueArray<T>::QueueArray(const QueueArray<T> & src)
{
	try
	{
		array_ = new T[size_ = src.size_];
	}
	catch (...)
	{
		throw WrongQueueSize();
	}
  head_ = src.head_;
	tail_ = src.tail_;

	for (size_t i = 1; i <= abs(head_ - tail_); i++)
	{
		array_[i] = src.array_[i];
	}
}

template<class T>
void QueueArray<T>::enQueue(const T & e)
{
	if (head_ == tail_ + 1)
		throw QueueOverflow();
	
	array_[tail_] = e;
  tail_++;
}

template<class T>
T& QueueArray<T>::deQueue()
{
	if (head_ == tail_)
		throw QueueUnderflow();

	return array_[head_++];
}

template<class T>
void QueueArray<T>::out()
{
	for (size_t i = head_; i < tail_; i++)
		std::cout << array_[i] << " ";
}

#endif //! QUEUE_QUEUEARRAY_H