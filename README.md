A simple C/C++ queue implementation.

Get source code, build and test:
	$ git clone https://github.com/raycad/sdt_queue.git
	$ cd sdt_queue
	$ make
	$ ./queue_test

Check memory usage using valgrind:
	$ valgrind --tool=memcheck --leak-check=full ./queue_test