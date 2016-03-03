#ifndef DOGEMAN_H
#define DOGEMAN_H


class DogeMan
{
    public:
        DogeMan(char* name);
        virtual ~DogeMan();

        char* GetName();
        bool IsAlive();
        int GetScore();
        int GetLives();

    protected:
    private:
        char* name;
        bool alive;
        int score;
        int lives;

};

#endif // DOGEMAN_H
