#ifndef OBSTACLES_H
#define OBSTACLES_H


class Obstacles
{
    public:
        Obstacles(int width, int height);
        virtual ~Obstacles();

        int GetWidth();
        int GetHeight();
    protected:
    private:
        int width;
        int height;
};

#endif // OBSTACLES_H
