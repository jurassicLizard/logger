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
 
#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <iostream>
#include <sstream>

class StdoutRedirector {
private:
    std::streambuf* original_buf_;
    std::streambuf* err_original_buf_;
    std::stringstream stream_;
    std::stringstream err_stream_;

public:
    StdoutRedirector() {
        // Save original buffer and redirect stdout
        original_buf_ = std::cout.rdbuf();
        err_original_buf_ = std::cerr.rdbuf();
        std::cout.rdbuf(stream_.rdbuf());
        std::cerr.rdbuf(err_stream_.rdbuf());
    }

    ~StdoutRedirector() {
        // Restore original buffer
        std::cout.rdbuf(original_buf_);
        std::cerr.rdbuf(err_original_buf_);
    }

    std::string str_out() const {
        return stream_.str();
    }
    std::string str_err() const {
        return err_stream_.str();
    }
};


#endif //UNIT_TESTS_H
