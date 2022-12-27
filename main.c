#include "main.h"
#include "generator.c"

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

int main() 
{   
    generate();
    draw_table(table);
    
    return 0;
}
