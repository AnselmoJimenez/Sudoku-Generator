#include "generator.h"

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

int check_validity(int entry, int row, int column) 
{
    if (check_row(entry, row) && check_column(entry, column) && check_box(entry, row, column))
    {
        return TRUE;
    }
    return FALSE;
}

int random_number(int length, int offset) {
    // generate number in range of length offsetted
    return (rand() % length) + offset;
}

// Fill Diagonal Boxes of the board
void fill_diagonal(int row, int column) {
    // Filled all diagonal boxes
    if (row > 6 && column > 6) { return; }

    // Identify what box the current position is in
    int box_row = row - (row % 3);
    int box_column = column - (column % 3);

    // Loop through each entry in that box
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Select a random number for the box
            int entry = random_number(9, 1);
            
            // Check if that number is a valid entry
            // If not, continue generating new random number
            while (check_box(entry, i + box_row, j + box_column) == FALSE) 
            {
                entry = random_number(9, 1);
            } 
            
            // insert entry if valid
            table[i + box_row][j + box_column] = entry;
        }
    }

    return fill_diagonal(row + 3, column + 3);
}

void fill_rows(int row, int column) {
    // Complete
    if (row > 8 && column > 5) { return; }

    // Increment position
    if (column == 9) 
    {
        column = 0;
        row++;
    }

    // Check if board position is populated
    // if it is move on
    if (table[row][column] != 0) 
    {
        fill_rows(row, column + 1); 
        
    }

    for (int i = 1; i < 10; i++) 
    {
        if (check_validity(i, row, column)) 
        {
            table[row][column] = i;
            fill_rows(row, column + 1);
        }
        table[row][column] = 0;
    }
}

// generate game
void generate(void) {
    // 1.) Generate Seed for Random Numbers
    srand(time(0));

    // 2.) fill diagonal boxes of the board
    fill_diagonal(0, 0);

    // 3.) Fill the rest of the rows recursively
    fill_rows(0, 3);

    // 4.) Set random amount of boxes to empty

}