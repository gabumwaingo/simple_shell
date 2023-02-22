#include <stdio.h>

extern  struct  _iobuf {
    char    *_ptr;
    int     _cnt;
    char    *_base;
    char    _flag;
    char    _file;
} _iob[_NFILE];

#define _IOEOF  020

#define feof(p)         (((p)->_flag&_IOEOF)!=0)

#define getc(p)         (--(p)->_cnt>=0? *(p)->_ptr++&0377:_filbuf(p))

int _filbuf(FILE *iop)
{

    iop->_ptr = iop->_base;
    iop->_cnt = read(fileno(iop), iop->_ptr, BUFSIZ);
    if (iop->_cnt == 0) {
            iop->_flag |= _IOEOF;
            return(EOF);
    }
    return(*iop->_ptr++ & 0377);
}


