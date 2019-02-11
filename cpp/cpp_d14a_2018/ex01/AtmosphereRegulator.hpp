
#ifndef ATMOSPHERE_REGULATOR_HPP_
#define ATMOSPHERE_REGULATOR_HPP_

#include "BaseComponent.hpp"
#include "Errors.hpp"

class AtmosphereRegulator
    : public BaseComponent
{
    public:
        AtmosphereRegulator();
        virtual ~AtmosphereRegulator();
};

#endif // ATMOSPHERE_REGULATOR_HPP_
