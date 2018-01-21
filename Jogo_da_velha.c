#include <stdio.h>
#include <stdlib.h>

int matrix[3][3];
int check_winner();
int check_draw();	
void init_matrix();
void get_player_action();
void get_computer_action();
void show_matrix();


int main(int argc, char** argv)
{
	system("Title - Tic-Tac-Toe");

	char winner = 'E';
	int cont;
	printf("\nYou're [X]");
	init_matrix();
	do
	{
		do
		{
			show_matrix();

			// player's movement

			get_player_action();

			if (check_winner() == 1)
			{
				winner = 'P';
				break;
			}

			//computer's movement

			get_computer_action();

			// verifica se ha um vencedor

			if (check_winner() == 1)
			{
				winner = 'C';
				break;
			}

			if (check_draw() == 1)
			{
				winner = 'E';
				break;

			}

		}
		while(1);

		show_matrix();

		if(winner == 'P')
		{
			printf("\n\nCongratulations, You've won!!");
		}
		else if(winner == 'C')
		{
			printf("\n\nYou lost, try again!");
		}
		else
		{
			printf("\n\nIt's a draw!");
		}

		printf("\n\n Wish to carry on playing? <1> for YES <any other value> for NO: ");
		scanf("%d%*c", &cont);

		if (cont == 1)
		{
			system("cls");
			init_matrix();
			continue;
		}
		else
		{
			break;
		}
	}
	while(1);

	printf("\n\nPress ENTER to exit.");
	scanf("%*c");

	return 0;
}

// funcao que inicializa a matriz
void init_matrix()
{
	int i, j;

	for(i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}


// funcao para mostrar a matriz

void show_matrix()
{
	int i;

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("							%c | %c | %c\n", matrix[i][0], matrix[i][1], matrix[i][2]);

		if(i != 2)
		{
			printf("\n						       ---|---|---\n");
		}
	}
}

//funcao que obtem o movimento do jogador

void get_player_action()
{
	int x, y;

	printf("Type in the coordinates [row col](example: 1 2): ");
	scanf("%d %d%*c", &x, &y);

	//decrements x and y to get correct positions in matrix
	x--;
	y--;

	if (matrix[x][y] != ' ' )
	{
		printf("\nInvalid position, try again.\n");
		get_player_action();
	}
	else
	{
		matrix[x][y] = 'X';
	}

}

//funcao que obtem o movimento do computador

void get_computer_action()
{
	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(matrix[i][j] == ' ')
			{
				matrix[i][j] = 'O';
				return;
			}
		}
	}
}

//funcao que verifica se ha um vencedor

int check_winner()
{
	int i;

	// check rows

	for(i = 0; i < 3; i++)
	{
		if(matrix[i][0] != ' ' && matrix[i][1] != ' ' && matrix[i][2] != ' ')
		{
			if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
			{
				return 1;
			}
		}
	}

	// check columns

	for(i = 0; i < 3; i++)
	{
		if(matrix[0][i] != ' ' && matrix[1][i] != ' ' && matrix[2][i] != ' ')
		{
			if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
			{
				return 1;
			}
		}
	}

	// check diagonals

	if(matrix[0][0] != ' ' && matrix[1][1] != ' ' && matrix[2][2] != ' ')
	{
		if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		{
			return 1;
		}
	}

	if(matrix[0][2] != ' ' && matrix[1][1] != ' ' && matrix[2][0] != ' ')
	{
		if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		{
			return 1;
		}
	}

	return 0;


}

// check if it's a draw

int check_draw()
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if(matrix[i][j] == ' ')
			{
				return 0;
			}
		}
	}

	return 1;
}

















