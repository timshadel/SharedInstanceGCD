# SharedInstanceGCD
**A collection of the best GCD singleton macros.**

> Cleanup your code!

There are lots of GCD singleton macros out there. Some are from Apple,
some are on Github, some are on Stack Overflow. This collects the
three main types into one header file, easily included by CocoaPods.

## Create Singletons

There are 3 main ways to create singletons using these macros.

### `sharedInstance`

This is the best one, in my opinion. It follows a prevailing naming
convention in recent Cocoa modules, and needs no parameters. It relies
on the convention that the [designated initializer] for your class is
simply `init`.

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


### `sharedClassname`

This one follows a longer-standing naming convention in Cocoa modules,
and needs to be told what this class is.

```ObjC
// Database.h

@interface Database
+ (instancetype)sharedDatabase;
@end

// Database.m

@implementation Database
SHARED_INSTANCE_CGD_WITH_NAME("Database")
@end
```


### Initialize Using a Block

This one gives you the most flexibility: you can use either of the
naming conventions above, or the method-body variant.

**sharedInstance naming convention**
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

**sharedClassname naming convention**
```ObjC
// Database.h

@interface Database
+ (instancetype)sharedDatabase;
@end

// Database.m

@implementation Database
SHARED_INSTANCE_GCD_WITH_NAME_USING_BLOCK("Database", ^{
  return [[Database alloc] initWithAnotherInitializer];
})
@end
```

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
