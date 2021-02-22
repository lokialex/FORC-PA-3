

#ifndef FORC_PA_3_COMPRESSOR_H
#define FORC_PA_3_COMPRESSOR_H

#include "HuffmanEncoder.h"
#include "fstream"


class Compressor {
public:
    Compressor() = default;
    explicit Compressor(EncodeInfo* compression_info);
    ~Compressor();
    void compress(string file_name);

private:
    EncodeInfo* compression_info;
    void write_bytes(ofstream& out_stream);
    void write_header(ofstream& out_stream);
    void write_header2(ofstream& out_stream);
    void set_bit(char& byte, char& bit_char, int& byte_index, bool is_overflow);
};


#endif //FORC_PA_3_COMPRESSOR_H
