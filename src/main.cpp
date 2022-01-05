#include <iostream>
#include <boost/program_options.hpp>
#include "Compressor.h"
using namespace std;

int main() {
    namespace  po = boost::program_options;
    std::string infile,outfile;
    int num_thr;
    std::srand(unsigned(std::time(0)));
    std::cout << "Hello, World!" << std::endl;
    std::string working_dir;
    po::options_description desc("Allowed options");
    size_t n,k,l;
    desc.add_options()(
            "input-file,i",
            po::value<std::string>(&infile),
            "input file name")(
            "output-file,o",po::value<std::string>(&outfile)->default_value("output"),
            "output file name")(
            "num-threads,t", po:value<int>(&num_thr)->default_value(20),
            "number of threads (default 20)")(
            "kmer,k", po::value<size_t>(&k)->default_value(23),"kmer size for the minhash (default 23)")(
             "L,l",po::value<::size_t>(&l)->default_value(2),"l size for omh (default 2)")(
            "num-hash,n", po::value<size_t>(&n)->default_value(60));
    try
    {
        Compressor compressor;
        compressor.n=n;
        compressor.k=k;
        compressor.l=l;
        const std::string filename(infile);
        const std::string extension =
                filename.substr(filename.find_last_of('.') + 1);
        if (!extension.compare("gz"))
            compressor.filetype = ReadData::Filetype::GZIP;
        else if (!extension.compare("fastq"))
            compressor.filetype = ReadData::Filetype::FASTQ;
    }catch(std::runtime_error& e){

    }
    return 0;
}


