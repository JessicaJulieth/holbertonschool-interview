#ifndef SLIDE_H_
#define SLIDE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);

#endif /* SLIDE_H_ */