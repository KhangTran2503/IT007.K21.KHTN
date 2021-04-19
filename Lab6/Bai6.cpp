#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void Print(int *seq, int **table, char* fault, int n,int f)
{
	int count = 0;
	printf("\n\t--- Page Replacement algorithm ---\n");
	printf("\t----------------------------------\n\n\t");
	for (int i = 0; i < n; i++)
		printf("%2d ", seq[i]);
	printf("\n\n\t");
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < n; j++)
			if (table[i][j] != -1)
				printf("%2d ", table[i][j]);
			else
				printf("   ");
		printf("\n\n\t");
	}
	for (int i = 0; i < n; i++)
	{
		printf(" %c ", fault[i]);
		if (fault[i] == '*')
			count++;
	}
	printf("\n\n\tNumber of Page Fault : %d\n\n", count);
}

int in_MMR(int** table, int f, int i, int page)
{
	for (int j = 0; j < f; j++)
		if (table[j][i] == page || table[j][i]==-1)
			return j;
	return -1;
}

void FIFO(int* seq, int **table, char *fault, int n, int f)
{
	int first = 0;
	table[0][0] = seq[0];
	fault[0] = '*';
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < f; j++)
			table[j][i] = table[j][i - 1];
		int id = in_MMR(table, f, i, seq[i]);
		if (id != -1)
		{	
			if (table[id][i] == -1) {
				table[id][i] = seq[i];
				fault[i] = '*';
			} else	fault[i] = ' ';
		}
		else
		{
			fault[i] = '*';
			table[first][i] = seq[i];
			first = (first + 1) % f;
		}
	}
}
void OPT(int* seq, int** table, char* fault, int n, int f)
{
	int* next,k; 
	next = (int*)malloc(f * sizeof(int));

	table[0][0] = seq[0];
	fault[0] = '*';
	for (k = 1; k < n; k++)
		if (seq[k] == seq[0])
			break;
	next[0] = k;
	for (int i = 1; i < n; i++)
	{
		int j;
		for (j = 0; j < f; j++)
			table[j][i] = table[j][i - 1];

		int id = in_MMR(table, f, i, seq[i]);
		if (id == -1)
		{
			int choose = 0;
			for (j = 1; j < f; j++)
				if (next[choose] < next[j])
					choose = j;
			table[choose][i] = seq[i];
			for (j = i + 1; j < n; j++)
				if (seq[j] == seq[i])
					break;
			next[choose] = j;
			fault[i] = '*';
		}
		else
		{
			if (table[id][i] == -1) {
				table[id][i] = seq[i];
				fault[i] = '*';
			}
			else 		fault[i] = ' ';
			j = i + 1;
			for (j = i + 1; j < n; j++)
				if (seq[j] == seq[i])
					break;
			next[id] = j;
		}
	}
}
void LRU(int* seq, int** table, char* fault, int n, int f)
{
	int* last; 
	last = (int*)malloc(f * sizeof(int));

	table[0][0] = seq[0];
	fault[0] = '*';
	last[0] = 0;
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < f; j++)
			table[j][i] = table[j][i - 1];

		int id = in_MMR(table, f, i, seq[i]);
		if (id == -1)
		{
			fault[i] = '*';
			int min_ref = 0;
			for (int j = 1; j < f; j++)
				if (last[j] < last[min_ref])
					min_ref = j;
			last[min_ref] = i;
			table[min_ref][i] = seq[i];
		}
		else
		{
			if (table[id][i] == -1) {
				table[id][i] = seq[i];
				fault[i] = '*';
			} else 		fault[i] = ' ';
			last[id] = i;
		}
	}
}

int main()
{
	int* DRS, *MIS, n,i, f, algo;
	printf("\t--- Page Replacement algorithm ---\n");
	printf("\t1. 1, 8, 5, 2, 0, 0, 7, 2, 0, 0, 7\n");
	printf("\t2. Manual input sequence:       \t\n");
	printf("\tInput length of sequences: ");
	scanf("%d", &n);
	MIS = (int*)malloc(n * sizeof(int));
	printf("\tInpute sequences: ");
	for (i = 0; i < n; i++)
		scanf("%d", &MIS[i]);

	
	printf("\t--- Page Replacement algorithm ---\n");
	printf("\tInpute page frames: ");
	scanf("%d", &f);
	

	while (1){
		char* fault = (char*)malloc((n + 1) * sizeof(char));
		int** table = (int**)malloc(f * sizeof(int*));
		for (i = 0; i < f; i++)	{
			table[i] = (int*)malloc(n * sizeof(int));
			for (int j = 0; j < n; j++)
				table[i][j] = -1;
		}
	

		printf("\n\t--- Page Replacement algorithm ---\n");
		printf("\t1. FIFO algorithm.\n");
		printf("\t2. OPT algorithm.\n");
		printf("\t3. LRU algorithm.\n");
		printf("\t4. Exit.\n");
		printf("\tChoose algorithm: ");
		scanf("%d", &algo);
		if (algo  == 4) break;
		switch (algo)
		{
		case 1: 
			FIFO(MIS, table, fault, n, f);
			break;
		case 2: 
			OPT(MIS, table, fault, n, f);
			break;
		case 3: 
			LRU(MIS, table, fault, n, f);
			break;
		default:
			return 0;
		}
	
		//system("cls");
		Print(MIS, table, fault, n, f);
	}
	return 0;
}
