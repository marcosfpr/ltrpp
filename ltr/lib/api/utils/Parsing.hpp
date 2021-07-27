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

#ifndef LTR_PARSING_HPP_
#define LTR_PARSING_HPP_

#include <fstream>
#include <string>

#include <boost/property_tree/ptree.hpp>
namespace pt = boost::property_tree;

using std::string;

namespace ltr {

    /**
     * @brief Parsing types of ltr models
     * 
     */
    enum parser_t{
        dot_json,
        dot_xml,
        dot_info
    };

    /**
     * @brief Unsafe method that writes a property tree into a XML|JSON|INFO file
     *  Unsafe because of ofstream's side effects.
     * @param file 
     * @param property_tree 
     * @param type 
     * @return true 
     * @return false 
     */
    void save(std::ofstream& file, pt::ptree property_tree, parser_t type);
    
    /**
     * @brief Unsafe method that loads a property tree from a XML|JSON|INFO file
     * Unsafe because a valid extension needs to be guaranteed
     * @param file 
     * @param property_tree 
     * @param extension 
     * @return true 
     * @return false 
     */
    void load(std::ifstream& file, pt::ptree& property_tree, string extension);
}


#endif