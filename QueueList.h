#ifndef QUEUE_QUEUELIST_H
#define QUEUE_QUEUELIST_H

#include <iostream>
#include "Queue.h"

template <class T>
class QueueList final : public Queue<T>
{
public:
  QueueList();
	virtual ~QueueList();
	void enQueue(const T& e) override;
	T& deQueue() override;
	bool isEmpty() override;
	void out() const;
private:
	template <class T>
	class Node
	{
	public:
		T data_;
		Node* next_;
	};
	Node<T>* head_;
	Node<T>* tail_;
};

template <class T>
QueueList<T>::QueueList(): head_(nullptr), tail_(nullptr) {}

template<class T>
QueueList<T>::~QueueList()
{
	Node<T>* temp = head_;

	while(temp)
	{
		temp = head_->next_;
		delete head_;
		head_ = temp;
	}
}

template<class T>
void QueueList<T>::enQueue(const T & e)
{
	Node<T>* temp = new Node<T>;
	temp->data_ = e;
	temp->next_ = nullptr;

	if(head_)
	{
		tail_->next_ = temp;
		tail_ = temp;
	}
	else
	{
		head_ = tail_ = temp;
	}
}

template<class T>
T& QueueList<T>::deQueue()
{
	if (!head_)
		throw QueueUnderflow();

	Node<T>* temp = head_;
	T data = head_->data_;
	head_ = head_->next_;
	delete temp;
	return data;
}

template<class T>
bool QueueList<T>::isEmpty()
{
	return !head_;
}

template<class T>
void QueueList<T>::out() const
{
	Node<T>* temp = head_;
	while(temp)
	{
		std::cout << temp->data_ << " ";
		temp = temp->next_;
	}
	std::cout << "\n";
}

#endif //! QUEUE_QUEUELIST_H