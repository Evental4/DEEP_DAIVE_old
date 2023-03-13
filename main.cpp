#include "TXLib.h"

int main()
{
txCreateWindow (800, 600);

  HDC fon= txLoadImage("fon.bmp");
  HDC dvarf= txLoadImage("dvarf_min.bmp");
  HDC dark_cnaite= txLoadImage("dark_cnaite.bmp");
  HDC ckelet= txLoadImage("ckelet.bmp");
  int x_dvarf =400;
  int y_dvarf =300;
  int x_dark_cnaite =200;
  int y_dark_cnaite =216;
    while(!txGetAsyncKeyState (VK_ESCAPE))
{

   txBegin();

   txClear ();

    txBitBlt(txDC() ,0 ,0, 800,600, fon);
    txTransparentBlt(txDC() , x_dvarf  ,y_dvarf, 100,200,dvarf, 0 ,0 , TX_white);
    txTransparentBlt(txDC() , x_dark_cnaite ,y_dark_cnaite, 200,216,dark_cnaite, 0 ,0 , TX_white);
    txTransparentBlt(txDC() ,177,176, 193,220,ckelet, 0 ,0 , TX_white);
    if(txGetAsyncKeyState ('D'))
    {
    x_dvarf += 10;
    }

    if(txGetAsyncKeyState ('A'))
    {
    x_dvarf -= 10;
    }
    if(txGetAsyncKeyState ('W'))
    {
    y_dvarf -= 10;
    }
    if(txGetAsyncKeyState ('S'))
    {
    y_dvarf += 10;
    }
    if(txGetAsyncKeyState ('L'))
    {
    x_dark_cnaite += 10;
    }

    if(txGetAsyncKeyState ('J'))
    {
    x_dark_cnaite-= 10;
    }
    if(txGetAsyncKeyState ('I'))
    {
    y_dark_cnaite -= 10;
    }
    if(txGetAsyncKeyState ('K'))
    {
    y_dark_cnaite += 10;
    }
   txEnd();
   txSleep(20);


}

    txDeleteDC (fon);
    txDeleteDC (ckelet );
    txDeleteDC (dvarf );
    txDeleteDC (dark_cnaite);

    txTextCursor (false);
    return 0;
}
