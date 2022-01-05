//
// Created by USER on 2022/1/4.
//

#ifndef MY_COMPRESS_COMPRESS_H
#define MY_COMPRESS_COMPRESS_H
#include <string>
#include "ReadData.h"
class Compressor
{
public:
    size_t n,k,l;
    ReadData::Filetype filetype = ReadData::Filetype::READ;
//    ReadAligner *rA;
    /*!
     *
     * @param inputFileName
     * @param numThr
     */
    void compress(const char *inputFileName, const int numThr);
};
#endif //MY_COMPRESS_COMPRESS_H
