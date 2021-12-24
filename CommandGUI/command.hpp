//
//  command.hpp
//  CS3307_A
//
//  Created by David Shang on 2021-09-23.
//
#ifndef command_hpp
#define command_hpp
#include <boost/process.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/join.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
class command{
private:
    string cmd;
    string para;
    string entire;
    string result;
    int code;
public:
    command(string);
    string get_command();
    string get_result();
    void execute();
    int get_code();
    ~command(){
    }
};
#endif /* command_hpp */
