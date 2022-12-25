#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ROWS 9
#define COLUMNS 9
#define TRUE 1
#define FALSE 0

int TABLE[ROWS][COLUMNS] = 
    {
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

// print table to console
void draw_table(int table[ROWS][COLUMNS]);

// check entry against the row
int check_row(int entry, int row);

// check entry against the column
int check_column(int entry, int column);

// check entry against box
int check_box(int entry, int row, int column);

// generate game
int generate(void);
