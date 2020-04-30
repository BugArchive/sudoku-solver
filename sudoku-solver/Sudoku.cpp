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
