#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include <assert.h>

template <typename T>
struct Node {
	T data;
	Node *next;
};

template <typename T>
struct Queue {
	Node<T> *node;
	uint32_t capacity;
};

template <typename T>
struct Queue<T> *init_with_capacity(uint32_t capacity);

template <typename T>
struct Node<T> *deque(struct Queue<T> *queue);

template <typename T>
struct Node<T> *deque(struct Node<T> *node, uint32_t count);

template <typename T>
void enque(struct Queue<T> *queue, T val);

template <typename T>
bool is_empty(struct Queue<T> *queue);

template <typename T>
void drop(struct Queue<T> *queue);

template <typename T>
void drop(struct Node<T> *node);

template <typename T>
void print(struct Queue<T> *queue);

template <typename T>
void print(struct Node<T> *node, uint32_t i);

int main(void)
{
	struct Node<int> *last = NULL;
	struct Queue<int> *queue = init_with_capacity<int>(2);
	printf("queue initial state:\n");
	print(queue);
	printf("-----------------------\n");
	printf("dequing last element.\n");
	last = deque(queue);
	free(last);
	printf("updated queue:\n");
	print(queue);
	printf("-----------------------\n");
	printf("dequing last element.\n");
	last = deque(queue);
	printf("updated queue:\n");
	print(queue);
	if (is_empty(queue))
		printf("queue is empty.\n");
	free(last);
	printf("-----------------------\n");
	printf("enquing '8' to queue.\n");
	enque(queue, 8);
	printf("updated queue:\n");
	print(queue);
	drop(queue);
	return 0;
}

template <typename T>
struct Queue<T> *init_with_capacity(uint32_t capacity)
{
	struct Node<T> *prev = NULL;
	struct Node<T> *curr = NULL;
	for (uint32_t i = 0; i < capacity; i++)
	{
		curr = (struct Node<T> *)malloc(sizeof(struct Node<T>));
		if (curr)
		{
			curr->data = 0;
			curr->next = prev;
		}
		prev = curr;
	}
	struct Queue<T> *queue = (struct Queue<T> *)malloc(sizeof(struct Queue<T>));
	if (queue)
	{
		queue->node = curr;
		queue->capacity = capacity;
	}
	return queue;
}

template <typename T>
struct Node<T> *deque(struct Queue<T> *queue)
{
	assert(queue->capacity > 0);
	struct Node<T> *second_last = deque(queue->node, queue->capacity-1);
	struct Node<T> *last = deque(queue->node, queue->capacity);
	if (second_last == NULL) // queue has one element
		queue->node = NULL;
	else
		second_last->next = NULL;
	queue->capacity--;
	return last;
}

template <typename T>
struct Node<T> *deque(struct Node<T> *node, uint32_t count)
{
	if (count == 0)
		return NULL;
	if (count == 1)
		return node;
	if (count == 2)
		return node->next;
	return deque(node->next, count-1);
}

template <typename T>
void enque(struct Queue<T> *queue, T val)
{
	struct Node<T> *new_node = (struct Node<T> *)malloc(sizeof(struct Node<T>));
	if (new_node)
	{
		new_node->data = val;
		new_node->next = queue->node;
		queue->node = new_node;
		queue->capacity++;
	}
}

template <typename T>
bool is_empty(struct Queue<T> *queue)
{
	return !queue->node;
}

template <typename T>
void drop(struct Queue<T> *queue)
{
	drop(queue->node);
	free(queue);
}

template <typename T>
void drop(struct Node<T> *node)
{
	if (node)
	{
		drop(node->next);
		free(node);
	}
}

template <typename T>
void print(struct Queue<T> *queue)
{
	if (queue)
	{
		print(queue->node, 0);
	}
}

template <typename T>
void print(struct Node<T> *node, uint32_t i)
{
	if (node)
	{
		printf("Node %d: %d\n", i, node->data);
		print(node->next, ++i);
	}
}

