#include "TXLib.h"

struct Per
{
 int x;
 int y;
 HDC image_left;
 HDC image_raite;
 HDC image;
 int w;
 int h;
 int vx;
 int vy;

 void draw()
 {
 txTransparentBlt(txDC(), x ,y, w,h,image, 0 ,0 , TX_white);
 }

};

int main()
{
txCreateWindow (800, 600);

    HDC fon= txLoadImage("fon.bmp");

    Per dvarf ={400,300,txLoadImage("dvarf_min.bmp"),txLoadImage("dvarf_min_raite.bmp"),dvarf.image_left,100,200,10,10};
    Per bob ={200,216, txLoadImage("draf_left.bmp"),txLoadImage("draf_raite.bmp"),bob.image_left,100,200,10,10};
    Per ckelet={10,10,txLoadImage("ckelet_left.bmp"),txLoadImage("ckelet_raite.bmp"),ckelet.image_raite,193,220,5,5 };
    Per ckelet_1={15,420,txLoadImage("ckelet_left.bmp"),txLoadImage("ckelet_raite.bmp"),ckelet.image_raite,193,220,5,5 };

    while(!txGetAsyncKeyState (VK_ESCAPE))
    {

        txBegin();
        txClear ();
        //���������
        txBitBlt(txDC() ,0 ,0, 800,600, fon);
        dvarf.draw();
        bob.draw();
        ckelet.draw();
        ckelet_1.draw();
        //�������� ��.
        //dvarf ������.
        if(txGetAsyncKeyState ('D'))
        {
            dvarf.x += dvarf.vx;
            dvarf.image= dvarf.image_raite ;
        }

        if(txGetAsyncKeyState ('A'))
        {
            dvarf.x -= dvarf.vx;
            dvarf.image=dvarf.image_left;
        }
        if(txGetAsyncKeyState ('W'))
        {
            dvarf.y -= dvarf.vy;
        }
        if(txGetAsyncKeyState ('S'))
        {
            dvarf.y +=dvarf.vy;
        }
        //draf ������������
        if(txGetAsyncKeyState ('L'))
        {
            bob.x +=bob.vx;
            bob.image=bob.image_raite ;
        }

        if(txGetAsyncKeyState ('J'))
        {
            bob.x-= bob.vx;
            bob.image=bob.image_left;
        }
        if(txGetAsyncKeyState ('I'))
        {
           bob.y-= bob.vy;
        }
        if(txGetAsyncKeyState ('K'))
        {
            bob.y += bob.vy;
        }
        //�������� ��
        ckelet.x=ckelet.x +ckelet.vx;
        if (ckelet.x<0 || ckelet.x+ckelet.w>800)
            ckelet.vx =-ckelet.vx;
        if(ckelet.vx>0) ckelet.image=ckelet.image_raite;
        else ckelet.image=ckelet.image_left;

        txEnd();
        txSleep(20);


    }

    txDeleteDC (fon);
    txDeleteDC (ckelet.image );
    txDeleteDC (dvarf.image);
    txDeleteDC (bob.image);


txTextCursor (false);
return 0;
}
