#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <uchar.h>
#include <unistd.h>

static char const *const letters[] = {
	u8"נ",
	u8"ג",
	u8"ה",
	u8"ש"
};

int main(int argc, char *argv[]) {
	int ret = EXIT_FAILURE;

	int fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0) {
		perror("open");
		goto exit;
	}

	uint8_t rnd;
	if (read(fd, &rnd, sizeof rnd) < sizeof rnd) {
		perror("read");
		goto exit;
	}

	puts(letters[rnd & 3]);

	ret = EXIT_SUCCESS;

exit:
	return ret;
}
