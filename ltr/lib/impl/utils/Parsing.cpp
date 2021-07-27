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
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#include "../../api/utils/Parsing.hpp"
#include "../../api/utils/LtrError.hpp"

#include <string>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/info_parser.hpp>

void ltr::save(std::ofstream& file, pt::ptree property_tree, ltr::parser_t type) {

    switch (type) {
        case ltr::dot_info: 
            pt::write_info(file, property_tree);
        break;
        case ltr::dot_json:
            pt::write_json(file, property_tree);
        break;
        case ltr::dot_xml:
            pt::write_xml(file, property_tree);
        break;
    }
    
}

void ltr::load(std::ifstream& file, pt::ptree& property_tree, string extension) {

    if (std::strcmp(extension.c_str(), ".json") == 0) {
        pt::read_json(file, property_tree);
    }
    else if (std::strcmp(extension.c_str(), ".xml") == 0) {
        pt::read_xml(file, property_tree);
    }
    else if (std::strcmp(extension.c_str(), ".info") == 0) {
        pt::read_info(file, property_tree);
    }
    else throw ltr::LtrError("Error in ltr::load() : invalid format of input file.");

}

