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
    HDC fon_0= txLoadImage("fon_0.bmp");

    Per dvarf ={400,300,txLoadImage("megig_dfar_left.bmp"),txLoadImage("megig_dfar_raite.bmp"),dvarf.image_left,100,200,10,10,true};
    ziod kam  ={300,50,txLoadImage("doi.bmp"),100,75,true};
    ziod kam_1  ={500,200,txLoadImage("red_doi.bmp"),100,75,true};
    ziod kam_0  ={200,400,txLoadImage("doi_blie.bmp"),100,75,true};


    Bool bul={dvarf.x+dvarf.w/2,dvarf.y,15,false};

    Button bth_start={50,50,250,50,"������"};
    Button bth_About={50,150,250,50,"�� ����"};
    Button bth_exit={50,250,250,50,"�����"};

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
            //���������
            txBitBlt(txDC() ,0 ,0, 800,600, fon);
            dvarf.draw();
            kam.draw();
            bul.draw();
            kam_1.draw();
            kam_0.draw();
            //�������� ��.
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

            if( bul.x> kam.x && bul.x< kam.x+kam.w &&
                bul.y> kam.y && bul.y< kam.y+kam.h   )
             {
               kam.visible= false;
             }
            if( bul.x> kam_1.x && bul.x< kam_1.x+kam_1.w &&
                bul.y> kam_1.y && bul.y< kam_1.y+kam_1.h   )
             {
               kam_1.visible= false;
             }
             if( bul.x> kam_0.x && bul.x< kam_0.x+kam_0.w &&
                bul.y> kam_0.y && bul.y< kam_0.y+kam_0.h   )
             {
               kam_0.visible= false;
             }
            // ������� ��.

           /* if(
                txMouseButtons() == 1 &&
                txMouseX() = kam.x && txMouseX() = kam.x + kam.w && txMouseY() = kam.y && txMouseY() = kam.y+kam.h )

            {
             kam.visible= false;
            } */


             }

        txEnd();
        txSleep(20);


    }
    txDeleteDC  (fon_0);
    txDeleteDC (fon);
    txDeleteDC (dvarf.image);
    txDeleteDC  (kam.image);
    txDeleteDC  (kam_1.image);
    txDeleteDC  (kam_0.image);
txTextCursor (false);
return 0;
}
