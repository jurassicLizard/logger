/*
 * MIT License
 * 
 * Copyright (c) 2025 Salem Bouraoui
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 */

#include "unit_tests.h"

#include <assert.h>

#include "jlizard/logger.h"

using namespace jlizard;

void test_log_error()
{
    const StdoutRedirector red;
    const std::string error_msg = "this is an error";
    logger::error(error_msg);
    const std::string output = red.str_err();


    assert(output.find("ERROR") != std::string::npos && "error string not contained");
    assert(output.find(error_msg) != std::string::npos && "error message not found");
}

void test_log_warn()
{
    const StdoutRedirector red;
    const std::string msg = "this is a warning";
    logger::warn(msg);
    const std::string output = red.str_out();

    assert(output.find("WARN") != std::string::npos && "warning string not contained");
    assert(output.find(msg) != std::string::npos && "warning message not found");
}

void test_log_info()
{
    const StdoutRedirector red;
    const std::string msg = "this is an info";
    logger::info(msg);
    const std::string output = red.str_out();

    assert(output.find("INFO") != std::string::npos && "info string not contained");
    assert(output.find(msg) != std::string::npos && "info message not found");
}

void test_log_default()
{
    const StdoutRedirector red;
    const std::string msg = "this is an info";
    logger::info(msg);
    const std::string output = red.str_out();

    assert(output.find("INFO") != std::string::npos && "info string not contained");
    assert(output.find(msg) != std::string::npos && "info message not found");
}

int main()
{
    test_log_error();
    test_log_info();
    test_log_warn();

}