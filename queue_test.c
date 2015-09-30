#include <stdio.h>
#include <stdlib.h>
#include "sdt_queue.h"
#include <string.h>

void display_queue_elements(sdt_queue *queue)
{
	int queue_size = sdt_queue_size(queue);
	printf("There are %d elements in the queue:\n", queue_size);
	while (!sdt_queue_is_empty(queue)) {
		int *int_tmp = sdt_queue_get(queue);
		if (int_tmp) {
			printf("%d ", *int_tmp);

			// Release element's memory
			free(int_tmp);
		}
	}
}

void input_normal_queue()
{
	sdt_queue *queue = NULL;
	queue = sdt_queue_create();	

	int i = 0;
	for (; i < 10; i++) {
		int *data = (int *)malloc(sizeof(int));
		*data = i+1;
		if (!sdt_queue_put(queue, data))
			free(data);
	}

	// Display all elements of the queue
	display_queue_elements(queue);

	// Destroy the queue
	sdt_queue_destroy(queue);
}

void input_limited_queue(int max_elements)
{
	sdt_queue *queue = NULL;
	queue = sdt_queue_create_limited(max_elements);	

	int i = 0;
	for (; i < max_elements + 10; i++) {
		int *data = (int *)malloc(sizeof(int));
		*data = i+1;
		if (!sdt_queue_put(queue, data))
			free(data);
	}

	// Display all elements of the queue
	display_queue_elements(queue);

	// Destroy the queue
	sdt_queue_destroy(queue);
}

int main()
{
	printf("Queue options:\n");		
	printf("Enter 1 to create a normal queue\n");
	printf("Enter 2 to create a limited queue\n");
	printf("Enter 3 to quit the application\n");
	
	int option = 0;
	while (option != 3) {
		printf("Please select a queue option:\n");
		scanf("%d", &option);

		if (option == 3)
			break;

      	if (option == 1) {
			input_normal_queue();
			printf("\n");
		} else if (option == 2) {
			input_limited_queue(8);
			printf("\n");
		} else
			break;
	}

	return 0;
}