//
// Created by User on 17.06.2022.
//

#ifndef EX4_MAIN_EXCEPTIONS_H
#define EX4_MAIN_EXCEPTIONS_H

#include "exception"
#include "cstring"
class DeckFileNotFound: public std::exception{
public:

    const char* what() const noexcept override{
        return "Deck File Error: File not found";
    }

};

class DeckFileFormatError: public std::exception{
public:
    std::string m_toReturn;
    DeckFileFormatError(int line): m_toReturn("Deck File Error: File format error in line " + to_string(line)){}
    const char* what() const noexcept override{

        return  this->m_toReturn.c_str();
    }

};

class DeckFileInvalidSize: public std::exception{
public:

    const char* what() const noexcept override{
        return "Deck File Error: Deck size is invalid";
    }

};


#endif //EX4_MAIN_EXCEPTIONS_H
