# Physics Engine

Will have `RigidBody`
- affected by physics simulation with gravity
- example: falling crate

Will have `StaticBody`
- not affected by gravity and can't move when collided with, but still collides
- example: the ground

Will have `CharacterBody`
- your player would inherit from this and override the update function for movement
- not automatically affected by gravity

Will handle collisions with `CollisionShape`
- you add this to a body

Will have a way to add custom Input bindings
- custom actions that you can map to whatever key bindings you want
- you would use the actions in your `CharacterBody` instance (likely with a state machine)