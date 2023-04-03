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

    Per dvarf ={400,300,txLoadImage("dvarf_min.bmp"),txLoadImage("dvarf_min_raite.bmp"),dvarf.image_left,100,200,10,10,true};
    Per bob   ={200,216, txLoadImage("draf_left.bmp"),txLoadImage("draf_raite.bmp"),bob.image_left,100,200,10,10,true};
    Per ckelet={10,10,txLoadImage("ckelet_left.bmp"),txLoadImage("ckelet_raite.bmp"),ckelet.image_raite,193,220,5,5,true };
    Per gami  ={50,420,txLoadImage("gami_raite.bmp"),txLoadImage("gami_left.bmp"),gami.image_raite,150,75,10,10,true };
    Per doov  ={0,0,txLoadImage("2doov_left.bmp"),txLoadImage("2doov_raite.bmp"),doov.image_raite,150,300,10,10,true };

    Bool bul={bob.x+bob.w/2,bob.y,15,false};

    char str[20];
    int live =10;

    while(!txGetAsyncKeyState (VK_ESCAPE))
    {
        txSetColor(TX_BLACK);
        txBegin();
        txClear ();
        //рисование
        txBitBlt(txDC() ,0 ,0, 800,600, fon);
        dvarf.draw();
        bob.draw();
        ckelet.draw();
        gami.draw();
        doov.draw();
        bul.draw();
        //движение кл.
        //dvarf передв.
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
        //draf передвижение
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
        if(txGetAsyncKeyState (VK_SPACE))
        {

         bul.x=bob.x+bob.w/2,bob.y;
         bul.y=bob.y ;
          bul.visible= true;
        }

        if(bul.visible)
        {
         bul.y-=bul.v;
        }

        if( bul.x> gami.x && bul.x< gami.x+gami.w &&
            bul.y> gami.y && bul.y< gami.y+gami.h   )
         {
           gami.visible= false;
         }

        //движение ии

        ckelet.x=ckelet.x +ckelet.vx;
        if (ckelet.x<0 || ckelet.x+ckelet.w>800)
            ckelet.vx =-ckelet.vx;
        if(ckelet.vx>0) ckelet.image=ckelet.image_raite;
        else ckelet.image=ckelet.image_left;


        if(gami.x <bob.x && gami.y <bob.y )
        {
            gami.y +=1;
            gami.x +=1;
        }
        if(gami.x >bob.x && gami.y <bob.y )
        {
            gami.y +=1;
            gami.x -=1;
        }
        if(gami.x >bob.x && gami.y >bob.y )
        {
            gami.y -=1;
            gami.x -=1;
        }
        if(gami.x <bob.x && gami.y >bob.y )
        {
            gami.y -=1;
            gami.x +=1;
        }

          if(  gami.x +  gami.w > bob.x &&  gami.x < bob.x + bob.w &&
             gami.y +  gami.h > bob.y &&  gami.y < bob.y + 30)
          {
           live --;
           gami.y=50;
          }
           sprintf(str, "жизнь  -%d", live) ;
           txTextOut(650,10,str)  ;



        // косание об.
        if( dvarf.x + dvarf.w > bob.x && dvarf.x < bob.x + bob.w &&
            dvarf.y + dvarf.h > bob.y && dvarf.y < bob.y + bob.h)
        {
        txTextOut(10,10,"касание");
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
