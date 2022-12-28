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

// check entry against the row
int check_row(int entry, int row);

// check entry against the column
int check_column(int entry, int column);

// check entry against box
int check_box(int entry, int row, int column);

// Check validity of the entry against rows, columns, and boxes
int check_validity(int entry, int row, int column);

// Insert entry into table if valid
void insert_entry(int entry, int row, int column);

// generate random number
int random_number(int length, int offset);

// fill diagonal boxes of the board
void fill_diagonal(int row, int column);

// Fills the rest of the board recursively
int fill_rows(int row, int column);

// removes specified elements to finish generating the board
void remove_elements(int amount); 

// generate game
void generate(void);
