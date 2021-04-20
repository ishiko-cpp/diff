/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "Algorithms.h"
#include <Ishiko/Collections/Vector2D.h>
#include <algorithm>
#include <vector>

using namespace Ishiko::Collections;

namespace Ishiko
{
namespace Diff
{

size_t WagnerFischerAlgorithm(const std::string& originalString, const std::string& newString)
{
    Vector2D<size_t> distances(newString.size() + 1, originalString.size() + 1);

    for (size_t j = 0; j < (originalString.size() + 1); ++j)
    {
        distances.get(0, j) = j;
    }

    for (size_t i = 0; i < newString.size(); ++i)
    {
        distances.get(i + 1, 0) = (i + 1);
        for (size_t j = 0; j < originalString.size(); ++j)
        {
            size_t substitutionCost = 0;
            if (newString[i] != originalString[j])
            {
                substitutionCost = 1;
            }

            size_t insertionCost = distances.get(i, j + 1) + 1;
            size_t deletionCost = distances.get(i + 1, j) + 1;
            substitutionCost += distances.get(i, j);

            distances.get(i + 1, j + 1) = std::min({ insertionCost, deletionCost, substitutionCost });
        }
    }

    return distances.get(newString.size(), originalString.size());
}

}
}