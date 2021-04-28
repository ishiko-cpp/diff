/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "TextChunk.h"

namespace Ishiko
{
namespace Diff
{

TextChunk::TextChunk(Type type, const std::string& text)
    : m_type(type), m_text(text)
{
}

TextChunk::Type TextChunk::type() const
{
    return m_type;
}

const std::string& TextChunk::text() const
{
    return m_text;
}

}
}