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
#include <vector>
#include <iostream>

void ContainerTests::runAllContainerTests()
{
    std_vector_push_back(1000);
    std_vector_push_back(1000000);
    std_vector_push_back(1000000000);
}

void ContainerTests::std_vector_push_back(size_t count)
{
    std::vector<int> theVector;

    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < count; ++i)
    {
        theVector.push_back(i);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = endTime - startTime;
    std::cout << "std::vector::push_back " << Utilities::formatNumber(count) << " items: " << diff.count() << "s" << std::endl;
}
