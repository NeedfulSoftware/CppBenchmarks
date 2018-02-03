/*
    Copyright (c) 2018 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "MemoryTests.h"
#include "Utilities.h"
#include <chrono>
#include <iostream>

void MemoryTests::runAllMemoryTests()
{
    for (size_t i = 1; i <= 1000000000; i *= 10)
    {
        memset(i);
    }

    std::cout << std::endl;

    for (size_t i = 1; i <= 1000000000; i *= 10)
    {
        memmove1(i);
    }

    std::cout << std::endl;

    for (size_t i = 1; i <= 1000000000; i *= 10)
    {
        memmove2(i);
    }

    std::cout << std::endl;

    for (size_t i = 1; i <= 100000000; i *= 10)
    {
        memmove3(i);
    }

    std::cout << std::endl;
}

void MemoryTests::memset(size_t count)
{
    char* buffer = new char[count];

    auto startTime = std::chrono::high_resolution_clock::now();

    ::memset(buffer, 0, count);

    auto endTime = std::chrono::high_resolution_clock::now();

    delete[] buffer;

    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "memset " << Utilities::formatNumber(count) << " bytes: " << diff.count() << "s" << std::endl;
}

void MemoryTests::memmove1(size_t count)
{
    char* buffer1 = new char[count];
    char* buffer2 = new char[count];

    auto startTime = std::chrono::high_resolution_clock::now();

    memmove(buffer2, buffer1, count);

    auto endTime = std::chrono::high_resolution_clock::now();

    delete[] buffer1;
    delete[] buffer2;

    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "memmove " << Utilities::formatNumber(count) << " bytes: " << diff.count() << "s" << std::endl;
}

void MemoryTests::memmove2(size_t count)
{
    char* buffer1 = new char[count];
    char* buffer2 = new char[count];
    char* buffer3 = new char[count];

    memmove(buffer2, buffer1, count);

    auto startTime = std::chrono::high_resolution_clock::now();

    memmove(buffer3, buffer2, count);

    auto endTime = std::chrono::high_resolution_clock::now();

    delete[] buffer1;
    delete[] buffer2;
    delete[] buffer3;

    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "memmove " << Utilities::formatNumber(count) << " bytes: " << diff.count() << "s" << std::endl;
}

void MemoryTests::memmove3(size_t count)
{
    char* buffer1 = new char[count];
    char* buffer2 = new char[count];

    auto startTime = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < 10000; ++i)
    {
        memmove(buffer2, buffer1, count);
    }

    auto endTime = std::chrono::high_resolution_clock::now();

    delete[] buffer1;
    delete[] buffer2;

    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "memmove " << Utilities::formatNumber(count) << " bytes: " << diff.count() << "s" << std::endl;
}
