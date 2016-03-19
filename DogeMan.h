#ifndef DOGEMAN_H
#define DOGEMAN_H

class DogeMan
{
    public:
        DogeMan(char* name);
        virtual ~DogeMan();

        int posx;
        int posy;
        int jumping;
        int landing;
        char* GetName();
        bool IsAlive();
        int GetScore();
        int GetLives();
        char* GetBody();
        void Move(int x, int y);
        void ResetBody();
        void jump();
    protected:
    private:
        char* name;
        bool alive;
        int score;
        int lives;
        char body[100];
        void CreateBody();
};

#endif // DOGEMAN_H
