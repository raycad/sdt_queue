/**
  * @file queue.c
  *
  * @brief A simple queue implementation
  *
  * @author Nguyen Truong Duong
  *
  * @contact email: seedotech@gmail.com
  *
  * @contact Skype: raycadrb
  */
#include <stdlib.h>
#include "sdt_queue.h"

#define DEFAULT_MAX_QUEUE_SIZE 1000

bool sdt_release(sdt_queue *q);

sdt_queue *sdt_queue_create()
{
    sdt_queue *q = (sdt_queue *)malloc(sizeof(sdt_queue));
    q->first_node = NULL;
    q->last_node = NULL;
    q->max_queue_size = DEFAULT_MAX_QUEUE_SIZE;
    q->size = 0;
    return q;
}

sdt_queue *sdt_queue_create_limited(int max_elements)
{
    sdt_queue *q = sdt_queue_create();
    if (q != NULL)
        q->max_queue_size = max_elements;
    return q;
}

bool sdt_queue_put(sdt_queue *q, void *data)
{
    if (q->max_queue_size > 0 && q->size >= q->max_queue_size)
        return false;

    sdt_node *new_node = (sdt_node *)malloc(sizeof(sdt_node));
    new_node->data = data;

    if (!q->first_node)
        q->first_node = new_node;

    if (q->last_node)
        q->last_node->rear = new_node;

    new_node->font = q->last_node;
    new_node->rear = NULL;

    q->last_node = new_node;
    q->size++;

    return true;
}

void *sdt_queue_get(sdt_queue *q)
{
    void *data = NULL;
    if (q->first_node) {
        sdt_node *tmp = q->first_node;
        data = tmp->data;
        q->first_node = tmp->rear;
        // Release the node memory
        free(tmp);
        tmp = NULL;
        q->size--;
    }

    return data;
}

bool sdt_queue_is_empty(sdt_queue *q)
{
    return (q->first_node == NULL);
}

int sdt_queue_size(sdt_queue *q)
{
    return q->size;
}

// Release memory
bool sdt_release(sdt_queue *q)
{
    sdt_node *tmp = q->first_node;
    sdt_node *node_it = NULL;
    while (tmp) {
        node_it = tmp;
        tmp = tmp->rear;
        free(node_it);
    }

    return true;
}

bool sdt_queue_clear(sdt_queue *q)
{
    if (!sdt_release(q))
        return false;

    q->size = 0;
    q->first_node = NULL;
    q->last_node = NULL;

    return true;
}

bool sdt_queue_destroy(sdt_queue *q)
{
    if (!sdt_release(q))
        return false;

    free(q);
    q = NULL;

    return true;
}
