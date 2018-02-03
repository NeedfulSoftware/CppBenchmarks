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

#include "HeapAllocationTests.h"
#include "Utilities.h"
#include <chrono>
#include <vector>
#include <iostream>

void HeapAllocationTests::runAllHeapAllocationTests()
{
    for (size_t i = 1; i <= 100000000; i *= 10)
    {
        new_int(i);
    }

    std::cout << std::endl;

    for (size_t i = 1; i <= 10000000; i *= 10)
    {
        new_char256(i);
    }

    std::cout << std::endl;

    for (size_t i = 1; i <= 10000000; i *= 10)
    {
        new_char1024(i);
    }

    std::cout << std::endl;

    for (size_t i = 1; i <= 100; i *= 10)
    {
        new_char10MB(i);
    }

    std::cout << std::endl;
}

void HeapAllocationTests::new_int(size_t count)
{
    auto startTime = std::chrono::high_resolution_clock::now();

    std::vector<int*> pointers;
    pointers.resize(count);

    for (size_t i = 0; i < count; ++i)
    {
        pointers[i] = new int;
    }

    auto endTime = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < count; ++i)
    {
        delete pointers[i];
    }

    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "new " << Utilities::formatNumber(count) << " items: " << diff.count() << "s" << std::endl;
}

void HeapAllocationTests::new_char256(size_t count)
{
    auto startTime = std::chrono::high_resolution_clock::now();

    std::vector<char*> pointers;
    pointers.resize(count);

    for (size_t i = 0; i < count; ++i)
    {
        pointers[i] = new char[256];
    }

    auto endTime = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < count; ++i)
    {
        delete[] pointers[i];
    }

    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "new " << Utilities::formatNumber(count) << " items: " << diff.count() << "s" << std::endl;
}

void HeapAllocationTests::new_char1024(size_t count)
{
    auto startTime = std::chrono::high_resolution_clock::now();

    std::vector<char*> pointers;
    pointers.resize(count);

    for (size_t i = 0; i < count; ++i)
    {
        pointers[i] = new char[1024];
    }

    auto endTime = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < count; ++i)
    {
        delete[] pointers[i];
    }

    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "new " << Utilities::formatNumber(count) << " items: " << diff.count() << "s" << std::endl;
}

void HeapAllocationTests::new_char10MB(size_t count)
{
    auto startTime = std::chrono::high_resolution_clock::now();

    std::vector<char*> pointers;
    pointers.resize(count);

    for (size_t i = 0; i < count; ++i)
    {
        pointers[i] = new char[10*1024*1024];
    }

    auto endTime = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < count; ++i)
    {
        delete[] pointers[i];
    }

    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "new " << Utilities::formatNumber(count) << " items: " << diff.count() << "s" << std::endl;
}
