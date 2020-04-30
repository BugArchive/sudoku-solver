#pragma once

#include <iostream>
#include <array>

class Sudoku {
public:
	using grid_t = std::array<std::array<int, 9>, 9>;
	Sudoku(grid_t);
	void print() const;
	void solve();
private:
	bool solveRecursion(int row, int column);
	bool isCellConflicting(int row, int column) const;
	grid_t grid;
};
