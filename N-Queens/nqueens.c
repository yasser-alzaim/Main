/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malzaim <malzaim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:58:42 by malzaim           #+#    #+#             */
/*   Updated: 2024/01/31 00:58:46 by malzaim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdbool.h>
#include <stdio.h>

#define N 8

void	printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (board[i][j])
			{
				printf("🔴");
			}
			else
			{
				printf("⬜️");
			}
		printf("\n");
	}
	printf("\n");
}

bool	isSafe(int board[N][N], int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return (false);
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return (false);
	for (i = row, j = col; i < N && j >= 0; i++, j--)
		if (board[i][j])
			return (false);
	return (true);
}

bool	solveNQueensUtil(int board[N][N], int col)
{
	bool	res;

	if (col == N)
	{
		printSolution(board);
		return (true);
	}
	res = false;
	for (int i = 0; i < N; i++)
	{
		if (isSafe(board, i, col))
		{
			board[i][col] = 1;
			res = solveNQueensUtil(board, col + 1) || res;
			board[i][col] = 0;
		}
	}
	return (res);
}

void	solveNQueens(void)
{
	int	board[N][N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = 0;
	if (!solveNQueensUtil(board, 0))
		printf("No solution exists");
}

int	main(void)
{
	solveNQueens();
	return (0);
}
