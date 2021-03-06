// ic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>
#include <conio.h>
#include "StopWatch.h"
//#include "mmio.cpp"
#include "mmio.h"



int _tmain(int argc, _TCHAR* argv[])
{
    _ASSERTE(create_very_big_file(L"big.txt",4000));

    StopWatch sw2;
    sw2.Start();
    _ASSERTE(file_copy_using_memory_map(L"big.txt", L"big3.txt"));
    sw2.Stop();
    print("info] time elapsed = %f", sw2.GetDurationSecond());
    _ASSERTE(file_copy_using_read_write(L"big.txt", L"big2.txt"));
    sw2.Stop();
    print("info] time elapsed = %f", sw2.GetDurationSecond());

    

    return 0;
}

