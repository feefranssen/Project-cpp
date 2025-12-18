#include "Utils.h"

namespace Game {

bool Utils::isLowHP(const Character& c, int threshold) {
    return c.getHealth() < threshold;
}

}
