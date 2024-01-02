#include <stdio.h>
#include <conio.h>

int n, i, j, visited[20], stack[20], cost[20][20], x = 0;

void dfs();

void main() {
    int v;
    clrscr();
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the elements\n");
    for (i = 0; i < n; i++) {
	for (j = i; j < n; j++) {
	    printf("\nEdge(%d,%d)", i, j);
	    scanf("%d", &cost[i][j]);
	    cost[j][i] = cost[i][j];
	}
    }

    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    printf("%d\t", cost[i][j]);
	}
	printf("\n");
    }


    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);
    visited[v] = 1;
   // printf("\nDFS Traversal: ");
   // printf("%d ", v);
    stack[0] = v;
    dfs();

    getch();
}

void dfs() {
    int top = 0;
    int popped[20]; // To store popped elements for printing later
    int p = 0; // Index for storing popped elements
    while (top >= 0) {
	int current = stack[top];
	int found = 0;
	for (i = 0; i < n; i++) {
	    if (cost[current][i] == 1 && visited[i] == 0) {
		visited[i] = 1;
	       // printf("%d ", i);
		stack[++top] = i;
		found = 1;
		break;
	    }
	}
	if (!found) {
	    popped[p++] = stack[top]; // Store popped element
	    top--;
	}
    }

    printf("\nPopping Order from Stack: ");
    for (i = p - 1; i >= 0; i--) {
	printf("%d ", popped[i]); // Print elements in popping order
    }
}