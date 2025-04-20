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

#include "jlizard/logger.h"


void jlizard::logger::log(const std::string& msg,const LogLevel log_level)
{

    std::string pfx;
    std::ostream* out = &std::cout;

    switch (log_level)
    {
        case LogLevel::DEBUG:  { pfx = "DEBUG"; break;}
        case LogLevel::WARNING:{ pfx = "WARN"; break;}
        case LogLevel::ERROR:  { pfx = "ERROR"; break;}
        case LogLevel::INFO:
        default: { pfx= "INFO";}
    }

    time_t cur_time = time(nullptr);

    if (log_level == LogLevel::ERROR)
    {
        out = &std::cerr;
    }

    *out << "[" << pfx << "] " << cur_time << " : " << msg << std::endl;

}
