#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define ROWS 9
#define COLUMNS 9
#define TRUE 1
#define FALSE 0

int table[ROWS][COLUMNS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// generate random number
int random_number(int length, int offset);

// check entry against the row
int check_row(int entry, int row);

// check entry against the column
int check_column(int entry, int column);

// check entry against box
int check_box(int entry, int row, int column);

// generate game
void generate(void);
