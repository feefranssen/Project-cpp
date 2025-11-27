#ifndef UTILS_H
#define UTILS_H

namespace Game {

// Template functie: houdt een waarde tussen min en max
template<typename T>
T clamp(T value, T min, T max) {
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

}

#endif
