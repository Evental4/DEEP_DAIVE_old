#include "TXLib.h"

int main()
{
txCreateWindow (800, 600);

    HDC fon= txLoadImage("fon.bmp");

    HDC dvarf= txLoadImage("dvarf_min.bmp");
    HDC dvarf_raite= txLoadImage("dvarf_min_raite.bmp");
    HDC dvarf_1=dvarf ;
    int x_dvarf =400;
    int y_dvarf =300;
    int vx_dvarf =10;
    int w_dvarf  =100;
    int h_dvarf  =200;

    HDC bob_1= txLoadImage("draf_raite.bmp");
    HDC bob_2= txLoadImage("draf_left.bmp");
    HDC bob=bob_2;
    int x_bob =200;
    int y_bob =216;
    int vx_bob =10;
    int w_bob  =100;
    int h_bob  =200;
    HDC ckelet_raite= txLoadImage("ckelet_raite.bmp");
    HDC ckelet_left= txLoadImage("ckelet_left.bmp");
    HDC ckelet= ckelet_raite;
    int x_ckelet=10 ;
    int y_ckelet=10 ;
    int vx_ckelet =5;
    int w_ckelet  =193;
    int h_ckelet  =220;

    while(!txGetAsyncKeyState (VK_ESCAPE))
    {

        txBegin();
        txClear ();
        //���������
        txBitBlt(txDC() ,0 ,0, 800,600, fon);
        txTransparentBlt(txDC() , x_dvarf  ,y_dvarf, w_dvarf,h_dvarf,dvarf_1, 0 ,0 , TX_white);
        txTransparentBlt(txDC() ,x_bob , y_bob, w_bob ,h_bob,bob, 0 ,0 , TX_white);
        txTransparentBlt(txDC() , x_ckelet,y_ckelet,w_ckelet,h_ckelet ,ckelet, 0 ,0 , TX_white);
        //�������� ��.
        //dvarf ������.
        if(txGetAsyncKeyState ('D'))
        {
            x_dvarf += vx_dvarf;
            dvarf_1= dvarf_raite;
        }

        if(txGetAsyncKeyState ('A'))
        {
            x_dvarf -= vx_dvarf;
            dvarf_1=dvarf;
        }
        if(txGetAsyncKeyState ('W'))
        {
            y_dvarf -= vx_dvarf;
        }
        if(txGetAsyncKeyState ('S'))
        {
            y_dvarf +=vx_dvarf;
        }
        //draf ������������
        if(txGetAsyncKeyState ('L'))
        {
            x_bob += vx_bob;
            bob=bob_1;
        }

        if(txGetAsyncKeyState ('J'))
        {
            x_bob-= vx_bob;
            bob=bob_2;
        }
        if(txGetAsyncKeyState ('I'))
        {
           y_bob-= vx_bob;
        }
        if(txGetAsyncKeyState ('K'))
        {
            y_bob += vx_bob;
        }
        //�������� ��
        x_ckelet=x_ckelet +vx_ckelet;
        if (x_ckelet<0 || x_ckelet+w_ckelet>800)
            vx_ckelet =-vx_ckelet;
        if(vx_ckelet>0) ckelet=ckelet_raite;
        else ckelet=ckelet_left;

        txEnd();
        txSleep(20);


    }

    txDeleteDC (fon);
    txDeleteDC (ckelet_raite );
    txDeleteDC (ckelet_left );
    txDeleteDC (dvarf_1 );
    txDeleteDC (bob_1);
    txDeleteDC (bob_2);

txTextCursor (false);
return 0;
}
