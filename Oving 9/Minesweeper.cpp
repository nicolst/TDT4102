#include "Minesweeper.h"

Minesweeper::Minesweeper(int width, int height, int mines): width(width), height(height), mines(mines) {

    std::vector<std::vector<Tile>> newBoard;
    for (int i = 0; i < height; i++) {
        std::vector<Tile> row;
        for (int j = 0; j < width; j++) {
            Tile currentTile;
            currentTile.mine = false, currentTile.open = false, currentTile.mark = false;
            row.push_back(currentTile);
        }
        newBoard.push_back(row);
    }
    board = newBoard;

    generateMines(mines);
}

Minesweeper::~Minesweeper() {

}

void Minesweeper::generateMines(int mines) {
    for (int i = 0; i < mines; i++) {
        int row = rand() % height;
        int column = rand() % width;
        while(isTileMine(row, column)) {
            row = rand() % height;
            column = rand() % width;
        }
        board[row][column].mine = true;
    }
}

bool Minesweeper::isGameOver() const {
    int tilesLeft = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (isTileMine(i, j) && isTileOpen(i, j)) return true;
            if (!isTileOpen(i, j)) tilesLeft++;
        }
    }
    return tilesLeft == mines;
}

GameState Minesweeper::gameState() const {
    int tilesLeft = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (isTileMine(i, j) && isTileOpen(i, j)) return GameState::LOST;
            if (!isTileOpen(i, j)) tilesLeft++;
        }
    }
    if (tilesLeft == mines) return GameState::WON;
    return GameState::PLAYING;
}

bool Minesweeper::isTileOpen(int row, int col) const {
    return board[row][col].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
    return board[row][col].mine;
}

bool Minesweeper::isTileMarked(int row, int col) const {
    return board[row][col].mark;
}

void Minesweeper::openTile(int row, int col) {
    if (board[row][col].open) return;
    board[row][col].open = true;
    if (numAdjacentMines(row, col) == 0) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (row+i < 0 || row+i >= height || col+j < 0 || col+j >= width) continue;
                openTile(row+i, col+j);
            }
        }
    }
}

void Minesweeper::toggleMarkTile(int row, int col) {
    board[row][col].mark = !board[row][col].mark;
}

int Minesweeper::numAdjacentMines(int row, int col) const {
    int num = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (row+i < 0 || row+i >= height || col+j < 0 || col+j >= width) continue;
            if (isTileMine(row+i, col+j)) num++;
        }
    }
    return num;
}
