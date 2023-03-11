
#include "TXLib.h"

int main()
{
txCreateWindow (800, 600);

  HDC fon= txLoadImage("fon.bmp");
  HDC dvarf= txLoadImage("dvarf_min.bmp");
  HDC run= txLoadImage("run.bmp");
  HDC ran= txLoadImage("ran.bmp");
  int x_dvarf =400;
  int y_dvarf =300;
  int x_run =0;
  int y_run =300;
    while(!txGetAsyncKeyState (VK_ESCAPE))
{

   txBegin();

   txClear ();

    txBitBlt(txDC() ,0 ,0, 800,600, fon);
    txTransparentBlt(txDC() , x_dvarf  ,y_dvarf, 100,200,dvarf, 0 ,0 , TX_white);
    txTransparentBlt(txDC() , x_run ,y_run, 200,300,run, 0 ,0 , TX_white);
    txTransparentBlt(txDC() , 500  ,200, 300,400,ran, 0 ,0 , TX_white);
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
    x_run += 10;
    }

    if(txGetAsyncKeyState ('J'))
    {
    x_run-= 10;
    }
    if(txGetAsyncKeyState ('I'))
    {
    y_run -= 10;
    }
    if(txGetAsyncKeyState ('K'))
    {
    y_run += 10;
    }
   txEnd();
   txSleep(20);


}

  txDeleteDC (fon);
    txDeleteDC (ran );
  txDeleteDC (dvarf );
    txDeleteDC (run );

    txTextCursor (false);
    return 0;
}
