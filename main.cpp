#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "CRC.h"

using namespace std;

int main()
{
    ifstream ifs("/Users/shanesepac/Desktop/png_sample.png", ios::binary | ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    std::vector<char> result(pos);

    ifs.seekg(0, ios::beg);
    ifs.read(&result[0], pos);

    //length, chunkType type, chunk data, CRC
    //length is the number of bytes in the chunk data
    //CRC calculated on type code + data, not length.
    std::vector<char> chunkType = {'t', 'E', 'X', 't'};
    std::vector<char> chunkData = {'i', 'p', 'f', 's', 0x0, 't', 'e', 's', 't'};

    //Get length
    int length = chunkData.size();

    std::vector<char> chunkTypeData = chunkType;
    chunkTypeData.insert(chunkTypeData.end(), chunkData.begin(), chunkData.end());

    CRC crcClass;
    unsigned long crc = crcClass.crc(reinterpret_cast<unsigned char*>(chunkTypeData.data()), chunkTypeData.size());

    char* chunkAllData;
    chunkAllData = (char*)malloc(12+length);
    memcpy(&chunkAllData[0], &length, 4);
    memcpy(&chunkAllData[4], chunkType.data(), 4);
    memcpy(&chunkAllData[8], chunkData.data(), length);
    memcpy(&chunkAllData[8+length], &crc, 4);

    std::reverse(&chunkAllData[0], &chunkAllData[0]+4);
    std::reverse(&chunkAllData[8+length], &chunkAllData[8+length]+4);

    //Convert char* to vector
    std::vector<char> chunkAllDataVector(chunkAllData, chunkAllData + length+12);

    //inject the new chunk into the png
    result.insert(result.end()-12, std::begin(chunkAllDataVector), std::end(chunkAllDataVector));

    //output file
    ofstream fout("/Users/shanesepac/Desktop/png_sample_out3.png", ios::out | ios::binary);
    fout.write((char*)&result[0], result.size());
    fout.close();


/*    for (auto & element : result)
    {
        std::cout << std::setfill('0')
                  << std::setw(2)
                  << std::uppercase
                  << std::hex << (0xFF & element) << " ";
    }*/
    //49 45 4E 44 (IEND CHUNK, static)
    //CRC at end of file: AE 42 60 82

    return 0;
}