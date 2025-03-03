// Maze generation algorithm (Dooria)
#include <iostream>
#include <vector>
#include <stack>
#include <utility> // For std::pair
#include <cstdlib> // For rand() and srand()
#include <ctime>
#include <unordered_set>

using std::vector;
using std::stack;
using std::pair;
using Cell = pair<int, int>;

// initialize maze with walls ('#') and cells (' ')
void InitializeMaze(vector<vector<char>>& maze, int rows, int cols) {
    maze = vector<vector<char>>(rows, vector<char>(cols, '#'));
    for (int i = 1; i < rows; i += 2) {
        for (int j = 1; j < cols; j += 2) {
            maze[i][j] = ' ';
        }
    }
}

// Check if a cell is valid and unvisited
bool IsValidCell(int row, int col, int rows, int cols, const vector<vector<char>>& maze) {
    return row >= 1 && row < rows && col >= 1 && col < cols && maze[row][col] == ' ';
}

// Get all unvisited neighbors of a cell
vector<Cell> GetUnvisitedNeighbors(const Cell& cell, const vector<vector<char>>& maze, int rows, int cols) {
    vector<Cell> neighbors;
    int directions[4][2] = { {0, 2}, {2, 0}, {0, -2}, {-2, 0} }; // Move 2 steps to stay within odd indices

    for (auto& dir : directions) {
        int newRow = cell.first + dir[0], newCol = cell.second + dir[1];
        if (IsValidCell(newRow, newCol, rows, cols, maze)) {
            neighbors.push_back({ newRow, newCol });
        }
    }
    return neighbors;
}

// Remove the wall between two cells
void RemoveWall(Cell& current, Cell& next, vector<vector<char>>& maze) {
    int wallRow = (current.first + next.first) / 2;
    int wallCol = (current.second + next.second) / 2;
    maze[wallRow][wallCol] = ' ';
}

void getRandPerimPoints(int rows, int cols, vector<Cell>& output, int num) {
    srand(static_cast<unsigned>(time(nullptr)));

    // Collect all perimeter positions
    vector<Cell> perimPositions;

    // Top and bottom rows
    for (int col = 1; col < cols; col += 2) {
        perimPositions.push_back({ 0, col }); // Top row
        perimPositions.push_back({ rows - 1, col }); // Bottom row
    }

    // Left and right columns
    for (int row = 1; row < rows; row += 2) {
        perimPositions.push_back({ row, 0 }); // Left column
        perimPositions.push_back({ row, cols - 1 }); // Right column
    }

    // Ensure we don't pick more points than available and avoid duplicates
    num = std::min(num, static_cast<int>(perimPositions.size()));
    std::unordered_set<int> chosenIndices{};

    while (output.size() < static_cast<size_t>(num)) {
        int randIndex = rand() % perimPositions.size(); // Pick a random index
        // Ensure uniqueness
        if (chosenIndices.insert(randIndex).second) {
            output.push_back(perimPositions[randIndex]);
        }
    }
}

// Depth-First Search with Backtracking to generate maze paths
void GenerateMaze(vector<vector<char>>& maze, int rows, int cols) {
    srand(time(nullptr)); // Seed random number generator
    stack<Cell> stack;
    vector<Cell> doors;

    maze[1][1] = 'V';
    stack.push(Cell(1,1));

    while (!stack.empty()) {
        Cell currentCell = stack.top();
        stack.pop();

        auto neighbors = GetUnvisitedNeighbors(currentCell, maze, rows, cols);
        if (!neighbors.empty()) {
            stack.push(currentCell); // Push current cell back to stack

            Cell chosenNeighbor = neighbors[rand() % neighbors.size()];
            RemoveWall(currentCell, chosenNeighbor, maze);
            maze[chosenNeighbor.first][chosenNeighbor.second] = 'V';
            stack.push(chosenNeighbor);
        }
    }

    // Reset visited cells to empty spaces
    for (int i = 1; i < rows; i += 2) {
        for (int j = 1; j < cols; j += 2) {
            if (maze[i][j] == 'V') maze[i][j] = ' ';
        }
    }

    getRandPerimPoints(rows, cols, doors, 4);

    int doorIdx = 0;
    for (const auto& door : doors)
    {
        maze[door.first][door.second] = '0' + static_cast<char>(doorIdx);
        doorIdx++;
    }
}

void main()
{
    int rows = 21; // Must be odd
    int cols = 21; // Must be odd
    vector<vector<char>> maze;

    InitializeMaze(maze, rows, cols);
    GenerateMaze(maze, rows, cols);

    // Print the maze
    for (const auto& row : maze) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }

}
