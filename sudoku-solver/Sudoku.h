#pragma once

#include <iostream>
#include <array>

class Sudoku {
public:
	using grid_t = std::array<std::array<int, 9>, 9>;
	Sudoku(grid_t);
	void print() const;
private:
	grid_t grid;
};
