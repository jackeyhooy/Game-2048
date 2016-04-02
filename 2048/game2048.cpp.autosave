#include "game2048.h"
#include <iostream>
#include <time.h>

int Game2048::size_ = 0;

using namespace std;

Game2048::Game2048()
    :data_(make_shared<vector<int>> (vector<int>(16, 0))),
      dataSpace_(make_shared<vector<int>> (vector<int>(16))),
      eng_(), dis_(0, 15)
{
    for(int i = 0; i < 16; ++i)
        dataSpace_->at(i) = i;
    for(int i = 0; i < 2; ++i)
    {
        int pos = randomPostionGenerator();
        data_->at(pos) = 2;
    }

}

void Game2048::moveLeft()
{
    vector<int>::iterator b = data_->begin();
    for(int i = 0; i <4; ++i)
    {
        vector<int>::iterator beg = data_->begin();
        beg = b + i * 4;
        merge(beg, beg + 1, beg + 2, beg + 3);
    }
    int pos = randomPostionGenerator();
    if(-1 != pos)
        data_->at(pos) = 2;
    else
    {
        cout<<"Game over"<<endl;
        exit(0);
    }
}

void Game2048::moveRight()
{
    vector<int>::iterator b = data_->begin();
    for(int i = 0; i <4; ++i)
    {
        vector<int>::iterator beg = data_->begin();
        beg = b + i * 4;
        merge(beg + 3, beg + 2, beg + 1, beg);
    }
    int pos = randomPostionGenerator();
    if(-1 != pos)
        data_->at(pos) = 2;
    else
    {
        cout<<"Game over"<<endl;
        exit(0);
    }
}

void Game2048::moveUp()
{
    vector<int>::iterator b = data_->begin();
    for(int i = 0; i <4; ++i)
    {
        vector<int>::iterator beg = data_->begin();
        beg = b + i ;
        merge(beg, beg + 4, beg + 8, beg + 12);
    }
    int pos = randomPostionGenerator();
    if(-1 != pos)
        data_->at(pos) = 2;
    else
    {
        cout<<"Game over"<<endl;
        exit(0);
    }
}

void Game2048::moveDown()
{
    vector<int>::iterator b = data_->begin();
    for(int i = 0; i <4; ++i)
    {
        vector<int>::iterator beg = data_->begin();
        beg = b + i;
        merge(beg + 12, beg + 8, beg + 4, beg);
    }
    int pos = randomPostionGenerator();
    if(-1 != pos)
        data_->at(pos) = 2;
    else
    {
        cout<<"Game over"<<endl;
        exit(0);
    }
}

void Game2048::merge(vector<int>::iterator first, vector<int>::iterator second,
                     vector<int>::iterator third, vector<int>::iterator fourth)
{
    if(0 !=  *first && *first == *second )
    {
        *first *= 2;
        if(0 != *third && *third == *fourth)
        {
            *second = *third * 2;
            *third = *fourth = 0;
        }else if(0 != *third)
        {
            *second = *third;
            *third = *fourth;
            *fourth = 0;
        }else if(0 != *fourth)
        {
            *second = *fourth;
            *fourth = 0;
        }
    }else if(0 != *first && 0 != *second )
    {
        if(*second == *third)
        {
            *second *= 2;
            *third = *fourth;
            *fourth = 0;
        }
        else if(0 != *third && *third == *fourth)
        {
            *third *= 2;
            *fourth = 0;
        }else if(0 == *third)
        {
            if(*second == *fourth)
            {
                *second = 2 * *fourth;
                *fourth = 0;
            }else{
                *third = *fourth;
                *fourth = 0;
            }
        }
    }else if(0 == *first && 0 == *second)
    {
        if(0 != *third && *third == *fourth)
        {
            *first = 2 * *third;
            *third = *fourth = 0;
        }else if(0 != *third)
        {
            *first = *third;
            *second = *fourth;
            *third = *fourth = 0;
        }else
        {
            *first = *fourth;
            *fourth = 0;
        }
    }else if(0 == *first && 0 != *second)
    {
        if(*second == *third)
        {
            *first = 2 * *second;
            *second = *fourth;
            *fourth = 0;
        }else if(0 != *third && *third == *fourth)
        {
            *first = *second;
            *second = 2 * *third;
            *third = *fourth = 0;
        }else if(0 == *third)
        {
            if(*second == *fourth)
            {
                *first = 2 * *second;
                *second = *fourth = 0;
            }else{
                *first = *second;
                *second = *fourth;
                *fourth = 0;
            }
        }else if(0 != *third){
            *first = *second;
            *second = *third;
            *third = *fourth;
            *fourth = 0;
        }
    }else{
        if(*first == *third)
        {
            *first *= 2;
            *second = *fourth;
            *third = 0;
            *fourth = 0;
        }else if(0 != *third && *third == *fourth)
        {
            *second = 2 * *third;
            *third = *fourth = 0;
        }else if(0 == *third)
        {
            if(*first == *fourth)
            {
                *first = 2 * *fourth;
                *fourth = 0;
            }else {
                *second = *fourth;
                *fourth = 0;
            }
        }else if(0 != *third)
        {
            *second  = *third;
            *third = *fourth;
            *fourth = 0;
        }

    }

}

int Game2048::randomPostionGenerator()
{
    int pos = dis_(eng_);
    if(data_->at(pos) == 0)
        return pos;
    for(int i = 0; i < 16; ++i)
    {
        if(pos >= 15)
            pos = 0;
        if(data_->at(++pos)== 0)
            return pos;
    }
    return -1;
}

void Game2048::debug()
{
    for(auto beg = data_->begin(); beg != data_->end(); ++beg)
    {
        cout<<*beg<<" ";
        if((beg - data_->begin() + 1) % 4 == 0 )
            cout<<endl;
    }
}
