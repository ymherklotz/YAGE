/** ---------------------------------------------------------------------------
 * @file: system.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_ENGINE_SYSTEM_H
#define YAGE_ENGINE_SYSTEM_H

namespace yage
{

/**
 * System interface for the different systems in the engine.
 */
class System
{
public:
    /**
     * Virtual destructor to destroy all the objects that implement this
     * properly.
     */
    virtual ~System() = 0;

    /**
     * Initializes the system. Good practice to have this function instead
     * using the constructor.
     */
    virtual void init() = 0;

    /**
     * Updates the system at each interval using the time step.
     *
     * @param dt The time difference between the previous frame and the current one.
     */
    virtual void update(double dt) = 0;
};

/**
 * Implement the default destructor, but leaving it as purely virtual in the
 * definition of the abstract class. This is so that the classes that implement
 * the abstract class have to implement a desctructor, but at the same time,
 * that there is no undefined behavious when the stack unwinds to the system and
 * calls the system destructor.
 */
inline System::~System() {}

} // namespace yage

#endif
