#pragma once
#include "Matrix.h"
#include "IDrawable.h"
#include <fstream>
#include <vector>

class Walls : public Matrix<bool>, public IDrawable
{
public:
    void draw(Screen& screen) const;

    static Walls fromFile(const char* filepath)
    {
        std::ifstream file(filepath);
        if (!file) throw std::runtime_error("Cannot open file");

        std::vector<std::vector<bool>> grid;
        std::string line;
        while (std::getline(file, line)) {
            std::vector<bool> row = {};
            for (size_t i = 0; i < line.size(); ++i) {
                row.push_back(line[i] != ' ');
            }
            if (!row.empty()) grid.push_back(std::move(row));
        }

        Walls walls(grid.empty() ? 0 : grid[0].size(), grid.size());
        for (size_t i = 0; i < grid.size(); ++i)
            for (size_t j = 0; j < grid[i].size(); ++j)
                walls.at(i, j) = grid[i][j];

        return walls;
    }

    Walls(size_t width, size_t height, bool fillValue);
    Walls(size_t width, size_t height);
};