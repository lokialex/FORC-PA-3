//
// Created by emmik on 19/02/2021.
//

#include "Decompressor.h"



Decompressor::Decompressor(DecodeInfo *decode_info) {
    this->decode_info = decode_info;
}

Decompressor::~Decompressor() {
    delete this->decode_info;
}

bool is_bit_set(char byte, int k){
    if (byte & (1 << (7-k))){
        return true;
    }
    else{
        return false;
    }
}

void Decompressor::decompress(ifstream &in_stream, ofstream &out_stream) {
    cout << "THIS IS WHAT I WANT TO SEE" << endl;
    auto byte = 0;
    Node* current_node = this->decode_info->get_root();
    in_stream.get();
    int bit_count = 0;
    while (!in_stream.eof() && bit_count < *this->decode_info->get_bit_count()){
        byte = in_stream.get();
//        cout << hex << byte << endl;
        for(int i = 0; i < 8; i++){


            if(current_node->get_data()->get_value() != '\0'){
                out_stream << current_node->get_data()->get_value();
                current_node = this->decode_info->get_root();
            }

            if(is_bit_set(byte, i)){
                current_node = current_node->get_right();
            }
            else{
                current_node = current_node->get_left();
            }
            if(bit_count == *this->decode_info->get_bit_count()) {
                break;
            }
            bit_count++;
        }


    }
}












