//
// Created by USER on 2022/1/4.
//
#include <iostream>
#include <omp.h>
#include <chrono>
#include "Compressor.h"
void Compressor::compress(const char *inputFileName, const int numThr)
{
        //读入数据
    std::cout<<"number of threads: "<<numThr<<std::endl;
    omp_set_num_threads(numThr);
    {
        ReadData rD;
        auto read_start = std::chrono::high_resolution_clock::now();
        rD.loadFromFile(inputFileName, filetype);
        auto read_end = std::chrono::high_resolution_clock::now();
        auto duration =
                std::chrono::duration_cast<std::chrono::milliseconds>(read_end - read_start);
        std::cout << "Reading file took " << duration.count()
                  << " milliseconds" << std::endl;
        std::cout << "After rD.loadFromFile():\n";
    }
}