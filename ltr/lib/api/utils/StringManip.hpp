// Copyright (c) 2021 LTR++ Project (Marcos Pontes)

//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:

//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.

//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef LTR_STRMANIP_HPP
#define LTR_STRMANIP_HPP

#include <string>
#include <vector>

namespace ltr {
    /**
     * @brief Splits a string by some delimiter character
     * 
     * @param str : String to split
     * @param out : Response vector
     * @param delim : Delimiter char
     */
     void split(std::string &str, std::vector<std::string> &out, char delim);

    /**
     * @brief Trim one string
     * 
     * @param s : string to be processed
     */
     void trim(std::string &s);
    
    /**
     * @brief Trim one string from start
     * 
     * @param s : string to be processed
     */
     void rtrim(std::string &s);
    
    /**
     * @brief Trim one string from end
     * 
     * @param s : string to be processed
     */
     void ltrim(std::string &s);
}

#endif
