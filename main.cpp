#include <iostream>
#include <fstream>
#include <cstdlib>
#include<chrono>
#include<thread>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <memory>

#include "dl_iso8583.h"
#include "dl_iso8583_defs_1993.h"
#include "dl_output.h"


int main(int argc, char* argv[])
{
    DL_ISO8583_HANDLER isoHandler;
    DL_ISO8583_MSG     isoMsg;
    DL_UINT8           packBuf[1000];
    DL_UINT16          packedSize;

    /* get ISO-8583 1993 handler */
    DL_ISO8583_DEFS_1993_GetHandler(&isoHandler);
}
