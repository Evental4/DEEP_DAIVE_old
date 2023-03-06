
#include "TXLib.h"

int main()
{
txCreateWindow (800, 600);

  HDC fon= txLoadImage("fon.bmp");
  HDC dvarf= txLoadImage("dvarf_min.bmp");
  int x_dvarf =400;
    while(!txGetAsyncKeyState (VK_ESCAPE))
{

   txBegin();

   txClear ();

    txBitBlt(txDC() ,0 ,0, 800,600, fon);
    txTransparentBlt(txDC() , x_dvarf  ,300, 100,200,dvarf, 0 ,0 , TX_white);


    if(txGetAsyncKeyState ('D'))
    {
    x_dvarf += 10;
    }

    if(txGetAsyncKeyState ('A'))
    {
    x_dvarf -= 10;
    }

   txEnd();
   txSleep(20);


}

  txDeleteDC (fon);

  txDeleteDC (dvarf );


    txTextCursor (false);
    return 0;
}
