# SharedInstanceGCD
**A collection of the best GCD singleton macros.**

> Cleanup your code!

There are lots of GCD singleton macros out there. Some are from Apple,
some are on Github, some are on Stack Overflow. This collects the
three main types into one header file, easily included by CocoaPods.

## Create Singletons

There are 3 main ways to create singletons using these macros.

### Use sharedInstance

This is the best one, in my opinion. It follows a prevailing naming
convention in recent Cocoa modules, and needs no parameters.

The first example relies on the convention that the
[designated initializer](https://developer.apple.com/library/ios/documentation/general/conceptual/CocoaEncyclopedia/Initialization/Initialization.html)
for your class is simply `init`. The second uses a block to allow you
to call any initializer.

**sharedInstance, default initializer**
```ObjC
// MyClass.h

@interface MyClass
+ (instancetype)sharedInstance;
@end

// MyClass.m

@implementation MyClass
SHARED_INSTANCE_CGD
@end
```

**sharedInstance, custom initializer**
```ObjC
// MyClass.h

@interface MyClass
+ (instancetype)sharedInstance;
@end

// MyClass.m

@implementation MyClass
SHARED_INSTANCE_GCD_USING_BLOCK(^{
  return [[MyClass alloc] initWithAnotherInitializer];
})
@end
```

### Use sharedClassname

This one follows a longer-standing naming convention in Cocoa modules,
and needs to be told what this class is.

**sharedClassname, default initializer**
```ObjC
// Database.h

@interface Database
+ (instancetype)sharedDatabase;
@end

// Database.m

@implementation Database
SHARED_INSTANCE_CGD_WITH_NAME(Database)
@end
```

**sharedClassname, custom initializer**
```ObjC
// Database.h

@interface Database
+ (instancetype)sharedDatabase;
@end

// Database.m

@implementation Database
SHARED_INSTANCE_GCD_WITH_NAME_USING_BLOCK(Database, ^{
  return [[Database alloc] initWithAnotherInitializer];
})
@end
```

### Method Body

This one gives you the most flexibility: you can use any method name.
Unlike the other options, you have to define the method in your
implementation file.

**Method body only approach**
```ObjC
// Utility.h

@interface Utility
+ (instancetype)defaultUtility;
@end

// Utility.m

@implementation Utility

+ (instancetype)defaultUtility
{
    DEFINE_SHARED_INSTANCE_GCD_USING_BLOCK(^{
        return [[Utility alloc] initWithAnotherInitializer];
    })
}

@end
```

## Installing the Macros

You can simply copy the header file into your project.

If you want updates, use CocoaPods:

```
pod 'SharedInstanceGCD'
```

## License

MIT.

I've consolidated the macros written by several people. If you'd like
to look at a couple, check out
[this gist](https://gist.github.com/lukeredpath/1057420), and this
[SO article](http://stackoverflow.com/questions/5720029/create-singleton-using-gcds-dispatch-once-in-objective-c).
