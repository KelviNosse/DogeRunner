#ifndef OBSTACLES_H
#define OBSTACLES_H


class Obstacles
{
    public:
        Obstacles(int width, int height);
        virtual ~Obstacles();

        int GetWidth();
        int GetHeight();
        void SetWidth(int w);
        void SetHeight(int h);
        int posx;
        int posy;
        char* GetBox();
        void Move(int x, int y);
    protected:
    private:
        int width;
        int height;
        char box[100];
        void CreateBox();
};

#endif // OBSTACLES_H
