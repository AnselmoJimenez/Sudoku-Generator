#include "generator.h"

int random_number(int length, int offset) {
    // create seed from current time
    srand(time(0));

    // generate number in range of length offsetted
    int number = (rand() % length) + offset;

    return number;
}

// check entry against the row
int check_row(int entry, int row) {
    // Check the individual row
    for (int i = 0; i < COLUMNS; i++)
    {
        // Check if the entry is in the row
        if (table[row][i] == entry) 
        {
            return FALSE;
        }
    }
    return TRUE;
}

// check entry against the column
int check_column(int entry, int column) {
    // Check the same row position in each row
    for (int i = 0; i < ROWS; i++)
    {
        // Check if the entry in column
        if (table[i][column] == entry) 
        {
            return FALSE;
        }
    }
    return TRUE;
}

// check entry against box
int check_box(int entry, int row, int column) {
    // Identify what box the current position is in
    int box_row = row - (row % 3);
    int box_column = column - (column % 3);

    // Loop through each entry in that box
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Check if the entry we want matches any other number
            if (table[i + box_row][j + box_column] == entry)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

// generate game
void generate(void) {
    
}