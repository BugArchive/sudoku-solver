#include "Sudoku.h"

Sudoku::Sudoku(grid_t grid) : grid(grid) {}

void Sudoku::print() const {

	// print width = cell width + 8 inbetween lines + 2 double outlines + 2 aditional 3x3 separators
	int print_width = 3 * 9 + 8 + 2 * 2 + 2;

	for (int row = 0; row < 9; row++) {

		for (int i = 0; i < print_width; i++) {
			std::cout << (row % 3 == 0 ? "=" : "-");
		}
		std::cout << std::endl;
		for (int column = 0; column < 9; column++) {
			std::cout << (column % 3 == 0 ? "|| " : "| ") << grid[row][column] << " ";
		}
		std::cout << "||" << std::endl;
	}
	for (int i = 0; i < print_width; i++) {
		std::cout << "=";
	}
	std::cout << std::endl;
}

void Sudoku::solve() { solveRecursion(0, 0); }

bool Sudoku::solveRecursion(int start_row, int start_column) {
	if (start_row == 8 && start_column == 8 && grid[start_row][start_column] != 0) {
		return true;
	}
	int column = start_column;
	for (int row = start_row; row < 9; row++) {
		for (; column < 9; column++) {
			if (grid[row][column] == 0) {
				for (int i = 1; i <= 9; i++) {
					grid[row][column] = i;
					if (!isCellConflicting(row, column)) {
						if (solveRecursion(row, column)) {
							return true;
						}
					}
				}
				grid[row][column] = 0;
				return false;
			}
		}
		column = 0;
	}
}

bool Sudoku::isCellConflicting(int row, int column) const {
	//check row
	for (int check_row = 0; check_row < 9; check_row++) {
		if (check_row != row && grid[check_row][column] == grid[row][column]) {
			return true;
		}
	}
	//check column
	for (int check_column = 0; check_column < 9; check_column++) {
		if (check_column != column && grid[row][check_column] == grid[row][column]) {
			return true;
		}
	}
	//check block
	int block_start_row = row - row % 3;
	int block_start_column = column - column % 3;
	for (int block_row = block_start_row; block_row < block_start_row + 3; block_row++) {
		for (int block_column = block_start_column; block_column < block_start_column + 3; block_column++) {
			if (block_row != row && block_column != column && grid[block_row][block_column] == grid[row][column]) {
				return true;
			}
		}
	}
	return false;
}
