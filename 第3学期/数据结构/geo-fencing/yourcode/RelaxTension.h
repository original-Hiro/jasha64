#pragma once

template <class T>
inline void Relax(T& a, const T b) {if (a > b) a = b;}
template <class T>
inline void Tension(T& a, const T b) {if (a < b) a = b;}

