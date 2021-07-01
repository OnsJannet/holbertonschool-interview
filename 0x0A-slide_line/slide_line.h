#ifndef SLIDE_H
#define SLIDE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void moving_left(int *line, size_t size);
void moving_right(int *line, size_t size);

#endif