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

        void CreateCoin();
    protected:
    private:
        int length;
        char body[100];

};

#endif // DOGECOINS_H
