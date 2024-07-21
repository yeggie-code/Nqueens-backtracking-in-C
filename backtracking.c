// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

// Declare an array to store the positions of the queens
int a[30];

// Initialize a counter to keep track of the number of solutions
int count = 0;

// Function to check if a queen can be placed at a given position
int place(int pos) {
    int i; 
    // Check from the 1st row to the (current row-1) to check with all previous queens
    for(i=0; i<pos; i++) {
        // If a queen exists in the same column or diagonally, return 0
        if ((a[i]==a[pos]) || ((abs(a[i]-a[pos])==abs(i-pos))))
            return 0;
    }
    // If no queen exists in the same column or diagonally, return 1
    return 1;
}

// Function to print a solution
void print_sol(int n) {
    int i, j;
    // Increment the solution counter
    count++;
    printf("\n\nsolution #%d: \n", count);
    // Print the solution
    for(i=0; i<n; i++) {
        for(j=1; j<=n; j++) {
            if(a[i]==j)
                printf("Q\t"); // Print 'Q' for queen positions
            else
                printf("*\t"); // Print '*' for empty positions
        }
        printf("\n");
    }
}

// Recursive function to place queens
void queen(int k, int n) {
    // Base case: if all queens are placed, print the solution
    if(k > n) {
        print_sol(n);
        return;
    }
    // Try placing the queen in each column
    for(a[k-1] = 1; a[k-1] <= n; a[k-1]++) {
        // If the queen can be placed at the current position, recursively place the next queen
        if(place(k-1)) {
            queen(k+1, n);
        }
    }
}

// Main function
void main() {
    int n;
    // Ask the user for the number of queens
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    // Start placing queens from the first row
    queen(1, n);
    // Print the total number of solutions
    printf("\n Total solutions=%d", count);
}
