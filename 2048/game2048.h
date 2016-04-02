#ifndef GAME2048_H
#define GAME2048_H

#include <vector>
#include <memory>
#include <random>
#include <map>

class Game2048
{
public:
    Game2048();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    static int size();
    void debug();

private:
    int randomPostionGenerator();
    void merge(std::vector<int>::iterator, std::vector<int>::iterator,
               std::vector<int>::iterator, std::vector<int>::iterator);
private:
    static int size_;
    std::shared_ptr<std::vector<int>> data_;
    std::shared_ptr<std::vector<int>> dataSpace_;
    std::default_random_engine eng_;
    std::uniform_int_distribution<unsigned> dis_;
};


#endif
