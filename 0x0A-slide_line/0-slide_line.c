#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"


/**
 * slide_line - slides and merges a line either left or right
 * @line: input array
 * @size: size of the int array
 * @direction: direction to slide
 * Return: 0 on failure, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction != 0 && direction != 1)
        return (0);
    if (line == NULL || size < 1)
        return (0);
    if (direction == 0)
        moving_left(line, size);
    if (direction == 1)
        moving_right(line, size);
    return (1);
}

/**
 * moving_left - slides a line to the left
 * @line: input array
 * @size: size of array
 */
void moving_left(int *line, size_t size)
{
    int i = 0, j, previous = 0, current;

    for (j = 0; j < (int)size; j++)
    {
        current = line[j];
        if (!current)
            continue;
        if (!previous)
            previous = current;
        else if (previous == current)
        {
            line[i++] = current << 1;
            previous = 0;
        } else
        {
            line[i++] = previous;
            previous = current;
        }
    }
    if (previous)
        line[i++] = previous;
    while (i < (int)size)
        line[i++] = 0;
}

/**
 * tothe_right - slides a line to the right
 * @line: input array
 * @size: size of array
 */
void moving_right(int *line, size_t size)
{
    int previous = 0, i = size - 1, j, current;

    for (j = size - 1; j >= 0; j--)
    {
        current = line[j];
        if (!current)
            continue;
        if (!previous)
            previous = current;
        else if (previous == current)
        {
            line[i--] = current << 1;
            previous = 0;
        } else
        {
            line[i--] = previous;
            previous = current;
        }
    }
    if (previous)
        line[i--] = previous;
    while (i >= 0)
        line[i--] = 0;
}
