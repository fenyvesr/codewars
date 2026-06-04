/*!
***     \file        snakeEye.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/696503a831e8e76d36706fb9
***
***     \par    Description:
***                  You are a zoologist studying the little-known Python species
***                  Applicatus Serpens Characteribus Instructus Informaticus or in
***                  short ASCII-Python.
***
***                  All known specimens share a distinctive anatomy: a head with two eyes
***                  and a tongue, followed by a segmented torso.
***
**/

#pragma once

#include <cstddef> /* Needed for std::size_t */

class SnakeEye {
    std::size_t n_{1};

public:
    constexpr SnakeEye() = default;
    explicit constexpr SnakeEye(std::size_t n) noexcept : n_{ n } {}

    [[nodiscard]] constexpr std::size_t size() const noexcept { return n_; }

    friend constexpr SnakeEye operator>(const SnakeEye& lhs,
                                        const SnakeEye& rhs) noexcept {
        return SnakeEye{ lhs.size() + rhs.size() + 3 };  // (o > o) gives 5 chars: (o>o)
    }

    friend constexpr SnakeEye operator-(const SnakeEye& s, int) noexcept {
        return SnakeEye{ s.size() + 2 }; // each -0 adds two chars: -0
    }
};
