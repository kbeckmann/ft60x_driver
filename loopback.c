#include <stdio.h>
#include <event2/event.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

uint32_t last_sec = 0;
uint64_t bytes_out = 0;
uint64_t bytes_in = 0;

void udp_callback(int fd, short event, void *arg)
{
	int val;

	static uint16_t buf[40960];
	printf("GOT EVENT...\n");
	printf("read(\n");
	val = read(fd, buf, 40960);
	printf(")\n");
	bytes_in += val;

	// enable for SPAM
	printf("GOT EVENT %d!\n", val);
#if 0
	for (int x = 0; x < val/2; x++) {
		printf("%04x ", buf[x]);
		// if (x % 16 == 0)
			// printf("\n");
	}
	printf("\n");
#endif

	printf("write(\n");
	if (val > 0)
		bytes_out += write(fd, buf, val);
		// bytes_out += write(fd, buf, val);
	printf(")\n");

    struct timeval tv;
	gettimeofday(&tv, NULL);
	if (tv.tv_sec != last_sec) {
		last_sec = tv.tv_sec;
		printf("IN: %llu B/s, OUT: %llu B/s\n", bytes_in, bytes_out);
		printf("IN: %llu Mbytes/s, %llu Mbytes/s\n", bytes_in / 1024 / 1024, bytes_out / 1024 / 1024);
		bytes_in = 0;
		bytes_out = 0;
	}
}

int main(int argc, char **argv)
{
	struct event_base *base;
	struct event *ev;

	int in;
	unsigned char *buf;
	int i;

	if (argc != 2) {
		printf("Usage %s </dev/ft60x?>\n", argv[0], argv[1]);
		return 1;
	}

	buf = malloc(128 * 1024);

	for (i = 0; i < 128 * 1024; i++) {
		// buf[i] = 'A' + (i % 64);
		buf[i] = '\xAA';
	}

	in = open(argv[1], O_RDWR | O_CLOEXEC);

	base = event_base_new();
	if (!base) {
		return 1;
	}

	ev = event_new(base, in, EV_READ | EV_PERSIST, &udp_callback, NULL);
	event_add(ev, NULL);

	printf("Before write\n");
	write(in, buf, 2);
	// write(in, buf, 2048);
	// write(in, buf, 2048);
	// write(in, buf, 2048);
	// write(in, buf, 2048);
	printf("After write\n");
	udp_callback(in, 0, 0); //fake

#if 0
    struct timeval tv;
	uint32_t last_sec = 0;
	uint64_t bytes = 0;
	while (1) {
		write(in, buf, 2048);
		bytes += 2048;

	    gettimeofday(&tv, NULL);
		if (tv.tv_sec != last_sec) {
			last_sec = tv.tv_sec;
			printf("%llu bytes/s\n", bytes);
			printf("%llu Mbytes/s\n", bytes / 1024 / 1024);
#	if 0
	char *buf = malloc(1024 * 128);
	int val = read(in, buf, 1);
	printf("GOT EVENT %d!\n", val);
#	endif
			bytes = 0;
		}
	}
#endif
	event_base_dispatch(base);
	event_base_free(base);

	return 0;
}
