#include <iostream>
#include <vector>
#include <array>
class SudokuSolver 
{
private:
	std::array<std::array<int, 9>, 9> board;
public:
	SudokuSolver() 
{
	// Initialize board with zeros
	for (auto& row : board) 
{
	row.fill(0);
}
}
	void setCell(int row, int col, int value) 
{
	board[row][col] = value;
}
	bool isValid(int row, int col, int num) 
{
	// Check if num is already in the same row or column
	for (int i = 0; i < 9; ++i) 
{
	if (board[row][i] == num || board[i][col] == num) 
{
	return false;
}
}
	// Check if num is already in the 3x3 subgrid
	int subgridRow = row - row % 3;
	int subgridCol = col - col % 3;
	for (int i = 0; i < 3; ++i) 
{
	for (int j = 0; j < 3; ++j) 
{
	if (board[subgridRow + i][subgridCol + j] == num) 
{
	return false;
}
}
}
	return true;
}
	bool solve() 
{
	int row, col;
	if (!findEmptyCell(row, col)) 
{
	// No empty cell found, puzzle solved
	return true;
}
	for (int num = 1; num <= 9; ++num) 
{
	if (isValid(row, col, num)) 
{
	board[row][col] = num;
	if (solve()) 
{
	return true; // Solution found
}
	board[row][col] = 0; // Backtrack
}
}
	return false; // No solution found
}
	bool findEmptyCell(int& row, int& col) 
{
	for (row = 0; row < 9; ++row) 
{
	for (col = 0; col < 9; ++col) 
{
	if (board[row][col] == 0) 
{
	return true;
}
}
}
	return false;
}
	void printBoard() const 
{
	for (const auto& row : board) 
{
	for (int num : row) 
{
	std::cout << num << " ";
}
	std::cout << std::endl;
}
}
};
int main() 
{
	SudokuSolver solver;
	// Example puzzle
	solver.setCell(0, 0, 5);
	solver.setCell(0, 1, 3);
	solver.setCell(0, 4, 7);
	solver.setCell(1, 0, 6);
	solver.setCell(1, 3, 1);
	solver.setCell(1, 4, 9);
	solver.setCell(1, 5, 5);
	solver.setCell(2, 1, 9);
	solver.setCell(2, 2, 8);
	solver.setCell(2, 7, 6);
	solver.setCell(3, 0, 8);
	solver.setCell(3, 4, 6);
	solver.setCell(3, 8, 3);
	solver.setCell(4, 0, 4);
	solver.setCell(4, 3, 8);
	solver.setCell(4, 5, 3);
	solver.setCell(4, 8, 1);
	solver.setCell(5, 0, 7);
	solver.setCell(5, 4, 2);
	solver.setCell(5, 8, 6);
	solver.setCell(6, 1, 6);
	solver.setCell(6, 6, 2);
	solver.setCell(6, 7, 8);
	solver.setCell(7, 3, 4);
	solver.setCell(7, 4, 1);
	solver.setCell(7, 5, 9);
	solver.setCell(7, 8, 5);
	solver.setCell(8, 4, 8);
	solver.setCell(8, 7, 7);
	solver.setCell(8, 8, 9);
	std::cout << "Sudoku puzzle:" << std::endl;
	solver.printBoard();
	std::cout << std::endl << "Solving..." << std::endl;
	if (solver.solve()) 
{
	std::cout << "Sudoku solved:" << std::endl;
	solver.printBoard();
}
    else
{
	std::cout << "No solution exists for the given puzzle." << std::endl;
}
	return 0;
}