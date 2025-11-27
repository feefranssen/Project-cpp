#ifndef UTILS_H
#define UTILS_H

namespace Game {

template<typename T>
T clamp(T value, T min, T max) {
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

}

#endif
