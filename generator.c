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

// check the validity of the entry against rows, columns, and boxes
int check_validity(int entry, int row, int column) 
{
    if (check_row(entry, row) && check_column(entry, column) && check_box(entry, row, column))
    {
        return TRUE;
    }
    return FALSE;
}

// Insert entry into the table if valid
void insert_entry(int entry, int row, int column) 
{
    // insert entry into table
    table[row][column] = entry;
}

int random_number(int length, int offset) 
{
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

// Fills the rest of the board recursively
int fill_rows(int row, int column) {
    // Complete
    if (row == 8 && column == 9) { return TRUE; }

    // Increment position
    if (column == 9) 
    { 
        column = 0;
        row++;
    }

    // If the space isn't empty
    if (table[row][column] != 0) 
    {
        // check the next position of the table
        if (fill_rows(row, column + 1)) { return TRUE; }
    }
    // If the space is empty
    else
    {
        // Begin testing numbers 1 through 9
        for (int i = 1; i < 10; i++) 
        {
            // Check if the current number is valid
            if (check_validity(i, row, column)) 
            {
                // Insert Entry into position
                insert_entry(i, row, column);

                // Go to next position
                if (fill_rows(row, column + 1)) 
                {
                    return TRUE;
                }
            }
            // Not valid entry
            table[row][column] = 0;
        }
    }
    return FALSE;
}

// removes specified elements to finish generating the board
void remove_elements(int amount) 
{
    // Until the amount specified remove an element
    for (int i = 0; i < amount; i++) {
        // choose a random position to remove the element from board
        int row_index = 0;
        int column_index = 0;
        do {
            row_index = random_number(9, 0);
            column_index = random_number(9, 0);
        } while (table[row_index][column_index] == 0);

        // insert 0 in that position if not already 0
        insert_entry(0, row_index, column_index);
    }
}

// generate game
void generate(void) {
    // 1.) Generate Seed for Random Numbers
    srand(time(0));

    // 2.) fill diagonal boxes of the board
    fill_diagonal(0, 0);

    // 3.) Fill the rest of the rows recursively
    fill_rows(0, 0);

    // 4.) Set random amount of boxes to empty
    remove_elements(50);
}