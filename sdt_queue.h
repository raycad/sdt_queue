/**
  * @file queue.h
  *
  * @brief A simple queue implementation
  *
  * @author Nguyen Truong Duong
  *
  * @contact email: seedotech@gmail.com
  *
  * @contact Skype: raycadrb
  */
#ifndef __SDT_QUEUE_H__
#define __SDT_QUEUE_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Define the node structure of the queue's element
typedef struct sdt_node {
    void *data; // Data holder
    struct sdt_node *font; // The previous node's pointer
    struct sdt_node *rear;  // The next node's pointer
} sdt_node;

typedef struct sdt_queue {
    int max_queue_size; // The maximum queue's elements
    int size; // The numbers of the queue's elements
    struct sdt_node *first_node; // The first node of the queue
    struct sdt_node *last_node; // The last node of the queue
} sdt_queue;

/**
  * @brief Initializes and allocates a queue with unlimited elements
  *
  * @returns NULL on error, or a pointer to the queue
  */
sdt_queue *sdt_queue_create();

/**
  * @brief Initializes and allocates a queue
  *
  * @param max_elements: maximum number of elements which are allowed in the queue, == 0 for "unlimited"
  *
  * @returns NULL on error, or a pointer to the queue
  */
sdt_queue *sdt_queue_create_limited(int max_elements);

/**
  * @brief Push data pointer to the specific queue
  *
  * @param q: the specific queue
  *
  * @param data: a void pointer to hold the data
  *
  * @returns true if successful, otherwise returns false
  */
bool sdt_queue_put(sdt_queue *q, void *data);

/**
  * @brief Pop an element of the specific queue
  *
  * @param q: the specific queue
  *
  * @returns the data pointer if the queue is not empty, otherwise returns a NULL pointer
  */
void *sdt_queue_get(sdt_queue *q);

/**
  * @brief Check if the specific queue is empty
  *
  * @param q: the specific queue
  *
  * @returns zero if queue is NOT empty, < 0 => error
  */
bool sdt_queue_is_empty(sdt_queue *q);

/**
  * @brief Get the number of the elements of the queue
  *
  * @param q: the specific queue
  *
  * @returns the number of the elements in the queue
  */
int sdt_queue_size(sdt_queue *q);

/**
  * @brief Reset the queue, release the queue memories
  *
  * @param q: the specific queue
  *
  * @returns true if successful, otherwise returns false
  */
bool sdt_queue_clear(sdt_queue *q);

/**
  * @brief Reset the queue, release the queue memories and free the queue also
  *
  * @param q: the specific queue
  *
  * @returns true if successful, otherwise returns false
  */
bool sdt_queue_destroy(sdt_queue *q);

#ifdef __cplusplus
}
#endif
#endif /* __SDT_QUEUE_H__ */
