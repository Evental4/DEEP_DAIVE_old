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
 bool visible;


 void draw()
 {
   if(visible)
 txTransparentBlt(txDC(), x ,y, w,h,image, 0 ,0 , TX_white);
 }

};

struct ziod
{
int x;
int y;
 HDC image;
 int w;
 int h;

  void draw()
 {
   if(visible)
 txTransparentBlt(txDC(), x ,y, w,h,image, 0 ,0 , TX_white);
 }

 };
 struct Bool
 {
 int x;
 int y;
 int v;
 bool visible;

   void draw()
   {
        if (visible)
       {
        txSetColor(TX_white);
        txSetFillColor(TX_white);
        txCircle(x,y,5);
        }
   }
  };
int main()
{
txCreateWindow (800, 600);

    HDC fon= txLoadImage("fon.bmp");
    HDC fon_1= txLoadImage("geme.bmp");

    Per dvarf ={400,300,txLoadImage("megig_dfar_left.bmp"),txLoadImage("megig_dfar_raite.bmp"),dvarf.image_left,100,200,10,10,true};
    Per ckelet={10,10,txLoadImage("ckelet_left.bmp"),txLoadImage("ckelet_raite.bmp"),ckelet.image_raite,193,220,5,5,true };
    Per gami  ={50,420,txLoadImage("gami_raite.bmp"),txLoadImage("gami_left.bmp"),gami.image_raite,150,75,10,10,true };
    Per doov  ={0,0,txLoadImage("2doov_left.bmp"),txLoadImage("2doov_raite.bmp"),doov.image_raite,150,300,10,10,true };
    ziod kam  ={300,50,txLoadImage("doi.bmp"),doi.image,100,75,true};
    Bool bul={dvarf.x+dvarf.w/2,dvarf.y,15,false};

    char str[20];
    int live =10;

    //char str[20];
    //int protection =10;

    while(!txGetAsyncKeyState (VK_ESCAPE))
    {
        txSetColor(TX_BLACK);
        txBegin();
        txClear ();
        //���������
        txBitBlt(txDC() ,0 ,0, 800,600, fon);
        dvarf.draw();
        kam.draw();
        ckelet.draw();
        gami.draw();
        doov.draw();
        bul.draw();
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

        if(txGetAsyncKeyState (VK_SPACE))
        {

         bul.x=dvarf.x+dvarf.w/2,dvarf.y;
         bul.y=dvarf.y ;
          bul.visible= true;
        }
        //����
        if(bul.visible)
        {
         bul.y-=bul.v;
        }

        if( bul.x> gami.x && bul.x< gami.x+gami.w &&
            bul.y> gami.y && bul.y< gami.y+gami.h   )
         {
           gami.visible= false;
         }
        if( bul.x> ckelet.x && bul.x< ckelet.x+ckelet.w &&
            bul.y>ckelet.y && bul.y< ckelet.y+ckelet.h   )
         {
           ckelet.visible= false;
         }

        //�������� ��

        if( ckelet.x <dvarf.x &&  ckelet.y <dvarf.y )
        {
             ckelet.y +=1;
             ckelet.x +=1;
        }
        if( ckelet.x >dvarf.x &&  ckelet.y <dvarf.y )
        {
             ckelet.y +=1;
             ckelet.x -=1;
        }
        if( ckelet.x >dvarf.x &&  ckelet.y >dvarf.y )
        {
             ckelet.y -=1;
             ckelet.x -=1;
        }
        if( ckelet.x <dvarf.x &&  ckelet.y >dvarf.y )
        {
            ckelet.y -=1;
            ckelet.x +=1;
        }

        if(gami.x <dvarf.x && gami.y <dvarf.y )
        {
            gami.y +=1;
            gami.x +=1;
        }
        if(gami.x >dvarf.x && gami.y <dvarf.y )
        {
            gami.y +=1;
            gami.x -=1;
        }
        if(gami.x >dvarf.x && gami.y >dvarf.y )
        {
            gami.y -=1;
            gami.x -=1;
        }
        if(gami.x <dvarf.x && gami.y >dvarf.y )
        {
            gami.y -=1;
            gami.x +=1;
        }

          if(  gami.x +  gami.w > dvarf.x &&  gami.x < dvarf.x +dvarf.w &&
             gami.y +  gami.h > dvarf.y &&  gami.y <dvarf.y + 30)
          {
           live --;
           gami.y=50;
          }
           sprintf(str, "�����  -%d", live) ;
           txTextOut(650,10,str)  ;

          if(  ckelet.x +  ckelet.w > dvarf.x &&  ckelet.x < dvarf.x + dvarf.w &&
            ckelet.y +  ckelet.h > dvarf.y &&  ckelet.y <dvarf.y + 30)
          {
           live --;
           ckelet.y=400;
           ckelet.x=400;
          }
           sprintf(str, "�����  -%d", live) ;
           txTextOut(650,10,str)  ;


        // ������� ��.

        /*if( dvarf.x + dvarf.w > bob.x && dvarf.x < bob.x + bob.w &&
            dvarf.y + dvarf.h > bob.y && dvarf.y < bob.y + bob.h)
        {
        txTextOut(10,10,"�������");
        } */

        if (live<0)
        {
        txBitBlt(txDC() ,0 ,0, 800,600, fon_1);
        break;
        }


        txEnd();
        txSleep(20);


    }

    txDeleteDC (fon_1);
    txDeleteDC (fon);
    txDeleteDC (ckelet.image);
    txDeleteDC (dvarf.image);
    //txDeleteDC (bob.image);
    txDeleteDC (gami.image);
    txDeleteDC (doov.image);

txTextCursor (false);
return 0;
}
