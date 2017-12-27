#ifndef YAGE_CORE_BATCH_H
#define YAGE_CORE_BATCH_H

namespace yage
{

/** The Batch class will be the base class for all the different batching 
 * processes that might use different shaders and attributes. This is necessary
 * because when we use a different shader, we have to bind a specific number
 * of attributes, and we might not always want to have a texture, colours and
 * coordinates, for example, when only using simple shapes.
 * 
 * Batching
 * ========
 * The purpose of batching is to combine all sprites that use the same textures
 * so that the textures does not have to be switched out on the gpu very often.
 * This produces a much more efficient rendering process. An implementation of 
 * this can be seen in the SpriteBatch class, as it sorts and renders the 
 * objects you give it.
 * 
 * The reason this base class exists, is because it makes it easier to also
 * render objects that may not need a texture, or may require multiple textures
 * or different attributes.
 */
class Batch
{
public:
    virtual bool init();
    virtual void begin();
    virtual void end();
    virtual void render();
};

} // namespace yage

#endif
