#pragma once

class IShuffle
{
public:
    virtual void shuffle() = 0;
    virtual void shuffle(int i, int j) = 0;

    virtual ~IShuffle() = default;
};
