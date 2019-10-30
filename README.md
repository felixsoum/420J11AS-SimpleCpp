# 420J11AS-SimpleCpp

## Make a dummy BP
1. Make Dummy C++ class
1. Add a Static Mesh Component
1. Compile and create a BP from it
1. Put it in the level and test

## Destroy the dummy on hit
1. Find NotifyHit declaration and override it
1. Use cast to make sure we only react to projectile hit
1. Add HP (3 hits to kill)
1. Print message to screen with AddOnScreenDebugMessage

## Make dummy turn red on damage
1. Declare DummyMaterial field
1. Create CreateDynamicMaterialInstance in BeginPlay
1. SetScalarParameterValue on hit
1. Use Tick to decrement the HitValue
