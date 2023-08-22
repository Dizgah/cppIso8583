#include "cppiso8583.h"

#include "dl_iso8583.h"
#include "dl_iso8583_defs_1987.h"
#include "dl_output.h"


cppIso8583::cppIso8583()
{
    DL_ISO8583_HANDLER isoHandler;
    DL_ISO8583_MSG     isoMsg;
    DL_UINT8           packBuf[1000];
    DL_UINT16          packedSize;

    /* get ISO-8583 1993 handler */
    DL_ISO8583_DEFS_1993_GetHandler(&isoHandler);


    /* initialise ISO message */
    DL_ISO8583_MSG_Init(NULL,0,&isoMsg);
}

cppIso8583::~cppIso8583()
{

}

