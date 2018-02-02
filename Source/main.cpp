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

#include "ContainerTests.h"
#include "Utilities.h"
#include <chrono>
#include <iostream>
#include <set>
#include <unordered_set>

void set_insert(size_t count)
{
    std::set<int> theSet;

    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; ++i)
    {
        theSet.insert(i);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "std::set::insert " << Utilities::formatNumber(count) << " items: " << diff.count() << "s" << std::endl;
}

void unordered_set_insert(size_t count)
{
    std::unordered_set<int> theUnorderedSet;

    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; ++i)
    {
        theUnorderedSet.insert(i);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "std::unordered_set::insert " << Utilities::formatNumber(count) << " items: " << diff.count() << "s" << std::endl;
}

int main(int argc, char* argv[])
{
    ContainerTests::runAllContainerTests();

    std::cout << std::endl;

    set_insert(1000);
    set_insert(1000000);
    set_insert(100000000);

    std::cout << std::endl;

    unordered_set_insert(1000);
    unordered_set_insert(1000000);
    unordered_set_insert(100000000);

    return 0;
}
