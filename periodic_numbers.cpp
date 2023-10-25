/*
 * This program handles periodicity of circular degrees like for example,
 * 0 degree == 360 degree, 1 degree == 361 degree and so on, so if we are given a
 * degree value for example this program will provide the result in range of 0 to 360 degrees
 * for operations like addition, substraction, multiplication and division and can also provide 
 * with the signed shortest angular difference between 2 degrees. 
 */



#include<iostream>
using namespace std;

// doing with basic primitives

// addition
template<class TL, class TR>
constexpr auto circ_add(
    const TL lhs, 
    const TR rhs, 
    const decltype(lhs + rhs) rmin = 0, 
    const decltype(lhs + rhs) rmax = 360)
{
    auto result = lhs + rhs;
    auto range = rmax - rmin;

    while(result >= rmax) result -= range;
    while(result < rmin) result += range;

    return result;

}

// substraction
template<class TL, class TR>
constexpr auto circ_sub(
    const TL lhs, 
    const TR rhs, 
    const decltype(lhs + rhs) rmin = 0, 
    const decltype(lhs + rhs) rmax = 360)
{
    auto result = lhs - rhs;
    auto range = rmax - rmin;

    while(result >= rmax) result -= range;
    while(result < rmin) result += range;

    return result;

}

// multipliaction
template<class TL, class TR>
constexpr auto circ_mul(
    const TL lhs, 
    const TR rhs, 
    const decltype(lhs + rhs) rmin = 0, 
    const decltype(lhs + rhs) rmax = 360)
{
    auto result = lhs * rhs;
    auto range = rmax - rmin;

    while(result >= rmax) result -= range;
    while(result < rmin) result += range;

    return result;

}

// division
template<class TL, class TR>
constexpr auto circ_div(
    const TL lhs, 
    const TR rhs, 
    const decltype(lhs + rhs) rmin = 0, 
    const decltype(lhs + rhs) rmax = 360)
{
    auto result = lhs / rhs;
    auto range = rmax - rmin;

    while(result >= rmax) result -= range;
    while(result < rmin) result += range;

    return result;

}

// shortest distance (unsigned)
template<class TL, class TR>
constexpr auto circ_shortdist(
    const TL lhs, 
    const TR rhs, 
    const decltype(lhs + rhs) rmin = 0, 
    const decltype(lhs + rhs) rmax = 360)
{
    auto a = circ_sub(rhs, lhs, rmin, rmax);
    auto b = circ_sub(lhs, rhs, rmin, rmax);

    return min(a,b);
}

// shortest distance (signed)
template<class TL, class TR>
constexpr auto circ_shortdiff(
    const TL lhs, 
    const TR rhs, 
    const decltype(lhs + rhs) rmin = 0, 
    const decltype(lhs + rhs) rmax = 360)
{
    auto a = circ_sub(rhs, lhs, rmin, rmax);
    auto b = circ_sub(lhs, rhs, rmin, rmax);

    if(b > a)
        return a;
    else
        return -b;
}

int main()
{
    //Example
    constexpr float a = 20;
    constexpr int b = 340;

    auto c = circ_shortdist(a, b); // unsigned
    auto d = circ_shortdiff(a, b); // signed

    cout << c << " " << d << endl;
    
    return 0;
}