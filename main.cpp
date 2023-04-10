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

 struct Button
 {
   int x;
   int y;
   int w;
   int h;
   const char* text;

   void draw()
   {
    txSetColor(TX_BLACK);
    txSetFillColor(TX_white);
    txRectangle(x,y,x+w,y+h);
    txDrawText(x,y,x+w,y+h, text);
   }

   bool click()
   {
   if(txMouseButtons() == 1 &&
            txMouseX() >x && txMouseX() <x+w &&
            txMouseY() >y && txMouseY() <y+h)
           {
               return true;
           }
           else
           {
              return false;
           }
   }
 } ;

int main()
{
txCreateWindow (800, 600);

    HDC fon= txLoadImage("fon.bmp");
    HDC fon_1= txLoadImage("geme.bmp");
    HDC fon_0= txLoadImage("fon_0.bmp");

    Per dvarf ={400,300,txLoadImage("megig_dfar_left.bmp"),txLoadImage("megig_dfar_raite.bmp"),dvarf.image_left,100,200,10,10,true};
    Per ckelet={10,10,txLoadImage("ckelet_left.bmp"),txLoadImage("ckelet_raite.bmp"),ckelet.image_raite,193,220,5,5,true };
    Per gami  ={50,420,txLoadImage("gami_raite.bmp"),txLoadImage("gami_left.bmp"),gami.image_raite,150,75,10,10,true };
    Per doov  ={0,0,txLoadImage("2doov_left.bmp"),txLoadImage("2doov_raite.bmp"),doov.image_raite,150,300,10,10,true };
    ziod kam  ={300,50,txLoadImage("doi.bmp"),100,75,true};

    Bool bul={dvarf.x+dvarf.w/2,dvarf.y,15,false};

    Button bth_start={50,50,250,50,"Играть"};
    Button bth_About={50,150,250,50,"Об игре"};
    Button bth_exit={50,200,250,50,"Выход"};

    char str[20];
    int live =10;

    string PAGE="Menu";

    while(true)
    {
        txBegin();
           if (txGetAsyncKeyState (VK_ESCAPE))PAGE="Menu";

           if (PAGE=="Menu")
           {

            txClear ();
            txBitBlt(txDC() ,0 ,0, 800,600, fon_0);

            bth_start.draw();
            if (bth_start.click())PAGE="Game";
            bth_About.draw();
            if (bth_About.click()) PAGE="About" ;
            bth_exit.draw();
            if(bth_exit.click())
            {
             txDisableAutoPause ();
             return  0;
            }
           }
           if (PAGE=="About")
           {
            txSetColor(TX_BLACK);
            txClear ();
           }

           if (PAGE=="Game")
           {
            txSetColor(TX_BLACK);
            txClear ();
            //рисование
            txBitBlt(txDC() ,0 ,0, 800,600, fon);
            dvarf.draw();
            kam.draw();
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

            if(txGetAsyncKeyState (VK_SPACE))
            {

             bul.x=dvarf.x+dvarf.w/2,dvarf.y;
             bul.y=dvarf.y ;
              bul.visible= true;
            }
            //пуля
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

            //движение ии

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
               sprintf(str, "жизнь  -%d", live) ;
               txTextOut(650,10,str)  ;

              if(  ckelet.x +  ckelet.w > dvarf.x &&  ckelet.x < dvarf.x + dvarf.w &&
                ckelet.y +  ckelet.h > dvarf.y &&  ckelet.y <dvarf.y + 30)
              {
               live --;
               ckelet.y=400;
               ckelet.x=400;
              }
               sprintf(str, "жизнь  -%d", live) ;
               txTextOut(650,10,str)  ;


            // косание об.

            /*if( dvarf.x + dvarf.w > bob.x && dvarf.x < bob.x + bob.w &&
                dvarf.y + dvarf.h > bob.y && dvarf.y < bob.y + bob.h)
            {
            txTextOut(10,10,"касание");
            } */

            if (live<0)
            {
            txBitBlt(txDC() ,0 ,0, 800,600, fon_1);
            break;
            }
             }

        txEnd();
        txSleep(20);


    }
    txDeleteDC  (fon_0);
    txDeleteDC (fon_1);
    txDeleteDC (fon);
    txDeleteDC (ckelet.image);
    txDeleteDC (dvarf.image);
    txDeleteDC (gami.image);
    txDeleteDC (doov.image);
     txDeleteDC  (kam.image);

txTextCursor (false);
return 0;
}
