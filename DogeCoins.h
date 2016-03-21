#ifndef DOGECOINS_H
#define DOGECOINS_H


class DogeCoins
{
    public:
        DogeCoins();
        virtual ~DogeCoins();

        int posx;
        int posy;
        int scorevalue;
        int length;
        char* GetBody();
        void CreateCoin();
        void ResetBody();

        void Move(int x, int y);
    protected:
    private:
        char body[100];

};

#endif // DOGECOINS_H
