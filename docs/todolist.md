# TODO list

## Add Comments

### Reason

Currently there are no comments in the code. They should be added so that in the future the code
can be edited easily and improved without having to know the exact implementation of every function.

### Requirements

- It should follow the doxygen API so that documentation can easily be generated.


## Switch GPU API

### Reason

Vulkan is much more straight forward and it should be easier to understand OpenGL from it. I
also the newest API that will be used in the newest games and is supported by quite a few
graphics cards.

### Requirements

- yage shouldn't depend on GL anymore and exclusively use Vulkan libraries.

### Afterthought

In the end the library will first focus on modern OpenGL, as it is much more concise and easier to
implement initially.
