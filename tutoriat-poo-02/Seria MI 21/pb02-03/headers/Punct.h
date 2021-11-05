#ifndef PB02_03_PUNCT_H
#define PB02_03_PUNCT_H

class Punct {
private:
    int x;
    int y;

public:
    Punct();
    Punct(int x, int y);
    ~Punct() = default;

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);
};

#endif //PB02_03_PUNCT_H
