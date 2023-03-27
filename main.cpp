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
    HDC fon_1= txLoadImage("geme.bmp");

    Per dvarf ={400,300,txLoadImage("dvarf_min.bmp"),txLoadImage("dvarf_min_raite.bmp"),dvarf.image_left,100,200,10,10};
    Per bob   ={200,216, txLoadImage("draf_left.bmp"),txLoadImage("draf_raite.bmp"),bob.image_left,100,200,10,10};
    Per ckelet={10,10,txLoadImage("ckelet_left.bmp"),txLoadImage("ckelet_raite.bmp"),ckelet.image_raite,193,220,5,5 };
    Per gami  ={50,420,txLoadImage("gami_raite.bmp"),txLoadImage("gami_left.bmp"),gami.image_raite,150,75,10,10 };
    Per doov  ={0,0,txLoadImage("2doov_left.bmp"),txLoadImage("2doov_raite.bmp"),doov.image_raite,150,300,10,10 };

    char str[20];
    int live =5;

    while(!txGetAsyncKeyState (VK_ESCAPE))
    {
        txSetColor(TX_BLACK);
        txBegin();
        txClear ();
        //���������
        txBitBlt(txDC() ,0 ,0, 800,600, fon);
        dvarf.draw();
        bob.draw();
        ckelet.draw();
        gami.draw();
        doov.draw();
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

         gami.x= gami.x + gami.vx;
        if ( gami.x<0 ||  gami.x+ gami.w>800)
            gami.vx =- gami.vx;
        if( gami.vx>0)  gami.image= gami.image_raite;
        else  gami.image= gami.image_left;

        if(gami.x >bob.x)
        {
            gami.x =10;
        }

          if(  gami.x +  gami.w > bob.x &&  gami.x < bob.x + bob.w &&
             gami.y +  gami.h > bob.y &&  gami.y < bob.y + 30)
          {
           live --;
           gami.x=50;
          }
           sprintf(str, "�����  -%d", live) ;
           txTextOut(650,10,str)  ;



        // ������� ��.
        if( dvarf.x + dvarf.w > bob.x && dvarf.x < bob.x + bob.w &&
            dvarf.y + dvarf.h > bob.y && dvarf.y < bob.y + bob.h)
        {
        txTextOut(10,10,"�������");
        }

        if (live<0)
        {
        txBitBlt(txDC() ,0 ,0, 800,600, fon_1);
        break;
        }
        txEnd();
        txSleep(20);


    }

    txDeleteDC (fon);
    txDeleteDC (ckelet.image);
    txDeleteDC (dvarf.image);
    txDeleteDC (bob.image);
    txDeleteDC (gami.image);
    txDeleteDC (doov.image);

txTextCursor (false);
return 0;
}
