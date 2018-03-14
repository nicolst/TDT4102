#pragma once

#include <vector>
#include <random>

struct Tile {
    bool open;
    bool mine;
    bool mark;
};

enum GameState {
    PLAYING,
    LOST,
    WON
};

class Minesweeper {
private:
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger
    std::vector<std::vector<Tile>> board;
    int height;
    int width;
    int mines;

    void generateMines(int mines);

public:
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;

    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;
    bool isTileMarked(int row, int col) const;

    void openTile(int row, int col);
    void toggleMarkTile(int row, int col);

    GameState gameState() const;

    int numAdjacentMines(int row, int col) const;

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};

