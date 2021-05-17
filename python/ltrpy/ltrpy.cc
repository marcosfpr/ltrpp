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

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <ltrpp/utils.hpp>

namespace py = pybind11;
template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;
using namespace pybind11::literals;

PYBIND11_MODULE(ltrpy, lpy) {
    lpy.doc() = "Ltrpy - Learning to Rank library based on LTR++";

    py::module utils = lpy.def_submodule("utils", "Utilities used in ltrpy core.");

    utils.attr("RESET") = py::str(RESET);
    utils.attr("BLACK") = py::str(BLACK);
    utils.attr("RED") = py::str(RED);
    utils.attr("GREEN") = py::str(GREEN);
    utils.attr("YELLOW") = py::str(YELLOW);
    utils.attr("BLUE") =  py::str(BLUE);
    utils.attr("MAGENTA") =  py::str(MAGENTA); 
    utils.attr("CYAN") =  py::str(CYAN);
    utils.attr("BOLDBLACK") = py::str(BOLDBLACK); 
    utils.attr("BOLDRED") = py::str(BOLDRED); 
    utils.attr("BOLDGREEN") = py::str(BOLDGREEN);
    utils.attr("BOLDYELLOW") = py::str(BOLDYELLOW); 
    utils.attr("BOLDBLUE") = py::str(BOLDBLUE); 
    utils.attr("BOLDMAGENTA") = py::str(BOLDMAGENTA); 
    utils.attr("BOLDCYAN") = py::str(BOLDCYAN); 
    utils.attr("BOLDWHITE") = py::str(BOLDWHITE);

    py::enum_<ltr::log_level>(utils, "log_level")
        .value("info", ltr::log_level::info)
        .value("debug", ltr::log_level::debug)
        .value("warning", ltr::log_level::warning)
        .value("error", ltr::log_level::error)
        .value("critical", ltr::log_level::critical);

    utils.def("init_logging", &ltr::init_logging);

    utils.def("color_score", &ltr::color_score);

    utils.def("color_delta", &ltr::color_delta);

    utils.def("color_status", &ltr::color_status);

    utils.def("log", overload_cast_<vector<string>, bool, vector<const char*>, vector<int>>()(&ltr::log),
             "Log a set of messages into screen",
             py::arg("msg"), py::arg("header")=false,
             py::arg("colors")=vector<const char*>(), py::arg("sizes")=vector<int>());
    
    utils.def("log", overload_cast_<string, ltr::log_level, const char*, int>()(&ltr::log),
            "Log a single message into screen",
            py::arg("msg"), py::arg("type"), py::arg("color")="", py::arg("size")=0);
}