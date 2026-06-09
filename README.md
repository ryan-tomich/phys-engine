# Physics Engine

Will have `RigidBody`
- affected by physics simulation with gravity
- example: falling crate

Will have `StaticBody`
- not affected by gravity and can't move when collided with, but still collides
- example: the ground

Will have `CharacterBody`
- not automatically affected by gravity
- probably some other stuff having to do with how it's handled in the engine

Collisions
- use a quad tree for the broad phase, (or just split the screen into sections)
- check the axis aligned bounding boxes in the narrow phase, then actually check if they intersect
- handle response

Will have a way to add custom Input bindings
- custom actions that you can map to whatever key bindings you want

`Renderer` will access the `world`'s `MeshRenderer`s and `Transform`s

`Physics` will access the `world`'s Bodies (e.g. `StaticBody`) and `Transform`s