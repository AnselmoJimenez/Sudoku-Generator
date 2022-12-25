#include "generator.h"

// print table to console
void draw_table(int table[ROWS][COLUMNS]) {
    // Counting the rows
    for (int i = 0; i < ROWS; i++) 
    {   
        // Printing the spacers between the rows
        if ((i % 3 == 0) && (i != 0))   { printf("###########||###########||###########\n"); } 
        else if (i != 0)                { printf("---+---+---][---+---+---][---+---+---\n"); }

        // Counting the columns
        for (int j = 0; j < COLUMNS; j++) 
        {   
            // Printing the numbers
            if (table[i][j] == 0)       { printf("   "); }
            else                        { printf(" %d ", table[i][j]); }
            
            // Printing the spacers between the columns
            if ((j + 1) % 3 == 0 && j != 8) { printf("]["); }
            else if (j == 8)                { printf("\n"); }
            else                            { printf("|"); }
        }
    }
}

// check entry against the row
int check_row(int entry, int row) {
    // Check the individual row
    for (int i = 0; i < COLUMNS; i++)
    {
        // Check if the entry is in the row
        if (TABLE[row][i] == entry) 
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
        if (TABLE[i][column] == entry) 
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
            if (TABLE[i + box_row][j + box_column] == entry)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

// generate game
int generate(void) {
    return 0;
}